/**************************************************************
* Implement Student class
* Define Student class - StudentClass.h
***************************************************************/
#ifndef _STUDENT_CLASS_H_
#define _STUDENT_CLASS_H_

#include "DateClass.h"

class Student {
private:
    int studentID;
	std::string firstName;
	std::string lastName;
	std::string gender;
	Date dateOfBirth;
	std::string socialID;

public:
    // Default Constructor
    Student();

	// Constructor
    Student(int studentID, std::string firstName, std::string lastName,
            std::string gender, Date dateOfBirth, std::string socialID);

	// Destructor, nothing from now on
	~Student() {}

	// Copy constructor
    Student(const Student& student);

	// Assignment operator
    Student& operator=(const Student& student);

public:
	// Setters
    void setStudentID(int studentID) { this->studentID = studentID; }
	void setFirstName(std::string firstName) { this->firstName = firstName; }
	void setLastName(std::string lastName) { this->lastName = lastName; }
	void setGender(std::string gender) { this->gender = gender; }
	void setDateOfBirth(Date dateOfBirth) { this->dateOfBirth = dateOfBirth; }
	void setSocialID(std::string socialID) { this->socialID = socialID; }

	// Getters
    int getStudentID() { return studentID; }
	std::string getFirstName() { return firstName; }
	std::string getLastName() { return lastName; }
	std::string getGender() { return gender; }
	Date getDateOfBirth() { return dateOfBirth; }
	std::string getSocialID() { return socialID; }
    std::string getFullname() { return lastName + " " + firstName; }

	// Input/Output Operator Methods
    friend std::istream &operator>>(std::istream &is, Student &student);
    friend std::ostream &operator<<(std::ostream &os, const Student &student);

public:
    bool operator==(const Student& student) {
        return this->studentID == student.studentID;
    }
};
#endif // !_STUDENT_CLASS_H_
