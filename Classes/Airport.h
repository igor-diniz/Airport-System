#ifndef TP1_AED_AIRPORT_H
#define TP1_AED_AIRPORT_H
#include <list>
#include "Transport.h"
#include <string>
#include "BST.h"

using namespace std;
class Airport{
    string name, initials;
    BST<Transport> transports = BST<Transport>(Transport());
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
    bool operator==(const Airport& airport) const;
    bool operator <(const Airport& airport) const;
    friend ostream& operator<<(ostream& os , const Airport& air);

};
#endif