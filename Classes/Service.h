//
// Created by jeffe on 25/11/2021.
//

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
    char service_type[1];
    date data;
    string accountable;
};


#endif //TP1_AED_SERVICE_H
