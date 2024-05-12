/**************************************************************
* Implement Account class
* Define Account class - AccountClass.h
***************************************************************/
#ifndef _ACCOUNT_CLASS_H_
#define _ACCOUNT_CLASS_H_

#include "DateClass.h"

/*****************************************
// Define Class: Account
******************************************/
class Account {
private:
	int accountID;
    int staffOrStudentID;
	std::string username;
	std::string password;

public:
	// Constructor with parameters
    Account(int accountID = 0, int staffOrStudentID = 0, std::string username = "", std::string password = "")
	{
		this->accountID = accountID;
        this->staffOrStudentID = staffOrStudentID;
		this->username = username;
		this->password = password;
	}

	// Destructor
	~Account() {}

public:
	// Getters
	int getAccountID() { return accountID; }
    int getStaffOrStudentID() { return staffOrStudentID; }
	std::string getUsername() { return username; }
	std::string getPassword() { return password; }

	// Setters
	void setAccountID(int accountID) { this->accountID = accountID; }
    void setStaffOrStudentID(int staffOrStudentID) { this->staffOrStudentID = staffOrStudentID; }
	void setUsername(std::string username) { this->username = username; }
	void setPassword(std::string password) { this->password = password; }

public:
    friend std::ostream& operator<<(std::ostream& os, Account& account);
    friend std::istream& operator>>(std::istream& is, Account& account)  {
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

public:
    bool operator==(const Account& account) {
        return this->accountID == account.accountID;
    }
};

/*****************************************
 * Implementation Class: Account
 ******************************************/
// std::ostream& operator<<(std::ostream& os, Account& account) {
//     os << account.accountID << std::endl;
//     os << account.username << std::endl;
//     os << account.password << std::endl;
//     return os;
// }

// std::istream& operator>>(std::istream& is, Account& account) {
//     std::string line;
//     std::getline(is, line);

//     if (line.empty()) return is;

//     std::stringstream ss(line);
//     std::string acountID, staffOrStudentID, username, password;

//     std::getline(ss, acountID, CSV_DELIMITER);
//     std::getline(ss, staffOrStudentID, CSV_DELIMITER);
//     std::getline(ss, username, CSV_DELIMITER);
//     std::getline(ss, password, CSV_DELIMITER);

//     account.setAccountID(std::stoi(acountID));
//     account.setStaffOrStudentID(std::stoi(staffOrStudentID));
//     account.setUsername(username);
//     account.setPassword(password);

//     return is;
// }


#endif // !_ACCOUNT_CLASS_H_
