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
    ProfileInfo_Staff = 2,
    Courses_Staff = 3
};

// Define const file path
const QString COURSE_FILE_PATH = "course.csv";
const QString STUDENT_FILE_PATH = "student.csv";
const QString SCOREBOARD_FILE_PATH = "scoreboard.csv";
const QString SEMESTER_FILE_PATH = "semester.csv";
const QString STAFF_FILE_PATH = "staff.csv";
const QString ACCOUNT_FILE_PATH = "account.csv";


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

public:
    void loadCourseList();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
