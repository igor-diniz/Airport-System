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

