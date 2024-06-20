#include "mainwindow.h"
#include "changePassword.h"
#include "ui_mainwindow.h"

#include <QDesktopServices>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , db(new Database)
    , shortcut(new QShortcut(QKeySequence(Qt::Key_Return), this))
    , currentAccount(nullptr)
    , currentStudent(nullptr)
    , currentStaff(nullptr)
    , newStudentList()

{
    ui->setupUi(this);

    loadPageSignIn();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete db;
    delete shortcut;

    // Free memory of current account, student/staff
    if (currentAccount != nullptr)
        delete currentAccount;
    if (currentStudent != nullptr)
        delete currentStudent;
    if (currentStaff != nullptr)
        delete currentStaff;

    newStudentList.clear();
}


/**************************************************************
* Implement Default Page - SignIn
*
***************************************************************/
// Load all data in page's components
void MainWindow::loadPageSignIn() {
    // Display default page 'Sign In' using stack widget
    ui->stackedWidget->setCurrentIndex(int(Page::SignIn));

    // Create a shortcut for the Enter key to trigger the Sign In button
    connect(shortcut, &QShortcut::activated, this, &MainWindow::on_btnSignIn_clicked);

    // Set focus to username field by default
    ui->txtUsername->setFocus();
}

// Register button
void MainWindow::on_btnRegister_clicked()
{
    // // Open default website
    // QDesktopServices::openUrl(QUrl("https://hcmus.edu.vn"));

    /// For easy debug
    /// Go to Account List page using stack widget
    db->loadAccountList(ui->tableAccounts, db->accountList);
    ui->stackedWidget->setCurrentIndex(int(Page::Account_Staff));
}

// Forgot Password button
void MainWindow::on_btnForgotPassword_clicked()
{
    // Open 'Forgot Password' message box
    QMessageBox::information(this, "Forgot Password", "Please contact the administrator to reset your password.", QMessageBox::Ok | QMessageBox::Cancel);
}

// Sign In button
void MainWindow::on_btnSignIn_clicked()
{
    // Get username and password
    QString username = ui->txtUsername->text();
    QString password = ui->txtPassword->text();

    // Check if username and password are empty
    if (username.isEmpty() || password.isEmpty())
    {
        QMessageBox::warning(this, "Empty Fields", "Please enter your username and password to sign in.", QMessageBox::Ok);
        return;
    }
    /// else...
    // Initialize current account from account object loaded from datafile
    currentAccount = new Account(db->login(username, password));

    /// Check if username and password are incorrect
    // Login is failed when account ID is -1 because login() return default object with ID = -1
    if (currentAccount->getAccountID() == -1) {
        QMessageBox::critical(this, "Login Failed", "Invalid username or password. Please try again.", QMessageBox::Ok);
        return;
    }

    // Get staff/student ID
    int staffOrStudentID = currentAccount->getStaffOrStudentID();

    // Check if user is student or staff by counting num of digits
    if (staffOrStudentID < 10000) {
        Staff *staff = new Staff(db->getStaffByID(staffOrStudentID));
        currentStaff = staff;

        QString welcomeScript = "Welcome, " + QString::fromStdString(staff->getFullName()) + "!";
        QMessageBox::information(this, "Login Successful", welcomeScript, QMessageBox::Ok);

        // Go to Staff's Profile Info page
        loadPageProfileInfo_Staff();

    } else {
        Student *student = new Student(db->getStudentByID(staffOrStudentID));
        currentStudent = student;

        QString welcomeScript = "Welcome, " + QString::fromStdString(student->getFullname()) + "!";
        QMessageBox::information(this, "Login Successful", welcomeScript, QMessageBox::Ok);

        // Go to Student's Profile Info page
        loadPageProfileInfo_Student();
    }

    // Clear username and password fields
    ui->txtUsername->clear();
    ui->txtPassword->clear();

    // Disconnect the Enter key from triggering the Sign In button again
    disconnect(shortcut, &QShortcut::activated, this, &MainWindow::on_btnSignIn_clicked);
}


/**************************************************************
* Implement Page - ProfileInfo_Staff
*
***************************************************************/
// Load all data in page's components
void MainWindow::loadPageProfileInfo_Staff() {
    // Load staff info
    ui->lableUsernameHere_Staff->setText(QString::fromStdString(currentStaff->getFullName()));
    ui->lableStaffID->setText(QString::number(currentStaff->getStaffID()));
    ui->lableStaffBirth->setText(QString::fromStdString(currentStaff->getDateOfBirth().toString()));
    ui->lableStaffGender->setText(QString::fromStdString(currentStaff->getGender()));
    ui->lableStaffEmail->setText(QString::fromStdString(currentStaff->getEmail()));
    ui->lableStaffPhone->setText(QString::fromStdString(currentStaff->getPhone()));
    ui->lableStaffFacilityAddress->setText(QString::fromStdString(currentStaff->getFacilityAddress()));

    // Go to Profile Info page using stack widget
    ui->stackedWidget->setCurrentIndex(int(Page::ProfileInfo_Staff));
}

// Clear all data in page's components
void MainWindow::clearPageProfileInfo_Staff(){
    // Clear the data in Profile Info Staff page
    ui->lableUsernameHere_Staff->clear();
    ui->lableStaffID->clear();
    ui->lableStaffBirth->clear();
    ui->lableStaffGender->clear();
    ui->lableStaffEmail->clear();
    ui->lableStaffPhone->clear();
    ui->lableStaffFacilityAddress->clear();
}

// Change Password button
void MainWindow::on_btnEdit_ProfileInfo_Staff_clicked()
{
    // Open a new window to change password, with current password pass to it
    ChangePassword *changePasswordForm = new ChangePassword(this, currentAccount->getPassword());
    connect(changePasswordForm, &ChangePassword::passwordChanged, this, &MainWindow::on_changePassword);
    changePasswordForm->show();
}

// Sign Out button
void MainWindow::on_btnSignOut_ProfileInfo_Staff_clicked()
{
    // Open 'Sign Out' message box
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Sign Out", "Are you sure you want to sign out?", QMessageBox::Yes | QMessageBox::No);

    // Check if user wants to sign out
    if (reply == QMessageBox::Yes)
    {
        // Free memory of current account, student/staff
        if (currentAccount != nullptr)
            delete currentAccount;
        if (currentStaff != nullptr)
            delete currentStaff;

        currentAccount = nullptr;
        currentStaff = nullptr;

        // Free up components of the stack widget
        clearPageProfileInfo_Staff();

        // Go to Sign In page using stack widget
        loadPageSignIn();
    }
}

// Get new password from ChangePassword form and update to data file
void MainWindow::on_changePassword(const QString &newPassword)
{
    // Update password to current account and the one in the datafile
    currentAccount->setPassword(newPassword.toStdString());
    db->updateAccountList(*currentAccount, db->accountList);

    // Immediately save to data file
    db->exportAccountList(ACCOUNT_FILE_PATH, db->accountList);
}

// Go to Course page using stack widget
void MainWindow::on_btnCourses_ProfileInfo_Staff_clicked()
{
    // Temporarily disconnect the itemChanged signal
    disconnect(ui->tableCourses, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(on_tableCourses_itemChanged(QTableWidgetItem*)));

    // Load course list
    db->loadCourseList(ui->tableCourses, db->courseList);

    // Reconnect the itemChanged signal after loading the data
    connect(ui->tableCourses, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(on_tableCourses_itemChanged(QTableWidgetItem*)));

    // Go to Course page using stack widget
    ui->stackedWidget->setCurrentIndex(int(Page::Course_Staff));
}

// Go to Semester page using stack widget
void MainWindow::on_btnSemester_ProfileInfo_Staff_clicked()
{
    db->loadSemesterList(ui->tableSemesters, db->semesterList);
    ui->stackedWidget->setCurrentIndex(int(Page::Semester_Staff));
}

// Go to Class page using stack widget
void MainWindow::on_btnClass_ProfileInfo_Staff_clicked()
{
    db->loadClassList(ui->tableClasses, db->classList);
    ui->stackedWidget->setCurrentIndex(int(Page::Class_Staff));
}

// Go to Scoreboard page using stack widget
void MainWindow::on_btnScoreboard_ProfileInfo_Staff_clicked()
{
    db->loadScoreboardList(ui->tableScoreboards, db->scoreboardList);
    ui->stackedWidget->setCurrentIndex(int(Page::Scoreboard_Staff));
}

// Go back to Profile Info page using stack widget - From Course page
void MainWindow::on_btnBackToProfile_clicked()
{
    ui->stackedWidget->setCurrentIndex(int(Page::ProfileInfo_Staff));
}

// Go back to Sign In page using stack widget - From Account page
void MainWindow::on_btnBackToProfile_2_clicked()
{
    loadPageSignIn();
}


// Go back to Profile Info page using stack widget - From Semester page
void MainWindow::on_btnBackToProfile_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(int(Page::ProfileInfo_Staff));
}


// Go back to Profile Info page using stack widget - From Class page
void MainWindow::on_btnBackToProfile_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(int(Page::ProfileInfo_Staff));
}


/**************************************************************
* Implement Page - ProfileInfo_Student
*
***************************************************************/
// Load all data in page's components
void MainWindow::loadPageProfileInfo_Student() {
    // Load student info
    ui->labelUsernameHere_Student->setText(QString::fromStdString(currentStudent->getFullname()));
    ui->labelStudentID->setText(QString::number(currentStudent->getStudentID()));
    ui->labelStudentBirth->setText(QString::fromStdString(currentStudent->getDateOfBirth().toString()));
    ui->labelStudentGender->setText(QString::fromStdString(currentStudent->getGender()));
    ui->labelStudentSocialID->setText(QString::fromStdString(currentStudent->getSocialID()));

    // Go to Profile Info page using stack widget
    ui->stackedWidget->setCurrentIndex(int(Page::ProfileInfo_Student));
}

// Change Password button
void MainWindow::on_btnEdit_ProfileInfo_Student_clicked()
{
    // Open a new window to change password
    ChangePassword *changePasswordForm = new ChangePassword(this);
    connect(changePasswordForm, &ChangePassword::passwordChanged, this, &MainWindow::on_changePassword);
    changePasswordForm->show();
}

// Sign Out button
void MainWindow::on_btnSignOut_ProfileInfo_Student_clicked()
{
    // Open 'Sign Out' message box
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Sign Out", "Are you sure you want to sign out?", QMessageBox::Yes | QMessageBox::No);

    // Check if user wants to sign out
    if (reply == QMessageBox::Yes)
    {
        // Free memory of current account, student/staff
        if (currentAccount != nullptr)
            delete currentAccount;
        if (currentStudent != nullptr)
            delete currentStudent;

        currentAccount = nullptr;
        currentStudent = nullptr;

        // Go to Sign In page using stack widget
        loadPageSignIn();
    }
}


/**************************************************************
* Implement Page - Scoreboard_Staff
*
***************************************************************/
// Go back to Profile Info page using stack widget - From Scoreboard page
void MainWindow::on_btnBackToProfile_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(int(Page::ProfileInfo_Staff));
}

// Go to Course's Scoreboard page using stack widget
void MainWindow::on_btnScoreboardOfCourse_clicked()
{
    // Get the selected course in the table widget
    int selectedRow = ui->tableScoreboards->currentRow();
    if (selectedRow < 0) {
        QMessageBox::warning(this, "No Data Selected", "Please select a course to view scoreboard!", QMessageBox::Ok);
        return;
    }

    // Get course ID
    QTableWidgetItem *item = ui->tableScoreboards->item(selectedRow, 0);
    int selectCourseID = item->text().toInt();

    // Create new Set of Scoreboard filter by course ID
    Set<Scoreboard> scoreboardOfCourse;

    // Filter the scoreboard by course ID
    for (int i = 0; i < db->scoreboardList.size(); i++) {
        Scoreboard sb = db->scoreboardList[i];
        if (sb.getCourseID() == selectCourseID)
            scoreboardOfCourse.insert(sb);
    }

    // Load the scoreboard of the course
    db->loadScoreboardList(ui->tableScoreboardOfCourse, scoreboardOfCourse);

    // Get statistics of the course
    float avgGPA = 0.0f;
    float highestGPA = 0.0f;
    std::string achievedByStudent = "";

    for (int i = 0; i < scoreboardOfCourse.size(); i++) {
        Scoreboard sb = scoreboardOfCourse[i];
        avgGPA += sb.getFinalMark();
        if (sb.getFinalMark() > highestGPA) {
            highestGPA = sb.getFinalMark();
            achievedByStudent = sb.getFullName();
        }
    }

    // Calculate average GPA
    avgGPA /= scoreboardOfCourse.size();

    // Display statistics
    ui->labelAvgGPA_Binding->setText(QString::number(avgGPA));
    ui->labelHighestScore_Binding->setText(QString::number(highestGPA));
    ui->labelAchievedBy_Binding->setText(QString::fromStdString(achievedByStudent));

    // Go to Scoreboard Of Course page using stack widget
    ui->stackedWidget->setCurrentIndex(int(Page::ScoreboardOfCourse));
}

// Go to Class's Scoreboard page using stack widget
void MainWindow::on_btnScoreboardOfClass_clicked()
{
    // Get the selected class in the table widget
    int selectedRow = ui->tableScoreboards->currentRow();
    if (selectedRow < 0) {
        QMessageBox::warning(this, "No Data Selected", "Please select a class to view scoreboard!", QMessageBox::Ok);
        return;
    }

    // Get class name
    QTableWidgetItem *item = ui->tableScoreboards->item(selectedRow, 1);
    std::string selectClassName = item->text().toStdString();

    // Create new Set of Scoreboard filter by class ID
    Set<Scoreboard> scoreboardOfClass;

    // Filter the scoreboard by class ID
    for (int i = 0; i < db->scoreboardList.size(); i++) {
        Scoreboard sb = db->scoreboardList[i];
        if (sb.getClassName() == selectClassName)
            scoreboardOfClass.insert(sb);
    }

    // Load the scoreboard of the class
    db->loadScoreboardList(ui->tableScoreboardOfClass, scoreboardOfClass);

    // Get statistics of the class
    float avgGPA = 0.0f;
    float highestGPA = 0.0f;
    std::string achievedByStudent = "";

    for (int i = 0; i < scoreboardOfClass.size(); i++) {
        Scoreboard sb = scoreboardOfClass[i];
        avgGPA += sb.getFinalMark();
        if (sb.getFinalMark() > highestGPA) {
            highestGPA = sb.getFinalMark();
            achievedByStudent = sb.getFullName();
        }
    }

    // Calculate average GPA
    avgGPA /= scoreboardOfClass.size();

    // Display statistics
    ui->labelAvgGPA_Binding_2->setText(QString::number(avgGPA));
    ui->labelHighestScore_Binding_2->setText(QString::number(highestGPA));
    ui->labelAchievedBy_Binding_2->setText(QString::fromStdString(achievedByStudent));

    // Go to Scoreboard Of Class page using stack widget
    ui->stackedWidget->setCurrentIndex(int(Page::ScoreboardOfClass));
}


/**************************************************************
* Implement Page - Scoreboard_Staff - Scoreboard_Of_Course
*
***************************************************************/
// Go back to Scoreboard page using stack widget - From Scoreboard Of Course page
void MainWindow::on_btnBackToScoreboard_Staff_clicked()
{
    ui->stackedWidget->setCurrentIndex(int(Page::Scoreboard_Staff));
}


/**************************************************************
* Implement Page - Scoreboard_Staff - Scoreboard_Of_Class
*
***************************************************************/
// Go back to Scoreboard page using stack widget - From Scoreboard Of Class page
void MainWindow::on_btnBackToScoreboard_Staff_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(int(Page::Scoreboard_Staff));
}


/**************************************************************
* Implement Page - Course_Staff
*
***************************************************************/
// Get updates from table & update to datafile
void MainWindow::on_tableCourses_itemChanged(QTableWidgetItem *item)
{
    // Restrict the user from changing the course ID
    if (item->column() == 0) {
        QMessageBox::warning(this, "Invalid Change", "You cannot change the course ID!", QMessageBox::Ok);
        item->setText(QString::number(db->courseList[item->row()].getCourseID()));
        return;
    }

    // Get changed course information
    if (item->column() == 1) {
        db->courseList[item->row()].setCourseName(item->text().toStdString());
    }
    else if (item->column() == 2) {
        db->courseList[item->row()].setClassName(item->text().toStdString());
    }
    else if (item->column() == 3) {
        db->courseList[item->row()].setTeacherName(item->text().toStdString());
    }
    else if (item->column() == 4) {
        db->courseList[item->row()].setNumOfCredits(item->text().toInt());
    }
    else if (item->column() == 5) {
        db->courseList[item->row()].setMaxStudents(item->text().toInt());
    }
    else if (item->column() == 6) {
        db->courseList[item->row()].setDayOfWeek(stringToDayOfWeek(item->text().toStdString()));
    }
    else if (item->column() == 7) {
        db->courseList[item->row()].setSession(stringToSession(item->text().toStdString()));
    }

    // Immediately save to datafile
    db->exportCourseList(COURSE_FILE_PATH, db->courseList);

    // Pop up a message to inform the user
    QMessageBox::information(this, "Update Course", "Course information has been updated!", QMessageBox::Ok);
}

// Select a course in the table & delete from datafile
void MainWindow::on_btnDeleteCourse_clicked()
{
    // Get the selected course in the table widget
    int selectedRow = ui->tableCourses->currentRow();
    if (selectedRow < 0) {
        QMessageBox::warning(this, "No Data Selected", "Please select a course to delete!", QMessageBox::Ok);
        return;
    }

    // Get course object
    Course selectedCourse = db->courseList[selectedRow];

    // Open 'Delete Course Confirmation' message box
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete Confirmation", "Are you sure you want to delete this course?", QMessageBox::Yes | QMessageBox::No);

    // Check if user wants to delete
    if (reply == QMessageBox::Yes)
    {
        // Delete the course from the database
        db->deleteFromCourseList(selectedCourse, db->courseList);

        // Immediately save to datafile
        db->exportCourseList(COURSE_FILE_PATH, db->courseList);

        // Remove from table widget
        ui->tableCourses->removeRow(selectedRow);

        // Pop up a message to inform the user
        QMessageBox::information(this, "Delete Course", "Course has been deleted!", QMessageBox::Ok);
    }
}


/**************************************************************
* Implement Page - Course_Staff - Student_In_Course
*
***************************************************************/
// Go back to Course page using stack widget
void MainWindow::on_btnBackToCourse_Staff_clicked()
{
    ui->stackedWidget->setCurrentIndex(int(Page::Course_Staff));
}


/**************************************************************
* Implement Page - Class_Staff - Student_In_Class
*
***************************************************************/
// Go back to Class page using stack widget
void MainWindow::on_btnBackToClass_Staff_clicked()
{
    ui->stackedWidget->setCurrentIndex(int(Page::Class_Staff));
}

// Go to Student In Class page using stack widget
void MainWindow::on_btnStudentsInClass_clicked()
{
    // Get the selected class in the table widget
    int selectedRow = ui->tableClasses->currentRow();
    if (selectedRow < 0) {
        QMessageBox::warning(this, "No Data Selected", "Please select a class to view students!", QMessageBox::Ok);
        return;
    }

    // Get class name
    QTableWidgetItem *item = ui->tableClasses->item(selectedRow, 0);
    std::string selectClassName = item->text().toStdString();

    // Create new Set of Student filter by class name
    Set<Student> studentsInClass;

    // Filter the studentID by class name in student-in-class.csv
    for (int i = 0; i < db->studentInClassList.size(); i++) {
        if (db->studentInClassList[i].getClassName() == selectClassName) {
            Student st = db->getStudentByID(db->studentInClassList[i].getStudentID());
            studentsInClass.insert(st);
        }
    }

    // Load the student list of the class
    db->loadStudentList(ui->tableStudentInClass, studentsInClass);

    // Load page's components
    ui->labelStudentInClass_Binding->setText(QString::fromStdString(selectClassName));

    // Go to Student In Class page using stack widget
    ui->stackedWidget->setCurrentIndex(int(Page::StudentInClass));
}









/**************************************************************
* Implement Page - Procedure - Start_School_Year
*
***************************************************************/
// Procedure - Start School Year
void MainWindow::on_btnStartSchoolYear_clicked()
{
    // Open 'Start School Year Confirmation' message box
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Start School Year Confirmation", "Are you sure you want to start a new school year?", QMessageBox::Yes | QMessageBox::No);

    // Check if user wants to start a new school year
    if (reply == QMessageBox::Yes)
    {
        ui->stackedWidget->setCurrentIndex(int(Page::StartSchoolYear));
    }
}

// Go back to Profile page using stack widget
void MainWindow::on_btnBackToProfile_6_clicked()
{
    loadPageProfileInfo_Staff();
}

// Add new class to the list
void MainWindow::on_btnAddNewClass_clicked()
{
    // Remove leading/trailing spaces
    QString className = ui->txtClassName->text().trimmed();
    if (className.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a class name!", QMessageBox::Ok);
        return;
    }

    // Check for duplicate entry
    for (int i = 0; i < ui->listNewClasses->count(); ++i) {
        QListWidgetItem* item = ui->listNewClasses->item(i);
        if (item && item->text() == className) {
            QMessageBox::warning(this, "Duplicate Entry", "Class name already exists in the list!", QMessageBox::Ok);
            return;
        }
    }

    // Add to list widget
    QListWidgetItem* item = new QListWidgetItem(className, ui->listNewClasses);
    item->setFlags(item->flags() | Qt::ItemIsEditable);
    ui->listNewClasses->addItem(item);

    ui->txtClassName->clear();
    ui->txtClassName->setFocus();
}

// Remove selected class from the list
void MainWindow::on_btnRemoveClass_clicked()
{
    int currentRow = ui->listNewClasses->currentRow();
    if (currentRow < 0 || currentRow >= ui->listNewClasses->count())
        return;

    QListWidgetItem* item = ui->listNewClasses->takeItem(currentRow);
    delete item;
}

// Remove all classes from the list
void MainWindow::on_btnRemoveAllClass_clicked()
{
    ui->listNewClasses->clear();
}

// Save new classes with started school year & go to Page Add_Student_To_Class
void MainWindow::on_btnNext_StartSchoolYear_clicked()
{
    // Get school year from Spin Box
    int schoolYear = ui->spinBoxSchoolYear->value();

    // Get newest classID in list
    int newestID = db->classList.back().getClassID();

    // Get new class object and insert to datafile's class list
    for (int i = 0; i < ui->listNewClasses->count(); ++i) {
        QListWidgetItem* item = ui->listNewClasses->item(i);
        if (item) {
            // Get class name
            std::string className = item->text().toStdString();

            // Create new class object, with increased classID
            Class newClass(++newestID, className, schoolYear);

            // Insert to datafile's class list
            db->classList.insert(newClass);
        }
    }
    // Immediately save to datafile
    db->exportClassList(CLASS_FILE_PATH, db->classList);

    // Pop up a message to inform the user
    QString message = "New classes have been added! New school year is " + QString::number(schoolYear);
    QMessageBox::information(this, "Start School Year", message, QMessageBox::Ok);

    // Clear current page's components
    ui->spinBoxSchoolYear->setValue(2021);
    ui->listNewClasses->clear();
    ui->txtClassName->clear();

    // Load Page Start_School_Year_Next's components
    loadPageStartSchoolYear_Next();

    // Go to Add Student To Class page
    ui->stackedWidget->setCurrentIndex(int(Page::StartSchoolYear_Next));
}

/**************************************************************
* Implement Page - Procedure - Start_School_Year_Next
*
***************************************************************/
// Go back to Start School Year page using stack widget
void MainWindow::on_btnBackToStartSchoolYear_clicked()
{
    // Clear current page's components
    ui->comboBoxStudentClass->clear();
    ui->txtClassName_8->clear();
    ui->tableNewStudentsInClass->clear();

    // Go back to Start School Year page
    ui->stackedWidget->setCurrentIndex(int(Page::StartSchoolYear));
}

// Load Page Start_School_Year_Next
void MainWindow::loadPageStartSchoolYear_Next()
{
    // Load all classes to combobox
    for (int i = 0; i < db->classList.size(); ++i) {
        ui->comboBoxStudentClass->addItem(QString::fromStdString(db->classList[i].getClassName()));
    }

    // Set default class name for combo box - last class name
    if (db->classList.size() > 0) {
        ui->comboBoxStudentClass->setCurrentIndex(db->classList.size() - 1);
    }
}

// Choose file to add students (from text box or file dialog)
void MainWindow::on_btnAddFileStudent_clicked()
{
    // Get class name from combo box
    QString className = ui->comboBoxStudentClass->currentText();
    if (className.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", "Please select a class!", QMessageBox::Ok);
        return;
    }

    // Get file path from Dialog if filename text box is empty
    QString filePath = ui->txtClassName_8->text();

    // Check if filename text box is empty
    if (filePath.isEmpty()) {
        // Open file dialog to get file path
        filePath = QFileDialog::getOpenFileName(this, "Open Student File", QDir::homePath(), "Text/CSV files (*.txt *.csv)");
        if (filePath.isEmpty()) {
            return;
        }
        // Update text box
        ui->txtClassName_8->setText(filePath);
    }
    else {
        // Check file path is valid from text box
        if (!QFile::exists(filePath)) {
            QMessageBox::warning(this, "Invalid Input", "File does not exist!", QMessageBox::Ok);
            return;
        }
    }
    try {
        // Load student list from file
        db->importStudentList(filePath, newStudentList);

        // Add students to table widget
        db->loadStudentList(ui->tableNewStudentsInClass, newStudentList);
    } catch (...) {
        QMessageBox::warning(this, "Error", "Invalid data file. Please try again!", QMessageBox::Ok);
    }
}

// Remove selected student from the list
void MainWindow::on_btnRemoveStudentInClass_clicked()
{
    // Get selected row
    int selectedRow = ui->tableNewStudentsInClass->currentRow();
    if (selectedRow < 0 || selectedRow >= ui->tableNewStudentsInClass->rowCount())
        return;

    // Remove selected row
    ui->tableNewStudentsInClass->removeRow(selectedRow);

    // Create temp student object
    Student tempStudent = newStudentList[selectedRow];

    // Remove from student list
    db->deleteFromStudentList(tempStudent, newStudentList);
}

// Remove all students from the list
void MainWindow::on_btnRemoveAllStudentInClass_clicked()
{
    // Clear table widget
    ui->tableNewStudentsInClass->clearContents();

    // Clear student list
    newStudentList.clear();
}

void MainWindow::on_btnSave_StartSchoolYear_clicked()
{
    // Open message box to confirm
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Save Confirmation", "Are you sure you want to save these students to the class?", QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // Open success message box
        QMessageBox::information(this, "Save Success", "Students have been added to the class!", QMessageBox::Ok);

        // Clear current page's components
        ui->comboBoxStudentClass->clear();
        ui->txtClassName_8->clear();
        ui->tableNewStudentsInClass->clear();

        // Go back to Profile page using stack widget
        loadPageProfileInfo_Staff();
    }
}


























