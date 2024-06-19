#include "mainwindow.h"
#include "changePassword.h"
#include "ui_mainwindow.h"

#include <QDesktopServices>
#include <QMessageBox>

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
        // Open 'Empty Fields' message box
        QMessageBox::warning(this, "Empty Fields", "Please enter your username and password to sign in.", QMessageBox::Ok);
    }
    else
    {
        int index = db->login(username, password);

        // Check if username and password are incorrect
        if(index == -1) {
            QMessageBox::critical(this, "Login Failed", "Invalid username or password. Please try again.", QMessageBox::Ok);
            return;
        }

        // ELSE: Open 'Login Successful' message box
        currentAccount = new Account(db->accountList[index]);

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

    // /// For easy debug
    // // Go to Profile Info page using stack widget
    // ui->stackedWidget->setCurrentIndex(int(Page::ProfileInfo_Staff));
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

void MainWindow::on_btnEdit_ProfileInfo_Staff_clicked()
{
    // Open a new window to change password
    ChangePassword *changePasswordForm = new ChangePassword(this);
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

        // Go to Sign In page using stack widget
        ui->stackedWidget->setCurrentIndex(int(Page::SignIn));
    }
}

void MainWindow::on_changePassword(const QString &newPassword)
{
    // Update password to label
    ui->lableTestPassword->setText(newPassword);
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
    db->loadScoreboardList(ui->tableScoreboards);
    ui->stackedWidget->setCurrentIndex(int(Page::Scoreboard_Staff));
}

void MainWindow::on_btnBackToProfile_clicked()
{
    // Go back to Profile Info page using stack widget
    ui->stackedWidget->setCurrentIndex(int(Page::ProfileInfo_Staff));
}

void MainWindow::on_btnBackToProfile_2_clicked()
{
    // Go back to Profile Info page using stack widget
    ui->stackedWidget->setCurrentIndex(int(Page::ProfileInfo_Staff));
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
* Implement Default Page - Courses_Staff
*
***************************************************************/








/**************************************************************
* Implement Default Page - Courses_Student
*
***************************************************************/

















































