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

int Flight::GetId()
{
    return id;
}

date Flight::GetArrivalDate()
{
    return arrival;
}

date Flight::GetDepartureDate()
{
    return departure;
}

Airport Flight::GetDestination()
{
    return destination;
}

Airport Flight::GetOrigin()
{
    return origin;
}