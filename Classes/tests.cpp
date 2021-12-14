#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Service.h"
#include "Airport.h"
#include "Plane.h"


using testing::Eq;

//só pra ver se funciona
TEST(test_1, buildService){
    Date d1; d1.day = 26; d1.month = 01; d1.year = 2002;
    Service s1('M', d1, "Eduardo");
    ASSERT_EQ('M', s1.getServiceType());
    ASSERT_EQ(2002, s1.getDate().year);
    ASSERT_EQ("Eduardo", s1.getAccountable());
}
TEST(test_2, PlaneDelete) //just to show the throw
{
    list<Flight> b;
    Plane a(10,"22A","A",b);
    a.deleteFlight(4);
}



