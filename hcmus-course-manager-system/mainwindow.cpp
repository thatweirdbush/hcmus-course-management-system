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

    // Go to default page 'Sign In' using stack widget
    ui->stackedWidget->setCurrentIndex(int(Page::SignIn));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete db;
    if (currentAccount != nullptr)
        delete currentAccount;
    if (currentStudent != nullptr)
        delete currentStudent;
    if (currentStaff != nullptr)
        delete currentStaff;
}

void MainWindow::on_btnRegister_clicked()
{
    // // Open default website
    // QDesktopServices::openUrl(QUrl("https://hcmus.edu.vn"));

    /// For easy debug
    // Go to Account List page using stack widget
    // loadAccountList();
    loadStudentList();
    ui->stackedWidget->setCurrentIndex(4);
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
        if (currentStaff != nullptr)
            delete currentStaff;

        currentAccount = nullptr;
        currentStudent = nullptr;
        currentStaff= nullptr;

        // Go to Sign In page using stack widget
        ui->stackedWidget->setCurrentIndex(int(Page::SignIn));
    }
}


void MainWindow::on_btnSignOut_ProfileInfo_Staff_clicked()
{
    // Open 'Sign Out' message box
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Sign Out", "Are you sure you want to sign out?", QMessageBox::Yes | QMessageBox::No);

    // Check if user wants to sign out
    if (reply == QMessageBox::Yes)
    {
        // Go to Sign In page using stack widget
        ui->stackedWidget->setCurrentIndex(int(Page::SignIn));
    }
}

void MainWindow::on_btnEdit_ProfileInfo_Staff_clicked()
{
    // Open a new window to change password
    ChangePassword *changePasswordForm = new ChangePassword(this);
    connect(changePasswordForm, &ChangePassword::passwordChanged, this, &MainWindow::on_changePassword);
    changePasswordForm->show();
}

void MainWindow::on_btnEdit_ProfileInfo_Student_clicked()
{
    // Open a new window to change password
    ChangePassword *changePasswordForm = new ChangePassword(this);
    connect(changePasswordForm, &ChangePassword::passwordChanged, this, &MainWindow::on_changePassword);
    changePasswordForm->show();
}

void MainWindow::on_changePassword(const QString &newPassword)
{
    // Update password to label
    ui->lableTestPassword->setText(newPassword);
}


void MainWindow::on_btnCourses_ProfileInfo_Staff_clicked()
{
    // Go to Course page using stack widget
    loadCourseList();
    ui->stackedWidget->setCurrentIndex(int(Page::Courses_Staff));
}

void MainWindow::loadCourseList()
{
    // Create a list of courses
    Vector<Course> courseList;

    // Add courses to the list
    readCoursesFromFile(COURSE_FILE_PATH, courseList);

    // Display courses in the table
    ui->tableCourses->setRowCount(courseList.size());
    ui->tableCourses->setColumnCount(8);

    // Set table headers
    ui->tableCourses->setHorizontalHeaderItem(0, new QTableWidgetItem("Course ID"));
    ui->tableCourses->setHorizontalHeaderItem(1, new QTableWidgetItem("Course Name"));
    ui->tableCourses->setHorizontalHeaderItem(2, new QTableWidgetItem("Class Name"));
    ui->tableCourses->setHorizontalHeaderItem(3, new QTableWidgetItem("Teacher Name"));
    ui->tableCourses->setHorizontalHeaderItem(4, new QTableWidgetItem("Credits"));
    ui->tableCourses->setHorizontalHeaderItem(5, new QTableWidgetItem("Max Students"));
    ui->tableCourses->setHorizontalHeaderItem(6, new QTableWidgetItem("Day of Week"));
    ui->tableCourses->setHorizontalHeaderItem(7, new QTableWidgetItem("Session"));

    // Display courses in the table
    for (int i = 0; i < courseList.size(); i++)
    {
        Course course = courseList[i];
        ui->tableCourses->setItem(i, 0, new QTableWidgetItem(QString::number(course.getCourseID())));
        ui->tableCourses->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(course.getCourseName())));
        ui->tableCourses->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(course.getClassName())));
        ui->tableCourses->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(course.getTeacherName())));
        ui->tableCourses->setItem(i, 4, new QTableWidgetItem(QString::number(course.getNumOfCredits())));
        ui->tableCourses->setItem(i, 5, new QTableWidgetItem(QString::number(course.getMaxStudents())));
        ui->tableCourses->setItem(i, 6, new QTableWidgetItem(QString::fromStdString(dayOfWeekToString(course.getDayOfWeek()))));
        ui->tableCourses->setItem(i, 7, new QTableWidgetItem(QString::fromStdString(sessionToString(course.getSession()))));
    }
}

void MainWindow::loadAccountList()
{
    db->accountList;

    // Display courses in the table
    ui->tableAccount->setRowCount(db->accountList.size());
    ui->tableAccount->setColumnCount(4);

    // Set table headers
    ui->tableAccount->setHorizontalHeaderItem(0, new QTableWidgetItem("Account ID"));
    ui->tableAccount->setHorizontalHeaderItem(1, new QTableWidgetItem("Staff/Student ID"));
    ui->tableAccount->setHorizontalHeaderItem(2, new QTableWidgetItem("Username"));
    ui->tableAccount->setHorizontalHeaderItem(3, new QTableWidgetItem("Password"));

    // Display courses in the table
    for (int i = 0; i < db->accountList.size(); i++)
    {
        Account account = db->accountList[i];
        ui->tableAccount->setItem(i, 0, new QTableWidgetItem(QString::number(account.getAccountID())));
        ui->tableAccount->setItem(i, 1, new QTableWidgetItem(QString::number(account.getStaffOrStudentID())));
        ui->tableAccount->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(account.getUsername())));
        ui->tableAccount->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(account.getPassword())));
    }
}

void MainWindow::loadStudentList()
{
    db->studentList;

    // Display courses in the table
    ui->tableAccount->setRowCount(db->studentList.size());
    ui->tableAccount->setColumnCount(7);

    // Set table headers
    ui->tableAccount->setHorizontalHeaderItem(0, new QTableWidgetItem("No"));
    ui->tableAccount->setHorizontalHeaderItem(1, new QTableWidgetItem("Student ID"));
    ui->tableAccount->setHorizontalHeaderItem(2, new QTableWidgetItem("First name"));
    ui->tableAccount->setHorizontalHeaderItem(3, new QTableWidgetItem("Last Name"));
    ui->tableAccount->setHorizontalHeaderItem(4, new QTableWidgetItem("Gender"));
    ui->tableAccount->setHorizontalHeaderItem(5, new QTableWidgetItem("Birth"));
    ui->tableAccount->setHorizontalHeaderItem(6, new QTableWidgetItem("Social ID"));


    // Display courses in the table
    for (int i = 0; i < db->studentList.size(); i++)
    {
        Student student = db->studentList[i];
        ui->tableAccount->setItem(i, 0, new QTableWidgetItem(QString::number(student.getClassID())));
        ui->tableAccount->setItem(i, 1, new QTableWidgetItem(QString::number(student.getStudentID())));
        ui->tableAccount->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(student.getFirstName())));
        ui->tableAccount->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(student.getLastName())));
        ui->tableAccount->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(student.getGender())));
        ui->tableAccount->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(student.getDateOfBirth().toString())));
        ui->tableAccount->setItem(i, 6, new QTableWidgetItem(QString::fromStdString(student.getSocialID())));
    }
}

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





















































