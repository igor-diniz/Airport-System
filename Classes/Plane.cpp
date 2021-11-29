#include "Plane.h"

Plane::Plane(int capacity,string registration,string type)
{
    this->capacity = capacity;
    this->registration = registration;
    this->type = type;
    flights = list<Flight>();
}

void Plane::addFlight(Flight &flight)
{
    flights.push_back(flight);
}

void Plane::addFlight(list<Flight> &flight)
{
    for (Flight a: flight)
    {
        flights.push_back(a);
    }
}

void Plane::deleteFlight(int id)
{
    for (Flight a: flights)
    {
        if(a.getId() == id)
        {
            flights.remove(a);
        }
    }
}

int Plane::getCapacity() const
{
    return capacity;
}

list<Flight> Plane::getFlights() const
{
    return flights;
}

string Plane::getRegistration() const
{
    return registration;
}

string Plane::getType() const
{
    return type;
}