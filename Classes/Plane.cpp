#include <sstream>
#include "Plane.h"

Plane::Plane(int capacity,string registration,string type){
    this->capacity = capacity;
    this->registration = registration;
    this->type = type;
    this->flightsId = list<int>(0);
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


void Plane::addFlight(int flightId)
{
    flightsId.push_back(flightId);
}

void Plane::addService(Service &service) {
    servicesToDo.push(service);
}

void Plane::popService() {
    servicesDone.push(servicesToDo.front());
    servicesToDo.pop();
}

bool Plane::deleteFlight(int flightId)
{
    for (int id : flightsId)
    {
        if(id == flightId)
        {
            flightsId.remove(id);
            return true;
        }
    }
    return false;
}

int Plane::getCapacity() const
{
    return capacity;
}

list<int> Plane::getFlightsId()
{
    return flightsId;
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