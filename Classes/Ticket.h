
#ifndef TP1_AED_TICKET_H
#define TP1_AED_TICKET_H
#include <list>
#include "Flight.h"
#include "Luggage.h"
//#include "Passenger.h"

class Ticket {
private:
    int id; //esse "id" é o equivalente ao assento do mlk???????? se for melhor trocar o nome
    Flight flightAssocieted;
    //Passenger passengerAssocieted;
    bool checkin = false;
    bool luggageIncluded = false;
    int luggageQuantity = 0;
    list<Luggage> ticketLuggages;

public:
    Ticket(int id, Flight flightAssocieted);
    int getID() const;
    void setID(int id);
    Flight getFlightAssocited() const;
    void setFlightAssociated(Flight flight);
    //Passenger getPassengerAssocieted();
    bool getLuggageStatus() const;
    void setLuggageIncluded();
    int getLuggageQuantity() const;
    void setLuggageQuantity(int qntd, vector<Luggage> Luggages);
    bool operator==(const Ticket &t) const;
    void setCheckin();
    bool getCheckin() const;

    list<Luggage> getTicketLuggages();
};


#endif //TP1_AED_TICKET_H
