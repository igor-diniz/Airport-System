#include "Flight.h"
int Flight::id = 0;
Flight::Flight()
{
    availableSeats = 0;
    arrival = Date();
    departure = Date();
    destination = Airport();
    origin = Airport();
    capacity = 0;
}

Flight::Flight(Date &arrival,Date &departure,Airport &destination,Airport &origin, int capacity)
{
    id++;
    this->arrival = arrival;
    this->departure = departure;
    this->destination = destination;
    this->origin = origin;
    this->capacity = capacity;
    availableSeats = capacity;
}

int Flight::getId() const {
    return id;
}

Date Flight::getArrivalDate() const
{
    return arrival;
}

Date Flight::getDepartureDate() const
{
    return departure;
}

Airport Flight::getDestination() const
{
    return destination;
}

Airport Flight::getOrigin() const
{
    return origin;
}

int Flight::getAvailableSeats() const {
    return availableSeats;
}

void Flight::setAvailableSeats(int availableSeats){
    this->availableSeats = availableSeats;
}


//Plane Flight::getPlaneAssocieted() const{
    //return planeAssociated;
//}


bool Flight::operator==(const Flight &flight)
{
    return id == flight.getId();
}

void Flight::setArrival(Date date) {arrival = date;}

void Flight::setDeparture(Date date) {departure = date;}

void Flight::setDestination(Airport airport) {destination = airport;}

void Flight::setOrigin(Airport airport) {origin = airport;}