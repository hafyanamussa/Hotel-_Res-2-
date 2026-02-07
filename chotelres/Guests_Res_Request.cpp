#include "Guests_Res_Request.h"
#include <iostream>

int Guests_Res_Request::counter = 0;

Guests_Res_Request::Guests_Res_Request(const Guests& g, int nights) {
    guests = g;
    numberOfNights = nights;
    reservationID = ++counter;
}


Guests_Res_Request::~Guests_Res_Request() {}

int Guests_Res_Request::getReservationID() const {
    return reservationID;
}

int Guests_Res_Request::getNumberOfNights() const {
    return numberOfNights;
}

Guests Guests_Res_Request::getGuests() const {
    return guests;
}

void Guests_Res_Request::print() const {
    std::cout << "Reservation ID: " << reservationID << "\n";
    std::cout << guests.toString();
    std::cout << "Nights: " << numberOfNights << "\n";
}
