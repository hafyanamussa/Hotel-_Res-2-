#include "Date.h"
#include <sstream>

Date::Date() : month(1), day(1), year(2026) {} //Default Constructor

Date::Date(int m, int d, int y) : month(m), day(d), year(y) {} //Parameterized Constructor

Date::Date(const Date& other) { //Copy Constructor
    month = other.month;
    day = other.day;
    year = other.year;
}

Date::~Date() {} //Deconstructor

/*
 * Update date.
 */

void Date::setMonth(int m) { month = m; }
void Date::setDay(int d) { day = d; }
void Date::setYear(int y) { year = y; }

/*
 * Return date changes.
 */

int Date::getMonth() const { return month; }
int Date::getDay() const { return day; }
int Date::getYear() const { return year; }

void Date::print() const {
    std::cout << month << "/" << day << "/" << year;
}

std::string Date::toString() const {
    std::stringstream ss;
    ss << month << "/" << day << "/" << year;  //Returns the date in string format (MM/DD/YYYY)
    return ss.str();
}
