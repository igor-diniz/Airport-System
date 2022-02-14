#include "Classes/App.h"

int main() {
    App app("Flights.txt","Passengers.txt","Planes.txt","LuggageCars.txt","Airports.txt");
    app.mainMenu();
}