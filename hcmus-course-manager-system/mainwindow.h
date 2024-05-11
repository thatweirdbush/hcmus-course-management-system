#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}

// Enum class for stack widget index
enum class Page
{
    SignIn = 0,
    ProfileInfo_Student = 1,
    ProfileInfo_Staff = 2
};

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnRegister_clicked();

    void on_btnForgotPassword_clicked();

    void on_btnSignIn_clicked();

    void on_btnSignOut_ProfileInfo_Student_clicked();

    void on_btnSignOut_ProfileInfo_Staff_clicked();

    void on_btnEdit_ProfileInfo_Staff_clicked();

    void on_changePassword(const QString &newPassword);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
