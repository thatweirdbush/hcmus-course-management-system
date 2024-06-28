/**************************************************************
* Implement Semester class
* Define Semester class - SemesterClass.h
***************************************************************/
#ifndef _SEMESTER_CLASS_H_
#define _SEMESTER_CLASS_H_

#include "DateClass.h"

/*****************************************
// Define Class: Semester
******************************************/
class Semester {
private:
    int semesterID;
    int no;
    int schoolYear;
    Date startDate;
    Date endDate;

public:
	Semester();
	~Semester();
    Semester(int semesterID, int no, int schoolYear, Date startDate, Date endDate);
	Semester(const Semester& semester);
	Semester& operator=(const Semester& semester);

public:
    // Getters
    int getSemesterID() const { return semesterID; }
    int getNo() const { return no;}
    int getSchoolYear() const { return schoolYear; }
    Date getStartDate() const { return startDate; }
    Date getEndDate() const { return endDate; }

    // Setters
    void setSemesterID(int semesterID) { this->semesterID = semesterID; }
    void setNo(int no) { this->no = no; }
    void setSchoolYear(int schoolYear) { this->schoolYear = schoolYear; }
    void setStartDate(Date startDate) { this->startDate = startDate; }
    void setEndDate(Date endDate) { this->endDate = endDate; }

public:
    // Input/Output Operator Methods
	friend std::ostream& operator<<(std::ostream& os, const Semester& semester);
	friend std::istream& operator>>(std::istream& is, Semester& semester);

public:
    bool operator==(const Semester& semester) {
        return this->semesterID == semester.semesterID;
    }
};
#endif // !_SEMESTER_CLASS_H_
