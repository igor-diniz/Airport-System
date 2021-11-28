#include "Service.h"
#include "Transport.h"
using namespace std;

Service::Service(char serviceType, struct date date, string accountable)
{
    this->date = date;
    this->accountable = accountable; //responsável
}
const char Service::getserviceType() const {
    return this->serviceType;
}
const date Service::getdate() const {
    return date;
}
const string Service::getaccountable() const {
    return accountable;
}