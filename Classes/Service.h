#ifndef TP1_AED_SERVICE_H
#define TP1_AED_SERVICE_H
#include <string>
using namespace std;
struct Date
{
    int day;
    int month;
    int year;
};
//a. Um serviço é caracterizado
//por tipo de serviço (manutenção/limpeza), data e funcionário responsável.
class Service {
private:
    char serviceType;
    Date date;
    string accountable; //responsável

public:
    Service(char serviceType, Date date, string accountable);
    char getserviceType() const;
    Date getdate() const;
    string getaccountable() const;
    bool operator< (Service s);
};


#endif //TP1_AED_SERVICE_H
