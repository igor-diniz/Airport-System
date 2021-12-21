#ifndef TP1_AED_LUGGAGECAR_H
#define TP1_AED_LUGGAGECAR_H

#include "Luggage.h"
#include "Airport.h"
#include <string>
#include <list>
using namespace std;

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
    ///
    /// \param airport the Airport of the LuggageCar
    /// \param numCarriages the max number of carriages the car handles
    /// \param stacksPerCarriage the max number of stacks each carriage handles
    /// \param luggagesPerStack the max number of luggages a stack can handle
    ///
    LuggageCar(Airport airport,int numCarriages, int stacksPerCarriage, int luggagesPerStack);
    LuggageCar(string CSVluggageCar);
    void setAirport(Airport& airport1);
    Airport getAirport() const;
    int getNumCarriages() const;
    list<Luggage> getLuggage() const;
    int getNumStacks() const;
    ///
    /// makes the luggage In Car empty and updates the availability
    ///
    void clear();
    int getNumLuggagesPerStack() const;
    ///
    /// \param luggageCar
    /// Luggage cars are the same if all attributes are equal except de ID
    ///
    bool operator ==(const LuggageCar& luggageCar);
    ///
    /// \param luggageOutCar a Luggage queue
    /// this will put all the luggages from luggageOutCar into the LuggageInCar of the car until the car is full
    /// returns the remaining luggages in a queue
    ///
    queue<Luggage> setLuggageInCar(queue<Luggage> &luggageOutCar);
    ///
    /// \param os
    /// \param luggageCar Luggage cars are showed in the form ID - Airport - num Carriages - stacks per carriage - luggages per stack
    /// \return
    friend ostream& operator<<(ostream& os , const LuggageCar& luggageCar);
};


#endif //TP1_AED_LUGGAGECAR_H
