#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Service.h"
#include "Airport.h"
#include "Plane.h"
#include "Time.h"


using testing::Eq;

//só pra ver se funciona
TEST(test_1, buildService){
    Date d1(2002,1,26);
    Service s1('M', d1, "Eduardo");
    ASSERT_EQ('M', s1.getServiceType());
    ASSERT_EQ(2002, s1.getDate().getYear());
    ASSERT_EQ("Eduardo", s1.getAccountable());
}
TEST(test_2, PlaneDelete) //just to show the throw
{
    list<Flight> b;
    Plane a(10,"22A","A",b);
    ASSERT_EQ(false,a.deleteFlight(4));
}
TEST(test_3, TimeTest)
{
    Time a(3,3,3);
    Time b(3,3,3);
    Time c(2,3,3);
    ASSERT_EQ(true,a==b);
    ASSERT_EQ(false,a==c);
}



