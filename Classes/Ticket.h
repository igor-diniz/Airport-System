
#ifndef TP1_AED_TICKET_H
#define TP1_AED_TICKET_H
#include <list>
#include "Flight.h"
#include "Luggage.h"

class Ticket {
private:
    static int nextid;
    int id;
    Flight flightAssocieted;
    //Passenger passengerAssocieted;
    bool checkin = false;
    list<Luggage> ticketLuggages;

public:
    Ticket(Flight flightAssocieted);
    int getID() const;
    void setID(int id);
    Flight getFlightAssocited() const;
    void setFlightAssociated(Flight flight);
    //Passenger getPassengerAssocieted();
    bool getLuggageStatus() const;
    void setLuggageIncluded();
    int getLuggageQuantity() const;
    void addLuggage(Luggage &luggage);
    void setLuggageQuantity(int qntd, list<Luggage> Luggages);
    bool operator==(const Ticket &t) const;
    void setCheckin();
    bool getCheckin() const;
    friend ostream& operator<<(ostream& os , const Ticket& ticket);
    list<Luggage> getTicketLuggages();
};


#endif //TP1_AED_TICKET_H
