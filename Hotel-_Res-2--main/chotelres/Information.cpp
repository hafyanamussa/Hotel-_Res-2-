#include "Information.h"
#include <cstring>
#include <sstream>
#include <iostream>

Information::Information() {
    strcpy_s(firstName, 30, "");
    strcpy_s(lastName, 30, "");
}

Information::Information(const char* f, const char* l, const Date& dob) {
    dateOfBirth = dob;
    strcpy_s(firstName, 30, f);
    strcpy_s(lastName, 30, l);
}

Information::Information(const Information& other) {
    dateOfBirth = other.dateOfBirth;
    strcpy_s(firstName, 30, other.firstName);
    strcpy_s(lastName, 30, other.lastName);
}


Information::~Information() {}

void Information::print() const {
    std::cout << toString();
}

std::string Information::toString() const {
    std::stringstream ss;
    ss << firstName << " " << lastName
        << " (DOB: " << dateOfBirth.toString() << ")";
    return ss.str();
}
