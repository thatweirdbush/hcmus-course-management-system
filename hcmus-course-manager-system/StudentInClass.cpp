#include "StudentInClass.h"

/*****************************************
// Implementation Class: StudentInClass
******************************************/
// Default Constructor
StudentInClass::StudentInClass() {
    this->className = "";
    this->studentID = -1;
}

// Constructor with parameters
StudentInClass::StudentInClass(std::string className, int studentID) {
    this->className = className;
    this->studentID = studentID;
}

// Input Operator Method
std::istream& operator>>(std::istream& is, StudentInClass& studentInClass) {
    std::string line;
    std::getline(is, line);

    if (line.empty()) return is;

    std::stringstream ss(line);
    std::string className, studentID;

    std::getline(ss, className, CSV_DELIMITER);
    std::getline(ss, studentID, CSV_DELIMITER);

    studentInClass.setClassName(className);
    studentInClass.setStudentID(std::stoi(studentID));

    return is;
}

// Output Operator Method
std::ostream& operator<<(std::ostream& os, StudentInClass& studentInClass) {
    os << studentInClass.getClassName() << CSV_DELIMITER
        << studentInClass.getStudentID() << std::endl;

    return os;
}
