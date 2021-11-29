#include "Airport.h"

Airport::Airport(string name, string initials)
{
    this->name = name;
    this->initials = initials;
}
bool Airport::AddTransport(Transport transport){
    //listTransp.push_back(transport);
    return transports.insert(transport);
}
const string Airport::getName() const {
    return name;
}
const string Airport::getInitials() const {
    return initials;
}
const list<Transport> Airport::getListtransp() const {
    return listTransp; //trocar pela binary tree
}