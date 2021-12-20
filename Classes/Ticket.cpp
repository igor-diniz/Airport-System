#include "Ticket.h"
#include <iostream>
#include <sstream>
int Ticket::nextid = 0;
Ticket::Ticket(Flight& flightAssocieted){
    nextid++;
    id = nextid;
    this->flightAssocieted = flightAssocieted;
    flightAssocieted.reduceAvailableSeats();
}

Ticket::Ticket(string CSVticket)
{
    stringstream ssTicket;
    string strTickeID, strFlightID;

    ssTicket << CSVticket;

    getline(ssTicket, strTickeID, ',');
    getline(ssTicket, strFlightID);

    id = stoi(strTickeID);
    flightAssocieted.setID(stoi(strFlightID));
}

Flight Ticket::getFlightAssocited() const{return flightAssocieted;}

int Ticket::getID() const{return id;}

void Ticket::setFlightAssociated(Flight flight) { flightAssocieted = flight;}

void Ticket::setID(int id) {this->id = id;}

int Ticket::getLuggageQuantity() const{return ticketLuggages.size();}

bool Ticket::operator==(const Ticket &t) const{
    return flightAssocieted == t.getFlightAssocited();
}

void Ticket::setCheckin() {
    for(auto l: ticketLuggages){
        flightAssocieted.addLuggageToQueue(l);
    }
    checkin = true;
}

void Ticket::removeLuggage()
{
    if(!ticketLuggages.empty())
    ticketLuggages.pop_front();
}

void Ticket::addLuggage(Luggage& luggage)
{
    ticketLuggages.push_back(luggage);
}

bool Ticket::getCheckin() const {return checkin;}

list<Luggage> Ticket::getTicketLuggages(){return ticketLuggages;}

ostream& operator<<(ostream& os , const Ticket& ticket)
{
    os << ticket.getID() << " - " << ticket.getFlightAssocited();
    return os;
}