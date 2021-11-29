#ifndef TP1_AED_PASSENGER_H
#define TP1_AED_PASSENGER_H

#include <string>
#include <vector>
#include "Flight.h"
#include "Ticket.h"

using namespace std;

class Passenger {
private:
    string name, passport;
    bool checkin = false;
    Ticket ticket;

public:
    Passenger();
    Passenger(string name, string passport);
    inline void setName(string name) { this->name = name; }
    inline void setPassport(string passport) { this->passport = passport; }
    string getName();
    string getPassport();
    bool getCheckin();
    void setCheckin(bool const checkin);
    Ticket getTicket() const;
    bool buyTicket(Flight &flight, const vector<Passenger> &passengers);
};


#endif //TP1_AED_PASSENGER_H
