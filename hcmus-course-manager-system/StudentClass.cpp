#include "StudentClass.h"

/*****************************************
// Implementation Class: Student
******************************************/
// Default Constructor
Student::Student() {
    studentID = 0;
    firstName = "";
    lastName = "";
    gender = "";
    dateOfBirth = Date();
    socialID = "";
}

// Constructor
Student::Student(int studentID, std::string firstName, std::string lastName,
                 std::string gender, Date dateOfBirth, std::string socialID)

    : studentID(studentID),
    firstName(firstName), lastName(lastName), gender(gender),
    dateOfBirth(dateOfBirth), socialID(socialID) {}

// Copy constructor
Student::Student(const Student& student) {
    studentID = student.studentID;
    firstName = student.firstName;
    lastName = student.lastName;
    gender = student.gender;
    dateOfBirth = student.dateOfBirth;
    socialID = student.socialID;
}

// Assignment operator
Student& Student::operator=(const Student& student) {
    studentID = student.studentID;
    firstName = student.firstName;
    lastName = student.lastName;
    gender = student.gender;
    dateOfBirth = student.dateOfBirth;
    socialID = student.socialID;
}

// Input operator
std::istream& operator>>(std::istream& is, Student& student) {
    std::string line;
    std::getline(is, line);

    if (line.empty()) return is;

    std::stringstream ss(line);
    std::string studentID, firstName, lastName, gender, dateOfBirth, socialID;

    std::getline(ss, studentID, CSV_DELIMITER);
    std::getline(ss, firstName, CSV_DELIMITER);
    std::getline(ss, lastName, CSV_DELIMITER);
    std::getline(ss, gender, CSV_DELIMITER);
    std::getline(ss, dateOfBirth, CSV_DELIMITER);
    std::getline(ss, socialID, CSV_DELIMITER);

    student.setStudentID(std::stoi(studentID));
    student.setFirstName(firstName);
    student.setLastName(lastName);
    student.setGender(gender);
    student.setDateOfBirth(Date(dateOfBirth));
    student.setSocialID(socialID);

    return is;
}

// Output operator
std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << student.studentID << CSV_DELIMITER << student.firstName << CSV_DELIMITER << student.lastName << CSV_DELIMITER
       << student.gender << CSV_DELIMITER << student.dateOfBirth << CSV_DELIMITER << student.socialID << "\n";
    return os;
}




