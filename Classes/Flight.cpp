#include "Flight.h"
#include <queue>
#include <sstream>

int Flight::nextid = 0;
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
    nextid++;
    id = nextid;
    this->availableSeats = availableSeats;
    this->duration = duration;
    this->departure = departure;
    this->destination = destination;
    this->origin = origin;
}

Flight::Flight(Date &departure, Airport &origin)
{
    nextid++;
    id = nextid;
    this->departure = departure;
    this->origin = origin;
}

Flight::Flight(string CSVflight){

    stringstream ssFlight;
    ssFlight << CSVflight;

    string strID, name, passport, airport, initials, date, durationStr, availableSeatsStr;

    //ID
    getline(ssFlight,strID,',' );
    id = stoi(strID);
    if(id >= nextid)
        nextid = id;

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

void Flight::setID(const int flightID){
    id = flightID;
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


bool Flight::operator==(const Flight &flight) const
{
    return id == flight.getId();
}

void Flight::setDeparture(Date date) {departure = date;}

void Flight::setDestination(Airport& airport) {destination = airport;}

void Flight::setDuration(Time duration) {this->duration = duration;}

void Flight::setOrigin(Airport& airport) {origin = airport;}

queue<Luggage> Flight::getLuggagesOutCar() const
{
    return luggagesOutCar;
}

void Flight::addLuggageToQueue(Luggage luggage) {
    flightLuggages.push(luggage);
    luggagesOutCar.push(luggage);
}

void Flight::luggagesToCar(LuggageCar& Car) {
    luggagesOutCar = Car.setLuggageInCar(luggagesOutCar);
}

Time Flight::getDuration() const {return duration;}

bool Flight::equals(const Flight &flight) const
{
    return departure == flight.getDepartureDate() && origin == flight.getOrigin();
}

ostream& operator<<(ostream& os , const Flight& fli)
{
    os << fli.getId() << " - " << fli.getDepartureDate() << " - " << fli.getDuration() << " - " << fli.getOrigin() << " - " << fli.getDestination() << " - " << fli.getAvailableSeats();
    return os;
}


