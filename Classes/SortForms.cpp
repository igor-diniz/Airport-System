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

bool plane_sort_regiasc(const Plane& p1, const Plane& p2)
{
    return p1.getRegistration() < p2.getRegistration();
}

bool plane_sort_regidesc(const Plane& p1, const Plane& p2)
{
    return p1.getRegistration() > p2.getRegistration();
}

bool plane_sort_capacityasc(const Plane& p1, const Plane& p2)
{
    return p1.getCapacity() < p2.getCapacity();
}

bool plane_sort_capacitydesc(const Plane& p1, const Plane& p2)
{
    return p1.getCapacity() > p2.getCapacity();
}

bool plane_sort_typeasc(const Plane& p1, const Plane& p2)
{
    return p1.getType() < p2.getType();
}

bool plane_sort_typedesc(const Plane& p1, const Plane& p2)
{
    return p1.getType() > p2.getType();
}

