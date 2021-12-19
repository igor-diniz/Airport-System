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
    void mainMenu();
    void save(){}; //TODO

private:
    vector<int> possibleChoices();
    unsigned stringToInt(string str);
    void readAirportsFile(const string& airportsFile);
    void readPassengersFile(const string& passengersFile);
    void readPlanesFile(const string& planesFile);
    void readLuggageCarsFile(const string& luggageCarsFile);
    void checkin(Passenger &passenger);
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
    void luggageCarCreation();
    void luggageCarDeletion();
    void luggageCarFind();
    void showluggageCars();
    void planeCreation();
    void planeDeletion();
    void planeFind();
    void updatePlane(Plane &plane);
    void showPlanes();
    void flightMenu();
    void serviceMenu();
    void serviceCreation(Plane &plane);
    void serviceDeletion(Plane& plane);
    void showServicesToDo(Plane& plane);
    void showServicesDone(Plane& plane);
    void flightCreation(Plane &plane);
    void flightDeletion(Plane &plane);
    void flightFind(Plane &plane);
    void updateFlight(Flight& flight,Plane &plane);
    void showFlights(Plane &plane);
    bool checkAirportExists(string initials,Airport& airport);
    void getLuggageToCar(Plane &plane);
    ///
    ///  creates a passenger and adds it to the general passengers list
    ///
    void passengerCreation();
    ///
    ///  removes a passenger from the general passengers list
    ///
    void passengerDeletion();
    ///
    ///  searchs for a passenger and gives the option to edit if found or to creat if not found
    ///
    void passengerFind();
    ///
    ///  prints the passengers list, sorted and filtered by user inputs
    ///
    void showPassengers();
    ///
    ///  \param passenger allows the user to update a specific passenger info
    ///
    void updatePassenger(Passenger &passenger);
    ///
    ///  prints the ticket menu and asks for an option
    ///
    void ticketMenu();
    ///
    ///  \param passenger creates a ticket and adds it to the passengers ticket list, asking if they want to add another
    ///  ticket for the same flight, both creations asking for luggage quantity
    ///
    void ticketCreation(Passenger& passenger);
    ///
    ///  \param passenger removes a ticket from the passenger tickets list
    ///
    void ticketDeletion(Passenger& passenger);
    ///
    ///  \param passenger searchs for a ticket from the passengers tickets
    ///  and gives the option to edit if found or to creat if not found
    ///
    void ticketFind(Passenger& passenger);
    ///
    ///  \param passenger prints the passenger's tickets list, sorted and filtered by user inputs
    ///
    void showTicket(Passenger& passenger);
    ///
    /// \param ticket allows the user to update a specific passenger's ticket info
    ///
    void updateTicket(Ticket& ticket);
};


#endif //TP1_AED_APP_H
