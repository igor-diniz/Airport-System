#include "Flight.h"
#include <queue>
#include <sstream>

int Flight::nextid = 0;
Flight::Flight()
{
    id++;
    id = nextid;
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
    id = nextid;
    this->availableSeats = availableSeats;
    this->duration = duration;
    this->departure = departure;
    this->destination = destination;
    this->origin = origin;
}

Flight::Flight(string CSVflight){
    stringstream ssFlight;
    ssFlight << CSVflight;

    string name, passport, airport, initials, date, durationStr, availableSeatsStr;

    //departureDate
    getline(ssFlight,date,',' );
    departure = Date(date);

    //duration
    getline(ssFlight,durationStr,',' );
    duration = Time(durationStr);

    //origin
    getline(ssFlight,airport,',' );
    getline(ssFlight,initials,',' );
    origin = Airport(airport, initials);

    //destination
    getline(ssFlight,airport,',' );
    getline(ssFlight,initials,',' );
    destination = Airport(airport, initials);

    //availableSeats
    getline(ssFlight, availableSeatsStr);
    availableSeats = stoi(availableSeatsStr);
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

void Flight::reduceAvailableSeats(){
    availableSeats -= 1;
}


//Plane Flight::getPlaneAssocieted() const{
    //return planeAssociated;
//}


bool Flight::operator==(const Flight &flight) const
{
    return id == flight.getId();
}

void Flight::setDeparture(Date date) {departure = date;}

void Flight::setDestination(Airport airport) {destination = airport;}

void Flight::setDuration(Time duration) {this->duration = duration;}

void Flight::setOrigin(Airport airport) {origin = airport;}

queue<Luggage> Flight::getLuggagesOutCar() const
{
    return luggagesOutCar;
}

//nt Flight::getLuggageTotal() {return luggageTotal;}

//void Flight::setLuggageTotal(int qntd) {luggageTotal += qntd;}

void Flight::addLuggageToQueue(Luggage luggages) {
    flightLuggages.push(luggages);
    luggagesOutCar.push(luggages);
}

void Flight::luggagesToCar(LuggageCar& Car) {
    luggagesOutCar = Car.setLuggageInCar(luggagesOutCar);
}

/*bool Flight::operator==(const Flight &f) const{
    return (
    id == f.getId() &&
    availableSeats == f.getAvailableSeats() &&
    departure == f.getDepartureDate() &&
    destination == f.getDestination() &&
    origin == f.getOrigin()
    );
}*/

Time Flight::getDuration() const {return duration;}

bool Flight::equals(const Flight &flight) const
{
    return departure == flight.getDepartureDate() && origin == flight.getOrigin();
}

Flight::Flight(Date &departure, Airport &origin)
{
    id++;
    id = nextid;
    this->departure = departure;
    this->origin = origin;
}

ostream& operator<<(ostream& os , const Flight& fli)
{
    os << fli.getId() << " - " << fli.getDepartureDate() << " - " << fli.getDuration() << " - " << fli.getOrigin() << " - " << fli.getDestination() << " - " << fli.getAvailableSeats();
    return os;
}


