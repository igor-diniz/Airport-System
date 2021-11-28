//
// Created by Ian on 28/11/2021.
//

#ifndef TP1_AED_PASSENGER_H
#define TP1_AED_PASSENGER_H

#include <string>
#include "Flight.h"

using namespace std;

class Passenger {
private:
    string name, passport;

public:
    Passenger();
    Passenger(string name, string passport);
    string getName();
    string getPassport();
    bool checkin();
};


#endif //TP1_AED_PASSENGER_H
