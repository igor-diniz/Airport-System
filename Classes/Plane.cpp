#include "Plane.h"

Plane::Plane(int capacity,string registration,string type){
    this->capacity = capacity;
    this->registration = registration;
    this->type = type;
    this->flights = list<Flight>(0);
    servicesToDo = queue<Service>();
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

bool Plane::deleteFlight(int id)
{
    for (Flight a: flights)
    {
        if(a.getId() == id)
        {
            flights.remove(a);
            return true;
        }
    }
    return false;

}

int Plane::getCapacity() const
{
    return capacity;
}

bool sort_id_asc(const Flight& a, const Flight& b){return a.getId() < b.getId();}

bool sort_id_desc(const Flight& a, const Flight& b){return a.getId() > b.getId();}

bool sort_availableSeats_asc(const Flight& a, const Flight& b){return a.getAvailableSeats() < b.getAvailableSeats();}

bool sort_availableSeats_desc(const Flight& a, const Flight& b){return a.getAvailableSeats() > b.getAvailableSeats();}

bool sort_arrival_asc(const Flight& a, const Flight& b){return a.getArrivalDate() < b.getArrivalDate();}

bool sort_arrival_desc(const Flight& a, const Flight& b){return !(a.getArrivalDate() < b.getArrivalDate());}

bool sort_departure_asc(const Flight& a, const Flight& b){return a.getDepartureDate() < b.getDepartureDate();}

bool sort_departure_desc(const Flight& a, const Flight& b){return !(a.getDepartureDate() < b.getDepartureDate());}

bool sort_destination_asc(const Flight& a, const Flight& b){return a.getDestination().getName() < b.getDestination().getName();}

bool sort_destination_desc(const Flight& a, const Flight& b){return a.getDestination().getName() > b.getDestination().getName();}

bool sort_origin_asc(const Flight& a, const Flight& b) {return a.getOrigin().getName() < b.getOrigin().getName();}

bool sort_origin_desc(const Flight& a, const Flight& b) {return a.getOrigin().getName() > b.getOrigin().getName();}

bool sort_capacity_asc(const Flight& a, const Flight& b) {return a.getCapacity() < b.getCapacity();}

bool sort_capacity_desc(const Flight& a, const Flight& b) {return a.getCapacity() > b.getCapacity();}

list<Flight> Plane::getFlights(SortPossibilites sortOrder , bool descending)
{
    switch(sortOrder)
    {
        case ID:
            if(descending) {flights.sort(sort_id_desc);}
            else flights.sort(sort_id_asc);
            break;

        case AVAILABLESEATS:
            if(descending) {flights.sort(sort_availableSeats_desc);}
            else flights.sort(sort_availableSeats_asc);
            break;

        case ARRIVAL:
            if(descending) {flights.sort(sort_arrival_desc);}
            else flights.sort(sort_arrival_asc);
            break;

        case DEPARTURE:
            if(descending) {flights.sort(sort_departure_desc);}
            else flights.sort(sort_departure_asc);
            break;

        case DESTINATION:
            if(descending) {flights.sort(sort_destination_desc);}
            else flights.sort(sort_destination_asc);
            break;

        case ORIGIN:
            if(descending){flights.sort(sort_origin_desc);}
            else flights.sort(sort_origin_asc);
            break;

        case CAPACITY:
            if(descending){flights.sort(sort_capacity_desc);}
            else flights.sort(sort_capacity_asc);
            break;
    }
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

void Plane::setType(string type) {this->type = type;}

void Plane::setCapacity(int capacity) {this->capacity = capacity;}

void Plane::setRegistration(string registration) {this->registration = registration;}
