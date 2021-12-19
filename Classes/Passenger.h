#ifndef TP1_AED_PASSENGER_H
#define TP1_AED_PASSENGER_H

#include <string>
#include "Ticket.h"
#include <list>

using namespace std;

class Passenger {
private:
    string name, passport;
    list<Ticket> tickets; //isso deveria ser lista de tickets

public:
    Passenger() = default;
    Passenger(string name, string passport);
    void setName(string name);
    void setPassport(string passport);
    void setTickets(list<Ticket> tickets);
    void removeTicket(Ticket& ticket);
    string getName() const;
    string getPassport() const;
    bool getCheckin();
    void setCheckin();
    bool buyTicket(Flight &flight, bool haslugg);
    bool buyTicket(Flight &flight, bool haslugg, const vector<pair<Passenger, bool>> &passengers);
    bool operator == (const Passenger &b);
    void Checkin(Ticket ticket);
    friend ostream& operator<<(ostream& os , const Passenger& passenger);

    list<Ticket> getTickets() const;
};
#endif //TP1_AED_PASSENGER_H