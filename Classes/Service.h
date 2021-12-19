#ifndef TP1_AED_SERVICE_H
#define TP1_AED_SERVICE_H
#include <string>
#include "Date.h"
using namespace std;
//a. Um serviço é caracterizado
//por tipo de serviço (manutenção/limpeza), data e funcionário responsável.
class Service {
private:
    char serviceType;
    Date date;
    string accountable; //responsável

public:
    Service(string CSVservice);
    Service(char serviceType, Date date, string accountable);
    char getServiceType() const;
    Date getDate() const;
    string getAccountable() const;
    void setDate(Date date);
    void setServiceType(char type);
    void setAccountable(string accountable);
    bool operator< (Service &s); //sort pelas datas, se forem igual pelo nome do accountable
    friend ostream& operator<<(ostream& os , const Service& service);
};


#endif //TP1_AED_SERVICE_H
