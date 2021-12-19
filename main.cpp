#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Classes/App.h"

int main() {
    App app("Passengers.txt","Planes.txt","luggageCars.txt","Airports.txt");
    app.mainMenu();
}