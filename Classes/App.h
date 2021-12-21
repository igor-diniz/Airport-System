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
    vector<LuggageCar> luggageCars;
    list<Airport> airports;
    vector<Flight> flights;

public:
    App(){};
    App(const string& flightsFile, const string& passengersFile, const string& planesFile, const string& luggageCarsFile, const string& airportsFile);
    void mainMenu();
    void save(); //TODO

private:
    vector<int> possibleChoices();
    ///
    ///  reads the file no formato bla bla bla bla
    ///
    void readFlightsFile(const string &flightsFile);
    void readAirportsFile(const string& airportsFile);
    void readPassengersFile(const string& passengersFile);
    void readPlanesFile(const string& planesFile);
    void readLuggageCarsFile(const string& luggageCarsFile);
    void checkin(Passenger &passenger);
    ///
    ///  creates an airport and adds it to the general airports list
    ///
    void airportCreation();
    ///
    ///  removes an airport from the general airports list
    ///
    void airportDeletion();
    ///
    ///  searches for a airport from the general airports list
    ///  and gives the option to edit if found or to creat if not found
    ///
    void airportFind();
    void updateAirport(Airport &airport);
    ///
    ///  prints the airports list, sorted and filtered by user inputs
    ///
    void showAirports();
    void transportMenu();
    ///
    ///  \param airport creates a transport and adds it to the airport's transports list
    ///
    void transportCreation(Airport &airport);
    ///
    ///  \param airport removes a transport from the airport's transports list
    ///
    void transportDeletion(Airport &airport);
    ///
    ///  \param airport searches for a transport from the airport's transports list
    ///  and gives the option to edit if found or to creat if not found
    ///
    void transportFind(Airport &airport);
    void updateTransport(Transport &transport, Airport &airport);
    ///
    ///  prints the airport's transports list, sorted and filtered by user inputs
    ///
    void showTransports(Airport &airport);
    ///
    ///  creates a luggage car and adds it to the general luggage cars list
    ///
    void luggageCarCreation();
    ///
    ///  removes a luggage car from the general luggage cars list
    ///
    void luggageCarDeletion();
    ///
    ///  searches for a luggage car from the general luggage car list
    ///  and gives the option to edit if found or to creat if not found
    ///
    void luggageCarFind();
    void showLuggageCars();
    void showLuggageFromCar();
    ///
    ///  prints the luggage car list, sorted and filtered by user inputs
    ///
    void showluggageCars();
    ///
    ///  creates a plane and adds it to the general plane list
    ///
    void planeCreation();
    ///
    ///  removes a plane and from the general plane list
    ///
    void planeDeletion();
    ///
    ///  searches for a plane from the general plane list
    ///  and gives the option to edit if found or to creat if not found
    ///
    void planeFind();
    void updatePlane(Plane &plane);
    ///
    ///  prints the plane list, sorted and filtered by user inputs
    ///
    void showPlanes();
    void flightMenu();
    void serviceMenu();
    ///
    ///  \param plane creates a service and adds it to the plane's services to do list
    ///
    void serviceCreation(Plane &plane);
    ///
    ///  \param plane removes a service and from one of the plane's services to do list
    ///
    void serviceDeletion(Plane& plane);
    ///
    ///  \param plane prints the plane's services to do list, sorted and filtered by user inputs
    ///
    void showServicesToDo(Plane& plane);
    ///
    ///  \param plane prints the plane's services done list, sorted and filtered by user inputs
    ///
    void showServicesDone(Plane& plane);
    ///
    ///  \param plane creates a flight and adds it to the general flights list and the plane's flights list
    ///
    void flightCreation(Plane &plane);
    ///
    ///  \param plane removes a flight from the general flights list and the plane's flights list
    ///
    void flightDeletion(Plane &plane);
    ///
    ///  \param plane searches for a flight from the general flights list and the plane's flights list
    ///  and gives the option to edit if found or to creat if not found
    ///
    void flightFind(Plane &plane);
    void updateFlight(Flight& flight,Plane &plane);
    ///
    ///  \param plane prints the plane's services to do list, sorted and filtered by user inputs
    ///
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
    ///  searches for a passenger and gives the option to edit if found or to creat if not found
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
    ///  \param passenger searches for a ticket from the passengers tickets
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
