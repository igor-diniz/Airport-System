#include "Passenger.h"
#include <vector>

Passenger::Passenger(string name, string passport){ this->name = name; this->passport = passport;}

string Passenger::getName() const {return name;}

string Passenger::getPassport() const {return passport;}

void Passenger::setName(string name) {this->name = name;}

void Passenger::setPassport(string passport) {this->passport = passport; }

list<Ticket> Passenger::getTickets() const{
    return tickets;
}

bool Passenger::addTicket(Ticket &ticket) {
    if(ticket.getFlightAssocited().getAvailableSeats() < 1)
        return false;
    tickets.push_back(ticket);
    return true;
}

void Passenger::removeTicket(Ticket &ticket)
{
    tickets.remove(ticket);
}

bool Passenger::operator == (const Passenger &passenger){
    return passport == passenger.getPassport();
};

ostream& operator<<(ostream& os , const Passenger& passenger)
{
    os << passenger.getName() << " - " << passenger.getPassport();
    return os;
}