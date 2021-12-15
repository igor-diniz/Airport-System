#include "Transport.h"
Transport::Transport(char type, float distance, Time time)
{
    this->type = type;
    this->distance = distance;
    this->time = time;
}

void Transport::setDistance(float distance) {this->distance = distance;}

void Transport::setTime(Time time) {this->time = time;}

void Transport::setType(char type) {this->type = type;}

Time Transport::getTime() const {return this->time;}

float Transport::getDistance() const {return this->distance;}

char Transport::getType() const {return this->type;}

bool Transport::operator==(const Transport &transp) const
{
    return (time == transp.getTime()) && (distance == transp.getDistance()) && (this->type != transp.getType());
}

bool Transport::operator<(const Transport &transp) const
{
    if(!(this->time == transp.getTime()))
    {
        return this->time < transp.getTime();
    }
    else if(this->distance != transp.getDistance())
    {
        return this->distance < transp.getDistance();
    }
    else
        return this->type < transp.getType();
}




