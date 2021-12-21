#ifndef TP1_AED_FLIGHT_H
#define TP1_AED_FLIGHT_H

#include "Airport.h"
#include "Luggage.h"
#include "Date.h"
#include "LuggageCar.h"

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
    ///
    /// \param CSVflight Flight in string format
    /// this constructor is used to get flight read from file manipulation
    ///
    explicit Flight(string CSVflight);
    Flight();
    ///
    /// \param departure Date of departure
    /// \param origin Airport of origin
    /// this constructor is created only with the Flight key (DEPARTURE,ORIGIN)
    ///
    Flight(Date &departure,Airport &origin); //just with the key
    ///
    /// \param departure a Date
    /// \param duration the flight duration
    /// \param origin Airport of origin
    /// \param destination Airport of departure
    /// \param availableSeats how many seats does the flight have (this is taken by the plane capacity)
    /// this is the complete constructor
    ///
    Flight(Date &departure,Time duration,Airport &origin,Airport &destination,int availableSeats);
    int getId() const;
    void setID(const int flightID);
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
    ///
    /// \param flight Flight to be compared
    /// compare a flight with other using only the Key
    ///
    bool equals (const Flight& flight) const;
    ///
    /// \param Luggages a Luggage
    /// put the Luggage into both flight queues
    ///
    void addLuggageToQueue(Luggage luggage);
    ///
    /// \param f a Flight
    /// compare flights by ID
    ///
    bool operator==(const Flight &f) const;
    Time getDuration() const;
    ///
    /// \param os
    /// \param fli Flights are showed in the form Id - departure - duration - origin - destination - available seats
    ///
    friend ostream& operator<<(ostream& os , const Flight& fli);
    ///
    /// \param Car a LuggageCar
    /// take the Luggages from luggageoutcar queue and put in the car until the car is full
    ///
    void luggagesToCar(LuggageCar& Car);
    ///
    /// Decrease the available seats by 1
    ///
    void reduceAvailableSeats();
};


#endif //TP1_AED_FLIGHT_H
