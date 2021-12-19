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
    ///
    /// \param name the Passenger name
    /// \param passport the Passenger passport (PRIMARY KEY)
    Passenger(string name, string passport);
    void setName(string name);
    void setPassport(string passport);
    ///
    /// \param ticket ticket that will be removed from the passenger
    ///
    void removeTicket(Ticket& ticket);
    string getName() const;
    string getPassport() const;
    list<Ticket> getTickets() const;
    ///
    /// \param ticket
    /// puts the Ticket into the Passenger list of tickets
    ///
    bool addTicket(Ticket &ticket);
    ///
    /// \param passenger passengers are compared by passport
    ///
    bool operator == (const Passenger &passenger);
    ///
    /// \param os
    /// \param passenger passengers are showed in the form Name - Passport
    ///
    friend ostream& operator<<(ostream& os , const Passenger& passenger);
};
#endif //TP1_AED_PASSENGER_H