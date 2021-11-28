//
// Created by Ian on 25/11/2021.
//

#ifndef TP1_AED_FLIGHT_H
#define TP1_AED_FLIGHT_H

#include "Airport.h"
struct date
{
    int day;
    int month;
    int year;
};
//Um voo é
//caracterizado, no mínimo, por: numero de voo, data de partida, duração do voo, origem, destino.
class Flight {
    int id;
    date arrival,departure;
    Airport destination, origin;

};


#endif //TP1_AED_FLIGHT_H
