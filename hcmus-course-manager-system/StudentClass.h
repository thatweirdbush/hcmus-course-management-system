/**************************************************************
* Implement Student class
* Define Student class - StudentClass.h
***************************************************************/
#ifndef _STUDENT_CLASS_H_
#define _STUDENT_CLASS_H_

#include "DateClass.h"

class Student {
private:
    int classID;
    int studentID;
	std::string firstName;
	std::string lastName;
	std::string gender;
	Date dateOfBirth;
	std::string socialID;

public:
	// Constructor
    Student(int classID = 0, int studentID = 0,
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
        gender = student.gender;
        dateOfBirth = student.dateOfBirth;
        socialID = student.socialID;
	}

	// Assignment operator
	Student& operator=(const Student& student) {
		classID = student.classID;
		studentID = student.studentID;
		firstName = student.firstName;
		lastName = student.lastName;
        gender = student.gender;
        dateOfBirth = student.dateOfBirth;
        socialID = student.socialID;
		return *this;
	}

public:
	// Setters
    void setClassID(int classID) { this->classID = classID; }
    void setStudentID(int studentID) { this->studentID = studentID; }
	void setFirstName(std::string firstName) { this->firstName = firstName; }
	void setLastName(std::string lastName) { this->lastName = lastName; }
	void setGender(std::string gender) { this->gender = gender; }
	void setDateOfBirth(Date dateOfBirth) { this->dateOfBirth = dateOfBirth; }
	void setSocialID(std::string socialID) { this->socialID = socialID; }

	// Getters
    int getClassID() { return classID; }
    int getStudentID() { return studentID; }
	std::string getFirstName() { return firstName; }
	std::string getLastName() { return lastName; }
	std::string getGender() { return gender; }
	Date getDateOfBirth() { return dateOfBirth; }
	std::string getSocialID() { return socialID; }
	std::string getFullname() { return firstName + " " + lastName; }

	// Input/Output Operator Methods
    friend std::istream& operator>>(std::istream& is, Student& student) {
        std::string line;
        std::getline(is, line);

        if (line.empty()) return is;

        std::stringstream ss(line);
        std::string classID, studentID, firstName, lastName, gender, dateOfBirth, socialID;

        std::getline(ss, classID, CSV_DELIMITER);
        std::getline(ss, studentID, CSV_DELIMITER);
        std::getline(ss, firstName, CSV_DELIMITER);
        std::getline(ss, lastName, CSV_DELIMITER);
        std::getline(ss, gender, CSV_DELIMITER);
        std::getline(ss, dateOfBirth, CSV_DELIMITER);
        std::getline(ss, socialID, CSV_DELIMITER);

        student.setClassID(std::stoi(classID));
        student.setStudentID(std::stoi(studentID));
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
        return os;
    }

public:
    bool operator==(const Student& student) {
        return this->studentID == student.studentID;
    }
};
#endif // !_STUDENT_CLASS_H_
