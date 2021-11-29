#include "Transport.h"

bool Transport::operator<(const Transport &transp)
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
