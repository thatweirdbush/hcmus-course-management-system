#include "SemesterClass.h"

/*****************************************
// Implementation Class: Semester
******************************************/
// Constructor
Semester::Semester() {
    semesterID = -1;
    no = -1;
    schoolYear = -1;
    startDate = Date();
    endDate = Date();
}

// Destructor
Semester::~Semester() {}

// Constructor with parameters
Semester::Semester(int semesterID, int no, int schoolYear, Date startDate, Date endDate) {
    this->semesterID = semesterID;
    this->no = no;
    this->schoolYear = schoolYear;
    this->startDate = startDate;
    this->endDate = endDate;
}

// Copy constructor
Semester::Semester(const Semester& semester) {
    this->semesterID = semester.semesterID;
    this->no = semester.no;
    this->schoolYear = semester.schoolYear;
    this->startDate = semester.startDate;
    this->endDate = semester.endDate;
}

// Assignment operator
Semester& Semester::operator=(const Semester& semester) {
    this->semesterID = semester.semesterID;
    this->no = semester.no;
    this->schoolYear = semester.schoolYear;
    this->startDate = semester.startDate;
    this->endDate = semester.endDate;
    return *this;
}

// Input Operator Methods
std::ostream& operator<<(std::ostream& os, const Semester& semester) {
    os << semester.semesterID << CSV_DELIMITER << semester.no << CSV_DELIMITER << semester.schoolYear << CSV_DELIMITER;
    os << semester.startDate << CSV_DELIMITER << semester.endDate << "\n";
    return os;
}

// Output Operator Methods
std::istream& operator>>(std::istream& is, Semester& semester) {
    std::string line;
    std::getline(is, line);

    if (line.empty()) return is;

    std::stringstream ss(line);
    std::string id, no, schoolYear, startDate, endDate;

    std::getline(ss, id, CSV_DELIMITER);
    std::getline(ss, no, CSV_DELIMITER);
    std::getline(ss, schoolYear, CSV_DELIMITER);
    std::getline(ss, startDate, CSV_DELIMITER);
    std::getline(ss, endDate, CSV_DELIMITER);

    semester.setSemesterID(std::stoi(id));
    semester.setNo(std::stoi(no));
    semester.setSchoolYear(std::stoi(schoolYear));
    semester.setStartDate(Date(startDate));
    semester.setEndDate(Date(endDate));

    return is;
}
