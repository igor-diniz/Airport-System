#include "Plane.h"

Plane::Plane(int capacity,string registration,string type, list<Flight> &flights){
    this->capacity = capacity;
    this->registration = registration;
    this->type = type;
    this->flights = flights;
    servicesToDo = queue<Service>();
}

Plane::Plane(int capacity, string registration, string type, list<Flight> &flights, queue<Service> &servicesToDo) {
    this->capacity = capacity;
    this->registration = registration;
    this->type = type;
    this->flights = flights;
    this->servicesToDo = servicesToDo;
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

void Plane::addService(Service &service) {
    servicesToDo.push(service);
}

void Plane::addService(queue<Service> &services) {
    while (!services.empty())
    {
        servicesToDo.push(services.front());
        services.pop();
    }
}

void Plane::deleteService() {
    servicesDone.push(servicesToDo.front());
    servicesToDo.pop();
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