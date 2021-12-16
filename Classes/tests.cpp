#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Service.h"
#include "Airport.h"
#include "Plane.h"
#include "Passenger.h"
#include "App.h"

using testing::Eq;
/*
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

TEST(test_3, buyTickets){
    Airport a1("Guarulhos", "GRU");
    Airport a2("Tom Jobim", "GIG");
    Date d1(2021,01,26);
    Date d2(2021,01,27);
    Flight f1(d2,d1,a1,a2,200);
    Passenger p1("Igor Diniz", "XL459635"), p2("Ian Italo", "GB264578"),
    p3("Eduardo da Silva", "GB765844"), p4("Ingrid Rodrigues", "KP256987"),
    p5("Laura Ferreira", "SW999999");
    p2.buyTicket(f1, true);
    Ticket t1(1,f1);
    ASSERT_EQ(t1, p2.getTicket());
    ASSERT_EQ(true, p2.getTicket().getLuggageStatus());
    vector<pair<Passenger,bool>> passengers;
}
*/

