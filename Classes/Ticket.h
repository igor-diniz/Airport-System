
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
    bool luggageIncluded = false;
    int luggageQuantity = 0;
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
    void setLuggageQuantity(int qntd, list<Luggage> Luggages);
    bool operator==(const Ticket &t) const;
    void setCheckin();
    bool getCheckin() const;

    list<Luggage> getTicketLuggages();
};


#endif //TP1_AED_TICKET_H
