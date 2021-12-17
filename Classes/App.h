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
    App(const string& passengersFile, const string& planesFile, const string& luggageCarsFile, const string& airportsFile); //isso daqui vai ler dos TXT e botar nas listas e chamar o menu principal

        void menuPrincipal(); //isso vai dar display das opções de CRUD dos elementos das listas e vai ter um switch pra cada caso

private:
    void airportCreation();
    void airportDeletion();
    void airportDetail();
    void showAirports();
    void transportMenu();
    void transportCreation(Airport &airport);
    void transportDeletion(Airport &airport);
    void transportDetail(Airport &airport);
    void showTransports(Airport &airport);
    void readPassengersFile(const string& passengersFile);
    void readPlanesFile(const string& planesFile);
    void readLuggageCarsFile(string& luggageCarsFile);
    void readAirportsFile(string& airportsFile);


};


#endif //TP1_AED_APP_H
