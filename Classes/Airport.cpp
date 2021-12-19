#include "Airport.h"

Airport::Airport(string name, string initials)
{
    this->name = name;
    this->initials = initials;
}
bool Airport::addTransport(Transport transport){
    return transports.insert(transport);
}
string Airport::getName() const {
    return name;
}
string Airport::getInitials() const {
    return initials;
}
const BST<Transport>& Airport::getTransports() const {
    return transports;
}

bool Airport::deleteTransport(Transport transport)
{
    return transports.remove(transport);
}

void Airport::setInitials(string initials)
{
    this->initials = initials;
}

void Airport::setName(string name)
{
    this->name = name;
}

bool Airport::operator==(const Airport& airport) const{
    return initials == airport.getInitials();
}

ostream& operator<<(ostream& os , const Airport& air)
{
    os << air.getName() << " - " << air.getInitials();
    return os;
}

bool Airport::operator<(const Airport &airport) const
{
    return name < airport.getName();
}

