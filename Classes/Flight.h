#ifndef TP1_AED_FLIGHT_H
#define TP1_AED_FLIGHT_H

#include "Airport.h"
#include "Luggage.h"
#include "Date.h"
//#include "Plane.h"
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
    list<Luggage> flightLuggages;
    list<Luggage> luggagesOutCar;

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
    void setLuggagesOutCar(list<Luggage> &alista);
    int getCapacity() const;
    bool operator==(const Flight &f) const;
};


#endif //TP1_AED_FLIGHT_H
