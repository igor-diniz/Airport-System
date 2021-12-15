#ifndef TP1_AED_LUGGAGECAR_H
#define TP1_AED_LUGGAGECAR_H

#include "Luggage.h"
#include "Flight.h"
#include <list>

class LuggageCar {
    public:
    LuggageCar(int c, int n, int m, Flight flight);

    int capacity, availability;
    private:
        int c, n, m;
        Flight flight;
        list<Luggage> luggageOutCar;
        list<list<stack<Luggage>>> luggageInCar;
        list<stack<Luggage>> carruagens;
        stack<Luggage> pilhas;

    void setLuggageOutCar(list<Luggage> Luggages);
    list<Luggage> setLuggageInCar();
};


#endif //TP1_AED_LUGGAGECAR_H
