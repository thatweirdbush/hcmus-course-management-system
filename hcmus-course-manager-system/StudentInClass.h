/**************************************************************
* Implement Class StudentInClass
* Define StudentInClass class - StudentInClass.h
***************************************************************/
#ifndef STUDENTINCLASS_H
#define STUDENTINCLASS_H

#include "StudentClass.h"
#include "ClassClass.h"

/*****************************************
// Define Class: StudentInClass
******************************************/
class StudentInClass
{
public:
    std::string className;
    int studentID;

public:
    StudentInClass();
    StudentInClass(std::string className, int studentID);
    ~StudentInClass() {}

public:
    // Getters
    std::string getClassName() { return className;}
    int getStudentID() { return studentID; }

    // Setters
    void setClassName(std::string className) { this->className = className; }
    void setStudentID(int studentID) { this->studentID = studentID; }

public:
    // Input/Output Operator Methods
    friend std::ostream& operator << (std::ostream& os, StudentInClass& studentInClass);
    friend std::istream& operator >> (std::istream& is, StudentInClass& studentInClass);

public:
    bool operator==(const StudentInClass& studentInClass) {
        return className == studentInClass.className && studentID == studentInClass.studentID;
    }
};

#endif // STUDENTINCLASS_H
