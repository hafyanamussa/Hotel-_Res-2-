#include "Reservation_Manager.h"
#include <iostream>

Reservation_Manager::Reservation_Manager()
    : max_no_of_nights(7), no_of_rooms(20), requestCount(0)
{
    // Array space of 50 for requests
    arr = new Guests_Res_Request * [50];

    // 0 = FREE
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 20; j++) {
            calendar[i][j] = 0;
        }
    }
}

Reservation_Manager::~Reservation_Manager() {
    // delete all requests
    for (int i = 0; i < requestCount; i++) {
        delete arr[i];
    }
    delete[] arr;
}

int Reservation_Manager::processReservation(Guests_Res_Request* req) {
    // pointers
    Guests_Res_Request& request = *req;

    int roomIndex = request.getGuests().getRoomNumber() - 1; // room # to index
    int nights = request.getNumberOfNights();

    // basic safety checks
    if (roomIndex < 0 || roomIndex >= no_of_rooms || nights < 1 || nights > max_no_of_nights) {
        delete req;
        return -1;
    }

    // check if the room is available during request
    for (int day = 0; day < nights; day++) {
        if (calendar[day][roomIndex] != 0) {
            delete req;
            return -1;
        }
    }

    // reserve the room using reservation id
    int id = request.getReservationID();
    for (int day = 0; day < nights; day++) {
        calendar[day][roomIndex] = id;
    }

    // store request
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
    // remove reservation id from calendar
    for (int day = 0; day < 7; day++) {
        for (int room = 0; room < 20; room++) {
            if (calendar[day][room] == reservationID) {
                calendar[day][room] = 0;
            }
        }
    }

    // delete the request and remove from array
    for (int i = 0; i < requestCount; i++) {
        if (arr[i]->getReservationID() == reservationID) {
            delete arr[i];

            // move last element into this spot
            arr[i] = arr[requestCount - 1];
            requestCount--;

            return;
        }
    }
}