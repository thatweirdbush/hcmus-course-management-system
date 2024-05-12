#include "Database.h"
#include "qmessagebox.h"

/*****************************************
// Implementation Class: Semester
******************************************/
// Constructor: Load all data files
Database::Database() {
    importAccountList(ACCOUNT_FILE_PATH);
    importCourseList(COURSE_FILE_PATH);
    // importSemesterList(SEMESTER_FILE_PATH);
    importStudentList(STUDENT_FILE_PATH);
    importStaffList(STAFF_FILE_PATH);
    // importScoreboardList(SCOREBOARD_FILE_PATH);
}

// Destructor
Database::~Database() {
    // // Write data to file
    // // Write account list to file
    // std::ofstream ofs(ACCOUNT_FILE_PATH.toStdString());
    // for (int i = 0; i < accountList.size(); i++) {
    //     ofs << accountList[i];
    // }
    // ofs.close();

    // // Write course list to file
    // ofs.open(COURSE_FILE_PATH.toStdString());
    // for (int i = 0; i < courseList.size(); i++) {
    //     ofs << courseList[i];
    // }
    // ofs.close();

    // // Write semester list to file
    // ofs.open(SEMESTER_FILE_PATH.toStdString());
    // for (int i = 0; i < semesterList.size(); i++) {
    //     ofs << semesterList[i];
    // }
    // ofs.close();

    // // Write student list to file
    // ofs.open(STUDENT_FILE_PATH.toStdString());
    // for (int i = 0; i < studentList.size(); i++) {
    //     ofs << studentList[i];
    // }
    // ofs.close();

    // // Write scoreboard list to file
    // ofs.open(SCOREBOARD_FILE_PATH.toStdString());
    // for (int i = 0; i < scoreboardList.size(); i++) {
    //     ofs << scoreboardList[i];
    // }
    // ofs.close();
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

Student Database::getStudentByID(int studentID) {
    for (int i = 0; i < studentList.size(); i++) {
        if (studentList[i].getStudentID() == studentID) {
            return studentList[i];
        }
    }
    return Student();
}

Staff Database::getStaffByID(int staffID) {
    for (int i = 0; i < studentList.size(); i++) {
        if (staffList[i].getStaffID() == staffID) {
            return staffList[i];
        }
    }
    return Staff();
}

void Database::importAccountList(QString filename){
    std::ifstream ifs(filename.toStdString());
    // size_t count = 0;
    if (!ifs.is_open()) {
        // open message box
        QMessageBox::information(nullptr, "Read Error", filename, QMessageBox::Ok | QMessageBox::Cancel);
        return;
    }

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

void Database::importCourseList(QString filename) {
    std::ifstream ifs(filename.toStdString());
    // size_t count = 0;
    if (!ifs.is_open()) {
        // open message box
        QMessageBox::information(nullptr, "Read Error", filename, QMessageBox::Ok | QMessageBox::Cancel);
        return;
    }

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

void Database::importSemesterList(QString filename) {
    std::ifstream ifs(filename.toStdString());
    // size_t count = 0;
    if (!ifs.is_open()) {
        // open message box
        QMessageBox::information(nullptr, "Read Error", filename, QMessageBox::Ok | QMessageBox::Cancel);
        return;
    }

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

void Database::importStudentList(QString filename) {
    std::ifstream ifs(filename.toStdString());
    // size_t count = 0;
    if (!ifs.is_open()) {
        // open message box
        QMessageBox::information(nullptr, "Read Error", filename, QMessageBox::Ok | QMessageBox::Cancel);
        return;
    }

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

void Database::importStaffList(QString filename) {
    std::ifstream ifs(filename.toStdString());
    // size_t count = 0;
    if (!ifs.is_open()) {
        // open message box
        QMessageBox::information(nullptr, "Read Error", filename, QMessageBox::Ok | QMessageBox::Cancel);
        return;
    }

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

void Database::importScoreboardList(QString filename) {
    std::ifstream ifs(filename.toStdString());
    // size_t count = 0;
    if (!ifs.is_open()) {
        // open message box
        QMessageBox::information(nullptr, "Read Error", filename, QMessageBox::Ok | QMessageBox::Cancel);
        return;
    }

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
