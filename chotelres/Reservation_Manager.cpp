#include "Reservation_Manager.h"
#include <iostream>

Reservation_Manager::Reservation_Manager() {
    max_no_of_nights = 7;
    no_of_rooms = 20;
    requestCount = 0;


    arr = new Guests_Res_Request * [50];

    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 20; j++)
            calendar[i][j] = 0;
}

Reservation_Manager::~Reservation_Manager() {
    for (int i = 0; i < requestCount; i++)
        delete arr[i];
    delete[] arr;
}

int Reservation_Manager::processReservation(Guests_Res_Request* req) {
    int room = req->getGuests().getRoomNumber() - 1;
    int nights = req->getNumberOfNights();

    for (int i = 0; i < nights; i++) {
        if (calendar[i][room] != 0) {
            delete req;
            return -1;
        }
    }

    int id = req->getReservationID();
    for (int i = 0; i < nights; i++)
        calendar[i][room] = id;

    arr[requestCount++] = req;
    return id;
}

void Reservation_Manager::printReservation(int reservationID) const {
    for (int i = 0; i < requestCount; i++) {
        if (arr[i]->getReservationID() == reservationID) {
            arr[i]->print();
            return;
        }
    }
    std::cout << "Reservation not found\n";
}

void Reservation_Manager::cancelReservation(int reservationID) {
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 20; j++)
            if (calendar[i][j] == reservationID)
                calendar[i][j] = 0;

    for (int i = 0; i < requestCount; i++) {
        if (arr[i]->getReservationID() == reservationID) {
            delete arr[i];
            arr[i] = arr[--requestCount];
            return;
        }
    }
}
