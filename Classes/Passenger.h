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
    bool checkin = false;

public:
    Passenger();
    Passenger(string name, string passport);
    string getName();
    string getPassport();
    bool getCheckin();
    void setCheckin(bool const checkin);

};


#endif //TP1_AED_PASSENGER_H
