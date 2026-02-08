#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

/*
 * Date:  Categorizes a real calendar date using month, day, and year values.
*/

class Date {
private:
    int month;
    int day;
    int year;

public:
    Date();
    Date(int m, int d, int y);
    Date(const Date& other);
    ~Date();

    void setMonth(int m);
    void setDay(int d);
    void setYear(int y);

    int getMonth() const;
    int getDay() const;
    int getYear() const;

    void print() const;
    std::string toString() const;
};

#endif
