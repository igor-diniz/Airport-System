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

    static int nextid; ///Incrementor for next flight creation
    int id; ///Actual flight id
    int availableSeats; ///Total of empty seats on the flight
    Date departure;
    Time duration; ///Flight duration
    Airport destination, origin;
    queue<Luggage> flightLuggages; ///List of luggages that are going in the flight
    queue<Luggage> luggagesOutCar; ///List of luggages that still need to be assigned to a car

public:
    explicit Flight(string CSVflight);
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
    queue<Luggage> getLuggagesOutCar() const ;
    void setDuration(Time duration);
    bool equals (const Flight& flight) const;
    void addLuggageToQueue(Luggage Luggages);
    bool operator==(const Flight &f) const;
    Time getDuration() const;
    friend ostream& operator<<(ostream& os , const Flight& fli);
    void luggagesToCar(LuggageCar& Car);
    void reduceAvailableSeats();
};


#endif //TP1_AED_FLIGHT_H
