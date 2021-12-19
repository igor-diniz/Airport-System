#ifndef TP1_AED_LUGGAGECAR_H
#define TP1_AED_LUGGAGECAR_H

#include "Luggage.h"
#include "Airport.h"
#include <list>

class LuggageCar {
private:
    static int nextid;
    int id;
    int numCarriages, stacksPerCarriage, luggagesPerStack;
    Airport airport;
    list<list<stack<Luggage>>> luggageInCar;
    int availability;
public:
    int getId();
    LuggageCar(){};
    LuggageCar(Airport airport,int numCarriages, int stacksPerCarriage, int luggagesPerStack);
    void setLuggageOutCar(list<Luggage> Luggages);
    Airport getAirport(const Airport& airport) const;
    queue<Luggage> setLuggageInCar(queue<Luggage> &luggageOutCar);
};


#endif //TP1_AED_LUGGAGECAR_H
