#ifndef TP1_AED_PASSENGER_H
#define TP1_AED_PASSENGER_H

#include <string>
#include <vector>
#include "Flight.h"
#include "Ticket.h"
#include <list>

using namespace std;

class Passenger {
private:
    string name, passport;
    bool checkin = false;
    Ticket ticket;

public:
    Passenger() = default;
    Passenger(string name, string passport);
    void setName(string name);
    void setPassport(string passport);
    string getName();
    string getPassport();
    bool getCheckin();
    void setCheckin();
    Ticket getTicket() const;
    bool buyTicket(Flight &flight, bool haslugg);
    bool buyTicket(Flight &flight, bool haslugg, const vector<pair<Passenger, bool>> &passengers);
};
#endif //TP1_AED_PASSENGER_H