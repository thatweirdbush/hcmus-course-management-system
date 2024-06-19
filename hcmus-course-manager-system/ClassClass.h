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
    std::string roomNo;

public:
    Class();
    Class(int classID, std::string className, std::string roomNo);
    ~Class() {}
    Class(const Class& other);
    Class& operator=(const Class& other);

public:
    // Setters
    void setClassID(int classID) { this->classID = classID; }
    void setClassName(std::string className) { this->className = className; }
    void setRoomNo(std::string roomNo) { this->roomNo = roomNo; }

    // Getters
    int getClassID() { return classID; }
    std::string getClassName() { return className; }
    std::string getRoomNo() { return roomNo; }

public:
    // Input/Output Operator Methods
    friend std::istream& operator>>(std::istream& is, Class& classObj);
    friend std::ostream& operator<<(std::ostream& os, Class& classObj);

public:
    bool operator==(const Class& classObj) {
        return this->classID == classObj.classID;
    }
};
#endif // _CLASS_CLASS_H_
