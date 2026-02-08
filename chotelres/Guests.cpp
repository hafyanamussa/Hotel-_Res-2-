#include "Guests.h"
#include <sstream>

Guests::Guests() : guestCount(0), roomNumber(0) {} //Default Constructor

Guests::Guests(const Date& in, const Date& out, int room) { //Parameterized Constructor
    checkIn = in;
    checkOut = out;
    guestCount = 0;
    roomNumber = room;
}


Guests::Guests(const Guests& other) { //Copy Constructor
    checkIn = other.checkIn;
    checkOut = other.checkOut;
    guestCount = other.guestCount;
    roomNumber = other.roomNumber;

    for (int i = 0; i < guestCount; i++) {
        guests[i] = other.guests[i];
    }
}

Guests::~Guests() {} //Deconstructor

void Guests::addGuest(const Information& info) {
    if (guestCount < 4) {
        guests[guestCount++] = info;
    }
}

int Guests::getRoomNumber() const {
    return roomNumber;
}

Date Guests::getCheckIn() const {
    return checkIn;
}

Date Guests::getCheckOut() const {
    return checkOut;
}

std::string Guests::toString() const {
    std::stringstream ss;

    /* Gets information from above and returns a string describing the reservation, 
    including room number, check in and out, and a count of guests.*/

    ss << "Room: " << roomNumber << "\n";
    ss << "Check-in: " << checkIn.toString() << "\n";
    ss << "Check-out: " << checkOut.toString() << "\n";
    ss << "Guests:\n";

    for (int i = 0; i < guestCount; i++) {
        ss << " - " << guests[i].toString() << "\n"; // Add each guest string representation with -
    }

    return ss.str();
}
