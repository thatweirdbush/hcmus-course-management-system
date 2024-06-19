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
    Staff();
    Staff(int staffID, std::string fullName, std::string gender,
          Date dateOfBirth, std::string phone, std::string email,
          std::string facilityAddress);
    ~Staff() {}
    Staff(const Staff &staff);
    Staff &operator=(const Staff &staff);

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
    friend std::istream &operator>>(std::istream &is, Staff &staff);
    friend std::ostream &operator<<(std::ostream &os, const Staff &staff);

public:
    bool operator==(const Staff& staff) {
        return this->staffID == staff.staffID;
    }
};
#endif // !_STAFF_CLASS_H_
