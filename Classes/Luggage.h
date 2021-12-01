//
// Created by Ian on 28/11/2021.
//

#ifndef TP1_AED_LUGGAGE_H
#define TP1_AED_LUGGAGE_H
#include "Ticket.h"


class Luggage {
    Luggage() : ticket(0,Flight()) {}

    Ticket ticket;
};


#endif //TP1_AED_LUGGAGE_H
