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
	std::string username;
	std::string password;
	std::string role;
	std::string fullName;
	Date dateOfBirth;
	std::string address;
	std::string email;
	std::string phone;

public:
	// Constructor with parameters
	Account(int accountID = 0, std::string username = "", std::string password = "",
		std::string role = "", std::string fullName = "", Date dateOfBirth = Date(),
		std::string address = "", std::string email = "", std::string phone = "") 
	{
		this->accountID = accountID;
		this->username = username;
		this->password = password;
		this->role = role;
		this->fullName = fullName;
		this->dateOfBirth = dateOfBirth;
		this->address = address;
		this->email = email;
		this->phone = phone;
	}

	// Destructor
	~Account() {}

public:
	// Getters
	int getAccountID() { return accountID; }
	std::string getUsername() { return username; }
	std::string getPassword() { return password; }
	std::string getRole() { return role; }
	std::string getFullName() { return fullName; }
	Date getDateOfBirth() { return dateOfBirth; }
	std::string getAddress() { return address; }
	std::string getEmail() { return email; }
	std::string getPhone() { return phone; }

	// Setters
	void setAccountID(int accountID) { this->accountID = accountID; }
	void setUsername(std::string username) { this->username = username; }
	void setPassword(std::string password) { this->password = password; }
	void setRole(std::string role) { this->role = role; }
	void setFullName(std::string fullName) { this->fullName = fullName; }
	void setDateOfBirth(Date dateOfBirth) { this->dateOfBirth = dateOfBirth; }
	void setAddress(std::string address) { this->address = address; }
	void setEmail(std::string email) { this->email = email; }
	void setPhone(std::string phone) { this->phone = phone; }
};

#endif // !_ACCOUNT_CLASS_H_
