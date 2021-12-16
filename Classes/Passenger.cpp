#include "Passenger.h"
#include <vector>

Passenger::Passenger(string name, string passport) : ticket(0, Flight()) { this->name = name; this->passport = passport;}

string Passenger::getName() {return name;}

string Passenger::getPassport() {return passport;}

bool Passenger::getCheckin() {return checkin;}

void Passenger::setCheckin() {this->checkin = true;}

void Passenger::setName(string name) {this->name = name;}

void Passenger::setPassport(string passport) {this->passport = passport; }

Ticket Passenger::getTicket() const{
    return ticket;
}

bool Passenger::buyTicket(Flight &flight, bool haslugg) {
    if(flight.getAvailableSeats() < 1)
        return false;

    int id = flight.getCapacity() - flight.getAvailableSeats() + 1;

    ticket = Ticket(id, flight);

    if(haslugg)
        ticket.setLuggageIncluded();

    flight.setAvailableSeats(flight.getAvailableSeats() - 1);
    return true;


}

bool Passenger::buyTicket(Flight &flight, bool haslugg, const vector<pair<Passenger,bool>> &passengers) {
    if (flight.getAvailableSeats() < passengers.size() + 1)
        return false;

    flight.setAvailableSeats(flight.getAvailableSeats() - 1);

    //this->ticket(0, flight, this); //Maybe ID for Tickets doesn't make sense, the PDF doesn't specify anything

    //if (haslugg) ticket.setLuggageIncluded;
    int id = flight.getCapacity() - flight.getAvailableSeats() + 1;

    ticket = Ticket(id, flight);
    if(haslugg)
        ticket.setLuggageIncluded();

    for(auto p : passengers)
    {
        id++;
        Passenger anotherPassenger(p.first);
        bool isLuggageIncluded = p.second;
        anotherPassenger.ticket = Ticket(id, flight);
        if (isLuggageIncluded)
        {
            anotherPassenger.ticket.setLuggageIncluded();
        }
        flight.setAvailableSeats(flight.getAvailableSeats() - 1);
    }
    return true;
}