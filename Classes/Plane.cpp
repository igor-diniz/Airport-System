//
// Created by Ian on 25/11/2021.
//

#include "Plane.h"

Plane::Plane(int capacity,string registration,string type)
{
    this->capacity = capacity;
    this->registration = registration;
    this->type = type;
    flights = list<Flight>();
}

void Plane::AddFlight(Flight flight)
{
    flights.push_back(flight);
}

void Plane::AddFlight(list<Flight> flight)
{
    for (Flight a: flight)
    {
        flights.push_back(a);
    }
}

void Plane::DeleteFlight(int id)
{
    for (Flight a: flights)
    {
        if(a.GetId() == id)
        {
            flights.remove(a);
        }
    }
}

int Plane::GetCapacity() const
{
    return capacity;
}

list<Flight> Plane::GetFlights() const
{
    return flights;
}

string Plane::GetRegistration() const
{
    return registration;
}

string Plane::GetType() const
{
    return type;
}