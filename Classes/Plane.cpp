#include <sstream>
#include "Plane.h"

Plane::Plane(int capacity,string registration,string type){
    this->capacity = capacity;
    this->registration = registration;
    this->type = type;
    this->flights = list<Flight>(0);
    servicesToDo = queue<Service>();
}

Plane::Plane(string CSVplane) {
    stringstream ssPlane;
    ssPlane << CSVplane;
    //capacity
    string strCapacity;
    getline(ssPlane, strCapacity, ',');
    capacity = stoi(strCapacity);

    //registration
    getline(ssPlane, registration, ',');

    //type
    getline(ssPlane, type);
}

void Plane::addOldService(Service &oldService){
    servicesDone.push(oldService);
}


void Plane::addFlight(Flight &flight)
{
    flights.push_back(flight);
}

void Plane::addService(Service &service) {
    servicesToDo.push(service);
}

void Plane::popService() {
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

list<Flight> Plane::getFlights()
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

bool Plane::operator==(const Plane &plane)
{
    return registration == plane.getRegistration();
}

queue<Service> Plane::getServicesToDo()
{
    return servicesToDo;
}

stack<Service> Plane::getServicesDone()
{
    return servicesDone;
}

void Plane::setType(string type) {this->type = type;}

void Plane::setCapacity(int capacity) {this->capacity = capacity;}

void Plane::setRegistration(string registration) {this->registration = registration;}

ostream& operator<<(ostream& os , const Plane& plane)
{
    os << plane.getRegistration() << " - " << plane.getType() << " - " << plane.getCapacity();
    return os;
}