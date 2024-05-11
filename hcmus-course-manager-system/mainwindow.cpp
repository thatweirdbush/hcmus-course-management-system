#include "mainwindow.h"
#include "changePassword.h"
#include "changePassword.h"
#include "ui_mainwindow.h"

#include <QDesktopServices>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Go to default page 'Sign In' using stack widget
    ui->stackedWidget->setCurrentIndex(int(Page::SignIn));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnRegister_clicked()
{
    // Open default website
    QDesktopServices::openUrl(QUrl("https://hcmus.edu.vn"));
}

void MainWindow::on_btnForgotPassword_clicked()
{
    // Open 'Forgot Password' message box
    QMessageBox::information(this, "Forgot Password", "Please contact the administrator to reset your password.", QMessageBox::Ok | QMessageBox::Cancel);
}


void MainWindow::on_btnSignIn_clicked()
{
    // // Get username and password
    // QString username = ui->txtUsername->text();
    // QString password = ui->txtPassword->text();

    // // Check if username and password are empty
    // if (username.isEmpty() || password.isEmpty())
    // {
    //     // Open 'Empty Fields' message box
    //     QMessageBox::warning(this, "Empty Fields", "Please enter your username and password to sign in.", QMessageBox::Ok);
    // }
    // else
    // {
    //     // Check if username and password are correct
    //     if (username == "admin" && password == "admin")
    //     {
    //         // Open 'Login Successful' message box
    //         QMessageBox::information(this, "Login Successful", "Welcome, Admin!", QMessageBox::Ok);

    //         // Clear username and password fields
    //         ui->txtUsername->clear();
    //         ui->txtPassword->clear();

    //         // Go to Profile Info page using stack widget
    //         ui->stackedWidget->setCurrentIndex(1);
    //     }
    //     else
    //     {
    //         // Open 'Login Failed' message box
    //         QMessageBox::critical(this, "Login Failed", "Invalid username or password. Please try again.", QMessageBox::Ok);
    //     }
    // }

    /// For easy debug
    // Go to Profile Info page using stack widget
    ui->stackedWidget->setCurrentIndex(int(Page::ProfileInfo_Staff));
}

void MainWindow::on_btnSignOut_ProfileInfo_Student_clicked()
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

void MainWindow::on_changePassword(const QString &newPassword)
{
    // Update password to label
    ui->lableTestPassword->setText(newPassword);
}
































