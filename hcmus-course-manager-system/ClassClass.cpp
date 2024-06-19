#include "ClassClass.h"

/*****************************************
// Implementation Class: Class
******************************************/
// Default Constructor
Class::Class() {
    classID = 0;
    className = "";
    roomNo = "";
}

// Constructor
Class::Class(int classID, std::string className, std::string roomNo)
    : classID(classID), className(className), roomNo(roomNo) {}

// Copy constructor
Class::Class(const Class& classObj) {
    classID = classObj.classID;
    className = classObj.className;
    roomNo = classObj.roomNo;
}

// Assignment operator
Class& Class::operator=(const Class& classObj) {
    classID = classObj.classID;
    className = classObj.className;
    roomNo = classObj.roomNo;
    return *this;
}

// Input Operator Method
std::istream& operator>>(std::istream& is, Class& classObj) {
    std::string line;
    std::getline(is, line);

    if (line.empty()) return is;

    std::stringstream ss(line);
    std::string classID, className, roomNo;

    std::getline(ss, classID, CSV_DELIMITER);
    std::getline(ss, className, CSV_DELIMITER);
    std::getline(ss, roomNo, CSV_DELIMITER);

    classObj.setClassID(std::stoi(classID));
    classObj.setClassName(className);
    classObj.setRoomNo(roomNo);

    return is;
}

// Output Operator Method
std::ostream& operator<<(std::ostream& os, Class& classObj) {
    os << classObj.getClassID() << CSV_DELIMITER << classObj.getClassName() << CSV_DELIMITER << classObj.getRoomNo() << std::endl;
    return os;
}
