#include "Ticket.h"
#include "Flight.h"
int Ticket::nextid = 0;
Ticket::Ticket(Flight flightAssocieted){
    nextid++;
    id = nextid;
    this->flightAssocieted = flightAssocieted;
}

Flight Ticket::getFlightAssocited() const{return flightAssocieted;}

//Passenger Ticket::getPassengerAssocieted() {return passengerAssocieted;}

int Ticket::getID() const{return id;}

void Ticket::setFlightAssociated(Flight flight) { flightAssocieted = flight;}

void Ticket::setID(int id) {this->id = id;}

int Ticket::getLuggageQuantity() const{return ticketLuggages.size();}

bool Ticket::operator==(const Ticket &t) const{
    return id == t.getID();
}

void Ticket::setCheckin() {checkin = true;}

void Ticket::addLuggage(Luggage& luggage)
{
    ticketLuggages.push_back(luggage);
    flightAssocieted.addLuggageToQueue(luggage);
}

bool Ticket::getCheckin() const {return checkin;}

list<Luggage> Ticket::getTicketLuggages(){return ticketLuggages;}