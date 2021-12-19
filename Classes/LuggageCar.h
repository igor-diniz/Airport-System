#ifndef TP1_AED_LUGGAGECAR_H
#define TP1_AED_LUGGAGECAR_H

#include "Luggage.h"
#include "Airport.h"
#include <list>

class LuggageCar {
private:
    static int nextid; ///incrementor for next luggage car creation
    int id; ///actual luggage car id
    int numCarriages, stacksPerCarriage, luggagesPerStack; ///respectively refers to the utterance's "c","n" and "m"
    Airport airport;
    list<list<stack<Luggage>>> luggageInCar; ///All the luggage already assigned to this car
    int availability; ///All the empty "slots" left on the car
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
