/**************************************************************
* Implement Student class
* Define Student class - StudentClass.h
***************************************************************/
#ifndef _STUDENT_CLASS_H_
#define _STUDENT_CLASS_H_

#include "DateClass.h"

class Student {
private:
	std::string classID;
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string gender;
	Date dateOfBirth;
	std::string socialID;

public:
	// Constructor
	Student(std::string classID = "", std::string studentID = "",
		std::string firstName = "", std::string lastName = "", std::string gender = "",
		Date dateOfBirth = Date(), std::string socialID = "")

		: classID(classID), studentID(studentID),
		firstName(firstName), lastName(lastName), gender(gender),
		dateOfBirth(dateOfBirth), socialID(socialID) {}

	// Destructor, nothing from now on
	~Student() {}

	// Copy constructor
	Student(const Student& student) {
		classID = student.classID;
		studentID = student.studentID;
		firstName = student.firstName;
		lastName = student.lastName;
	}

	// Assignment operator
	Student& operator=(const Student& student) {
		classID = student.classID;
		studentID = student.studentID;
		firstName = student.firstName;
		lastName = student.lastName;
		return *this;
	}

public:
	// Setters
	void setClassID(std::string classID) { this->classID = classID; }
	void setStudentID(std::string studentID) { this->studentID = studentID; }
	void setFirstName(std::string firstName) { this->firstName = firstName; }
	void setLastName(std::string lastName) { this->lastName = lastName; }
	void setGender(std::string gender) { this->gender = gender; }
	void setDateOfBirth(Date dateOfBirth) { this->dateOfBirth = dateOfBirth; }
	void setSocialID(std::string socialID) { this->socialID = socialID; }

	// Getters
	std::string getClassID() { return classID; }
	std::string getStudentID() { return studentID; }
	std::string getFirstName() { return firstName; }
	std::string getLastName() { return lastName; }
	std::string getGender() { return gender; }
	Date getDateOfBirth() { return dateOfBirth; }
	std::string getSocialID() { return socialID; }

	// Input/Output Operator Methods
	friend std::istream& operator>>(std::istream& is, Student& student) {
		std::string line;
		std::getline(is, line);
		std::stringstream ss(line);

		std::string classID, studentID, firstName, lastName, gender, dateOfBirth, socialID;

		std::getline(ss, classID, CSV_DELIMITER);
		std::getline(ss, studentID, CSV_DELIMITER);
		std::getline(ss, firstName, CSV_DELIMITER);
		std::getline(ss, lastName, CSV_DELIMITER);
		std::getline(ss, gender, CSV_DELIMITER);
		std::getline(ss, dateOfBirth, CSV_DELIMITER);
		std::getline(ss, socialID, CSV_DELIMITER);

		student.setClassID(classID);
		student.setStudentID(studentID);
		student.setFirstName(firstName);
		student.setLastName(lastName);
		student.setGender(gender);
		student.setDateOfBirth(Date(dateOfBirth));
		student.setSocialID(socialID);

		return is;
	}

	friend std::ostream& operator<<(std::ostream& os, const Student& student) {
		os << student.classID << CSV_DELIMITER << student.studentID
			<< CSV_DELIMITER << student.firstName << CSV_DELIMITER << student.lastName << CSV_DELIMITER
			<< student.gender << CSV_DELIMITER << student.dateOfBirth << CSV_DELIMITER << student.socialID << "\n";
	}
};
#endif // !_STUDENT_CLASS_H_
