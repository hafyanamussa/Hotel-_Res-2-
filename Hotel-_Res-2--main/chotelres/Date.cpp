#include "Date.h"
#include <sstream>

Date::Date() : month(1), day(1), year(2026) {}

Date::Date(int m, int d, int y) : month(m), day(d), year(y) {}

Date::Date(const Date& other) {
    month = other.month;
    day = other.day;
    year = other.year;
}

Date::~Date() {}

void Date::setMonth(int m) { month = m; }
void Date::setDay(int d) { day = d; }
void Date::setYear(int y) { year = y; }

int Date::getMonth() const { return month; }
int Date::getDay() const { return day; }
int Date::getYear() const { return year; }

void Date::print() const {
    std::cout << month << "/" << day << "/" << year;
}

std::string Date::toString() const {
    std::stringstream ss;
    ss << month << "/" << day << "/" << year;
    return ss.str();
}
