//
// Created by Ian on 28/11/2021.
//

#include "Ticket.h"

Ticket::Ticket(int id, Flight flightAssocieted, Passenger passengerAssocieted){
    this->id = id;
    this->flightAssocieted = flightAssocieted;
    this->passengerAssocieted = passengerAssocieted;
}

Flight Ticket::getFlightAssocited() {return flightAssocieted;}

Passenger Ticket::getPassengerAssocieted() {return passengerAssocieted;}

int Ticket::getID() {return id;}

bool Ticket::getLuggageStatus() {return luggageIncluded;}
