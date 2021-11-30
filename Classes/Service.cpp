#include "Service.h"
using namespace std;

Service::Service(char serviceType, Date date, string accountable)
{
    this->serviceType = serviceType;
    this->date = date;
    this->accountable = accountable; //responsável
}
char Service::getserviceType() const {
    return serviceType;
}
Date Service::getDate() const {
    return date;
}
string Service::getaccountable() const {
    return accountable;
}

bool Service::operator<(Service s) {
    if (date.year < s.getDate().year)
        return true;
    else if(date.year > s.getDate().year)
    {
        return false;
    }
    else if(date.month < s.getDate().month)
    {
        return true;
    }
    else if(date.month > s.getDate().month)
    {
        return false;
    }
    else if(date.day < s.getDate().day)
    {
        return true;
    }
    return false;
}