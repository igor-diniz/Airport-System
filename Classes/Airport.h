//
// Created by Ian on 25/11/2021.
//

#ifndef TP1_AED_AIRPORT_H
#define TP1_AED_AIRPORT_H
#include <list>
#include "Transport.h"
#include <string>

//Para cada aeroporto, a informação sobre os locais
//de transporte terrestre (metro, comboio, autocarro) está guardada numa árvore binária de pesquisa.
class Airport{
    list<Transport> Transports;
    string name, initials;

};


#endif //TP1_AED_AIRPORT_H
