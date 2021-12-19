
#ifndef TP1_AED_TRANSPORT_H
#define TP1_AED_TRANSPORT_H
#include <list>
#include "Time.h"
#include <iostream>

class Transport{
    char type;
    float distance;
    Time time;
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
