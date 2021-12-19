#include <sstream>
#include "Service.h"
#include "iostream"
using namespace std;

Service::Service(char serviceType, Date date, string accountable)
{
    this->serviceType = serviceType;
    this->date = date;
    this->accountable = accountable; //responsável
}
char Service::getServiceType() const {return serviceType;}

Date Service::getDate() const {return date;}

string Service::getAccountable() const {return accountable;}

void Service::setAccountable(string accountable) {this->accountable = accountable;}

Service::Service(string CSVservice){
    stringstream ssService;
    ssService << CSVservice;

    //type
    ssService.get(serviceType); ssService.get();

    //date
    string strDate;
    getline(ssService, strDate,',');
    date = Date(strDate);

    //accountable
    getline(ssService, accountable);
}

void Service::setDate(Date date) {this->date = date;}

void Service::setServiceType(char type) {this->serviceType = type;}

bool Service::operator<(Service &s) {
    if(date != s.getDate()) return date < s.getDate();
    else return accountable < s.getAccountable();
}

ostream& operator<<(ostream& os , const Service& service)
{
    os << service.getDate() << " - " << service.getAccountable() << " - " << service.getServiceType();
    return os;
}

