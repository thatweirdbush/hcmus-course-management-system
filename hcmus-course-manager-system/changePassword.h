#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

#include <QDialog>

namespace Ui {
class ChangePassword;
}

class ChangePassword : public QDialog
{
    Q_OBJECT

signals:
    void passwordChanged(const QString &newPassword);

public:
    explicit ChangePassword(QWidget *parent = nullptr, const std::string &currentPassword = "");

    ~ChangePassword();

private slots:
    void on_btnOK_clicked();

    void on_btnCancel_clicked();

private:
    Ui::ChangePassword *ui;

    QString currentPassword;
};

#endif // CHANGEPASSWORD_H
