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
    int studentID;
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
    Scoreboard(int courseID, int studentID, std::string fullName, float totalMark, float finalMark, float midtermMark, float otherMark);
	~Scoreboard();
	Scoreboard(const Scoreboard& scoreboard);
	Scoreboard& operator=(const Scoreboard& scoreboard);

public:
	// Setters
	void setCourseID(int courseID) { this->courseID = courseID; }
    void setStudentID(int studentID) { this->studentID = studentID; }
	void setFullName(std::string fullName) { this->fullName = fullName; }
	void setTotalMark(float totalMark) { this->totalMark = totalMark; }
	void setFinalMark(float finalMark) { this->finalMark = finalMark; }
	void setMidtermMark(float midtermMark) { this->midtermMark = midtermMark; }
	void setOtherMark(float otherMark) { this->otherMark = otherMark; }

	// Getters
	int getCourseID() { return courseID; }
    int getStudentID() { return studentID; }
	std::string getFullName() { return fullName; }
	float getTotalMark() { return totalMark; }
	float getFinalMark() { return finalMark; }
	float getMidtermMark() { return midtermMark; }
	float getOtherMark() { return otherMark; }

public:
	// Input/Output Operator
	friend std::istream& operator>>(std::istream& is, Scoreboard& scoreboard);
	friend std::ostream& operator<<(std::ostream& os, Scoreboard& scoreboard);    

public:
    bool operator==(const Scoreboard& scoreboard) {
        return this->courseID == scoreboard.courseID && this->studentID == scoreboard.studentID;
    }
};
#endif // !_SCOREBOARD_CLASS_H_
