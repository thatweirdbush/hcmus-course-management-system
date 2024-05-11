#include "changePassword.h"
#include "qmessagebox.h"
#include "ui_changePassword.h"

ChangePassword::ChangePassword(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChangePassword)
{
    ui->setupUi(this);
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
        // Open 'Empty Fields' message box
        QMessageBox::warning(this, "Empty Fields", "Please enter all fields.", QMessageBox::Ok);
    }
    else
    {
        // Check if new password and confirm password match
        if (newPassword == confirmPassword)
        {
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
        else
        {
            // Open 'Password Mismatch' message box
            QMessageBox::warning(this, "Password Mismatch", "New password and confirm password do not match.", QMessageBox::Ok);
        }
    }
}

