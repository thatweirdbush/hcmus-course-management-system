#include "mainwindow.h"
#include "changePassword.h"
#include "ui_mainwindow.h"

#include <QDesktopServices>
#include <QMessageBox>
#include <QShortcut>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , db(new Database)
    , currentAccount(nullptr)
    , currentStudent(nullptr)
    , currentStaff(nullptr)
{
    ui->setupUi(this);

    // Display default page 'Sign In' using stack widget
    ui->stackedWidget->setCurrentIndex(int(Page::SignIn));

    // Create a shortcut for the Enter key to trigger the Sign In button
    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::Key_Return), this);
    connect(shortcut, &QShortcut::activated, this, &MainWindow::on_btnSignIn_clicked);

    // Set focus to username field by default
    ui->txtUsername->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete db;

    // Free memory of current account, student/staff
    if (currentAccount != nullptr)
        delete currentAccount;
    if (currentStudent != nullptr)
        delete currentStudent;
    if (currentStaff != nullptr)
        delete currentStaff;
}


/**************************************************************
* Implement Default Page - SignIn
*
***************************************************************/
void MainWindow::on_btnRegister_clicked()
{
    // // Open default website
    // QDesktopServices::openUrl(QUrl("https://hcmus.edu.vn"));

    // For easy debug
    // Go to Account List page using stack widget
    db->loadAccountList(ui->tableAccounts);
    ui->stackedWidget->setCurrentIndex(int(Page::Account_Staff));
}

void MainWindow::on_btnForgotPassword_clicked()
{
    // Open 'Forgot Password' message box
    QMessageBox::information(this, "Forgot Password", "Please contact the administrator to reset your password.", QMessageBox::Ok | QMessageBox::Cancel);
}

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
}


/**************************************************************
* Implement Page - ProfileInfo_Staff
*
***************************************************************/
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

void MainWindow::on_btnEdit_ProfileInfo_Staff_clicked()
{
    // Open a new window to change password, with current password pass to it
    ChangePassword *changePasswordForm = new ChangePassword(this, currentAccount->getPassword());
    connect(changePasswordForm, &ChangePassword::passwordChanged, this, &MainWindow::on_changePassword);
    changePasswordForm->show();
}

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
        ui->stackedWidget->setCurrentIndex(int(Page::SignIn));
    }
}

// Get new password from ChangePassword form and update to data file
void MainWindow::on_changePassword(const QString &newPassword)
{
    // Update password to current account and the one in the datafile
    currentAccount->setPassword(newPassword.toStdString());
    db->updateAccountList(*currentAccount);

    // Immediately save to data file
    db->exportAccountList(ACCOUNT_FILE_PATH);
}

void MainWindow::on_btnCourses_ProfileInfo_Staff_clicked()
{
    // Go to Course page using stack widget
    db->loadCourseList(ui->tableCourses);
    ui->stackedWidget->setCurrentIndex(int(Page::Courses_Staff));
}

void MainWindow::on_btnSemester_ProfileInfo_Staff_clicked()
{
    // Go to Semester page using stack widget
    db->loadSemesterList(ui->tableSemesters);
    ui->stackedWidget->setCurrentIndex(int(Page::Semester_Staff));
}

void MainWindow::on_btnClass_ProfileInfo_Staff_clicked()
{
    // Go to Class page using stack widget
    db->loadClassList(ui->tableClasses);
    ui->stackedWidget->setCurrentIndex(int(Page::Class_Staff));
}

void MainWindow::on_btnScoreboard_ProfileInfo_Staff_clicked()
{
    // Go to Scoreboard page using stack widget
    db->loadScoreboardList(ui->tableScoreboards, db->scoreboardList);
    ui->stackedWidget->setCurrentIndex(int(Page::Scoreboard_Staff));
}

void MainWindow::on_btnBackToProfile_clicked()
{
    // Go back to Profile Info page using stack widget
    ui->stackedWidget->setCurrentIndex(int(Page::ProfileInfo_Staff));
}

void MainWindow::on_btnBackToProfile_2_clicked()
{
    // Go back to Sign In page using stack widget
    ui->stackedWidget->setCurrentIndex(int(Page::SignIn));
}


void MainWindow::on_btnBackToProfile_3_clicked()
{
    // Go back to Profile Info page using stack widget
    ui->stackedWidget->setCurrentIndex(int(Page::ProfileInfo_Staff));
}


void MainWindow::on_btnBackToProfile_4_clicked()
{
    // Go back to Profile Info page using stack widget
    ui->stackedWidget->setCurrentIndex(int(Page::ProfileInfo_Staff));
}

void MainWindow::on_btnBackToProfile_5_clicked()
{
    // Go back to Profile Info page using stack widget
    ui->stackedWidget->setCurrentIndex(int(Page::ProfileInfo_Staff));
}


/**************************************************************
* Implement Page - ProfileInfo_Student
*
***************************************************************/
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

void MainWindow::on_btnEdit_ProfileInfo_Student_clicked()
{
    // Open a new window to change password
    ChangePassword *changePasswordForm = new ChangePassword(this);
    connect(changePasswordForm, &ChangePassword::passwordChanged, this, &MainWindow::on_changePassword);
    changePasswordForm->show();
}

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
        ui->stackedWidget->setCurrentIndex(int(Page::SignIn));
    }
}








/**************************************************************
* Implement Page - Scoreboard_Staff
*
***************************************************************/
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
void MainWindow::on_btnBackToScoreboard_Staff_clicked()
{
    // Go back to Scoreboard page using stack widget
    ui->stackedWidget->setCurrentIndex(int(Page::Scoreboard_Staff));
}


/**************************************************************
* Implement Page - Scoreboard_Staff - Scoreboard_Of_Class
*
***************************************************************/
void MainWindow::on_btnBackToScoreboard_Staff_2_clicked()
{
    // Go back to Scoreboard page using stack widget
    ui->stackedWidget->setCurrentIndex(int(Page::Scoreboard_Staff));
}






























































