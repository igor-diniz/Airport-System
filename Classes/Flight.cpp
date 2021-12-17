#include "Flight.h"
#include <queue>
int Flight::id = 0;
Flight::Flight()
{
    availableSeats = 0;
    duration = Time();
    departure = Date();
    destination = Airport();
    origin = Airport();
    list<Luggage> flightLuggages;
    list<Luggage> luggagesOutCar;
}

Flight::Flight(Date &departure,Time duration,Airport &origin,Airport &destination,int availableSeats)
{
    id++;
    this->availableSeats = availableSeats;
    this->duration = duration;
    this->departure = departure;
    this->destination = destination;
    this->origin = origin;
}

int Flight::getId() const {
    return id;
}

Date Flight::getDepartureDate() const
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

void Flight::setDeparture(Date date) {departure = date;}

void Flight::setDestination(Airport airport) {destination = airport;}

void Flight::setOrigin(Airport airport) {origin = airport;}

//int Flight::getLuggageTotal() {return luggageTotal;}

//void Flight::setLuggageTotal(int qntd) {luggageTotal += qntd;}

void Flight::addLuggageToQueue(list<Luggage> Luggages) {for(auto L:Luggages){flightLuggages.push(L);luggagesOutCar.push(L);}}

void Flight::luggagesToCar(LuggageCar Car) {
    luggagesOutCar = Car.setLuggageInCar(luggagesOutCar);
}

bool Flight::operator==(const Flight &f) const{
    return (
    id == f.getId() &&
    availableSeats == f.getAvailableSeats() &&
    departure == f.getDepartureDate() &&
    destination == f.getDestination() &&
    origin == f.getOrigin()
    );
}

