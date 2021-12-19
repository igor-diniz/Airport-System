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
    int getId() const;
    LuggageCar(){};
    LuggageCar(Airport airport,int numCarriages, int stacksPerCarriage, int luggagesPerStack);
    void setLuggageOutCar(list<Luggage> Luggages);
    void setAirport(Airport& airport1);
    Airport getAirport() const;
    int getNumCarriages() const;
    int getNumStacks() const;
    int getNumLuggagesPerStack() const;
    bool operator ==(const LuggageCar& luggageCar);
    queue<Luggage> setLuggageInCar(queue<Luggage> &luggageOutCar);
    friend ostream& operator<<(ostream& os , const LuggageCar& luggageCar);
};


#endif //TP1_AED_LUGGAGECAR_H
