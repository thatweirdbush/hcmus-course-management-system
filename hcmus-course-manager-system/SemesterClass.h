#ifndef _SEMESTER_CLASS_H_
#define _SEMESTER_CLASS_H_

#include "DateClass.h"
#include "Vector.h"

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

};

/*****************************************
// Implementation Class: Semester
******************************************/
// Constructor
Semester::Semester() {
	no = 0;
	schoolYear = 0;
	startDate = Date();
	endDate = Date();
}

// Destructor
Semester::~Semester() {}

// Constructor with parameters
Semester::Semester(int no, int schoolYear, Date startDate, Date endDate) {
	this->no = no;
	this->schoolYear = schoolYear;
	this->startDate = startDate;
	this->endDate = endDate;
}

// Copy constructor
Semester::Semester(const Semester& semester) {
	this->no = semester.no;
	this->schoolYear = semester.schoolYear;
	this->startDate = semester.startDate;
	this->endDate = semester.endDate;
}

// Assignment operator
Semester& Semester::operator=(const Semester& semester) {
	this->no = semester.no;
	this->schoolYear = semester.schoolYear;
	this->startDate = semester.startDate;
	this->endDate = semester.endDate;
	return *this;
}

// Getters
int Semester::getNo() const {
	return no;
}

int Semester::getSchoolYear() const {
	return schoolYear;
}

Date Semester::getStartDate() const {
	return startDate;
}

Date Semester::getEndDate() const {
	return endDate;
}

// Setters
void Semester::setNo(int no) {
	this->no = no;
}

void Semester::setSchoolYear(int schoolYear) {
	this->schoolYear = schoolYear;
}

void Semester::setStartDate(Date startDate) {
	this->startDate = startDate;
}

void Semester::setEndDate(Date endDate) {
	this->endDate = endDate;
}

// Input/Output Operator Methods
std::ostream& operator<<(std::ostream& os, const Semester& semester) {
	os << semester.no << CSV_DELIMITER << semester.schoolYear << CSV_DELIMITER;
	os << semester.startDate << CSV_DELIMITER << semester.endDate << CSV_DELIMITER << "\n";
	return os;
}

std::istream& operator>>(std::istream& is, Semester& semester) {
	std::string line;
	std::getline(is, line);
	std::stringstream ss(line);

	std::string no, schoolYear, startDate, endDate;
	std::getline(ss, no, CSV_DELIMITER);
	std::getline(ss, schoolYear, CSV_DELIMITER);
	std::getline(ss, startDate, CSV_DELIMITER);
	std::getline(ss, endDate, CSV_DELIMITER);

	semester.no = std::stoi(no);
	semester.schoolYear = std::stoi(schoolYear);
	semester.startDate = Date(startDate);
	semester.endDate = Date(endDate);

	return is;
}

#endif _SEMESTER_CLASS_H_