//
// Created by Ian on 25/11/2021.
//

#ifndef TP1_AED_AIRPORT_H
#define TP1_AED_AIRPORT_H
#include <list>
#include "Transport.h"
#include <string>

using namespace std;
//Para cada aeroporto, a informação sobre os locais
//de transporte terrestre (metro, comboio, autocarro) está guardada numa árvore binária de pesquisa.
class Airport{
    list<Transport> ListTransp;
    string name, initials;
private:
    Airport();
    void AddTransport();

    void AddTransport(Transport transport){
        ListTransp.push_back(transport);
    }
};



<<<<<<< HEAD
#endif //TP1_AED_AIRPORT_H
=======
#endif //TP1_AED_AIRPORT_H
>>>>>>> de4e18f45f5235164e58cb9d1ff214034947b0cb
