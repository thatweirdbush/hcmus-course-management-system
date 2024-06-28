#include "AccountClass.h"

/*****************************************
// Implementation Class: Account
******************************************/
// Default Constructor
Account::Account() {
    accountID = -1;
    staffOrStudentID = -1;
    username = "";
    password = "";
}

// Constructor with parameters
Account::Account(int accountID, int staffOrStudentID, std::string username, std::string password) {
    this->accountID = accountID;
    this->staffOrStudentID = staffOrStudentID;
    this->username = username;
    this->password = password;
}

// Input Operator Method
std::ostream& operator<<(std::ostream& os, Account& account) {
    os << account.accountID << CSV_DELIMITER << account.staffOrStudentID << CSV_DELIMITER << account.username << CSV_DELIMITER << account.password << std::endl;
    return os;
}

// Output Operator Method
std::istream& operator>>(std::istream& is, Account& account) {
    std::string line;
    std::getline(is, line);

    if (line.empty()) return is;

    std::stringstream ss(line);
    std::string accountID, staffOrStudentID, username, password;

    std::getline(ss, accountID, CSV_DELIMITER);
    std::getline(ss, staffOrStudentID, CSV_DELIMITER);
    std::getline(ss, username, CSV_DELIMITER);
    std::getline(ss, password, CSV_DELIMITER);

    account.setAccountID(std::stoi(accountID));
    account.setStaffOrStudentID(std::stoi(staffOrStudentID));
    account.setUsername(username);
    account.setPassword(password);

    return is;
}
