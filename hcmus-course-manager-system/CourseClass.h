#ifndef _COURSE_CLASS_H_
#define _COURSE_CLASS_H_

#include "DateClass.h"

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
std::string sessionToString(Session session) {
	switch (session) {
	case Session::S1: return "S1";
	case Session::S2: return "S2)";
	case Session::S3: return "S3";
	case Session::S4: return "S4";
	default: return "ERR";
	}
}

// Convert DayOfWeek to string
std::string dayOfWeekToString(DayOfWeek dayOfWeek) {
	switch (dayOfWeek) {
	case DayOfWeek::MON: return "MON";
	case DayOfWeek::TUE: return "TUE";
	case DayOfWeek::WED: return "WED";
	case DayOfWeek::THU: return "THU";
	case DayOfWeek::FRI: return "FRI";
	case DayOfWeek::SAT: return "SAT";
	default: return "ERR";
	}
}

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
};

/*****************************************
// Implementation Class: Course
******************************************/
// Default Constructor
Course::Course() {
	courseID = 0;
	courseName = "";
	className = "";
	teacherName = "";
	numOfCredits = 0;
	maxStudents = 0;
	dayOfWeek = DayOfWeek::MON;
	session = Session::S1;
}

// Constructor with parameters
Course::Course(int courseID, std::string courseName,std::string className,
	std::string teacherName, int numOfCredits, int maxStudents,
	DayOfWeek dayOfWeek, Session session) 
{
	this->courseID = courseID;
	this->courseName = courseName;
	this->className = className;
	this->teacherName = teacherName;
	this->numOfCredits = numOfCredits;
	this->maxStudents = maxStudents;
	this->dayOfWeek = dayOfWeek;
	this->session = session;
}

// Destructor
Course::~Course() {}

// Getter
int Course::getCourseID() {
	return courseID;
}

std::string Course::getCourseName() {
	return courseName;
}

std::string Course::getClassName() {
	return className;
}

std::string Course::getTeacherName() {
	return teacherName;
}

int Course::getNumOfCredits() {
	return numOfCredits;
}

int Course::getMaxStudents() {
	return maxStudents;
}

DayOfWeek Course::getDayOfWeek() {
	return dayOfWeek;
}

Session Course::getSession() {
	return session;
}

// Setter
void Course::setCourseID(int courseID) {
	this->courseID = courseID;
}

void Course::setCourseName(std::string courseName) {
	this->courseName = courseName;
}

void Course::setClassName(std::string className) {
	this->className = className;
}

void Course::setTeacherName(std::string teacherName) {
	this->teacherName = teacherName;
}

void Course::setNumOfCredits(int numOfCredits) {
	this->numOfCredits = numOfCredits;
}

void Course::setMaxStudents(int maxStudents) {
	this->maxStudents = maxStudents;
}

void Course::setDayOfWeek(DayOfWeek dayOfWeek) {
	this->dayOfWeek = dayOfWeek;
}

void Course::setSession(Session session) {
	this->session = session;
}

// Input/Output Operator Methods
std::ostream& operator<<(std::ostream& os, Course& course) {
	os << course.getCourseID() << CSV_DELIMITER << course.getCourseName() << CSV_DELIMITER
		<< course.getClassName() << CSV_DELIMITER << course.getTeacherName() << CSV_DELIMITER
		<< course.getNumOfCredits() << CSV_DELIMITER << course.getMaxStudents() << CSV_DELIMITER
		<< dayOfWeekToString(course.getDayOfWeek()) << CSV_DELIMITER 
		<< sessionToString(course.getSession()) << "\n";
	return os;
}

std::istream& operator>>(std::istream& is, Course& course) {
	std::string line;
	std::getline(is, line);
	std::stringstream ss(line);

	std::string courseID, courseName, className, teacherName, numOfCredits, maxStudents, dayOfWeekStr, sessionStr;
	DayOfWeek dayOfWeek;
	Session session;
	std::getline(ss, courseID, CSV_DELIMITER);
	std::getline(ss, courseName, CSV_DELIMITER);
	std::getline(ss, className, CSV_DELIMITER);
	std::getline(ss, teacherName, CSV_DELIMITER);
	std::getline(ss, numOfCredits, CSV_DELIMITER);
	std::getline(ss, maxStudents, CSV_DELIMITER);
	std::getline(ss, dayOfWeekStr, CSV_DELIMITER);
	std::getline(ss, sessionStr, CSV_DELIMITER);

	if (dayOfWeekStr == "MON") dayOfWeek = DayOfWeek::MON;
	else if (dayOfWeekStr == "TUE") dayOfWeek = DayOfWeek::TUE;
	else if (dayOfWeekStr == "WED") dayOfWeek = DayOfWeek::WED;
	else if (dayOfWeekStr == "THU") dayOfWeek = DayOfWeek::THU;
	else if (dayOfWeekStr == "FRI") dayOfWeek = DayOfWeek::FRI;
	else if (dayOfWeekStr == "SAT") dayOfWeek = DayOfWeek::SAT;

	if (sessionStr == "S1") session = Session::S1;
	else if (sessionStr == "S2") session = Session::S2;
	else if (sessionStr == "S3") session = Session::S3;
	else if (sessionStr == "S4") session = Session::S4;

	course.setCourseID(std::stoi(courseID));
	course.setCourseName(courseName);
	course.setClassName(className);
	course.setTeacherName(teacherName);
	course.setNumOfCredits(std::stoi(numOfCredits));
	course.setMaxStudents(std::stoi(maxStudents));
	course.setDayOfWeek(dayOfWeek);
	course.setSession(session);

	return is;
}
#endif // !_COURSE_CLASS_H_
