cmake_minimum_required(VERSION 3.17)
project(TP1_AED)

set(CMAKE_CXX_STANDARD 14)

add_executable(TP1_AED main.cpp Classes/Plane.cpp Classes/Plane.h Classes/Flight.cpp Classes/Flight.h Classes/Service.cpp Classes/Service.h Classes/Airport.cpp Classes/Airport.h Classes/Transport.cpp Classes/Transport.h Classes/Ticket.cpp Classes/Ticket.h Classes/Passenger.cpp Classes/Passenger.h Classes/Luggage.cpp Classes/Luggage.h)
