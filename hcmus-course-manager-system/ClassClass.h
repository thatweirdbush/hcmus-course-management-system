/**************************************************************
* Implement Class class
* Define Class class - ClassClass.h
***************************************************************/
#ifndef _CLASS_CLASS_H_
#define _CLASS_CLASS_H_

#include "DateClass.h"

/*****************************************
// Define Class: Class
******************************************/
class Class
{
private:
    int classID;
    std::string className;
    int startedYear;

public:
    Class();
    Class(int classID, std::string className, int startedYear);
    ~Class() {}
    Class(const Class& other);
    Class& operator=(const Class& other);

public:
    // Setters
    void setClassID(int classID) { this->classID = classID; }
    void setClassName(std::string className) { this->className = className; }
    void setStartedYear(int startedYear) { this->startedYear = startedYear; }

    // Getters
    int getClassID() { return classID; }
    std::string getClassName() { return className; }
    int getStartedYear() { return startedYear; }

public:
    // Input/Output Operator Methods
    friend std::istream& operator>>(std::istream& is, Class& classObj);
    friend std::ostream& operator<<(std::ostream& os, Class& classObj);

public:
    bool operator==(const Class& classObj) {
        // Not using classID here because this fails when adding new classes.
        return this->className == classObj.className && this->startedYear == classObj.startedYear;
    }
};
#endif // _CLASS_CLASS_H_
