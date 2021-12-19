
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
    ///
    /// \param flightAssocieted the flight this ticket refers to
    /// this constructor is used to get dates read from file manipulation
    ///
    explicit Ticket(Flight flightAssocieted);
    int getID() const;
    void setID(int id);
    Flight getFlightAssocited() const;
    void setFlightAssociated(Flight flight);
    int getLuggageQuantity() const;
    ///
    /// \param luggage luggage to me added to ticketLuggages
    ///
    void addLuggage(Luggage &luggage);
    ///
    /// \param luggage luggage to me removed from ticketLuggages
    ///
    void removeLuggage();
    ///
    /// \param t checks if the t first is equal to the ticket flight
    ///
    bool operator==(const Ticket &t) const;
    void setCheckin();
    bool getCheckin() const;
    ///
    /// \param os
    /// \param t Tickets are show in the order id - flightAssocieted - checkin - ticketLuggages
    ///
    friend ostream& operator<<(ostream& os , const Ticket& ticket);
    list<Luggage> getTicketLuggages();
};


#endif //TP1_AED_TICKET_H
