#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Database.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}

// Enum class for stack widget index
enum class Page
{
    SignIn = 0,
    ProfileInfo_Student = 1,
    ProfileInfo_Staff = 2,
    Courses_Staff = 3,
    Courses_Student = 4,
    Semester_Staff = 5,
    Class_Staff = 6,
    Scoreboard_Staff = 7
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

    void on_btnEdit_ProfileInfo_Student_clicked();

    void on_btnCourses_ProfileInfo_Staff_clicked();

    void on_btnSemester_ProfileInfo_Staff_clicked();

    void on_btnClass_ProfileInfo_Staff_clicked();

    void on_btnBackToProfile_clicked();

    void on_btnBackToProfile_2_clicked();

    void on_btnBackToProfile_3_clicked();

    void on_btnBackToProfile_4_clicked();

    void on_btnScoreboard_ProfileInfo_Staff_clicked();

    void on_btnBackToProfile_5_clicked();

private:
    // Page Loaders
    void loadPageProfileInfo_Staff();

    void loadPageProfileInfo_Student();

private:
    Ui::MainWindow *ui;
    Database *db;

    Account *currentAccount;
    Student *currentStudent;
    Staff *currentStaff;
};
#endif // MAINWINDOW_H
