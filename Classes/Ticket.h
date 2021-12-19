
#ifndef TP1_AED_TICKET_H
#define TP1_AED_TICKET_H
#include <list>
#include "Flight.h"
#include "Luggage.h"

class Ticket {
private:
    static int nextid; ///incrementor for next ticket creation
    int id; ///actual ticket id
    Flight flightAssocieted;
    bool checkin = false;
    list<Luggage> ticketLuggages; ///Luggages the passenger is taking on this flight
                                  ///This was created as a list of luggages instead of a simple int so that there
                                  ///was more control over the luggages location in case one specific needed to be found

public:
    explicit Ticket(Flight flightAssocieted);
    int getID() const;
    void setID(int id);
    Flight getFlightAssocited() const;
    void setFlightAssociated(Flight flight);
    int getLuggageQuantity() const;
    void addLuggage(Luggage &luggage);
    void removeLuggage();
    bool operator==(const Ticket &t) const;
    void setCheckin();
    bool getCheckin() const;
    friend ostream& operator<<(ostream& os , const Ticket& ticket);
    list<Luggage> getTicketLuggages();
};


#endif //TP1_AED_TICKET_H
