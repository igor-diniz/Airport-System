#ifndef TP1_AED_PLANE_H
#define TP1_AED_PLANE_H

#include "Flight.h"
#include <list>
#include <string>
#include <queue>
#include "Service.h"
using namespace std;
//Um avião é caracterizado, no mínimo, por: matrícula, tipo ( A310, A320, A321, A330, A340, B737, B747, ...)
//e capacidade. Um avião possui ainda um plano de voo, isto é, a lista de voos que realiza.
class Plane{
private:
    int capacity;
    string registration;
    string type;
    list<Flight> flights;
    queue<Service> servicesToDo;
    queue<Service> servicesDone;

public:
    Plane(){};
    Plane(int capacity,string registration,string type, list<Flight> &flights, queue<Service> & servicesToDo);
    Plane(int capacity,string registration,string type, list<Flight> &flights);
    void addFlight(Flight &flight); //adicionar 1 voo só
    void addFlight(list<Flight> &flights); //adiciona uma lista de voos
    void addService(Service &service);
    void addService(queue<Service> &services);
    void deleteService();
    int getCapacity() const;
    string getRegistration() const;
    string getType() const;
    list<Flight> getFlights() const;
    void deleteFlight(int id);
};


#endif //TP1_AED_PLANE_H
