#ifndef TP1_AED_FLIGHT_H
#define TP1_AED_FLIGHT_H

#include "Airport.h"
struct date
{
    int day;
    int month;
    int year;
};
//Um voo é
//caracterizado, no mínimo, por: numero de voo, data de partida, duração do voo, origem, destino.
class Flight {
    int id;
    date arrival,departure;
    Airport destination, origin;

public:
    Flight(){};
    Flight(int id,date arrival,date departure,Airport destination,Airport origin);
    int GetId() const;
    Airport GetDestination() const;
    Airport GetOrigin() const;
    date GetArrivalDate() const;
    date GetDepartureDate() const;
    bool operator == (const Flight& flight);
};


#endif //TP1_AED_FLIGHT_H
