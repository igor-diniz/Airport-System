#ifndef TP1_AED_APP_H
#define TP1_AED_APP_H

#include "LuggageCar.h"
#include "Passenger.h"
#include "Plane.h"
#include "Airport.h"
#include "Date.h"
#include <fstream>
#include <sstream>

class App {

private:
    list<Passenger> passengers;
    list<Plane> planes;
    list<LuggageCar> luggageCars;
    list<Airport> airports;

public:
    App(){};
    App(const string& passengersFile, const string& planesFile, const string& luggageCarsFile, const string& airportsFile);
    int mainMenu();
    void save(){}; //TODO
    void airportCreation();
    void airportDeletion();
    void airportFind();
    void updateAirport(Airport &airport);
    void showAirports();
    void transportMenu();
    void transportCreation(Airport &airport);
    void transportDeletion(Airport &airport);
    void transportFind(Airport &airport);
    void updateTransport(Transport &transport, Airport &airport);
    void showTransports(Airport &airport);
    void luggageCarCreation(){}; //TODO
    void luggageCarDeletion(){}; //TODO
    void luggageCarFind(){}; //TODO
    void showluggageCars(){};//TODO
    void planeCreation();
    void planeDeletion();
    void planeFind();
    void updatePlane(Plane &plane);
    void showPlanes();
    void flightMenu();
    void serviceMenu(){};//TODO
    ;//TODO
    ;//TODO
    ;//TODO
    void showPassengers(){};//TODO
    void ticketMenu(){};//TODO
    void flightCreation(Plane &plane);
    void flightDeletion(Plane &plane);
    void flightFind(Plane &plane);
    void updateFlight(Flight& flight,Plane &plane);
    void showFlights(Plane &plane);
    bool checkAirportExists(string initials,Airport& airport);
    void getLuggageToCar(Plane &plane);
    void passengerCreation();
    void passengerDeletion();
    void passengerFind();
    void updatePassenger(Passenger &passenger);


private:
    vector<int> possibleChoices();
    unsigned stringToInt(string str);
    void readAirportsFile(const string& airportsFile);
    void readPassengersFile(const string& passengersFile);
    void readPlanesFile(const string& planesFile);
    void readLuggageCarsFile(const string& luggageCarsFile);


    void TicketMenu();
};


#endif //TP1_AED_APP_H
