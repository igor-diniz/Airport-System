#ifndef TP1_AED_FLIGHT_H
#define TP1_AED_FLIGHT_H

#include "Airport.h"
#include "Luggage.h"
//#include "Plane.h"
#ifndef DATE_STRUCT
#define DATE_STRUCT
struct Date
{
    int day;
    int month;
    int year;
};
#endif //DATE_STRUCT
//Um voo é
//caracterizado, no mínimo, por: numero de voo, data de partida, duração do voo, origem, destino.
class Flight {
private:
    static int id;
    int availableSeats;
    Date arrival,departure;
    Airport destination, origin;
    //Plane planeAssociated;
    int capacity;
    int luggageTotal = 0;
    vector<Luggage> FlightLuggages;
public:
    Flight();
    Flight(Date &arrival,Date &departure,Airport &destination,Airport &origin, int capacity);
    int getId() const;
    Airport getDestination() const;
    Airport getOrigin() const;
    Date getArrivalDate() const;
    Date getDepartureDate() const;
    int getAvailableSeats() const;
    void setArrival(Date date);
    void setDeparture(Date date);
    void setDestination(Airport airport);
    void setOrigin(Airport airport);
    void setAvailableSeats(int availableSeats);
    //Plane getPlaneAssocieted() const;
    bool operator == (const Flight& flight);

    int getLuggageTotal();

    void setLuggageTotal(int qntd);

    void addLuggageToVector(vector<Luggage> Luggages);
};


#endif //TP1_AED_FLIGHT_H
