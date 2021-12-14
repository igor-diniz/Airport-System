#include "Transport.h"
Transport::Transport(char type, float distance, Time time)
{
    this->type = type;
    this->distance = distance;
    this->time = time;
}

bool Transport::operator<(const Transport &transp) const
{
    if(this->time != transp.getTime())
    {
        return this->time < transp.time;
    }
    else if(this->distance != transp.distance)
    {
        return this->distance < transp.distance;
    }
    else if(this->type != transp.type)
    {
        return this->type < transp.type;
    }
    else
    {
        return false;
    }
}
bool Transport::operator==(const Transport &transp) const
{
    return !(this->time != transp.time) && (this->distance == transp.distance) && (this->type != transp.type);
}
void Transport::setDistance(float distance) {this->distance = distance;}

void Transport::setTime(Time time) {this->time = time;}

void Transport::setType(char type) {this->type = type;}

Time Transport::getTime() const {return this->time;}

float Transport::getDistance() const {return this->distance;}

char Transport::getType() const {return this->type;}


