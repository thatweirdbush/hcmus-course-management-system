#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "Database.h"
#include "qshortcut.h"

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
    Course_Staff = 3,
    Account_Staff = 4,
    Semester_Staff = 5,
    Class_Staff = 6,
    Scoreboard_Staff = 7,
    ScoreboardOfCourse = 8,
    ScoreboardOfClass = 9,
    StudentInClass = 10,
    StudentInCourse = 11,
    StartSchoolYear = 12,
    StartSchoolYear_Next = 13,
    AddStudentToCourseUsingFile = 14,
    AddStudentToCourseManual = 15,
    StartSemester = 16,
    StartSemester_Next = 18,
    StartSemester_Next_2 = 17,
    EndSemester = 18,
    Others = 19,
    Course_Student = 20,
    Scoreboard_Student = 21
};


QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void loadPageSignIn();

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

    void on_btnScoreboardOfCourse_clicked();

    void on_btnBackToScoreboard_Staff_clicked();

    void on_btnBackToScoreboard_Staff_2_clicked();

    void on_btnScoreboardOfClass_clicked();

    void on_tableCourses_itemChanged(QTableWidgetItem *item);

    void on_btnDeleteCourse_clicked();

    void on_btnBackToCourse_Staff_clicked();

    void on_btnBackToClass_Staff_clicked();

    void on_btnStartSchoolYear_clicked();

    void on_btnBackToProfile_6_clicked();

    void on_btnAddNewClass_clicked();

    void on_btnRemoveClass_clicked();

    void on_btnRemoveAllClass_clicked();

    void on_btnNext_StartSchoolYear_clicked();

    void on_btnBackToStartSchoolYear_clicked();

    void on_btnAddFileStudent_clicked();

    void on_btnRemoveStudentInClass_clicked();

    void on_btnRemoveAllStudentInClass_clicked();

    void on_btnSave_StartSchoolYear_clicked();

    void on_btnStudentsInClass_clicked();

    void on_btnStudentsInCourse_clicked();

    void on_btnFinishAll_StartSchoolYear_2_clicked();

    void on_btnExportStudentInCourse_clicked();

    void on_btnDeleteStudentInCourse_clicked();

    void on_btnStartSemester_clicked();

    void on_btnBackToProfile_7_clicked();

    void on_btnNext_StartSemester_clicked();

    void on_btnAddFileStudent_StartSemester_clicked();

    void on_btnRemoveStudent_StartSemester_clicked();

    void on_btnRemoveAllStudent_StartSemester_clicked();

    void on_btnBackToStartSemester_Next_clicked();

    void on_btnFinishAll_AddStudentToCourse_clicked();

    void on_btnSave_AddStudentToCourse_clicked();

    void on_btnNextToSemester_2_clicked();

    void on_btnBackFromStartSemester_clicked();

    void on_btnAddFileCourse_clicked();

    void on_btnRemoveCourse_clicked();

    void on_btnRemoveAllCourse_clicked();

    void on_btnOthers_clicked();

    void on_btnImportScoreboard_clicked();

    void on_btnEndSemester_clicked();

    void on_btnCourses_ProfileInfo_Student_clicked();

    void on_btnScoreboard_ProfileInfo_Student_clicked();

    void on_btnBackToProfile_Student_clicked();

    void on_btnBackToProfile_Student_2_clicked();

private:
    // Page Loaders
    void loadPageProfileInfo_Staff();

    void clearPageProfileInfo_Staff();

    void loadPageProfileInfo_Student();

    void loadPageStartSchoolYear_Next();

    void loadPageStartSemester_Next();

    void loadPageStartSemester_Next_2();

private:
    Ui::MainWindow *ui;
    Database *db;
    QShortcut *shortcut;

    Account *currentAccount;
    Student *currentStudent;
    Staff *currentStaff;

    // For Student In Course Page
    Set<StudentInCourse> studentsInCourse;

    // For Start School Year Procedure
    Set<Student> newStudentList;

    // For Start Semester Procedure
    Set<Course> newCourseList;

    // For End Semester Procedure
    Set<Scoreboard> newScoreboardList;

    // For Student
    Set<StudentInCourse> studentInCourseListForStudent;

    Set<Course> courseListForStudent;

    Set<Scoreboard> scoreboardListForStudent;

};
#endif // MAINWINDOW_H
