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

    string flightsFile, passengersFile, planesFile, luggageCarsFile, airportsFile;

public:
    App() = default;
    App(const string& flightsFile, const string& passengersFile, const string& planesFile, const string& luggageCarsFile, const string& airportsFile);
    void mainMenu();

private:
    static vector<int> possibleChoices();
    ///
    ///  reads the file no formato bla bla bla bla
    ///
    void readFlightsFile(const string &flightsFile);
    void readAirportsFile(const string& airportsFile);
    void readPassengersFile(const string& passengersFile);
    void readPlanesFile(const string& planesFile);
    void readLuggageCarsFile(const string& luggageCarsFile);
    ///
    ///  \param passenger updates de passenger's ticket checkin state and sends its luggage to the flights luggage lists
    ///
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
    ///
    ///  \param airport allows the user to update a specific airport info
    ///
    void updateAirport(Airport &airport);
    ///
    ///  prints the airports list, sorted and filtered by user inputs
    ///
    void showAirports();
    ///
    ///  prints the transport menu and asks for an option
    ///
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
    ///
    ///  \param transport allows the user to update a specific transport info
    ///
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
    ///
    ///  prints the luggage car list, sorted and filtered by user inputs
    ///
    void showLuggageFromCar();
    ///
    ///  prints the luggage car list, sorted and filtered by user inputs
    ///
    void showLuggageCars();
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
    ///
    ///  \param plane allows the user to update a specific plane info
    ///
    void updatePlane(Plane &plane);
    ///
    ///  prints the plane list, sorted and filtered by user inputs
    ///
    void showPlanes();
    ///
    ///  prints the flight menu and asks for an option
    ///
    void flightMenu();
    ///
    ///  prints the service menu and asks for an option
    ///
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
    ///
    ///  \param flight,plane allows the user to update a specific flight info
    ///
    void updateFlight(Flight& flight,Plane &plane);
    ///
    ///  \param plane prints the plane's services to do list, sorted and filtered by user inputs
    ///
    void showFlights(Plane &plane);
    ///
    /// \param initials, airport checks if the airport exists and if so, adds it to the general airport list
    ///
    bool checkAirportExists(string& initials,Airport& airport);
    ///
    /// \param plane takes the luggage out of a car from a flight and inserts it into a given luggage car
    ///
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
    ///
    /// Saves all the files in the program
    ///
    void saveAll();
    ///
    /// Saves the luggage cars file (this is a auxiliary function only)
    ///
    void saveLuggageCars();
    ///
    /// Saves the airports file (this is a auxiliary function only)
    ///
    void saveAirports();
    ///
    /// Saves the planes file (this is a auxiliary function only)
    ///
    void savePlanes();
    ///
    /// Saves the flights file (this is a auxiliary function only)
    ///
    void saveFlights();
    ///
    /// Saves the passengers file (this is a auxiliary function only)
    ///
    void savePassengers();
};


#endif //TP1_AED_APP_H
