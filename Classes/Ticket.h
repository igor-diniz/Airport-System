//
// Created by Ian on 28/11/2021.
//

#ifndef TP1_AED_TICKET_H
#define TP1_AED_TICKET_H
#include <list>
#include "Flight.h"
#include "Passenger.h"

class Ticket {
private:
    int id;
    Flight flightAssocieted;
    Passenger passengerAssocieted;
    bool luggageIncluded = false;

public:
    Ticket(int id, Flight &flightAssocieted, Passenger &passengerAssocieted);
    int getID();
    Flight getFlightAssocited();
    Passenger getPassengerAssocieted();
    bool getLuggageStatus();
};


#endif //TP1_AED_TICKET_H
