#include "Flight.h"
int Flight::id = 0;
Flight::Flight()
{
    availableSeats = 0;
    arrival = date();
    departure = date();
    destination = Airport();
    origin = Airport();
    capacity = 0;
}

Flight::Flight(date &arrival,date &departure,Airport &destination,Airport &origin, int capacity)
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

date Flight::getArrivalDate() const
{
    return arrival;
}

date Flight::getDepartureDate() const
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