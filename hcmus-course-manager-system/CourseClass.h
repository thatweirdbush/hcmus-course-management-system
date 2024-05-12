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
	~Course();

public:
	int getCourseID();
	std::string getCourseName();
	std::string getClassName();
	std::string getTeacherName();
	int getNumOfCredits();
	int getMaxStudents();
	DayOfWeek getDayOfWeek();
	Session getSession();

	void setCourseID(int courseID);
	void setCourseName(std::string courseName);
	void setClassName(std::string className);
	void setTeacherName(std::string teacherName);
	void setNumOfCredits(int numOfCredits);
	void setMaxStudents(int maxStudents);
	void setDayOfWeek(DayOfWeek dayOfWeek);
	void setSession(Session session);

public:
	friend std::ostream& operator<<(std::ostream& os, Course& course);
	friend std::istream& operator>>(std::istream& is, Course& course);

public:
    bool operator==(const Course& course) {
        return this->courseID == course.courseID;
    }
};

/*****************************************
// Define Function: Course Reader
******************************************/
size_t readCoursesFromFile(QString filename, Vector<Course>& courses);

#endif // !_COURSE_CLASS_H_
