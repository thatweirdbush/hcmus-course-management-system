/**************************************************************
* Implement Database class
* Define Database class - Database.h
***************************************************************/

#ifndef DATABASE_H
#define DATABASE_H

#include "AccountClass.h"
#include "CourseClass.h"
#include "SemesterClass.h"
#include "StudentClass.h"
#include "ScoreboardClass.h"
#include "StaffClass.h"
#include "ClassClass.h"
#include "StudentInClass.h"
#include "Set.h"
#include "StudentInCourse.h"
#include "qtablewidget.h"

// Define const file path
const QString COURSE_FILE_PATH = "course.csv";
const QString STUDENT_FILE_PATH = "student.csv";
const QString SCOREBOARD_FILE_PATH = "scoreboard.csv";
const QString SEMESTER_FILE_PATH = "semester.csv";
const QString STAFF_FILE_PATH = "staff.csv";
const QString ACCOUNT_FILE_PATH = "account.csv";
const QString CLASS_FILE_PATH = "class.csv";
const QString STUDENT_IN_CLASS_FILE_PATH = "student-in-class.csv";
const QString STUDENT_IN_COURSE_FILE_PATH = "student-in-course.csv";


class Database {
public:
    Set<Account> accountList;
    Set<Course> courseList;
    Set<Semester> semesterList;
    Set<Student> studentList;
    Set<Staff> staffList;
    Set<Scoreboard> scoreboardList;
    Set<Class> classList;
    Set<StudentInClass> studentInClassList;
    Set<StudentInCourse> studentInCourseList;

public:
    Database();
    ~Database();

public:
    void registerAccount();
    Account login(QString username, QString password);

public:
    // Import data from file - For Staff
    void importAccountList(QString filename, Set<Account>& accountList);

    void importCourseList(QString filename, Set<Course>& courseList);

    void importSemesterList(QString filename, Set<Semester>& semesterList);

    void importStudentList(QString filename, Set<Student>& studentList);

    void importStaffList(QString filename, Set<Staff>& staffList);

    void importScoreboardList(QString filename, Set<Scoreboard>& scoreboardList);

    void importClassList(QString filename, Set<Class>& classList);

    void importStudentInClassList(QString filename, Set<StudentInClass>& studentInClassList);

    // Import data from file - For Staff (and Student)
    void importStudentInCourseList(QString filename, Set<StudentInCourse>& studentInCourseList, int studentID = -1);

public:
    // Export data to file
    void exportAccountList(QString filename, Set<Account>& accountList);

    void exportCourseList(QString filename, Set<Course>& courseList);

    void exportSemesterList(QString filename, Set<Semester>& semesterList);

    void exportStudentList(QString filename, Set<Student>& studentList);

    void exportStaffList(QString filename, Set<Staff>& staffList);

    void exportScoreboardList(QString filename, Set<Scoreboard>& scoreboardList);

    void exportClassList(QString filename, Set<Class>& classList);

    void exportStudentInClassList(QString filename, Set<StudentInClass>& studentInClassList);

    void exportStudentInCourseList(QString filename, Set<StudentInCourse>& studentInCourseList);

public:
    // Load Data Context To Table Widget
    void loadCourseList(QTableWidget* table, Set<Course>& courseList);

    void loadStudentList(QTableWidget* table, Set<Student>& studentList);

    void loadStaffList(QTableWidget* table, Set<Staff>& staffList);

    void loadScoreboardList(QTableWidget* table, Set<Scoreboard>& scoreboardList);

    void loadSemesterList(QTableWidget* table, Set<Semester>& semesterList);

    void loadAccountList(QTableWidget* table, Set<Account>& accountList);

    void loadClassList(QTableWidget* table, Set<Class>& classList);

    void loadStudentInClassList(QTableWidget* table, Set<StudentInClass>& studentInClassList);

    void loadStudentInCourseList(QTableWidget* table, Set<StudentInCourse>& studentInCourseList);

public:
    // Update data to the database's attributes
    void updateCourseList(Course course, Set<Course>& courseList);

    void updateStudentList(Student student, Set<Student>& studentList);

    void updateStaffList(Staff staff, Set<Staff>& staffList);

    void updateScoreboardList(Scoreboard scoreboard, Set<Scoreboard>& scoreboardList);

    void updateSemesterList(Semester semester, Set<Semester>& semesterList);

    void updateAccountList(Account account, Set<Account>& accountList);

    void updateClassList(Class classObj, Set<Class>& classList);

public:
    // Delete data from the database's attributes
    void deleteFromCourseList(Course course, Set<Course>& courseList);

    void deleteFromStudentList(Student student, Set<Student>& studentList);

    void deleteFromStaffList(Staff staff, Set<Staff>& staffList);

    void deleteFromScoreboardList(Scoreboard scoreboard, Set<Scoreboard>& scoreboardList);

    void deleteFromSemesterList(Semester semester, Set<Semester>& semesterList);

    void deleteFromAccountList(Account account, Set<Account>& accountList);

    void deleteFromClassList(Class classObj, Set<Class>& classList);

    void deleteFromStudentInClassList(StudentInClass studentInClass, Set<StudentInClass>& studentInClassList);

    void deleteFromStudentInCourseList(StudentInCourse studentInCourse, Set<StudentInCourse>& studentInCourseList);

public:
    // Search functions - return single object
    Student getStudentByID(int studentID);

    Staff getStaffByID(int staffID);

    Course getCourseByID(int courseID);

    Semester getSemesterByID(int semesterID);

public:
    // Search functions - return all objects in list
    Set<Scoreboard> getScoreboardListByCourseID(int courseID);
};
#endif // DATABASE_H
