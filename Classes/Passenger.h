#ifndef TP1_AED_PASSENGER_H
#define TP1_AED_PASSENGER_H

#include <string>
#include "Ticket.h"
#include <list>

using namespace std;

class Passenger {
private:
    string name, passport;
    list<Ticket> tickets; ///All tickets bought/added to this passenger

public:
    Passenger() = default;
    Passenger(string name, string passport);
    void setName(string name);
    void setPassport(string passport);
    void removeTicket(Ticket& ticket);
    string getName() const;
    string getPassport() const;
    list<Ticket> getTickets() const;
    bool addTicket(Ticket &ticket);
    bool operator == (const Passenger &b);
    friend ostream& operator<<(ostream& os , const Passenger& passenger);
};
#endif //TP1_AED_PASSENGER_H