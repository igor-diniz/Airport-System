#ifndef TP1_AED_AIRPORT_H
#define TP1_AED_AIRPORT_H
#include <list>
#include "Transport.h"
#include <string>

using namespace std;
//Para cada aeroporto, a informação sobre os locais
//de transporte terrestre (metro, comboio, autocarro) está guardada numa árvore binária de pesquisa.
class Airport{
    Airport(string name, string initials);

    list<Transport> ListTransp;
    string name, initials;
public:
    Airport();
    void AddTransport();
    const string GetName() const;
    const string GetInitials() const;
    const list<Transport> GetListtransp() const;
};
#endif TP1_AED_AIRPORT_H