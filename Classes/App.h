#ifndef TP1_AED_APP_H
#define TP1_AED_APP_H

#include "LuggageCar.h"
#include "Passenger.h"
#include "Plane.h"

class App {

private:
    list<Flight> flights;
    list<Passenger> passengers;
    list<Plane> planes;
    list<Luggage> luggages;
    list<LuggageCar> luggageCars;
    list<Service> services;
    list<Ticket> tickets;

public:
    App(const string& flightsFile,const string& passengersFile, const string& planesFile, const string& luggagesFile,
        const string& luggageCarFile, const string& servicesFile, const string& ticketsFile); //isso daqui vai ler dos TXT e botar nas listas e chamar o menu principal

        static void menuPrincipal(); //isso vai dar display das opções de CRUD dos elementos das listas e vai ter um switch pra cada caso

private:
    static void airportCreation();
};


#endif //TP1_AED_APP_H
