#include "Airport.h"

Airport::Airport(string name, string initials)
{
    this->name = name;
    this->initials = initials;
    listTransp = list<Transport>();
}
void Airport::AddTransport(Transport transport){
    listTransp.push_back(transport);
}
const string Airport::getName() const {
    return name;
}
const string Airport::getInitials() const {
    return initials;
}
const list<Transport> Airport::getListtransp() const {
    return listTransp;
}