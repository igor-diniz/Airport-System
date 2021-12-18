#ifndef TP1_AED_AIRPORT_H
#define TP1_AED_AIRPORT_H
#include <list>
#include "Transport.h"
#include <string>
#include "BST.h"

using namespace std;
//Para cada aeroporto, a informação sobre os locais
//de transporte terrestre (metro, comboio, autocarro) está guardada numa árvore binária de pesquisa.
class Airport{
    string name, initials;
    BST<Transport> transports = BST<Transport>(Transport('o',0,{0,0}));
public:
    Airport(){};
    Airport(string name, string initials);
    bool addTransport(Transport transport);
    bool deleteTransport(Transport transport);
    string getName() const;
    string getInitials() const;
    const BST<Transport>& getTransports() const;
    void setName(string name);
    void setInitials (string initials);
    Transport getClosestTransport() const;
    bool operator==(const Airport& airport) const;
    Airport& operator=(const Airport& airport);
    friend ostream& operator<<(ostream& os , const Airport& air);

};
#endif