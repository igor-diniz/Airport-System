#include "Transport.h"
Transport::Transport(char type, float distance, Time time)
{
    this->type = type;
    this->distance = distance;
    this->time = time;
    sort = TIME;
}

void Transport::setDistance(float distance) {this->distance = distance;}

void Transport::setTime(Time time) {this->time = time;}

void Transport::setType(char type) {this->type = type;}

Time Transport::getTime() const {return this->time;}

float Transport::getDistance() const {return this->distance;}

char Transport::getType() const {return this->type;}

void Transport::setSortByDistance() {sort = DISTANCE;}

void Transport::setSortByType() {sort = TYPE;}

void Transport::setSortbyTime() {sort = TIME;}

bool Transport::operator==(const Transport &transp) const
{
    return (time == transp.getTime()) && (distance == transp.getDistance()) && (this->type != transp.getType());
}

bool Transport::operator<(const Transport &transp) const
{
    switch(sort)
    {
        case TIME:
            return time < transp.getTime();
            break;
        case DISTANCE:
            return distance < transp.getDistance();
            break;
        case TYPE:
            return type < transp.getType();
            break;
        default:
            return false;
    }
}




