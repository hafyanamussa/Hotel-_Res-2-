#ifndef GUESTS_H
#define GUESTS_H

#include "Information.h"
#include <string>

class Guests {
private:
    Date checkIn;
    Date checkOut;
    Information guests[4];
    int guestCount;
    int roomNumber;

public:
    Guests();
    Guests(const Date& in, const Date& out, int room);
    Guests(const Guests& other);
    ~Guests();

    void addGuest(const Information& info);

    int getRoomNumber() const;
    Date getCheckIn() const;
    Date getCheckOut() const;

    std::string toString() const;
};

#endif
