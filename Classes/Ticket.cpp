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

void Ticket::setLuggageQuantity(int qntd, list<Luggage> luggages) {
    luggageQuantity = qntd;
    flightAssocieted.setLuggageTotal(luggageQuantity);
    for (auto l : luggages){
        ticketLuggages.push_back(l);
    }
    flightAssocieted.addLuggageToVector(luggages);
}

bool Ticket::operator==(const Ticket &t) const{
    return (id == t.getID() && flightAssocieted == t.getFlightAssocited()
    && luggageIncluded == t.getLuggageStatus() && ticketLuggages.size() == t.getLuggageQuantity());
}

void Ticket::setCheckin() {checkin = true;}

bool Ticket::getCheckin() const {return checkin;}

list<Luggage> Ticket::getTicketLuggages(){return ticketLuggages;}