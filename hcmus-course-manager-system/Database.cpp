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
    importScoreboardList(SCOREBOARD_FILE_PATH);
    importClassList(CLASS_FILE_PATH);
}

// Destructor - Save all data to file, with first line header
Database::~Database() {
    exportAccountList(ACCOUNT_FILE_PATH);
    exportCourseList(COURSE_FILE_PATH);
    exportSemesterList(SEMESTER_FILE_PATH);
    exportStudentList(STUDENT_FILE_PATH);
    exportStaffList(STAFF_FILE_PATH);
    exportScoreboardList(SCOREBOARD_FILE_PATH);
    exportClassList(CLASS_FILE_PATH);
}

void Database::registerAccount() {
    /// NOT IMPLEMENTED YET
}

// Get account object in account list when login
Account Database::login(QString username, QString password) {
    Account account = Account();
    for (int i = 0; i < accountList.size(); i++) {
        if (accountList[i].getUsername().compare(username.toStdString()) == 0 &&
            accountList[i].getPassword().compare(password.toStdString()) == 0) {
            account = accountList[i];
            return account;
        }
    }
    return account;
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
        if (account.getAccountID() == -1)
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
        if (course.getCourseID() == -1)
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
        if (semester.getNo() == -1)
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
        if (student.getStudentID() == -1)
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
        if (staff.getStaffID() == -1)
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
        if (scoreboard.getCourseID() == -1)
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
        if (classObj.getClassID() == -1)
            break;

        classList.insert(classObj);
        // count++;
    }

    ifs.close();
    // return count;
}

/*****************************************
// Implementation Functions Set: Export data to file
******************************************/
// Export Account list to file
void Database::exportAccountList(QString filename) {
    std::ofstream ofs(filename.toStdString());
    ofs << "Account ID, Username, Password, Role" << std::endl;
    for (int i = 0; i < accountList.size(); i++) {
        ofs << accountList[i];
    }
    ofs.close();
}

// Export Course list to file
void Database::exportCourseList(QString filename) {
    std::ofstream ofs(filename.toStdString());
    ofs << "Course ID, Course Name, Credit, Lecturer ID, Start Date, End Date" << std::endl;
    for (int i = 0; i < courseList.size(); i++) {
        ofs << courseList[i];
    }
    ofs.close();
}

// Export Semester list to file
void Database::exportSemesterList(QString filename) {
    std::ofstream ofs(filename.toStdString());
    ofs << "Semester No, Start Date, End Date" << std::endl;
    for (int i = 0; i < semesterList.size(); i++) {
        ofs << semesterList[i];
    }
    ofs.close();
}

// Export Student list to file
void Database::exportStudentList(QString filename) {
    std::ofstream ofs(filename.toStdString());
    ofs << "Student ID, First Name, Last Name, Gender, Date of Birth, Phone Number" << std::endl;
    for (int i = 0; i < studentList.size(); i++) {
        ofs << studentList[i];
    }
    ofs.close();
}

// Export Staff list to file
void Database::exportStaffList(QString filename) {
    std::ofstream ofs(filename.toStdString());
    ofs << "Staff ID, Full Name, Gender, Date of Birth, Phone, Email, Facility Address" << std::endl;
    for (int i = 0; i < staffList.size(); i++) {
        ofs << staffList[i];
    }
    ofs.close();
}

// Export Scoreboard list to file
void Database::exportScoreboardList(QString filename) {
    std::ofstream ofs(filename.toStdString());
    ofs << "Course ID, Student ID, Midterm, Final, Lab, Bonus, Total" << std::endl;
    for (int i = 0; i < scoreboardList.size(); i++) {
        ofs << scoreboardList[i];
    }
    ofs.close();
}

// Export Class list to file
void Database::exportClassList(QString filename) {
    std::ofstream ofs(filename.toStdString());
    ofs << "Class ID, Class Name, Course ID, Lecturer ID, Start Date, End Date" << std::endl;
    for (int i = 0; i < classList.size(); i++) {
        ofs << classList[i];
    }
    ofs.close();
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
    table->setColumnCount(3);

    // Adjust columns to fill the table width
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Set table headers
    table->setHorizontalHeaderItem(0, new QTableWidgetItem("Staff/Student ID"));
    table->setHorizontalHeaderItem(1, new QTableWidgetItem("Username"));
    table->setHorizontalHeaderItem(2, new QTableWidgetItem("Password"));

    // Display accounts in the table
    for (int i = 0; i < accountList.size(); i++)
    {
        Account account = accountList[i];
        table->setItem(i, 0, new QTableWidgetItem(QString::number(account.getStaffOrStudentID())));
        table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(account.getUsername())));
        table->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(account.getPassword())));
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

// Load Scoreboard List
void Database::loadScoreboardList(QTableWidget* table, Set<Scoreboard>& scoreboardList)
{
    // Setup table row & column
    table->setRowCount(scoreboardList.size());
    table->setColumnCount(8);

    // Adjust columns to fill the table width
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Set table headers
    table->setHorizontalHeaderItem(0, new QTableWidgetItem("Course ID"));
    table->setHorizontalHeaderItem(1, new QTableWidgetItem("Class Name"));
    table->setHorizontalHeaderItem(2, new QTableWidgetItem("Student ID"));
    table->setHorizontalHeaderItem(3, new QTableWidgetItem("Student Name"));
    table->setHorizontalHeaderItem(4, new QTableWidgetItem("Total Mark"));
    table->setHorizontalHeaderItem(5, new QTableWidgetItem("Final Mark"));
    table->setHorizontalHeaderItem(6, new QTableWidgetItem("Midterm Mark"));
    table->setHorizontalHeaderItem(7, new QTableWidgetItem("Other Mark"));

    // Display scoreboards in the table
    for (int i = 0; i < scoreboardList.size(); i++)
    {
        Scoreboard scoreboard = scoreboardList[i];
        table->setItem(i, 0, new QTableWidgetItem(QString::number(scoreboard.getCourseID())));
        table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(scoreboard.getClassName())));
        table->setItem(i, 2, new QTableWidgetItem(QString::number(scoreboard.getStudentID())));
        table->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(scoreboard.getFullName())));
        table->setItem(i, 4, new QTableWidgetItem(QString::number(scoreboard.getTotalMark())));
        table->setItem(i, 5, new QTableWidgetItem(QString::number(scoreboard.getFinalMark())));
        table->setItem(i, 6, new QTableWidgetItem(QString::number(scoreboard.getMidtermMark())));
        table->setItem(i, 7, new QTableWidgetItem(QString::number(scoreboard.getOtherMark())));
    }
}

// Load Class List
void Database::loadClassList(QTableWidget* table)
{
    // Setup table row & column
    table->setRowCount(classList.size());
    table->setColumnCount(2);

    // Adjust columns to fill the table width
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Set table headers
    table->setHorizontalHeaderItem(0, new QTableWidgetItem("Class Name"));
    table->setHorizontalHeaderItem(1, new QTableWidgetItem("Room Number"));

    // Display classes in the table
    for (int i = 0; i < classList.size(); i++)
    {
        Class classObj = classList[i];
        table->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(classObj.getClassName())));
        table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(classObj.getRoomNo())));
    }
}


/*****************************************
// Implementation Functions Set: Update data to the database's attributes
******************************************/
// Update Account List
void Database::updateAccountList(Account account)
{
    // Find the account in the list then update it
    for (int i = 0; i < accountList.size(); i++)
    {
        if (accountList[i].getStaffOrStudentID() == account.getStaffOrStudentID())
        {
            accountList[i] = account;
            break;
        }
    }
}

// Update Course List
void Database::updateCourseList(Course course)
{
    // Find the course in the list then update it
    for (int i = 0; i < courseList.size(); i++)
    {
        if (courseList[i].getCourseID() == course.getCourseID())
        {
            courseList[i] = course;
            break;
        }
    }
}

// Update Student List
void Database::updateStudentList(Student student)
{
    // Find the student in the list then update it
    for (int i = 0; i < studentList.size(); i++)
    {
        if (studentList[i].getStudentID() == student.getStudentID())
        {
            studentList[i] = student;
            break;
        }
    }
}

// Update Semester List
void Database::updateSemesterList(Semester semester)
{
    // Find the semester in the list then update it
    for (int i = 0; i < semesterList.size(); i++)
    {
        if (semesterList[i].getNo() == semester.getNo())
        {
            semesterList[i] = semester;
            break;
        }
    }
}

// Update Scoreboard List
void Database::updateScoreboardList(Scoreboard scoreboard)
{
    // Find the scoreboard in the list then update it
    for (int i = 0; i < scoreboardList.size(); i++)
    {
        if (scoreboardList[i].getCourseID() == scoreboard.getCourseID() &&
            scoreboardList[i].getStudentID() == scoreboard.getStudentID() &&
            scoreboardList[i].getClassName() == scoreboard.getClassName())
        {
            scoreboardList[i] = scoreboard;
            break;
        }
    }
}

// Update Class List
void Database::updateClassList(Class classObj)
{
    // Find the class in the list then update it
    for (int i = 0; i < classList.size(); i++)
    {
        if (classList[i].getClassID() == classObj.getClassID())
        {
            classList[i] = classObj;
            break;
        }
    }
}

















