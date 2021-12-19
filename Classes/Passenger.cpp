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

bool Passenger::buyTicket(Flight &flight, bool haslugg) {
    if(flight.getAvailableSeats() < 1)
        return false;
    Ticket ticket(flight);
    if(haslugg) ticket.setLuggageIncluded();
    tickets.push_back(ticket);
    flight.setAvailableSeats(flight.getAvailableSeats() - 1);
    return true;
}

void Passenger::removeTicket(Ticket &ticket)
{
    tickets.remove(ticket);
}

/*bool Passenger::buyTicket(Flight &flight, bool haslugg, const vector<pair<Passenger,bool>> &passengers) {
    if (flight.getAvailableSeats() < passengers.size() + 1)
        return false;

    int id = flight.getAvailableSeats() - flight.getAvailableSeats() + 1;
    flight.setAvailableSeats(flight.getAvailableSeats() - 1);

    //this->ticket(0, flight, this); //Maybe ID for Tickets doesn't make sense, the PDF doesn't specify anything

    //if (haslugg) ticket.setLuggageIncluded;

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
}*/
void Passenger::Checkin(Ticket ticket){
    ticket.getFlightAssocited().addLuggageToQueue(ticket.getTicketLuggages());
    ticket.setCheckin();
}

void Passenger::setTickets(list<Ticket> tickets){
    this->tickets = tickets;
}

bool Passenger::operator == (const Passenger &b){
    return passport == b.getPassport();
};

ostream& operator<<(ostream& os , const Passenger& passenger)
{
    os << passenger.getName() << " - " << passenger.getPassport();
    return os;
}