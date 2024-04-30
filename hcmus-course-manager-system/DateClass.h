/**************************************************************
* Implement Date class 
* Define Date class - DateClass.h
***************************************************************/
#ifndef _DATE_CLASS_H_
#define _DATE_CLASS_H_

#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

#define CSV_DELIMITER ','

/*****************************************
// Define Class: Date
******************************************/
class Date {
private:
    int day;
    int month;
    int year;

public:
	// Constructor
	Date(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {}

	// Destructor, nothing from now on
	~Date() {}

	// Constructor from string
	Date(std::string date) {
		std::string delimiter = "/";
		size_t pos = 0;
		std::string token;
		int i = 0;
		while ((pos = date.find(delimiter)) != std::string::npos) {
			token = date.substr(0, pos);
			if (i == 0) {
				day = std::stoi(token);
			}
			else if (i == 1) {
				month = std::stoi(token);
			}
			date.erase(0, pos + delimiter.length());
			i++;
		}
		year = std::stoi(date);
	}

	// Copy constructor
	Date(const Date& date) { day = date.day; month = date.month; year = date.year; }

	// Assignment operator
	Date& operator=(const Date& date) {
		day = date.day;
		month = date.month;
		year = date.year;
		return *this;
	}

public:
	// Setters
	void setDay(int day) {
		this->day = day;
	}
	void setMonth(int month) {
		this->month = month;
	}
	void setYear(int year) {
		this->year = year;
	}

	// Getters
	int 
		getDay() const {
		return day;
	}
	int getMonth() const {
		return month;
	}
	int getYear() const {
		return year;
	}

	// Compare Methods
	bool operator==(const Date& date) const {
		return day == date.day && month == date.month && year == date.year;
	}

	bool operator!=(const Date& date) const {
		return !(*this == date);
	}

	bool operator<(const Date& date) const {
		if (year != date.year)
			return year < date.year;
		if (month != date.month)
			return month < date.month;
		return day < date.day;
	}

	bool operator<=(const Date& date) const {
		return *this < date || *this == date;
	}

	bool operator>(const Date& date) const {
		return !(*this <= date);
	}

	bool operator>=(const Date& date) const {
		return !(*this < date);
	}

public:
	// Convert date to string
	std::string toString() const {
		std::string str = std::to_string(day) + '/' + std::to_string(month) + '/' + std::to_string(year);
		return str;
	}

	// Input/Output Operator Methods
	friend std::istream& operator>>(std::istream& is, Date& date) {
		std::string str;
		is >> str;
		date = Date(str);
		return is;
	}

	friend std::ostream& operator<<(std::ostream& os, const Date& date) {
		os << date.day << '/' << date.month << '/' << date.year << "\n";
		return os;
	}
};
#endif // !_DATE_CLASS_H_
