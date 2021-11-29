#include "Transport.h"
Transport::Transport(char type, float distance, time_t time)
{
    this->type = type;
    this->distance = distance;
    this->time = time;
}

bool Transport::operator<(const Transport &transp) const
{
    if(this->time != transp.time)
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
    return (this->time == transp.time) && (this->distance == transp.distance) && (this->type != transp.type);
}
