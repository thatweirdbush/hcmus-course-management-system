#include "StudentInCourse.h"

/*****************************************
// Implementation Class: StudentInCourse
******************************************/
// Default Constructor
StudentInCourse::StudentInCourse() {
    this->semesterID = -1;
    this->courseID = -1;
    this->studentID = -1;
}

// Constructor
StudentInCourse::StudentInCourse(int semesterID, int courseID, int studentID) {
    this->semesterID = semesterID;
    this->courseID = courseID;
    this->studentID = studentID;
}

// Input Operator Method
std::istream &operator>>(std::istream &is, StudentInCourse &studentInCourse) {
    std::string line;
    std::getline(is, line);

    if (line.empty()) return is;

    std::stringstream ss(line);
    std::string semesterID, courseID, studentID;

    std::getline(ss, semesterID, CSV_DELIMITER);
    std::getline(ss, courseID, CSV_DELIMITER);
    std::getline(ss, studentID, CSV_DELIMITER);

    studentInCourse.setSemesterID(std::stoi(semesterID));
    studentInCourse.setCourseID(std::stoi(courseID));
    studentInCourse.setStudentID(std::stoi(studentID));

    return is;
}

// Output Operator Method
std::ostream &operator<<(std::ostream &os, const StudentInCourse &studentInCourse) {
    os << studentInCourse.semesterID << CSV_DELIMITER << studentInCourse.courseID << CSV_DELIMITER << studentInCourse.studentID << std::endl;
    return os;
}

// Overload operator ==
bool StudentInCourse::operator==(const StudentInCourse& studentInCourse) {
    return this->semesterID == studentInCourse.semesterID &&
           this->courseID == studentInCourse.courseID &&
           this->studentID == studentInCourse.studentID;
}

