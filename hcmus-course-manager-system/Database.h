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
    Set<Scoreboard> scoreboardList;

public:
    // Constructors
    Database();

    // Destructor
    ~Database();

public:
    void registerAccount();
    int login(QString username, QString password);

    void importAccountList(QString filename);

    void importCourseList(QString filename);

    void importSemesterList(QString filename);

    void importStudentList(QString filename);

    void importScoreboardList(QString filename);

public:
    Student getStudentByID(int studentID);

};
#endif // DATABASE_H
