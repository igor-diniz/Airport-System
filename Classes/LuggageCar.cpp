#include "LuggageCar.h"
#include "Luggage.h"
#include "Flight.h"

LuggageCar::LuggageCar(int c,int n,int m, Flight flight){
    this-> c = c;
    this-> n = n;
    this-> m = m;
    this-> flight = flight;
    capacity = c * n * m;
    availability = capacity;
}

list<Luggage> LuggageCar::setLuggageInCar() {
    if (luggageOutCar.size() != 0) {
        for (auto &&luggage: luggageOutCar) {
            for (auto &&carruagem: luggageInCar) {
                for (auto &&pilha: carruagem) {
                    while (pilha.size() != m && luggageOutCar.size() != 0) {
                        pilha.push(luggageOutCar.front());
                        luggageOutCar.pop_front();
                        availability -= 1;
                        if (luggageOutCar.size() == 0) return luggageOutCar;
                    }
                }
            }
        }
    }
    return luggageOutCar;
}
void LuggageCar::setLuggageOutCar(list<Luggage> luggages){
    luggageOutCar = luggages;
}
