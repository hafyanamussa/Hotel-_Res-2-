#include "Reservation_Manager.h"
#include <iostream>

int main() {
    Reservation_Manager manager;

    // check-in and check-out dates

    Date in(3, 1, 2026);
    Date out(3, 4, 2026);

    Guests g(in, out, 5);
    g.addGuest(Information("Amir", "Vasseghi", Date(3, 1, 2000)));
    g.addGuest(Information("Mussa", "Hafyana", Date(2, 2, 2001)));

    // create a reservation request for 3 nights

    Guests_Res_Request* req = new Guests_Res_Request(g, 3);

    // Reserve the room attemps (reserve or cancel)

    int id = manager.processReservation(req);

    if (id != -1) {
        std::cout << "Reservation successful!\n";
        manager.printReservation(id);
    }
    else {
        std::cout << "Reservation failed\n";
    }

    manager.cancelReservation(id);
    std::cout << "Reservation cancelled\n";

    return 0;
}
