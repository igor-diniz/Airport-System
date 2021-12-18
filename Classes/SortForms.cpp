
bool sortAirportByNameAsc(const Airport& a1, const Airport& a2)
{
    return a1.getName() < a2.getName();
}

bool sortAirportByNameDesc(const Airport& a1, const Airport& a2)
{
    return a1.getName() > a2.getName();
}

bool sortAirportByInitialsAsc(const Airport& a1, const Airport& a2)
{
    return a1.getInitials() < a2.getInitials();
}

bool sortAirportByInitialsDesc(const Airport& a1, const Airport& a2)
{
    return a1.getInitials() > a2.getInitials();
}

bool sortTransportByTypeAsc(const Transport& t1, const Transport& t2)
{
    return t1.getType() < t2.getType();
}

bool sortTransportByTypeDesc(const Transport& t1, const Transport& t2)
{
    return t1.getType() > t2.getType();
}

bool sortTransportByTimeAsc(const Transport& t1, const Transport& t2)
{
    return t1.getTime() < t2.getTime();
}

bool sortTransportByTimeDesc(const Transport& t1, const Transport& t2)
{
    return !(t1.getTime() < t2.getTime());
}

bool sortTransportByDistanceAsc(const Transport& t1, const Transport& t2)
{
    return t1.getDistance() < t2.getDistance();
}

bool sortTransportByDistanceDesc(const Transport& t1, const Transport& t2)
{
    return t1.getDistance() > t2.getDistance();
}

bool sortPlaneByRegAsc(const Plane& p1, const Plane& p2)
{
    return p1.getRegistration() < p2.getRegistration();
}

bool sortPlaneByRegDesc(const Plane& p1, const Plane& p2)
{
    return p1.getRegistration() > p2.getRegistration();
}

bool sortPlaneByCapacityAsc(const Plane& p1, const Plane& p2)
{
    return p1.getCapacity() < p2.getCapacity();
}

bool sortPlaneByCapacityDesc(const Plane& p1, const Plane& p2)
{
    return p1.getCapacity() > p2.getCapacity();
}

bool sortPlaneByTypeAsc(const Plane& p1, const Plane& p2)
{
    return p1.getType() < p2.getType();
}

bool sortPlaneByTypeDesc(const Plane& p1, const Plane& p2)
{
    return p1.getType() > p2.getType();
}


