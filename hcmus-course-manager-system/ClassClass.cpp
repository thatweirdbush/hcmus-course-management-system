#include "ClassClass.h"

/*****************************************
// Implementation Class: Class
******************************************/
// Default Constructor
Class::Class() {
    classID = -1;
    className = "";
    startedYear = -1;
}

// Constructor
Class::Class(int classID, std::string className, int startedYear)
    : classID(classID), className(className), startedYear(startedYear) {}

// Copy constructor
Class::Class(const Class& classObj) {
    classID = classObj.classID;
    className = classObj.className;
    startedYear = classObj.startedYear;
}

// Assignment operator
Class& Class::operator=(const Class& classObj) {
    classID = classObj.classID;
    className = classObj.className;
    startedYear = classObj.startedYear;
    return *this;
}

// Input Operator Method
std::istream& operator>>(std::istream& is, Class& classObj) {
    std::string line;
    std::getline(is, line);

    if (line.empty()) return is;

    std::stringstream ss(line);
    std::string classID, className, startedYear;

    std::getline(ss, classID, CSV_DELIMITER);
    std::getline(ss, className, CSV_DELIMITER);
    std::getline(ss, startedYear, CSV_DELIMITER);

    classObj.setClassID(std::stoi(classID));
    classObj.setClassName(className);
    classObj.setStartedYear(std::stoi(startedYear));

    return is;
}

// Output Operator Method
std::ostream& operator<<(std::ostream& os, Class& classObj) {
    os << classObj.getClassID() << CSV_DELIMITER << classObj.getClassName() << CSV_DELIMITER << classObj.getStartedYear() << std::endl;
    return os;
}
