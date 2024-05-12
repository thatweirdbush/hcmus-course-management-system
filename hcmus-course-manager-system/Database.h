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
#include "Set.h"


// Define const file path
const QString COURSE_FILE_PATH = "course.csv";
const QString STUDENT_FILE_PATH = "student.csv";
const QString SCOREBOARD_FILE_PATH = "scoreboard.csv";
const QString SEMESTER_FILE_PATH = "semester.csv";
const QString STAFF_FILE_PATH = "staff.csv";
const QString ACCOUNT_FILE_PATH = "account.csv";


class Database {
public:
    Set<Account> accountList;
    Set<Course> courseList;
    Set<Semester> semesterList;
    Set<Student> studentList;
    Set<Staff> staffList;
    Set<Scoreboard> scoreboardList;

public:
    // Constructors
    Database();

    // Destructor
    ~Database();

public:
    void registerAccount();
    int login(QString username, QString password);

public:
    // Import data from file
    void importAccountList(QString filename);

    void importCourseList(QString filename);

    void importSemesterList(QString filename);

    void importStudentList(QString filename);

    void importStaffList(QString filename);

    void importScoreboardList(QString filename);

public:
    // Search functions
    Student getStudentByID(int studentID);

    Staff getStaffByID(int staffID);

    Course getCourseByID(int courseID);

    Set<Scoreboard> getScoreboardListByCourseID(int courseID);

public:


};
#endif // DATABASE_H
