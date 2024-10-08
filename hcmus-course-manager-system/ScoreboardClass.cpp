#include "ScoreboardClass.h"

/*****************************************
// Implementation Class: Scoreboard
******************************************/
// Default Constructor
Scoreboard::Scoreboard() {
    courseID = -1;
    className = "";
    studentID = -1;
    fullName = "";
    totalMark = -1;
    finalMark = -1;
    midtermMark = -1;
    otherMark = -1;
}

// Constructor with arguments
Scoreboard::Scoreboard(int courseID, std::string className, int studentID,
                       std::string fullName, float totalMark, float finalMark,
                       float midtermMark, float otherMark)
{
    this->courseID = courseID;
    this->className = className;
    this->studentID = studentID;
    this->fullName = fullName;
    this->totalMark = totalMark;
    this->finalMark = finalMark;
    this->midtermMark = midtermMark;
    this->otherMark = otherMark;
}

// Destructor
Scoreboard::~Scoreboard() {}

// Copy constructor
Scoreboard::Scoreboard(const Scoreboard& scoreboard) {
    courseID = scoreboard.courseID;
    className = scoreboard.className;
    studentID = scoreboard.studentID;
    fullName = scoreboard.fullName;
    totalMark = scoreboard.totalMark;
    finalMark = scoreboard.finalMark;
    midtermMark = scoreboard.midtermMark;
    otherMark = scoreboard.otherMark;
}

// Assignment operator
Scoreboard& Scoreboard::operator=(const Scoreboard& scoreboard) {
    courseID = scoreboard.courseID;
    className = scoreboard.className;
    studentID = scoreboard.studentID;
    fullName = scoreboard.fullName;
    totalMark = scoreboard.totalMark;
    finalMark = scoreboard.finalMark;
    midtermMark = scoreboard.midtermMark;
    otherMark = scoreboard.otherMark;
    return *this;
}

// Input operator
std::istream& operator>>(std::istream& is, Scoreboard& scoreboard) {
    std::string line;
    std::getline(is, line);

    if (line.empty()) return is;

    std::stringstream ss(line);
    std::string courseID, className, studentID, fullName, totalMark, finalMark, midtermMark, otherMark;

    std::getline(ss, courseID, CSV_DELIMITER);
    std::getline(ss, className, CSV_DELIMITER);
    std::getline(ss, studentID, CSV_DELIMITER);
    std::getline(ss, fullName, CSV_DELIMITER);
    std::getline(ss, totalMark, CSV_DELIMITER);
    std::getline(ss, finalMark, CSV_DELIMITER);
    std::getline(ss, midtermMark, CSV_DELIMITER);
    std::getline(ss, otherMark, CSV_DELIMITER);

    scoreboard.courseID = std::stoi(courseID);
    scoreboard.className = className;
    scoreboard.studentID = std::stoi(studentID);
    scoreboard.fullName = fullName;
    scoreboard.totalMark = std::stof(totalMark);
    scoreboard.finalMark = std::stof(finalMark);
    scoreboard.midtermMark = std::stof(midtermMark);
    scoreboard.otherMark = std::stof(otherMark);
    return is;
}

// Output operator
std::ostream& operator<<(std::ostream& os, Scoreboard& scoreboard) {
    os << scoreboard.courseID << CSV_DELIMITER << scoreboard.className << CSV_DELIMITER
       << scoreboard.studentID << CSV_DELIMITER << scoreboard.fullName << CSV_DELIMITER
       << scoreboard.totalMark << CSV_DELIMITER << scoreboard.finalMark << CSV_DELIMITER
       << scoreboard.midtermMark << CSV_DELIMITER << scoreboard.otherMark << "\n";
    return os;
}
