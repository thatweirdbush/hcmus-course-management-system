#ifndef _STUDENT_CLASS_H_
#define _STUDENT_CLASS_H_

#include "DateClass.h"

class Student {
private:
	std::string classID;
	int no;
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string gender;
	Date dateOfBirth;
	std::string socialID;

public:
	// Constructor
	Student(std::string classID = "", int no = 0, std::string studentID = "",
		std::string firstName = "", std::string lastName = "", std::string gender = "",
		Date dateOfBirth = Date(), std::string socialID = "")

		: classID(classID), no(no), studentID(studentID),
		firstName(firstName), lastName(lastName), gender(gender),
		dateOfBirth(dateOfBirth), socialID(socialID) {}

	// Destructor, nothing from now on
	~Student() {}

	// Copy constructor
	Student(const Student& student) {
		classID = student.classID;
		no = student.no;
		studentID = student.studentID;
		firstName = student.firstName;
		lastName = student.lastName;
	}

	// Assignment operator
	Student& operator=(const Student& student) {
		classID = student.classID;
		no = student.no;
		studentID = student.studentID;
		firstName = student.firstName;
		lastName = student.lastName;
		return *this;
	}

public:
	// Setters
	void setClassID(std::string classID) { this->classID = classID; }
	void setNo(int no) { this->no = no; }
	void setStudentID(std::string studentID) { this->studentID = studentID; }
	void setFirstName(std::string firstName) { this->firstName = firstName; }
	void setLastName(std::string lastName) { this->lastName = lastName; }
	void setGender(std::string gender) { this->gender = gender; }
	void setDateOfBirth(Date dateOfBirth) { this->dateOfBirth = dateOfBirth; }
	void setSocialID(std::string socialID) { this->socialID = socialID; }

	// Getters
	std::string getClassID() { return classID; }
	int getNo() { return no; }
	std::string getStudentID() { return studentID; }
	std::string getFirstName() { return firstName; }
	std::string getLastName() { return lastName; }
	std::string getGender() { return gender; }
	Date getDateOfBirth() { return dateOfBirth; }
	std::string getSocialID() { return socialID; }

	// Input/Output Operator Methods
	friend std::istream& operator>>(std::istream& is, Student& student) {
		is >> student.classID >> student.no >> student.studentID
			>> student.firstName >> student.lastName >> student.gender
			>> student.dateOfBirth >> student.socialID;
	}

	friend std::ostream& operator<<(std::ostream& os, const Student& student) {
		os << student.classID << CSV_DELIMITER << student.no << CSV_DELIMITER << student.studentID
			<< CSV_DELIMITER << student.firstName << CSV_DELIMITER << student.lastName << CSV_DELIMITER
			<< student.gender << CSV_DELIMITER << student.dateOfBirth << CSV_DELIMITER << student.socialID << "\n";
	}
};
#endif // !_STUDENT_CLASS_H_
