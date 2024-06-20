/**************************************************************
* Implement StudentInCourse class
* Define StudentInCourse class - StudentInCourse.h
***************************************************************/
#ifndef STUDENTINCOURSE_H
#define STUDENTINCOURSE_H

#include "DateClass.h"

/*****************************************
// Define Class: StudentInCourse
******************************************/
class StudentInCourse
{
private:
    int semesterID;
    int courseID;
    int studentID;

public:
    StudentInCourse();
    StudentInCourse(int semesterID, int courseID, int studentID);
    ~StudentInCourse() {}

public:
    // Setters
    void setSemesterID(int semesterID) { this->semesterID = semesterID; }
    void setCourseID(int courseID) { this->courseID = courseID; }
    void setStudentID(int studentID) { this->studentID = studentID; }

    // Getters
    int getSemesterID() { return semesterID; }
    int getCourseID() { return courseID; }
    int getStudentID() { return studentID; }

public:
    // Input/Output Operator Methods
    friend std::istream &operator>>(std::istream &is, StudentInCourse &studentInCourse);
    friend std::ostream &operator<<(std::ostream &os, const StudentInCourse &studentInCourse);

public:
    bool operator==(const StudentInCourse& studentInCourse);
};

#endif // STUDENTINCOURSE_H
