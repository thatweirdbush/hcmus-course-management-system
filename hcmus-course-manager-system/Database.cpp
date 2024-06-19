#include "Database.h"
#include "qheaderview.h"
#include "qmessagebox.h"

/*****************************************
// Implementation Class: Database
******************************************/
// Constructor: Load all data files
Database::Database() {
    importAccountList(ACCOUNT_FILE_PATH);
    importCourseList(COURSE_FILE_PATH);
    importSemesterList(SEMESTER_FILE_PATH);
    importStudentList(STUDENT_FILE_PATH);
    importStaffList(STAFF_FILE_PATH);
    // importScoreboardList(SCOREBOARD_FILE_PATH);
    importClassList(CLASS_FILE_PATH);
}

// Destructor - Save all data to file, with first line header
Database::~Database() {
    // Write account list to file
    std::ofstream ofs(ACCOUNT_FILE_PATH.toStdString(), std::ios::trunc);
    ofs << "Account ID, Staff/Student ID, Username, Password" << std::endl;
    for (int i = 0; i < accountList.size(); i++) {
        ofs << accountList[i];
    }
    ofs.close();

    // Write course list to file
    ofs.open(COURSE_FILE_PATH.toStdString(), std::ios::trunc);
    ofs << "Course ID, Course Name, Class Name, Instructor Name, Credit, Max Students, Day, Session" << std::endl;
    for (int i = 0; i < courseList.size(); i++) {
        ofs << courseList[i];
    }
    ofs.close();

    // Write semester list to file
    ofs.open(SEMESTER_FILE_PATH.toStdString(), std::ios::trunc);
    ofs << "Semester ID, Semester No, School Year, Start Date, End Date" << std::endl;
    for (int i = 0; i < semesterList.size(); i++) {
        ofs << semesterList[i];
    }
    ofs.close();

    // Write student list to file
    ofs.open(STUDENT_FILE_PATH.toStdString(), std::ios::trunc);
    ofs << "Student ID, First Name, Last Name, Gender, Date of Birth, Phone Number" << std::endl;
    for (int i = 0; i < studentList.size(); i++) {
        ofs << studentList[i];
    }
    ofs.close();

    // Write staff list to file
    ofs.open(STAFF_FILE_PATH.toStdString(), std::ios::trunc);
    ofs << "Staff ID, Full Name, Gender, Date of Birth, Phone, Email, Facility Address" << std::endl;
    for (int i = 0; i < staffList.size(); i++) {
        ofs << staffList[i];
    }
    ofs.close();

    // // Write scoreboard list to file
    // ofs.open(SCOREBOARD_FILE_PATH.toStdString(), std::ios::trunc);
    // ofs << "Course ID, Student ID, Student Full Name, Total Mark, Final Mark, Midterm Mark, Other Mark" << std::endl;
    // for (int i = 0; i < scoreboardList.size(); i++) {
    //     ofs << scoreboardList[i];
    // }
    // ofs.close();

    // Write class list to file
    ofs.open(CLASS_FILE_PATH.toStdString(), std::ios::trunc);
    ofs << "Class ID, Class Name, Room Number" << std::endl;
    for (int i = 0; i < classList.size(); i++) {
        ofs << classList[i];
    }
    ofs.close();
}

void Database::registerAccount() {
    /// NOT IMPLEMENTED YET
}

// Get index of account in account list when login
int Database::login(QString username, QString password) {
    int index = -1;
    for (int i = 0; i < accountList.size(); i++) {
        if (accountList[i].getUsername().compare(username.toStdString()) == 0 &&
            accountList[i].getPassword().compare(password.toStdString()) == 0) {
            index = i;
        }
    }
    return index;
}

/*****************************************
// Implementation Functions Set: Import data from file
******************************************/
// Import Account list from file
void Database::importAccountList(QString filename){
    std::ifstream ifs(filename.toStdString());
    // size_t count = 0;
    if (!ifs.is_open()) {
        // open message box
        QMessageBox::information(nullptr, "Read Error", filename, QMessageBox::Ok | QMessageBox::Cancel);
        return;
    }

    // Skip header - the first line
    std::string line;
    std::getline(ifs, line);

    while (!ifs.eof()) {
        Account account;
        ifs >> account;
        // Check if the course read from is empty, then break, because default ID constructor is 0
        if (account.getAccountID() == 0)
            break;

        accountList.insert(account);
        // count++;
    }

    ifs.close();
    // return count;
}

// Import Course list from file
void Database::importCourseList(QString filename) {
    std::ifstream ifs(filename.toStdString());
    // size_t count = 0;
    if (!ifs.is_open()) {
        // open message box
        QMessageBox::information(nullptr, "Read Error", filename, QMessageBox::Ok | QMessageBox::Cancel);
        return;
    }

    // Skip header - the first line
    std::string line;
    std::getline(ifs, line);

    while (!ifs.eof()) {
        Course course;
        ifs >> course;

        // Check if the course read from is empty, then break, because default ID constructor is 0
        if (course.getCourseID() == 0)
            break;

        courseList.insert(course);
        // count++;
    }

    ifs.close();
    // return count;
}

// Import Semester list from file
void Database::importSemesterList(QString filename) {
    std::ifstream ifs(filename.toStdString());
    // size_t count = 0;
    if (!ifs.is_open()) {
        // open message box
        QMessageBox::information(nullptr, "Read Error", filename, QMessageBox::Ok | QMessageBox::Cancel);
        return;
    }

    // Skip header - the first line
    std::string line;
    std::getline(ifs, line);

    while (!ifs.eof()) {
        Semester semester;
        ifs >> semester;

        // Check if the course read from is empty, then break, because default No constructor is 0
        if (semester.getNo() == 0)
            break;

        semesterList.insert(semester);
        // count++;
    }

    ifs.close();
    // return count;
}

// Import Student list from file
void Database::importStudentList(QString filename) {
    std::ifstream ifs(filename.toStdString());
    // size_t count = 0;
    if (!ifs.is_open()) {
        // open message box
        QMessageBox::information(nullptr, "Read Error", filename, QMessageBox::Ok | QMessageBox::Cancel);
        return;
    }

    // Skip header - the first line
    std::string line;
    std::getline(ifs, line);

    while (!ifs.eof()) {
        Student student;
        ifs >> student;

        // Check if the course read from is empty, then break, because default ID constructor is 0
        if (student.getStudentID() == 0)
            break;

        studentList.insert(student);
        // count++;
    }

    ifs.close();
    // return count;
}

// Import Staff list from file
void Database::importStaffList(QString filename) {
    std::ifstream ifs(filename.toStdString());
    // size_t count = 0;
    if (!ifs.is_open()) {
        // open message box
        QMessageBox::information(nullptr, "Read Error", filename, QMessageBox::Ok | QMessageBox::Cancel);
        return;
    }

    // Skip header - the first line
    std::string line;
    std::getline(ifs, line);

    while (!ifs.eof()) {
        Staff staff;
        ifs >> staff;

        // Check if the course read from is empty, then break, because default ID constructor is 0
        if (staff.getStaffID() == 0)
            break;

        staffList.insert(staff);
        // count++;
    }

    ifs.close();
    // return count;
}

// Import Scoreboard list from file
void Database::importScoreboardList(QString filename) {
    std::ifstream ifs(filename.toStdString());
    // size_t count = 0;
    if (!ifs.is_open()) {
        // open message box
        QMessageBox::information(nullptr, "Read Error", filename, QMessageBox::Ok | QMessageBox::Cancel);
        return;
    }

    // Skip header - the first line
    std::string line;
    std::getline(ifs, line);

    while (!ifs.eof()) {
        Scoreboard scoreboard;
        ifs >> scoreboard;

        // Check if the course read from is empty, then break, because default ID constructor is 0
        if (scoreboard.getCourseID() == 0)
            break;

        scoreboardList.insert(scoreboard);
        // count++;
    }

    ifs.close();
    // return count;
}

// Import Class list from file
void Database::importClassList(QString filename) {
    std::ifstream ifs(filename.toStdString());
    // size_t count = 0;
    if (!ifs.is_open()) {
        // open message box
        QMessageBox::information(nullptr, "Read Error", filename, QMessageBox::Ok | QMessageBox::Cancel);
        return;
    }

    // Skip header - the first line
    std::string line;
    std::getline(ifs, line);

    while (!ifs.eof()) {
        Class classObj;
        ifs >> classObj;

        // Check if the course read from is empty, then break, because default ID constructor is 0
        if (classObj.getClassID() == 0)
            break;

        classList.insert(classObj);
        // count++;
    }

    ifs.close();
    // return count;
}

/*****************************************
// Implementation Functions Set: Search functions
******************************************/
// Search Student using unique ID
Student Database::getStudentByID(int studentID) {
    for (int i = 0; i < studentList.size(); i++) {
        if (studentList[i].getStudentID() == studentID) {
            return studentList[i];
        }
    }
    return Student();
}

// Search Staff using unique ID
Staff Database::getStaffByID(int staffID) {
    for (int i = 0; i < staffList.size(); i++) {
        if (staffList[i].getStaffID() == staffID) {
            return staffList[i];
        }
    }
    return Staff();
}

// Search Course using unique ID
Set<Scoreboard> Database::getScoreboardListByCourseID(int courseID) {
    Set<Scoreboard> result;
    for (int i = 0; i < scoreboardList.size(); i++) {
        if (scoreboardList[i].getCourseID() == courseID) {
            result.insert(scoreboardList[i]);
        }
    }
    return result;
}

/**************************************************************
* Implement Load Data Context
*
***************************************************************/
// Load Course List
void Database::loadCourseList(QTableWidget* table)
{
    // Setup table row & column
    table->setRowCount(courseList.size());
    table->setColumnCount(8);

    // Adjust columns to fill the table width
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Set table headers
    table->setHorizontalHeaderItem(0, new QTableWidgetItem("Course ID"));
    table->setHorizontalHeaderItem(1, new QTableWidgetItem("Course Name"));
    table->setHorizontalHeaderItem(2, new QTableWidgetItem("Class Name"));
    table->setHorizontalHeaderItem(3, new QTableWidgetItem("Teacher Name"));
    table->setHorizontalHeaderItem(4, new QTableWidgetItem("Credits"));
    table->setHorizontalHeaderItem(5, new QTableWidgetItem("Max Students"));
    table->setHorizontalHeaderItem(6, new QTableWidgetItem("Day of Week"));
    table->setHorizontalHeaderItem(7, new QTableWidgetItem("Session"));

    // Display courses in the table
    for (int i = 0; i < courseList.size(); i++)
    {
        Course course = courseList[i];
        table->setItem(i, 0, new QTableWidgetItem(QString::number(course.getCourseID())));
        table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(course.getCourseName())));
        table->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(course.getClassName())));
        table->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(course.getTeacherName())));
        table->setItem(i, 4, new QTableWidgetItem(QString::number(course.getNumOfCredits())));
        table->setItem(i, 5, new QTableWidgetItem(QString::number(course.getMaxStudents())));
        table->setItem(i, 6, new QTableWidgetItem(QString::fromStdString(dayOfWeekToString(course.getDayOfWeek()))));
        table->setItem(i, 7, new QTableWidgetItem(QString::fromStdString(sessionToString(course.getSession()))));
    }
}

// Load Account List
void Database::loadAccountList(QTableWidget* table)
{
    // Setup table row & column
    table->setRowCount(accountList.size());
    table->setColumnCount(4);

    // Adjust columns to fill the table width
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Set table headers
    table->setHorizontalHeaderItem(0, new QTableWidgetItem("Account ID"));
    table->setHorizontalHeaderItem(1, new QTableWidgetItem("Staff/Student ID"));
    table->setHorizontalHeaderItem(2, new QTableWidgetItem("Username"));
    table->setHorizontalHeaderItem(3, new QTableWidgetItem("Password"));

    // Display accounts in the table
    for (int i = 0; i < accountList.size(); i++)
    {
        Account account = accountList[i];
        table->setItem(i, 0, new QTableWidgetItem(QString::number(account.getAccountID())));
        table->setItem(i, 1, new QTableWidgetItem(QString::number(account.getStaffOrStudentID())));
        table->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(account.getUsername())));
        table->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(account.getPassword())));
    }
}

// Load Student List
void Database::loadStudentList(QTableWidget* table)
{
    // Setup table row & column
    table->setRowCount(studentList.size());
    table->setColumnCount(6);

    // Adjust columns to fill the table width
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Set table headers
    table->setHorizontalHeaderItem(0, new QTableWidgetItem("Student ID"));
    table->setHorizontalHeaderItem(1, new QTableWidgetItem("First name"));
    table->setHorizontalHeaderItem(2, new QTableWidgetItem("Last Name"));
    table->setHorizontalHeaderItem(3, new QTableWidgetItem("Gender"));
    table->setHorizontalHeaderItem(4, new QTableWidgetItem("Birth"));
    table->setHorizontalHeaderItem(5, new QTableWidgetItem("Social ID"));

    // Display students in the table
    for (int i = 0; i < studentList.size(); i++)
    {
        Student student = studentList[i];
        table->setItem(i, 0, new QTableWidgetItem(QString::number(student.getStudentID())));
        table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(student.getFirstName())));
        table->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(student.getLastName())));
        table->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(student.getGender())));
        table->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(student.getDateOfBirth().toString())));
        table->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(student.getSocialID())));
    }
}

// Load Semester List
void Database::loadSemesterList(QTableWidget* table)
{
    // Setup table row & column
    table->setRowCount(semesterList.size());
    table->setColumnCount(4);

    // Adjust columns to fill the table width
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Set table headers
    table->setHorizontalHeaderItem(0, new QTableWidgetItem("Semester"));
    table->setHorizontalHeaderItem(1, new QTableWidgetItem("School Year"));
    table->setHorizontalHeaderItem(2, new QTableWidgetItem("Start Date"));
    table->setHorizontalHeaderItem(3, new QTableWidgetItem("End Date"));

    // Display semesters in the table
    for (int i = 0; i < semesterList.size(); i++)
    {
        Semester semester = semesterList[i];
        table->setItem(i, 0, new QTableWidgetItem(QString::number(semester.getNo())));
        table->setItem(i, 1, new QTableWidgetItem(QString::number(semester.getSchoolYear())));
        table->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(semester.getStartDate().toString())));
        table->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(semester.getEndDate().toString())));
    }
}

// Load Class List
void Database::loadClassList(QTableWidget* table)
{
    // Setup table row & column
    table->setRowCount(classList.size());
    table->setColumnCount(3);

    // Adjust columns to fill the table width
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Set table headers
    table->setHorizontalHeaderItem(0, new QTableWidgetItem("Class ID"));
    table->setHorizontalHeaderItem(1, new QTableWidgetItem("Class Name"));
    table->setHorizontalHeaderItem(2, new QTableWidgetItem("Room Number"));

    // Display classes in the table
    for (int i = 0; i < classList.size(); i++)
    {
        Class classObj = classList[i];
        table->setItem(i, 0, new QTableWidgetItem(QString::number(classObj.getClassID())));
        table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(classObj.getClassName())));
        table->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(classObj.getRoomNo())));
    }
}
