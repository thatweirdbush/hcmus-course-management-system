/**************************************************************
* Implement AccountManager class
* Define AccountManager class - AccountManagerClass.h
***************************************************************/
#ifndef _ACCOUNT_MANAGERCLASS_H_
#define _ACCOUNT_MANAGERCLASS_H_

#include "AccountClass.h"
#include "Set.h"
#include <iostream>

/*****************************************
// Define Class: AccountManager
******************************************/
class AccountManager {
private:
	Set<Account> accountList;

public:
	// Constructors
	AccountManager() {}

	// Destructor
	~AccountManager() {}

public:
	// Getters
	Set<Account> getAccountList() { return accountList; }

	// Setters
	void setAccountList(Set<Account> accountList) { this->accountList = accountList; }

public:
	void registerAccount() {
		Account account;
		std::string username, password, role, fullName, address, email, phone;
		Date dateOfBirth;

		///
		/// TODO: finish this function
		///
		
		accountList.insert(account);
		std::cout << "Register successfully!\n";
	}

	Account login() {
		std::string username, password;
		int index = -1;

		///
		/// TODO: finish this function
		///

		return accountList[index];
	}

};

#endif // !_ACCOUNT_MANAGERCLASS_H_