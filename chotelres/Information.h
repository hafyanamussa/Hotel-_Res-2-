#ifndef INFORMATION_H
#define INFORMATION_H

#include "Date.h"
#include <string>

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

    void print() const;          // optional
    std::string toString() const; // NEW
};

#endif
