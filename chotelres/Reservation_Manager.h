#pragma once
#ifndef RESERVATION_MANAGER_H
#define RESERVATION_MANAGER_H

#include "Guests_Res_Request.h"

class Reservation_Manager {
private:
    int max_no_of_nights;
    int no_of_rooms;
    Guests_Res_Request** arr;
    int requestCount;

    int calendar[7][20];

public:
    Reservation_Manager();
    ~Reservation_Manager();

    int processReservation(Guests_Res_Request* req);
    void printReservation(int reservationID) const;
    void cancelReservation(int reservationID);
};

#endif
