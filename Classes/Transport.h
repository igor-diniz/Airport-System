//
// Created by jeffe on 25/11/2021.
//

#ifndef TP1_AED_TRANSPORT_H
#define TP1_AED_TRANSPORT_H

//Um local
//de transporte terrestre é caracterizado, no mínimo, por tipo de transporte (metro, autocarro, comboio), distância
//ao aeroporto, horário.
#include <list>
using namespace std;

class Transport{
    char type;
    float distance;
    time_t time; //ainda tem q fazer isso aqui

public:
    inline char getType() {return this->type;};
    inline float getDistance() {return this->distance;};
    bool operator<(const Transport& transp);
};


#endif //TP1_AED_TRANSPORT_H
