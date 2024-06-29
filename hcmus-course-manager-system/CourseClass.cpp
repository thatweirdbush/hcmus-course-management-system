#include "CourseClass.h"

// Convert Session to string
std::string sessionToString(Session session) {
    switch (session) {
    case Session::S1: return "S1";
    case Session::S2: return "S2";
    case Session::S3: return "S3";
    case Session::S4: return "S4";
    default: return "ERR";
    }
}

// Convert DayOfWeek to string
std::string dayOfWeekToString(DayOfWeek dayOfWeek) {
    switch (dayOfWeek) {
    case DayOfWeek::MON: return "MON";
    case DayOfWeek::TUE: return "TUE";
    case DayOfWeek::WED: return "WED";
    case DayOfWeek::THU: return "THU";
    case DayOfWeek::FRI: return "FRI";
    case DayOfWeek::SAT: return "SAT";
    default: return "ERR";
    }
}

// Convert string to Session
Session stringToSession(std::string session) {
    if (session == "S1") return Session::S1;
    if (session == "S2") return Session::S2;
    if (session == "S3") return Session::S3;
    else return Session::S4;
}

// Convert string to DayOfWeek
DayOfWeek stringToDayOfWeek(std::string dayOfWeek) {
    if (dayOfWeek == "MON") return DayOfWeek::MON;
    if (dayOfWeek == "TUE") return DayOfWeek::TUE;
    if (dayOfWeek == "WED") return DayOfWeek::WED;
    if (dayOfWeek == "THU") return DayOfWeek::THU;
    if (dayOfWeek == "FRI") return DayOfWeek::FRI;
    else return DayOfWeek::SAT;
}


/*****************************************
// Implementation Class: Course
******************************************/
// Default Constructor
Course::Course() {
    courseID = -1;
    courseName = "";
    className = "";
    teacherName = "";
    numOfCredits = -1;
    maxStudents = -1;
    dayOfWeek = DayOfWeek::MON;
    session = Session::S1;
}

// Constructor with parameters
Course::Course(int courseID, std::string courseName,std::string className,
               std::string teacherName, int numOfCredits, int maxStudents,
               DayOfWeek dayOfWeek, Session session)
{
    this->courseID = courseID;
    this->courseName = courseName;
    this->className = className;
    this->teacherName = teacherName;
    this->numOfCredits = numOfCredits;
    this->maxStudents = maxStudents;
    this->dayOfWeek = dayOfWeek;
    this->session = session;
}

// Input Operator Method
std::ostream& operator<<(std::ostream& os, Course& course) {
    os << course.getCourseID() << CSV_DELIMITER << course.getCourseName() << CSV_DELIMITER
       << course.getClassName() << CSV_DELIMITER << course.getTeacherName() << CSV_DELIMITER
       << course.getNumOfCredits() << CSV_DELIMITER << course.getMaxStudents() << CSV_DELIMITER
       << dayOfWeekToString(course.getDayOfWeek()) << CSV_DELIMITER
       << sessionToString(course.getSession()) << "\n";
    return os;
}

// Output Operator Method
std::istream& operator>>(std::istream& is, Course& course) {
    std::string line;
    std::getline(is, line);

    if (line.empty()) return is;

    std::stringstream ss(line);
    std::string courseID, courseName, className, teacherName, numOfCredits, maxStudents, dayOfWeekStr, sessionStr;
    DayOfWeek dayOfWeek = DayOfWeek::MON;
    Session session = Session::S1;

    std::getline(ss, courseID, CSV_DELIMITER);
    std::getline(ss, courseName, CSV_DELIMITER);
    std::getline(ss, className, CSV_DELIMITER);
    std::getline(ss, teacherName, CSV_DELIMITER);
    std::getline(ss, numOfCredits, CSV_DELIMITER);
    std::getline(ss, maxStudents, CSV_DELIMITER);
    std::getline(ss, dayOfWeekStr, CSV_DELIMITER);
    std::getline(ss, sessionStr, CSV_DELIMITER);

    dayOfWeek = stringToDayOfWeek(dayOfWeekStr);
    session = stringToSession(sessionStr);

    course.setCourseID(std::stoi(courseID));
    course.setCourseName(courseName);
    course.setClassName(className);
    course.setTeacherName(teacherName);
    course.setNumOfCredits(std::stoi(numOfCredits));
    course.setMaxStudents(std::stoi(maxStudents));
    course.setDayOfWeek(dayOfWeek);
    course.setSession(session);
    return is;
}
