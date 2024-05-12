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
    int no;
    int schoolYear;
    Date startDate;
    Date endDate;

public:
	Semester();
	~Semester();
	Semester(int no, int schoolYear, Date startDate, Date endDate);
	Semester(const Semester& semester);
	Semester& operator=(const Semester& semester);

public:
	int getNo() const;
	int getSchoolYear() const;
	Date getStartDate() const;
	Date getEndDate() const;

	void setNo(int no);
	void setSchoolYear(int schoolYear);
	void setStartDate(Date startDate);
	void setEndDate(Date endDate);

public:
	friend std::ostream& operator<<(std::ostream& os, const Semester& semester);
	friend std::istream& operator>>(std::istream& is, Semester& semester);

public:
    bool operator==(const Semester& semester) {
        return this->no == semester.no;
    }
};
#endif // !_SEMESTER_CLASS_H_
