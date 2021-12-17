#include "Airport.h"

bool Airport_sort_nameasc(const Airport& a1, const Airport& a2)
{
    return a1.getName() < a2.getName();
}

bool Airport_sort_namedesc(const Airport& a1, const Airport& a2)
{
    return a1.getName() > a2.getName();
}

bool Airport_sort_initialsasc(const Airport& a1, const Airport& a2)
{
    return a1.getInitials() < a2.getInitials();
}

bool Airport_sort_initialsdesc(const Airport& a1, const Airport& a2)
{
    return a1.getInitials() > a2.getInitials();
}

bool transport_sort_typeasc(const Transport& t1, const Transport& t2)
{
    return t1.getType() < t2.getType();
}

bool transport_sort_typedesc(const Transport& t1, const Transport& t2)
{
    return t1.getType() > t2.getType();
}

bool transport_sort_timeasc(const Transport& t1, const Transport& t2)
{
    return t1.getTime() < t2.getTime();
}

bool transport_sort_timedesc(const Transport& t1, const Transport& t2)
{
    return !(t1.getTime() < t2.getTime());
}

bool transport_sort_distanceasc(const Transport& t1, const Transport& t2)
{
    return t1.getDistance() < t2.getDistance();
}

bool transport_sort_distancedesc(const Transport& t1, const Transport& t2)
{
    return t1.getDistance() > t2.getDistance();
}

