#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Classes/App.h"

int main() {
    App app("Passengers.txt","","","Airports.txt");
    int menuChoice;

    while(true)
    {
        menuChoice = app.menuPrincipal();

        switch (menuChoice)
        {
            case 0: break;
            case 1: app.save(); break;
            case 11: app.airportCreation(); continue;
            case 12: app.airportDeletion(); continue;
            case 13: app.airportFind(); continue;
            case 14: app.showAirports(); continue;
            case 15: app.transportMenu(); continue;
            case 21: app.luggageCarCreation(); continue;
            case 22: app.luggageCarDeletion(); continue;
            case 23: app.luggageCarFind(); continue;
            case 24: app.showluggageCars(); continue;
            case 31: app.planeCreation(); continue;
            case 32: app.planeDeletion(); continue;
            case 33: app.planeFind(); continue;
            case 34: app.showPlanes(); continue;
            case 35: app.flightMenu(); continue;
            case 36: app.serviceMenu(); continue;
            case 41: app.passengerCreation(); continue;
            case 42: app.passengerDeletion(); continue;
            case 43: app.passengerFind(); continue;
            case 44: app.showPassengers(); continue;
            case 45: app.ticketMenu(); continue;
            default: break;
        }
        return 0;
    }
}