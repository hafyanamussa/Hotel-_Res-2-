#ifndef INFORMATION_H
#define INFORMATION_H

#include "Date.h"
#include <string>

/*
 * Information: Tracks and stores customer information such as first name, last name, and date of birth.
 */

class Information {
private:
    char firstName[30];
    char lastName[30];
    Date dateOfBirth;

public:
    Information();
    Information(const char* f, const char* l, const Date& dob);
    Information(const Information& other);
    ~Information();

    void print() const;
    std::string toString() const;
};

#endif
