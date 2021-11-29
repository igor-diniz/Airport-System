#ifndef TP1_AED_SERVICE_H
#define TP1_AED_SERVICE_H
#include <string>
using namespace std;
struct date
{
    int day;
    int month;
    int year;
};
//a. Um serviço é caracterizado
//por tipo de serviço (manutenção/limpeza), data e funcionário responsável.
class Service {
    Service(char serviceType, date date, string accountable);
    char serviceType;
    date date;
    string accountable; //responsável
    char getserviceType() const;
    struct date getdate() const;
    string getaccountable() const;
};


#endif //TP1_AED_SERVICE_H
