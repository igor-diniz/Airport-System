#include "Passenger.h"
#include <vector>

Passenger::Passenger() : ticket(0, Flight(), Passenger()) { name = "UNKNOWN"; passport = "UNKNONW";}

Passenger::Passenger(string name, string passport) : ticket(0, Flight(), Passenger()) { this->name = name; this->passport = passport;}

string Passenger::getName() {return name;}

string Passenger::getPassport() {return passport;}

bool Passenger::getCheckin() {return checkin;}

void Passenger::setCheckin(bool const checkin) {this->checkin = checkin;}

Ticket Passenger::getTicket() const{
    return ticket;
}

bool Passenger::buyTicket(Flight &flight, bool haslugg, const vector<pair<Passenger,bool>> &passengers = vector<pair<Passenger,bool>>()) {
    if (flight.getAvailableSeats() < passengers.size() + 1)
        return false;

    int id = flight.getPlaneAssocieted().getCapacity() - flight.getAvailableSeats() + 1;

    flight.setAvailableSeats(flight.getAvailableSeats() - 1);

    this->ticket(id, flight, this); //Maybe ID for Tickets doesn't make sense, the PDF doesn't specify anything

    if (haslugg) ticket.setLuggageIncluded;

    if(passengers.empty())
        return true;

    for(auto iter : passengers)
    {
        id++;
        iter.first.ticket(id,flight,this);
        if (iter.second) ticket.setLuggageIncluded;
        flight.setAvailableSeats(flight.getAvailableSeats() - 1);
    }

    return true;
}
