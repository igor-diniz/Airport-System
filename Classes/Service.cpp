#include "Service.h"
using namespace std;

Service::Service(char serviceType, struct date date, string accountable)
{
    this->serviceType = serviceType;
    this->date = date;
    this->accountable = accountable; //responsável
}
const char Service::getserviceType() const {
    return serviceType;
}
const date Service::getdate() const {
    return date;
}
const string Service::getaccountable() const {
    return accountable;
}