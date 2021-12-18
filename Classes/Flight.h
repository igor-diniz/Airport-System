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
    Flight(Date &departure,Airport &origin); //just with the key
    Flight(Date &departure,Time duration,Airport &origin,Airport &destination,int availableSeats);
    int getId() const;
    Airport getDestination() const;
    Airport getOrigin() const;
    Date getDepartureDate() const;
    int getAvailableSeats() const;
    void setDeparture(Date date);
    void setDestination(Airport airport);
    void setOrigin(Airport airport);
    void setAvailableSeats(int availableSeats);
    //Plane getPlaneAssocieted() const;
    void setDuration(Time duration);
    bool equals (const Flight& flight) const;
    int getLuggageTotal();
    //void setLuggageTotal(int qntd);
    void addLuggageToQueue(list<Luggage> Luggages);
    void setLuggagesOutCar(list<Luggage> &alista);
    bool operator==(const Flight &f) const;
    Time getDuration() const;
    friend ostream& operator<<(ostream& os , const Flight& fli);
    void luggagesToCar(LuggageCar Car);
};


#endif //TP1_AED_FLIGHT_H
