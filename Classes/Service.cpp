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
Date Service::getdate() const {
    return date;
}
string Service::getaccountable() const {
    return accountable;
}

bool Service::operator<(Service s) {
    if (date.year < s.getdate().year)
        return true;
    else if(date.year > s.getdate().year)
    {
        return false;
    }
    else if(date.month < s.getdate().month)
    {
        return true;
    }
    else if(date.month > s.getdate().month)
    {
        return false;
    }
    else if(date.day < s.getdate().day)
    {
        return true;
    }
    return false;
}