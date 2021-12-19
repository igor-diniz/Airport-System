
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

bool sortFlightByDepAsc(const Flight& f1, const Flight& f2)
{
    return f1.getDepartureDate() < f2.getDepartureDate();
}

bool sortFlightByDepDesc(const Flight& f1, const Flight& f2)
{
    return !(f1.getDepartureDate() < f2.getDepartureDate());
}

bool sortFlightByDurationAsc(const Flight& f1, const Flight& f2)
{
    return f1.getDuration() < f2.getDuration();
}

bool sortFlightByDurationDesc(const Flight& f1, const Flight& f2)
{
    return !(f1.getDuration() < f2.getDuration());
}

bool sortFlightByOriginAsc(const Flight& f1, const Flight& f2)
{
    return f1.getOrigin() < f2.getOrigin();
}

bool sortFlightByOriginDesc(const Flight& f1, const Flight& f2)
{
    return !(f1.getOrigin() < f2.getOrigin());
}

bool sortFlightByAvailableAsc(const Flight& f1, const Flight& f2)
{
    return f1.getAvailableSeats() < f2.getAvailableSeats();
}

bool sortFlightByAvailableDesc(const Flight& f1, const Flight& f2)
{
    return f1.getAvailableSeats() > f2.getAvailableSeats();
}

bool sortFlightByDestinationAsc(const Flight& f1, const Flight& f2)
{
    return f1.getDestination() < f2.getDestination();
}

bool sortFlightByDestinationDesc(const Flight& f1, const Flight& f2)
{
    return !(f1.getDestination() < f2.getDestination());
}

bool sortPassengersByNameAsc(const Passenger& p1, const Passenger& p2)
{
    return p1.getName() < p2.getName();
}

bool sortPassengersByNameDesc(const Passenger& p1, const Passenger& p2)
{
    return p1.getName() > p2.getName();
}

bool sortPassengersByPassAsc(const Passenger& p1, const Passenger& p2)
{
    return p1.getPassport() < p2.getPassport();
}

bool sortPassengersByPassDesc(const Passenger& p1, const Passenger& p2)
{
    return p1.getPassport() > p2.getPassport();
}

bool sortTicketByFlightAsc(const Ticket& t1, const Ticket& t2)
{
    return t1.getFlightAssocited().getId() < t2.getFlightAssocited().getId();
}

bool sortTicketByFlightDesc(const Ticket& t1, const Ticket& t2)
{
    return t1.getFlightAssocited().getId() > t2.getFlightAssocited().getId();
}