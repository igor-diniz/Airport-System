//
// Created by jeffe on 25/11/2021.
//

#ifndef TP1_AED_TRANSPORT_H
#define TP1_AED_TRANSPORT_H
struct Time
{
    int hour = 0;
    int minutes = 0;
    int seconds = 0;
};
bool operator !=(const Time& t1, const Time& t2)
{
    return !((t1.hour == t2.hour) && (t1.minutes == t2.minutes) && (t1.seconds == t2.seconds));
}
bool operator < (const Time& t1, const Time& t2)
{
    if (t1.hour != t2.hour) return t1.hour < t2.hour;
    if (t1.minutes != t2.minutes) return t1.minutes < t2.minutes;
    return t1.seconds < t2.seconds;
}
//Um local
//de transporte terrestre é caracterizado, no mínimo, por tipo de transporte (metro, autocarro, comboio), distância
//ao aeroporto, horário.
#include <list>
using namespace std;

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
