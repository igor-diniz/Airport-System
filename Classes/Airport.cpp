#include "Airport.h"

list<Transport> listtransp;

Airport::Airport(string name, string initials)
{
    this->name = name;
    this->initials = initials;
}
void AddTransport(Transport transport){
    listtransp.push_back(transport);
}
const string Airport::GetName() const {
    return name;
}
const string Airport::GetInitials() const {
    return initials;
}
const list<Transport> Airport::GetListtransp() const {
    return listtransp;
}