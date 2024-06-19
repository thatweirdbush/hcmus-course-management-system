#include "StaffClass.h"

/*****************************************
// Implementation Class: Staff
******************************************/
// Default Constructor
Staff::Staff() {
    staffID = -1;
    fullName = "";
    gender = "";
    dateOfBirth = Date();
    phone = "";
    email = "";
    facilityAddress = "";
}

// Constructor
Staff::Staff(int staffID, std::string fullName, std::string gender, Date dateOfBirth,
        std::string phone, std::string email, std::string facilityAddress)

    : staffID(staffID), fullName(fullName), gender(gender), dateOfBirth(dateOfBirth),
    phone(phone), email(email), facilityAddress(facilityAddress) {}

// Copy constructor
Staff::Staff(const Staff& staff) {
    staffID = staff.staffID;
    fullName = staff.fullName;
    gender = staff.gender;
    dateOfBirth = staff.dateOfBirth;
    phone = staff.phone;
    email = staff.email;
    facilityAddress = staff.facilityAddress;
}

// Assignment operator
Staff& Staff::operator=(const Staff& staff) {
    staffID = staff.staffID;
    fullName = staff.fullName;
    gender = staff.gender;
    dateOfBirth = staff.dateOfBirth;
    phone = staff.phone;
    email = staff.email;
    facilityAddress = staff.facilityAddress;
    return *this;
}

// Input Operator Method
std::istream& operator>>(std::istream& is, Staff& staff) {
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

// Output Operator Method
std::ostream& operator<<(std::ostream& os, const Staff& staff) {
    os << staff.staffID << CSV_DELIMITER << staff.fullName
       << CSV_DELIMITER << staff.gender << CSV_DELIMITER
       << staff.dateOfBirth << CSV_DELIMITER << staff.phone
       << CSV_DELIMITER << staff.email << CSV_DELIMITER
       << QUOTATION_MARK << staff.facilityAddress << QUOTATION_MARK << std::endl;
    return os;
}




