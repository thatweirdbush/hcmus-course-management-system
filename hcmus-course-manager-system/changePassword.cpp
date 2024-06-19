#include "changePassword.h"
#include "qmessagebox.h"
#include "ui_changePassword.h"
#include <QShortcut>

ChangePassword::ChangePassword(QWidget *parent, const std::string &currentPassword)
    : QDialog(parent)
    , ui(new Ui::ChangePassword)
    , currentPassword(QString::fromStdString(currentPassword))
{
    ui->setupUi(this);

    // Create a shortcut for the Enter key to trigger the Sign In button
    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::Key_Return), this);
    connect(shortcut, &QShortcut::activated, this, &ChangePassword::on_btnOK_clicked);

    // Set focus to current field by default
    ui->txtCurrent->setFocus();
}

ChangePassword::~ChangePassword()
{
    delete ui;
}

void ChangePassword::on_btnCancel_clicked()
{
    close();
}

void ChangePassword::on_btnOK_clicked()
{
    // Get old password, new password, and confirm password
    QString oldPassword = ui->txtCurrent->text();
    QString newPassword = ui->txtNew->text();
    QString confirmPassword = ui->txtRetype->text();

    // Check if old password, new password, and confirm password are empty
    if (oldPassword.isEmpty() || newPassword.isEmpty() || confirmPassword.isEmpty())
    {
        QMessageBox::warning(this, "Empty Fields", "Please enter all fields.", QMessageBox::Ok);
        return;
    }

    // Check if old password is correct
    if (oldPassword != currentPassword)
    {
        QMessageBox::warning(this, "Incorrect Password", "The current password you entered is incorrect.", QMessageBox::Ok);
        return;
    }

    // Check if new password and confirm password match
    if (newPassword != confirmPassword)
    {
        QMessageBox::warning(this, "Password Mismatch", "New password and confirm password do not match.", QMessageBox::Ok);
        return;
    }

    /// Else...
    // Open 'Password Changed' message box
    QMessageBox::information(this, "Password Changed", "Your password has been changed successfully.", QMessageBox::Ok);

    // Clear old password, new password, and confirm password fields
    ui->txtCurrent->clear();
    ui->txtNew->clear();
    ui->txtRetype->clear();

    // Pass new password to mainwindow
    emit passwordChanged(newPassword);

    // Close Change Password form
    close();
}

