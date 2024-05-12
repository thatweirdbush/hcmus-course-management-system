/**************************************************************
* Implement Staff class
* Define Staff class - StaffClass.h
***************************************************************/
#ifndef _STAFF_CLASS_H_
#define _STAFF_CLASS_H_

#include "DateClass.h"

class Staff {
private:
    int staffID;
    std::string fullName;
    std::string gender;
    Date dateOfBirth;
    std::string phone;
    std::string email;
    std::string facilityAddress;

public:
    // Constructor
    Staff(int staffID = 0, std::string fullName = "", std::string gender = "",
            Date dateOfBirth = Date(), std::string phone = "", std::string email = "",
          std::string facilityAddress = "")

        :staffID(staffID), fullName(fullName),
        gender(gender), dateOfBirth(dateOfBirth),
        phone(phone), email(email), facilityAddress(facilityAddress) {}

    // Destructor, nothing from now on
    ~Staff() {}

    // Copy constructor
    Staff(const Staff& staff) {
        staffID = staff.staffID;
        fullName = staff.fullName;
        gender = staff.gender;
        dateOfBirth = staff.dateOfBirth;
        phone = staff.phone;
        email = staff.email;
        facilityAddress = staff.facilityAddress;
    }

    // Assignment operator
    Staff& operator=(const Staff& staff) {
        staffID = staff.staffID;
        fullName = staff.fullName;
        gender = staff.gender;
        dateOfBirth = staff.dateOfBirth;
        phone = staff.phone;
        email = staff.email;
        facilityAddress = staff.facilityAddress;
        return *this;
    }

public:
    // Setters
    void setStaffID(int staffID) { this->staffID = staffID; }
    void setFullName(std::string fullName) { this->fullName = fullName; }
    void setGender(std::string gender) { this->gender = gender; }
    void setDateOfBirth(Date dateOfBirth) { this->dateOfBirth = dateOfBirth; }
    void setPhone(std::string phone) { this->phone = phone; }
    void setEmail(std::string email) { this->email = email; }
    void setFacilityAddress(std::string facilityAddress) { this->facilityAddress = facilityAddress; }

    // Getters
    int getStaffID() { return staffID; }
    std::string getFullName() { return fullName; }
    std::string getGender() { return gender; }
    Date getDateOfBirth() { return dateOfBirth; }
    std::string getPhone() { return phone; }
    std::string getEmail() { return email; }
    std::string getFacilityAddress() { return facilityAddress; }

    // Input/Output Operator Methods
    friend std::istream& operator>>(std::istream& is, Staff& staff) {
        std::string line;
        std::getline(is, line);

        if (line.empty()) return is;

        std::stringstream ss(line);
        std::string staffID, fullName, gender, dateOfBirth, phone, email, facilityAddress;

        std::getline(ss, staffID, CSV_DELIMITER);
        std::getline(ss, fullName, CSV_DELIMITER);
        std::getline(ss, gender, CSV_DELIMITER);
        std::getline(ss, dateOfBirth, CSV_DELIMITER);
        std::getline(ss, phone, CSV_DELIMITER);
        std::getline(ss, email, CSV_DELIMITER);

        ss.ignore(); // Ignore the first quotation mark
        std::getline(ss, facilityAddress, QUOTATION_MARK);

        staff.setStaffID(std::stoi(staffID));
        staff.setFullName(fullName);
        staff.setGender(gender);
        staff.setDateOfBirth(Date(dateOfBirth));
        staff.setPhone(phone);
        staff.setEmail(email);
        staff.setFacilityAddress(facilityAddress);
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Staff& staff) {
        os << staff.staffID << CSV_DELIMITER << staff.fullName
           << CSV_DELIMITER << staff.gender << CSV_DELIMITER
           << staff.dateOfBirth << CSV_DELIMITER << staff.phone
           << CSV_DELIMITER << staff.email << CSV_DELIMITER
           << QUOTATION_MARK << staff.facilityAddress << QUOTATION_MARK << std::endl;
        return os;
    }

public:
    bool operator==(const Staff& staff) {
        return this->staffID == staff.staffID;
    }
};
#endif // !_STAFF_CLASS_H_
