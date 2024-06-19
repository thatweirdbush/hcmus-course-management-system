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
#include "Set.h"
#include "qtablewidget.h"

// Define const file path
const QString COURSE_FILE_PATH = "course.csv";
const QString STUDENT_FILE_PATH = "student.csv";
const QString SCOREBOARD_FILE_PATH = "scoreboard.csv";
const QString SEMESTER_FILE_PATH = "semester.csv";
const QString STAFF_FILE_PATH = "staff.csv";
const QString ACCOUNT_FILE_PATH = "account.csv";
const QString CLASS_FILE_PATH = "class.csv";


class Database {
public:
    Set<Account> accountList;
    Set<Course> courseList;
    Set<Semester> semesterList;
    Set<Student> studentList;
    Set<Staff> staffList;
    Set<Scoreboard> scoreboardList;
    Set<Class> classList;

public:
    Database();
    ~Database();

public:
    void registerAccount();
    Account login(QString username, QString password);

public:
    // Import data from file
    void importAccountList(QString filename);

    void importCourseList(QString filename);

    void importSemesterList(QString filename);

    void importStudentList(QString filename);

    void importStaffList(QString filename);

    void importScoreboardList(QString filename);

    void importClassList(QString filename);

public:
    // Export data to file
    void exportAccountList(QString filename);

    void exportCourseList(QString filename);

    void exportSemesterList(QString filename);

    void exportStudentList(QString filename);

    void exportStaffList(QString filename);

    void exportScoreboardList(QString filename);

    void exportClassList(QString filename);

public:
    // Load Data Context To Table Widget
    void loadCourseList(QTableWidget* table);

    void loadStudentList(QTableWidget* table);

    void loadStaffList(QTableWidget* table);

    void loadScoreboardList(QTableWidget* table, Set<Scoreboard>& scoreboardList);

    void loadSemesterList(QTableWidget* table);

    void loadAccountList(QTableWidget* table);

    void loadClassList(QTableWidget* table);

public:
    // Search functions - return index of object in list
    Student getStudentByID(int studentID);

    Staff getStaffByID(int staffID);

    Course getCourseByID(int courseID);

public:
    // Update data to the database's attributes
    void updateCourseList(Course course);

    void updateStudentList(Student student);

    void updateStaffList(Staff staff);

    void updateScoreboardList(Scoreboard scoreboard);

    void updateSemesterList(Semester semester);

    void updateAccountList(Account account);

    void updateClassList(Class classObj);

public:
    // Delete data from the database's attributes
    void deleteFromCourseList(Course course);

    void deleteFromStudentList(Student student);

    void deleteFromStaffList(Staff staff);

    void deleteFromScoreboardList(Scoreboard scoreboard);

    void deleteFromSemesterList(Semester semester);

    void deleteFromAccountList(Account account);

    void deleteFromClassList(Class classObj);

public:
    // Search functions - return all objects in list
    Set<Scoreboard> getScoreboardListByCourseID(int courseID);

};
#endif // DATABASE_H
