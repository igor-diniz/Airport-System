#include "Ticket.h"

Ticket::Ticket(int id, Flight flightAssocieted){
    this->id = id;
    this->flightAssocieted = flightAssocieted;
    //this->passengerAssocieted = passengerAssocieted;
}

Flight Ticket::getFlightAssocited() {return flightAssocieted;}

//Passenger Ticket::getPassengerAssocieted() {return passengerAssocieted;}

int Ticket::getID() {return id;}

bool Ticket::getLuggageStatus() {return luggageIncluded;}

void Ticket::setLuggageIncluded() {luggageIncluded = true;}
