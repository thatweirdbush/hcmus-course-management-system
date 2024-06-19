/**************************************************************
* Implement Course class
* Define Course class - CourseClass.h
***************************************************************/
#ifndef _COURSE_CLASS_H_
#define _COURSE_CLASS_H_

#include "Vector.h"
#include "DateClass.h"
#include <iostream>
#include <QFile>

/*****************************************
// Define Enum Class: Session - DayOfWeek
******************************************/
// Represent sessions in a day
enum class Session {
	S1, // 7:30
	S2, // 9:30
	S3, // 13:30
	S4  // 15:30
};

// Represent days in a week
enum class DayOfWeek {
    MON,
    TUE,
    WED,
    THU,
    FRI,
    SAT
};

// Convert Session to string
std::string sessionToString(Session session);

// Convert DayOfWeek to string
std::string dayOfWeekToString(DayOfWeek dayOfWeek);

/*****************************************
// Define Class: Course
******************************************/
class Course {
private:
    int courseID;
    std::string courseName;
    std::string className;
    std::string teacherName;
    int numOfCredits;
    int maxStudents;
    DayOfWeek dayOfWeek;
    Session session;

public:
	Course();
	Course(int courseID, std::string courseName, std::string className,
		std::string teacherName, int numOfCredits, int maxStudents,
		DayOfWeek dayOfWeek, Session session);
    ~Course() {}

public:
    // Getters
    int getCourseID() { return courseID; }
    std::string getCourseName() { return courseName; }
    std::string getClassName() { return className; }
    std::string getTeacherName() { return teacherName; }
    int getNumOfCredits() { return numOfCredits; }
    int getMaxStudents() { return maxStudents; }
    DayOfWeek getDayOfWeek() { return dayOfWeek; }
    Session getSession() { return session; }

    // Setters
    void setCourseID(int courseID) { this->courseID = courseID; }
    void setCourseName(std::string courseName) { this->courseName = courseName; }
    void setClassName(std::string className) { this->className = className; }
    void setTeacherName(std::string teacherName) { this->teacherName = teacherName; }
    void setNumOfCredits(int numOfCredits) { this->numOfCredits = numOfCredits; }
    void setMaxStudents(int maxStudents) { this->maxStudents = maxStudents; }
    void setDayOfWeek(DayOfWeek dayOfWeek) { this->dayOfWeek = dayOfWeek; }
    void setSession(Session session) { this->session = session; }

public:
    // Input/Output Operator
    friend std::ostream& operator<<(std::ostream& os, Course& course);
	friend std::istream& operator>>(std::istream& is, Course& course);

public:
    bool operator==(const Course& course) {
        return this->courseID == course.courseID;
    }
};
#endif // !_COURSE_CLASS_H_
