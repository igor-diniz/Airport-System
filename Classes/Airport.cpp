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
const string Airport::GetName() const {
    return name;
}
const string Airport::GetInitials() const {
    return initials;
}
const list<Transport> Airport::GetListtransp() const {
    return listTransp;
}