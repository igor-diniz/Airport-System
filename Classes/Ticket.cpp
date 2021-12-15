#include "Ticket.h"
#include "Flight.h"

Ticket::Ticket(int id, Flight flightAssocieted){
    this->id = id;
    this->flightAssocieted = flightAssocieted;
    //this->passengerAssocieted = passengerAssocieted;
}

Flight Ticket::getFlightAssocited() const{return flightAssocieted;}

//Passenger Ticket::getPassengerAssocieted() {return passengerAssocieted;}

int Ticket::getID() const{return id;}

bool Ticket::getLuggageStatus() const{return luggageIncluded;}

void Ticket::setLuggageIncluded() {luggageIncluded = true;}

void Ticket::setFlightAssociated(Flight flight) { flightAssocieted = flight;}

void Ticket::setID(int id) {this->id = id;}

int Ticket::getLuggageQuantity() const{return luggageQuantity;}

void Ticket::setLuggageQuantity(int qntd) {
    getFlightAssocited().setLuggageTotal(-luggageQuantity);
    luggageQuantity = qntd;
    getFlightAssocited().setLuggageTotal(luggageQuantity);
}

