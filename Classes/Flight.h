#ifndef TP1_AED_FLIGHT_H
#define TP1_AED_FLIGHT_H

#include "Airport.h"
#include "Luggage.h"
#include "Date.h"
#include "LuggageCar.h"
//#include "Plane.h"
//Um voo é
//caracterizado, no mínimo, por: numero de voo, data de partida, duração do voo, origem, destino.
class Flight {
private:
    static int id;
    int availableSeats;
    Date departure;
    Time duration;
    Airport destination, origin;
    //Plane planeAssociated;
    queue<Luggage> flightLuggages;
    queue<Luggage> luggagesOutCar;

public:
    Flight();
    Flight(Date &departure,Date &arrival,Airport &origin,Airport &destination,Time duration,int availableSeats);
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
    void addLuggageToQueue(list<Luggage> Luggages);
    void setLuggagesOutCar(list<Luggage> &alista);
    bool operator==(const Flight &f) const;

    void luggagesToCar(LuggageCar Car);
};


#endif //TP1_AED_FLIGHT_H
