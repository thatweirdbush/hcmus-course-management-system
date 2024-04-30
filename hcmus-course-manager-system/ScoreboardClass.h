/**************************************************************
* Implement Scoreboard class
* Define Scoreboard class - ScoreboardClass.h
***************************************************************/
#ifndef _SCOREBOARD_CLASS_H_
#define _SCOREBOARD_CLASS_H_

#include "StudentClass.h"
#include "CourseClass.h"
#include "SemesterClass.h"

/*****************************************
// Define Class: Scoreboard
******************************************/
class Scoreboard {
private:
	// Raw data
	int courseID;
    std::string studentID;
    std::string fullName;
    float totalMark;
    float finalMark;
    float midtermMark;
    float otherMark;

private:
	// Convert to object
	Student student;
	Course course;
	Semester semester;

public:
    Scoreboard();
	Scoreboard(int courseID, std::string studentID, std::string fullName, float totalMark, float finalMark, float midtermMark, float otherMark);
	~Scoreboard();
	Scoreboard(const Scoreboard& scoreboard);
	Scoreboard& operator=(const Scoreboard& scoreboard);

public:
	// Setters
	void setCourseID(int courseID) { this->courseID = courseID; }
	void setStudentID(std::string studentID) { this->studentID = studentID; }
	void setFullName(std::string fullName) { this->fullName = fullName; }
	void setTotalMark(float totalMark) { this->totalMark = totalMark; }
	void setFinalMark(float finalMark) { this->finalMark = finalMark; }
	void setMidtermMark(float midtermMark) { this->midtermMark = midtermMark; }
	void setOtherMark(float otherMark) { this->otherMark = otherMark; }

	// Getters
	int getCourseID() { return courseID; }
	std::string getStudentID() { return studentID; }
	std::string getFullName() { return fullName; }
	float getTotalMark() { return totalMark; }
	float getFinalMark() { return finalMark; }
	float getMidtermMark() { return midtermMark; }
	float getOtherMark() { return otherMark; }

	// Input/Output Operator
	friend std::istream& operator>>(std::istream& is, Scoreboard& scoreboard);
	friend std::ostream& operator<<(std::ostream& os, Scoreboard& scoreboard);
};

/*****************************************
// Implementation Class: Scoreboard
******************************************/
// Default Constructor
Scoreboard::Scoreboard() {
	courseID = 0;
	studentID = "";
	fullName = "";
	totalMark = 0;
	finalMark = 0;
	midtermMark = 0;
	otherMark = 0;
}

// Constructor with arguments
Scoreboard::Scoreboard(int courseID, std::string studentID,
	std::string fullName, float totalMark, float finalMark,
	float midtermMark, float otherMark) 
{
	this->courseID = courseID;
	this->studentID = studentID;
	this->fullName = fullName;
	this->totalMark = totalMark;
	this->finalMark = finalMark;
	this->midtermMark = midtermMark;
	this->otherMark = otherMark;
}

// Destructor
Scoreboard::~Scoreboard() {}

// Copy constructor
Scoreboard::Scoreboard(const Scoreboard& scoreboard) {
	courseID = scoreboard.courseID;
	studentID = scoreboard.studentID;
	fullName = scoreboard.fullName;
	totalMark = scoreboard.totalMark;
	finalMark = scoreboard.finalMark;
	midtermMark = scoreboard.midtermMark;
	otherMark = scoreboard.otherMark;
}

// Assignment operator
Scoreboard& Scoreboard::operator=(const Scoreboard& scoreboard) {
	courseID = scoreboard.courseID;
	studentID = scoreboard.studentID;
	fullName = scoreboard.fullName;
	totalMark = scoreboard.totalMark;
	finalMark = scoreboard.finalMark;
	midtermMark = scoreboard.midtermMark;
	otherMark = scoreboard.otherMark;
	return *this;
}

// Input operator
std::istream& operator>>(std::istream& is, Scoreboard& scoreboard) {
	std::string line;
	std::getline(is, line);
	std::stringstream ss(line);

	std::string courseID, studentID, fullName, totalMark, finalMark, midtermMark, otherMark;
	std::getline(ss, courseID, CSV_DELIMITER);
	std::getline(ss, studentID, CSV_DELIMITER);
	std::getline(ss, fullName, CSV_DELIMITER);
	std::getline(ss, totalMark, CSV_DELIMITER);
	std::getline(ss, finalMark, CSV_DELIMITER);
	std::getline(ss, midtermMark, CSV_DELIMITER);
	std::getline(ss, otherMark, CSV_DELIMITER);

	scoreboard.courseID = std::stoi(courseID);
	scoreboard.studentID = studentID;
	scoreboard.fullName = fullName;
	scoreboard.totalMark = std::stof(totalMark);
	scoreboard.finalMark = std::stof(finalMark);
	scoreboard.midtermMark = std::stof(midtermMark);
	scoreboard.otherMark = std::stof(otherMark);

	return is;
}

// Output operator
std::ostream& operator<<(std::ostream& os, Scoreboard& scoreboard) {
	os << scoreboard.courseID << CSV_DELIMITER << scoreboard.studentID << CSV_DELIMITER
		<< scoreboard.fullName << CSV_DELIMITER << scoreboard.totalMark << CSV_DELIMITER
		<< scoreboard.finalMark << CSV_DELIMITER << scoreboard.midtermMark << CSV_DELIMITER
		<< scoreboard.otherMark << "\n";
	return os;
}

#endif // !_SCOREBOARD_CLASS_H_
