#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Classes/App.h"

int main() {
    App app("Flights.txt","Passengers.txt","Planes.txt","LuggageCars.txt","Airports.txt");
    app.mainMenu();
}