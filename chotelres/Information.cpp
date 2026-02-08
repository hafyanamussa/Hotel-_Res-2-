#include "Information.h"
#include <cstring>
#include <sstream>
#include <iostream>

Information::Information() { //Default Constructor
    strcpy_s(firstName, 30, "");
    strcpy_s(lastName, 30, "");
}

Information::Information(const char* f, const char* l, const Date& dob) { //Parameterized Constructor
    dateOfBirth = dob;
    strcpy_s(firstName, 30, f);
    strcpy_s(lastName, 30, l);
}

Information::Information(const Information& other) { //Copy Constructor
    dateOfBirth = other.dateOfBirth;
    strcpy_s(firstName, 30, other.firstName);
    strcpy_s(lastName, 30, other.lastName);
}


Information::~Information() {} //Deconstructor

void Information::print() const {
    std::cout << toString();
}

/* Prints a formatted string with the customers name and date of birth */

std::string Information::toString() const {
    std::stringstream ss;
    ss << firstName << " " << lastName
        << " (DOB: " << dateOfBirth.toString() << ")";
    return ss.str();
}
