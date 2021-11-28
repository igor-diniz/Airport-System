//
// Created by Ian on 28/11/2021.
//

#include "Passenger.h"

Passenger::Passenger(){name = "UNKNOWN"; passport = "UNKNONW";}
Passenger::Passenger(string name, string passport){this->name = name; this->passport = passport;}

string Passenger::getName() {return name;}
string Passenger::getPassport() {return passport;}
bool Passenger::getCheckin() {return checkin;}
void Passenger::setCheckin(bool const checkin) {this->checkin = checkin;}
