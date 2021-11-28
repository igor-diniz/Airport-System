#ifndef TP1_AED_AIRPORT_H
#define TP1_AED_AIRPORT_H
#include <list>
#include "Transport.h"
#include <string>

using namespace std;
//Para cada aeroporto, a informação sobre os locais
//de transporte terrestre (metro, comboio, autocarro) está guardada numa árvore binária de pesquisa.
class Airport{
    list<Transport> listTransp;
    string name, initials;
public:
    Airport();
    Airport(string name, string initials);
    void AddTransport(Transport transport);
    const string getName() const;
    const string getInitials() const;
    const list<Transport> getListtransp() const;
};
#endif TP1_AED_AIRPORT_H