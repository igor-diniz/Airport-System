#include "Flight.h"
Flight::Flight(int id,date &arrival,date &departure,Airport &destination,Airport &origin, Plane &planeAssocieted)
{
    this->id = id;
    this->arrival = arrival;
    this->departure = departure;
    this->destination = destination;
    this->origin = origin;
    this->planeAssociated = planeAssociated;
    availableSeats = planeAssocieted.getCapacity();
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


Plane Flight::getPlaneAssocieted() const{
    return planeAssociated;
}


bool Flight::operator==(const Flight &flight)
{
    return id == flight.getId();
}