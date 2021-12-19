
#ifndef TP1_AED_TRANSPORT_H
#define TP1_AED_TRANSPORT_H
//Um local
//de transporte terrestre é caracterizado, no mínimo, por tipo de transporte (metro, autocarro, comboio), distância
//ao aeroporto, horário.
#include <list>
#include "Time.h"
#include <iostream>

class Transport{
    char type;
    float distance;
    Time time; //ainda tem q fazer isso aqui
public:
    explicit Transport(string CSVtransport);
    Transport(){};
    Transport(char type,float distance,Time time);
    char getType() const;
    float getDistance() const;
    Time getTime() const;
    void setType(char type);
    void setDistance(float distance);
    void setTime(Time time);
    bool operator<(const Transport& transp) const;
    bool operator==(const Transport& transp) const;
    friend std::ostream& operator<<(std::ostream& os , const Transport& transport);
};


#endif //TP1_AED_TRANSPORT_H
