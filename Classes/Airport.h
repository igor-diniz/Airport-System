#ifndef TP1_AED_AIRPORT_H
#define TP1_AED_AIRPORT_H
#include <list>
#include "Transport.h"
#include <string>
#include "BST.h"

using namespace std;
class Airport{
    string name;
    string initials; ///This is also known as "IATA initials"
    BST<Transport> transports = BST<Transport>(Transport());
public:
    Airport(){};
    ///
    /// \param name the Airport name
    /// \param initials the Airport initials (PRIMARY KEY)
    ///
    Airport(string name, string initials);
    ///
    /// \param transport the transport that will be added to the transport BST
    ///
    bool addTransport(Transport transport);
    ///
    /// \param transport the transport that will be deleted to the transport BST
    ///
    bool deleteTransport(Transport transport);

    string getName() const;

    string getInitials() const;

    const BST<Transport>& getTransports() const;

    void setName(string name);

    void setInitials (string initials);
    ///
    /// \param airport checks if the Airport initials are equal to the parameter airport initials
    ///
    bool operator==(const Airport& airport) const;
    ///
    /// \param airport checks if the Airport name is < then the parameter airport name
    ///
    bool operator <(const Airport& airport) const;
    ///
    /// \param os
    /// \param air Airport are show in the order name - initials
    ///
    friend ostream& operator<<(ostream& os , const Airport& air);

};
#endif