#include "Guests.h"
#include <sstream>

Guests::Guests() : guestCount(0), roomNumber(0) {}

Guests::Guests(const Date& in, const Date& out, int room) {
    checkIn = in;
    checkOut = out;
    guestCount = 0;
    roomNumber = room;
}


Guests::Guests(const Guests& other) {
    checkIn = other.checkIn;
    checkOut = other.checkOut;
    guestCount = other.guestCount;
    roomNumber = other.roomNumber;

    for (int i = 0; i < guestCount; i++) {
        guests[i] = other.guests[i];
    }
}

Guests::~Guests() {}

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

    ss << "Room: " << roomNumber << "\n";
    ss << "Check-in: " << checkIn.toString() << "\n";
    ss << "Check-out: " << checkOut.toString() << "\n";
    ss << "Guests:\n";

    for (int i = 0; i < guestCount; i++) {
        ss << " - " << guests[i].toString() << "\n";
    }

    return ss.str();
}
