#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Classes/App.h"

int main() {
    App app("Passengers.txt","","","Airports.txt");
    int menuChoice;

    while(true)
    {
        menuChoice = app.mainMenu();

        switch (menuChoice)
        {
            case 0: exit(0);
            case 1: app.save(); exit(0);
            case 11: app.airportCreation(); break;
            case 12: app.airportDeletion(); break;
            case 13: app.airportFind(); break;
            case 14: app.showAirports(); break;
            case 15: app.transportMenu(); break;
            case 21: app.luggageCarCreation(); break;
            case 22: app.luggageCarDeletion(); break;
            case 23: app.luggageCarFind(); break;
            case 24: app.showluggageCars(); break;
            case 31: app.planeCreation(); break;
            case 32: app.planeDeletion(); break;
            case 33: app.planeFind(); break;
            case 34: app.showPlanes(); break;
            case 35: app.flightMenu(); break;
            case 36: app.serviceMenu(); break;
            case 41: app.passengerCreation(); break;
            case 42: app.passengerDeletion(); break;
            case 43: app.passengerFind(); break;
            case 44: app.showPassengers(); break;
            case 45: app.ticketMenu(); break;
            default: exit(1);
        }
    }
}