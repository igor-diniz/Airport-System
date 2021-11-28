//
// Created by Ian on 25/11/2021.
//

#include "Flight.h"
Flight::Flight(int id,date arrival,date departure,Airport destination,Airport origin)
{
    this->id = id;
    this->arrival = arrival;
    this->departure = departure;
    this->destination = destination;
    this->origin = origin;
}

int Flight::GetId() const {
    return id;
}

date Flight::GetArrivalDate() const
{
    return arrival;
}

date Flight::GetDepartureDate() const
{
    return departure;
}

Airport Flight::GetDestination() const
{
    return destination;
}

Airport Flight::GetOrigin() const
{
    return origin;
}

bool Flight::operator==(const Flight &flight)
{
    return id == flight.GetId();
}

/*Flight& Flight::operator=(const Flight &flight)
{
    if (this == &flight)
        return *this;
    id = flight.GetId();
    arrival = flight.GetArrivalDate();
    departure = flight.GetDepartureDate();
    destination = flight.GetDestination();
    origin = flight.GetOrigin();

    return *this;
}*/