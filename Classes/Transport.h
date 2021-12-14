
#ifndef TP1_AED_TRANSPORT_H
#define TP1_AED_TRANSPORT_H
struct Time //operadores definidos no cpp
{
    int hour = 0;
    int minutes = 0;
    int seconds = 0;
};
//Um local
//de transporte terrestre é caracterizado, no mínimo, por tipo de transporte (metro, autocarro, comboio), distância
//ao aeroporto, horário.
#include <list>

class Transport{
    char type;
    float distance;
    Time time; //ainda tem q fazer isso aqui

public:
    Transport(char type,float distance,Time time);
    char getType() const;
    float getDistance() const;
    Time getTime() const;
    void setType(char type);
    void setDistance(float distance);
    void setTime(Time time);
    bool operator<(const Transport& transp) const;
    bool operator==(const Transport& transp) const;
};


#endif //TP1_AED_TRANSPORT_H
