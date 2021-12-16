#ifndef TP1_AED_LUGGAGECAR_H
#define TP1_AED_LUGGAGECAR_H

#include "Luggage.h"
#include "Flight.h"
#include <list>

class LuggageCar {
private:
    int c, n, m;
    Airport airport;
    list<list<stack<Luggage>>> luggageInCar;
    list<stack<Luggage>> carruagens;
    stack<Luggage> pilhas;
    int capacity, availability;
public:
    LuggageCar(Airport airport,int c, int n, int m);
    void setLuggageOutCar(list<Luggage> Luggages);
    Airport getAirport(const Airport& airport) const;
    list<Luggage> setLuggageInCar(list<Luggage> &luggageOutCar);
};


#endif //TP1_AED_LUGGAGECAR_H
