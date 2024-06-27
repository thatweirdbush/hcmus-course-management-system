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
    , studentsInCourse()
    , newStudentList()
    , newCourseList()
    , newScoreboardList()
    , courseListForStudent()
    , scoreboardListForStudent()

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

    // Free memory of cache data
    studentsInCourse.clear();
    newStudentList.clear();
    newCourseList.clear();
    newScoreboardList.clear();
    courseListForStudent.clear();
    scoreboardListForStudent.clear();
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
    // Open default website
    QDesktopServices::openUrl(QUrl("https://hcmus.edu.vn"));
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

    // Temporarily disconnect the itemChanged signal
    disconnect(ui->tableCourses, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(on_tableCourses_itemChanged(QTableWidgetItem*)));

    // Load course & scoreboard list to cache
    // db->loadCourseList(ui->tableCourses, db->courseList);
    // db->loadScoreboardList(ui->tableScoreboards, db->scoreboardList);
    db->importCourseList(COURSE_FILE_PATH, db->courseList);


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

// Go to Student's Course page using stack widget
void MainWindow::on_btnCourses_ProfileInfo_Student_clicked()
{

}

// Go to Student's Scoreboard page using stack widget
void MainWindow::on_btnScoreboard_ProfileInfo_Student_clicked()
{

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

    // Get course object
    Course selectCourse = db->getCourseByID(selectCourseID);
    std::string selectCourseName = selectCourse.getCourseName();

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

    // Load page's components
    QString courseInfo = QString::fromStdString(selectCourseName) + " [" + QString::number(selectCourseID) + "]";
    ui->labelCourseName_Binding->setText(courseInfo);

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

    // Load page's components
    ui->labelClassName_Binding->setText(QString::fromStdString(selectClassName));

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

// Import Scoreboard CSV file and add to datafile's scoreboard list
void MainWindow::on_btnImportScoreboard_clicked()
{
    // Open file dialog to get file path
    QString filePath = QFileDialog::getOpenFileName(this, "Open Student File", QDir::homePath(), "CSV files (*.csv)");
    if (filePath.isEmpty()) {
        return;
    }
    // Check file path is valid from text box
    if (!QFile::exists(filePath)) {
        QMessageBox::warning(this, "Invalid Input", "File does not exist!", QMessageBox::Ok);
        return;
    }
    try {
        // Get previous scoreboard list size
        int previousSize = db->scoreboardList.size();

        // Load student list from file
        db->importScoreboardList(filePath, newScoreboardList);

        for (int i = 0; i < newScoreboardList.size(); ++i) {
            // Insert to datafile's scoreboard list
            db->scoreboardList.insert(newScoreboardList[i]);
        }

        // Get new scoreboard list size
        int newSize = db->scoreboardList.size();

        // Check if datafile's scoreboard list has changed
        if (newSize == previousSize) {
            QMessageBox::warning(this, "Import Status", "Import successfully! But no new scoreboard added!", QMessageBox::Ok);
            return;
        }

        // Reload table widget
        db->loadScoreboardList(ui->tableScoreboards, db->scoreboardList);

        // Open 'Import Success' message box
        QMessageBox::information(this, "Import Success", "Import scoreboards successfully!", QMessageBox::Ok);
    } catch (...) {
        QMessageBox::warning(this, "Error", "Invalid data file. Please try again!", QMessageBox::Ok);
    }
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
    // Clear the student in course list
    studentsInCourse.clear();

    // Go back to Course page
    ui->stackedWidget->setCurrentIndex(int(Page::Course_Staff));
}

// Go to Student In Course page using stack widget
void MainWindow::on_btnStudentsInCourse_clicked()
{
    // Get the selected course in the table widget
    int selectedRow = ui->tableCourses->currentRow();
    if (selectedRow < 0) {
        QMessageBox::warning(this, "No Data Selected", "Please select a course to view students!", QMessageBox::Ok);
        return;
    }

    // Get course ID & course name
    QTableWidgetItem *itemID = ui->tableCourses->item(selectedRow, 0);
    QTableWidgetItem *itemName = ui->tableCourses->item(selectedRow, 1);

    int selectCourseID = itemID->text().toInt();
    QString selectCourseName = itemName->text();

    // Filter the studentID by course name in student-in-course.csv
    for (int i = 0; i < db->studentInCourseList.size(); i++) {
        if (db->studentInCourseList[i].getCourseID() == selectCourseID)
            studentsInCourse.insert(db->studentInCourseList[i]);
    }

    // Load the students in the course
    db->loadStudentInCourseList(ui->tableStudentInCourse, studentsInCourse);

    // Load page's components
    QString courseInfo = selectCourseName + " [" + QString::number(selectCourseID) + "]";
    ui->labelStudentInCourse_Binding->setText(courseInfo);

    // Go to Student In Course page using stack widget
    ui->stackedWidget->setCurrentIndex(int(Page::StudentInCourse));
}

// Delete selected student in course from the table
void MainWindow::on_btnDeleteStudentInCourse_clicked()
{
    // Get the selected student in course in the table widget
    int selectedRow = ui->tableStudentInCourse->currentRow();
    if (selectedRow < 0) {
        QMessageBox::warning(this, "No Data Selected", "Please select a student to delete!", QMessageBox::Ok);
        return;
    }

    // Get student in course object
    StudentInCourse selectedStudentInCourse = studentsInCourse[selectedRow];

    // Open 'Delete Student In Course Confirmation' message box
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete Confirmation", "Are you sure you want to delete this student in course?", QMessageBox::Yes | QMessageBox::No);

    // Check if user wants to delete
    if (reply == QMessageBox::Yes)
    {
        // Delete the student in course from the database
        db->deleteFromStudentInCourseList(selectedStudentInCourse, studentsInCourse);

        // Remove from table widget
        ui->tableStudentInCourse->removeRow(selectedRow);

        // Pop up a message to inform the user
        QMessageBox::information(this, "Delete Student In Course", "Student in course has been deleted!", QMessageBox::Ok);
    }
}

// Export student in selected course to CSV file
void MainWindow::on_btnExportStudentInCourse_clicked()
{
    // Export to CSV file
    QString fileName = QFileDialog::getSaveFileName(this, "Export Student In Course", "", "CSV File (*.csv)");
    if (fileName.isEmpty()) return;
    db->exportStudentInCourseList(fileName, studentsInCourse);

    // Open 'Export Successful' message box
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Export Successful", "Export Successful! Do you want to open the file?", QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes){
        // Open the file to show the result
        QDesktopServices::openUrl(QUrl("file:///" + fileName));
    }
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
    // Open Confirmation message box
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Back to Profile", "Are you sure you want to go back? Any unsaved data will be lost!", QMessageBox::Yes | QMessageBox::No);

    // Check if user wants to go back to Profile page
    if (reply == QMessageBox::Yes)
    {
        loadPageProfileInfo_Staff();
    }
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
            QMessageBox::warning(this, "Duplicate Entry", "Class already exists. Try a different name!", QMessageBox::Ok);
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
    if (currentRow < 0 || currentRow >= ui->listNewClasses->count()) {
        QMessageBox::warning(this, "Invalid Selection", "Please select a class to remove!", QMessageBox::Ok);
        return;
    }

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
    // Check if there are any classes to add
    if (ui->listNewClasses->count() == 0) {
        QMessageBox::warning(this, "No Classes Added", "Please add at least one class to start the school year!", QMessageBox::Ok);
        return;
    }

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
    QString message = "New classes have been added to school year " + QString::number(schoolYear);
    QMessageBox::information(this, "Start School Year", message, QMessageBox::Ok);

    // Clear current page's components
    ui->spinBoxSchoolYear->setValue(2024);
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
    // Open Confirmation message box
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Back Confirmation", "Are you sure you want to go back? Any unsaved data will be lost!", QMessageBox::Yes | QMessageBox::No);

    // Check if user wants to go back to Start School Year page
    if (reply == QMessageBox::Yes)
    {
        // Clear current page's components
        ui->comboBoxStudentClass->clear();
        ui->txtClassName_8->clear();
        ui->tableNewStudentsInClass->clear();

        // Go back to Start School Year page
        ui->stackedWidget->setCurrentIndex(int(Page::StartSchoolYear));
    }
}

// Load Page Start_School_Year_Next
void MainWindow::loadPageStartSchoolYear_Next()
{    
    // Clear page's components first
    ui->txtClassName_8->clear();
    ui->tableNewStudentsInClass->clear();
    ui->tableNewStudentsInClass->setColumnCount(0);
    ui->tableNewStudentsInClass->setRowCount(0);
    newStudentList.clear();

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
    // Get file path from Dialog if filename text box is empty
    QString filePath = ui->txtClassName_8->text();

    // Check if filename text box is empty
    if (filePath.isEmpty()) {
        // Open file dialog to get file path
        filePath = QFileDialog::getOpenFileName(this, "Open Student File", QDir::homePath(), "CSV files (*.csv)");
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
    if (selectedRow < 0 || selectedRow >= ui->tableNewStudentsInClass->rowCount()) {
        QMessageBox::warning(this, "Invalid Input", "Please select a student to remove!", QMessageBox::Ok);
        return;
    }

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

// Save new students to class
void MainWindow::on_btnSave_StartSchoolYear_clicked()
{    
    // Check if student list is empty
    if (newStudentList.size() == 0) {
        QMessageBox::warning(this, "Invalid Input", "There's no student to be added. Please add at least one student!", QMessageBox::Ok);
        return;
    }

    // Get selected class name
    std::string className = ui->comboBoxStudentClass->currentText().toStdString();

    // Build message string
    QString message = "Are you sure you want to save these students to class " + QString::fromStdString(className) + "?";

    // Open message box to confirm
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Save Confirmation", message, QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // Get new students in the Table Widget, combine with new class name, and insert to datafile's student list
        StudentInClass student;

        for (int i = 0; i < newStudentList.size(); ++i) {
            // Set class name & student ID for each student-in-class object
            student.setClassName(className);
            student.setStudentID(newStudentList[i].getStudentID());

            // Insert to datafile's student list
            db->studentInClassList.insert(student);
        }

        // Immediately save to datafile
        db->exportStudentInClassList(STUDENT_IN_CLASS_FILE_PATH, db->studentInClassList);

        // Open success message box
        QMessageBox::information(this, "Save Success", "Students have been added to the class!", QMessageBox::Ok);

        // Reload current page's components
        loadPageStartSchoolYear_Next();
    }
}

// Finish adding new students to class, no saving data
void MainWindow::on_btnFinishAll_StartSchoolYear_2_clicked()
{
    // Check if there are still new students in the list
    if (newStudentList.size() > 0) {
        // Open Confirmation message box
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Finish Confirmation", "Are you sure you want to finish? Any unsaved data will be lost!", QMessageBox::Yes | QMessageBox::No);

        // Check if user wants to finish
        if (reply == QMessageBox::Yes) {
            // Clear current page's components
            ui->comboBoxStudentClass->clear();
            ui->txtClassName_8->clear();
            ui->tableNewStudentsInClass->clear();

            // Go back to Profile page
            loadPageProfileInfo_Staff();
        }
    }
    else {
        // Open Notification message box
        QMessageBox::information(this, "Finish", "Start School Year completed!", QMessageBox::Ok);

        // Clear current page's components
        ui->comboBoxStudentClass->clear();
        ui->txtClassName_8->clear();
        ui->tableNewStudentsInClass->clear();

        // Go back to Profile page
        loadPageProfileInfo_Staff();
    }
}


/**************************************************************
* Implement Page - Procedure - Start_Semester
*
***************************************************************/
// Go back to Profile Page
void MainWindow::on_btnBackToProfile_7_clicked()
{
    // Open Confirmation message box
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Back Confirmation", "Are you sure you want to go back? Any unsaved data will be lost!", QMessageBox::Yes | QMessageBox::No);

    // Check if user wants to go back to Profile page
    if (reply == QMessageBox::Yes)
    {
        // Reset current page's components
        ui->spinBoxSchoolYear_2->setValue(2024);
        ui->spinBoxSemesterNo->setValue(1);
        ui->dateEdit_Start->setDate(QDate(2024, 9, 5));
        ui->dateEdit_End->setDate(QDate(2025, 1, 5));

        // Go back to Profile page
        loadPageProfileInfo_Staff();
    }
}

// Procedure - Start Semester
void MainWindow::on_btnStartSemester_clicked()
{
    // Open 'Start Semester Confirmation' message box
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Start Semester Confirmation", "Are you sure you want to start a semester?", QMessageBox::Yes | QMessageBox::No);

    // Check if user wants to start a new school year
    if (reply == QMessageBox::Yes)
    {
        ui->stackedWidget->setCurrentIndex(int(Page::StartSemester));
    }
}

// Save new semester with started school year & go to Page Start_Semester_Next
void MainWindow::on_btnNext_StartSemester_clicked()
{
    // Get all info from Spin Boxs
    int schoolYear = ui->spinBoxSchoolYear_2->value();
    int semesterNo = ui->spinBoxSemesterNo->value();

    // Convert QDate to std::string
    std::string startDate = ui->dateEdit_Start->date().toString("dd/MM/yyyy").toStdString();
    std::string endDate = ui->dateEdit_End->date().toString("dd/MM/yyyy").toStdString();

    // Get newest semesterID in list
    int newestID = db->semesterList.back().getSemesterID();

    // Create new semester object, with increased semesterID
    Semester newSemester(++newestID, semesterNo, schoolYear, startDate, endDate);

    // Insert to datafile's semester list
    db->semesterList.insert(newSemester);

    // Immediately save to datafile
    db->exportSemesterList(SEMESTER_FILE_PATH, db->semesterList);

    // Pop up a message to inform the user
    QString message = "New semester have been added to school year " + QString::number(schoolYear);
    QMessageBox::information(this, "Start Semester", message, QMessageBox::Ok);

    // Clear current page's components
    ui->spinBoxSchoolYear_2->setValue(2024);
    ui->spinBoxSemesterNo->setValue(1);
    ui->dateEdit_Start->setDate(QDate(2024, 9, 5));
    ui->dateEdit_End->setDate(QDate(2025, 1, 5));

    // Load Page Start_Semester_Next's components
    loadPageStartSemester_Next();

    // Go to Start_Semester_Next page
    ui->stackedWidget->setCurrentIndex(int(Page::StartSemester_Next));
}


/**************************************************************
* Implement Page - Procedure - Start_Semester_Next
*
***************************************************************/
// Load Page Start_Semester_Next
void MainWindow::loadPageStartSemester_Next()
{
    // Clear page's components first
    ui->txtCourseFile->clear();
    ui->tableNewCourse->clear();
    ui->tableNewCourse->setColumnCount(0);
    ui->tableNewCourse->setRowCount(0);
    newCourseList.clear();

    // Load all semester to combobox
    for (int i = 0; i < db->semesterList.size(); ++i) {
        QString semesterInfoStr = QString::number(db->semesterList[i].getNo()) + " - " + QString::number(db->semesterList[i].getSchoolYear());
        ui->comboBoxSemester->addItem(semesterInfoStr);
    }

    // Set default semester for combo box - last semester info
    if (db->classList.size() > 0) {
        ui->comboBoxSemester->setCurrentIndex(db->semesterList.size() - 1);
    }
}

// Save new course list to datafile's course list & Go to Page Start_Semester_Next_2
void MainWindow::on_btnNextToSemester_2_clicked()
{
    // Check if course list is empty
    if (newCourseList.size() == 0) {
        QMessageBox::warning(this, "Invalid Input", "There's no course to be added. Please add at least one course!", QMessageBox::Ok);
        return;
    }

    // Get current semester info
    std::string semesterInfo = std::to_string(db->semesterList[ui->comboBoxSemester->currentIndex()].getNo()) + " - " +
                               std::to_string(db->semesterList[ui->comboBoxSemester->currentIndex()].getSchoolYear());

    // Build message string
    QString message = "Are you sure you want to save these course to semester " + QString::fromStdString(semesterInfo) + "?";

    // Open message box to confirm
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Save Confirmation", message, QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // Get newest courseID in list
        int newestID = db->courseList.back().getCourseID();

        // Get new courses in the Table Widget
        for (int i = 0; i < newCourseList.size(); ++i) {
            // Readjust courseID
            newCourseList[i].setCourseID(++newestID);

            // Insert to datafile's student list
            db->courseList.insert(newCourseList[i]);
        }

        // Immediately save to datafile
        db->exportCourseList(COURSE_FILE_PATH, db->courseList);

        // Open success message box
        QMessageBox::information(this, "Save Success", "Courses have been added to new semester!", QMessageBox::Ok);

        // Reload current page's components
        loadPageStartSemester_Next();

        // Load Page Start_Semester_Next_2's components
        loadPageStartSemester_Next_2();
    }
}

// Go back to Page Start_Semester
void MainWindow::on_btnBackFromStartSemester_clicked()
{
    // Open Confirmation message box
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Back Confirmation", "Are you sure you want to go back? Any unsaved data will be lost!", QMessageBox::Yes | QMessageBox::No);

    // Check if user wants to go back to Start_Semester page
    if (reply == QMessageBox::Yes)
    {
        // Reset current page's components
        loadPageStartSemester_Next();

        // Go back to Start_Semester page
        ui->stackedWidget->setCurrentIndex(int(Page::StartSemester));
    }
}

// Choose file to add courses (from text box or file dialog)
void MainWindow::on_btnAddFileCourse_clicked()
{
    // Get file path from Dialog if filename text box is empty
    QString filePath = ui->txtCourseFile->text();

    // Check if filename text box is empty
    if (filePath.isEmpty()) {
        // Open file dialog to get file path
        filePath = QFileDialog::getOpenFileName(this, "Open Course File", QDir::homePath(), "CSV files (*.csv)");
        if (filePath.isEmpty()) {
            return;
        }
        // Update text box
        ui->txtCourseFile->setText(filePath);
    }
    else {
        // Check file path is valid from text box
        if (!QFile::exists(filePath)) {
            QMessageBox::warning(this, "Invalid Input", "File does not exist!", QMessageBox::Ok);
            return;
        }
    }
    try {
        // Load course list from file
        db->importCourseList(filePath, newCourseList);

        // Add courses to table widget
        db->loadCourseList(ui->tableNewCourse, newCourseList);
    } catch (...) {
        QMessageBox::warning(this, "Error", "Invalid data file. Please try again!", QMessageBox::Ok);
    }
}

// Remove selected course from the list
void MainWindow::on_btnRemoveCourse_clicked()
{
    // Get selected row
    int selectedRow = ui->tableNewCourse->currentRow();
    if (selectedRow < 0 || selectedRow >= ui->tableNewCourse->rowCount()) {
        QMessageBox::warning(this, "Invalid Input", "Please select a course to remove!", QMessageBox::Ok);
        return;
    }

    // Remove selected row
    ui->tableNewCourse->removeRow(selectedRow);

    // Create temp course object
    Course tempCourse= newCourseList[selectedRow];

    // Remove from course list
    db->deleteFromCourseList(tempCourse, newCourseList);
}

// Remove all courses from the list
void MainWindow::on_btnRemoveAllCourse_clicked()
{
    // Clear table widget
    ui->tableNewCourse->clearContents();

    // Clear course list
    newCourseList.clear();
}


/**************************************************************
* Implement Page - Procedure - Start_Semester_Next_2
*
***************************************************************/
// Load Page Start_Semester_Next_2
void MainWindow::loadPageStartSemester_Next_2()
{
    // Clear page's components first
    ui->txtStudentFile->clear();
    ui->tableNewStudents_StartSemester->clear();
    ui->tableNewStudents_StartSemester->setColumnCount(0);
    ui->tableNewStudents_StartSemester->setRowCount(0);
    newStudentList.clear();

    // Load all courses to combobox
    for (int i = 0; i < db->courseList.size(); ++i) {
        std::string courseInfoStr = std::to_string(db->courseList[i].getCourseID()) + " - " + db->courseList[i].getCourseName() + " - " + db->courseList[i].getClassName();
        ui->comboBoxCourse_StartSemester->addItem(QString::fromStdString(courseInfoStr));
    }

    // Set default course name for combo box - last course info
    if (db->courseList.size() > 0) {
        ui->comboBoxCourse_StartSemester->setCurrentIndex(db->courseList.size() - 1);
    }

    // Go to Page Start_Semester_Next_2
    ui->stackedWidget->setCurrentIndex(int(Page::StartSemester_Next_2));
}

// Choose file to add students (from text box or file dialog)
void MainWindow::on_btnAddFileStudent_StartSemester_clicked()
{
    // Get file path from Dialog if filename text box is empty
    QString filePath = ui->txtStudentFile->text();

    // Check if filename text box is empty
    if (filePath.isEmpty()) {
        // Open file dialog to get file path
        filePath = QFileDialog::getOpenFileName(this, "Open Student File", QDir::homePath(), "CSV files (*.csv)");
        if (filePath.isEmpty()) {
            return;
        }
        // Update text box
        ui->txtStudentFile->setText(filePath);
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
        db->loadStudentList(ui->tableNewStudents_StartSemester, newStudentList);
    } catch (...) {
        QMessageBox::warning(this, "Error", "Invalid data file. Please try again!", QMessageBox::Ok);
    }
}

// Remove selected student from the list
void MainWindow::on_btnRemoveStudent_StartSemester_clicked()
{
    // Get selected row
    int selectedRow = ui->tableNewStudents_StartSemester->currentRow();
    if (selectedRow < 0 || selectedRow >= ui->tableNewStudents_StartSemester->rowCount()) {
        QMessageBox::warning(this, "Invalid Input", "Please select a student to remove!", QMessageBox::Ok);
        return;
    }

    // Remove selected row
    ui->tableNewStudents_StartSemester->removeRow(selectedRow);

    // Create temp student object
    Student tempStudent = newStudentList[selectedRow];

    // Remove from student list
    db->deleteFromStudentList(tempStudent, newStudentList);
}

// Remove all students from the list
void MainWindow::on_btnRemoveAllStudent_StartSemester_clicked()
{
    // Clear table widget
    ui->tableNewStudents_StartSemester->clearContents();

    // Clear student list
    newStudentList.clear();
}

// Back to Start_Semester page
void MainWindow::on_btnBackToStartSemester_Next_clicked()
{
    // Open Confirmation message box
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Back Confirmation", "Are you sure you want to go back? Any unsaved data will be lost!", QMessageBox::Yes | QMessageBox::No);

    // Check if user wants to go back to Start_Semester page
    if (reply == QMessageBox::Yes)
    {
        // Reset current page's components
        loadPageStartSemester_Next();

        // Go back to Start_Semester page
        ui->stackedWidget->setCurrentIndex(int(Page::StartSemester_Next));
    }
}

// Finish adding new students to course, no saving data
void MainWindow::on_btnFinishAll_AddStudentToCourse_clicked()
{
    // Check if there are still new students in the list
    if (newStudentList.size() > 0) {
        // Open Confirmation message box
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Finish Confirmation", "Are you sure you want to finish? Any unsaved data will be lost!", QMessageBox::Yes | QMessageBox::No);

        // Check if user wants to finish
        if (reply == QMessageBox::Yes) {
            // Reset current page's components
            loadPageStartSemester_Next_2();

            // Go back to Profile page
            loadPageProfileInfo_Staff();
        }
    }
    else {
        // Open Notification message box
        QMessageBox::information(this, "Finish", "Start Semester completed!", QMessageBox::Ok);

        // Reset current page's components
        loadPageStartSemester_Next_2();

        // Go back to Profile page
        loadPageProfileInfo_Staff();
    }
}

// Save new students to course & Reload current page
void MainWindow::on_btnSave_AddStudentToCourse_clicked()
{
    // Check if student list is empty
    if (newStudentList.size() == 0) {
        QMessageBox::warning(this, "Invalid Input", "There's no student to be added. Please add at least one student!", QMessageBox::Ok);
        return;
    }

    // Build message string
    QString message = "Are you sure you want to save these students to Course " + ui->comboBoxCourse_StartSemester->currentText() + "?";

    // Open message box to confirm
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Save Confirmation", message, QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // Get current semester ID
        int currentSemesterID = db->semesterList[db->semesterList.size() - 1].getSemesterID();

        // Get selected course ID from combo box by index
        int selectedCourseIndex = ui->comboBoxCourse_StartSemester->currentIndex();
        int selectedCourseID = db->courseList[selectedCourseIndex].getCourseID();
        std::string selectedClassName = db->courseList[selectedCourseIndex].getClassName();

        // Get newest student ID in datafile's list
        int newestStudentID = db->studentList.back().getStudentID();

        // Get new students in the Table Widget, with readjusted student ID
        StudentInClass studentInClass;
        StudentInCourse studentInCours;

        for (int i = 0; i < newStudentList.size(); ++i) {
            // Set class name & student ID for each student-in-class object
            newStudentList[i].setStudentID(++newestStudentID);

            // Insert to datafile's student list
            db->studentList.insert(newStudentList[i]);

            // Insert to datafile's student-in-class
            studentInClass.setClassName(selectedClassName);
            studentInClass.setStudentID(newestStudentID);
            db->studentInClassList.insert(studentInClass);

            // Insert to datafile's student-in-course list
            studentInCours.setSemesterID(currentSemesterID);
            studentInCours.setCourseID(selectedCourseID);
            studentInCours.setStudentID(newestStudentID);
            db->studentInCourseList.insert(studentInCours);
        }

        // Immediately save to datafiles
        db->exportStudentList(STUDENT_FILE_PATH, db->studentList);
        db->exportStudentInClassList(STUDENT_IN_CLASS_FILE_PATH, db->studentInClassList);
        db->exportStudentInCourseList(STUDENT_IN_COURSE_FILE_PATH, db->studentInCourseList);

        // Open success message box
        QMessageBox::information(this, "Save Success", "Students have been added to the course this semester!", QMessageBox::Ok);

        // Reload current page's components
        loadPageStartSemester_Next_2();
    }
}


/**************************************************************
* Implement Page - Procedure - End Semester
*
***************************************************************/
// Go to End_Semester page - Actually this page is Scoreboard_Staff page
void MainWindow::on_btnEndSemester_clicked()
{
    // Get current semester info
    Semester currentSemester = db->semesterList[db->semesterList.size() - 1];
    QString message = "Are you sure you want to end the current Semester " +
                      QString::number(currentSemester.getNo()) + " - " +
                      QString::number(currentSemester.getSchoolYear()) + "?";

    // Open Confirmation message box
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "End Semester Confirmation", message, QMessageBox::Yes | QMessageBox::No);

    // Check if user wants to end the semester
    if (reply == QMessageBox::Yes) {
        // Load page's components
        db->loadScoreboardList(ui->tableScoreboards, db->scoreboardList);
        // Go to Scoreboard page
        ui->stackedWidget->setCurrentIndex(int(Page::Scoreboard_Staff));
    }
}


/**************************************************************
* Implement Page - Procedure - Others
*
***************************************************************/
// Show "Coming soon" message box
void MainWindow::on_btnOthers_clicked()
{
    QMessageBox::information(this, "Coming Soon", "New feature coming soon!", QMessageBox::Ok);
}










