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
    Account();
    Account(int accountID, int staffOrStudentID, std::string username, std::string password);
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
    // Input/Output Operator Methods
    friend std::ostream& operator<<(std::ostream& os, Account& account);
    friend std::istream &operator>>(std::istream &is, Account &account);

public:
    bool operator==(const Account& account) {
        return this->accountID == account.accountID;
    }
};
#endif // !_ACCOUNT_CLASS_H_
