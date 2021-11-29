#ifndef TP1_AED_FLIGHT_H
#define TP1_AED_FLIGHT_H

#include "Airport.h"
#include "Plane.h"

struct date
{
    int day;
    int month;
    int year;
};
//Um voo é
//caracterizado, no mínimo, por: numero de voo, data de partida, duração do voo, origem, destino.
class Flight {
private:
    int id, availableSeats;
    date arrival,departure;
    Airport destination, origin;
    Plane planeAssociated;

public:
    Flight(){};
    Flight(int id,date &arrival,date &departure,Airport &destination,Airport &origin, Plane &planeAssocieted);
    int getId() const;
    Airport getDestination() const;
    Airport getOrigin() const;
    date getArrivalDate() const;
    date getDepartureDate() const;
    int getAvailableSeats() const;
    void setAvailableSeats(int availableSeats);
    Plane getPlaneAssocieted() const;
    bool operator == (const Flight& flight);
};


#endif //TP1_AED_FLIGHT_H
