#pragma once
#ifndef GUESTS_RES_REQUEST_H
#define GUESTS_RES_REQUEST_H

#include "Guests.h"

/*
 * Guest Reservation Request: Allows customers to book rooms in hotel and get provided with a custom identification (reservationID), and well as counting number of days for stay.
 */

class Guests_Res_Request {
private:
    static int counter;
    int reservationID;
    Guests guests;
    int numberOfNights;

public:
    Guests_Res_Request(const Guests& g, int nights);
    ~Guests_Res_Request();

    int getReservationID() const;
    int getNumberOfNights() const;
    Guests getGuests() const;

    void print() const;
};

#endif
