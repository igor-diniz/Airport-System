#ifndef TP1_AED_PLANE_H
#define TP1_AED_PLANE_H

#include "Flight.h"
#include <list>
#include <string>
#include <queue>
#include "Service.h"
#include <exception>
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
    stack<Service> servicesDone;

public:
    Plane() = default;
    enum SortPossibilites {ID,AVAILABLESEATS,ARRIVAL,DEPARTURE,DESTINATION,ORIGIN,CAPACITY};
    Plane(int capacity,string registration,string type);
    void addFlight(Flight &flight); //adicionar 1 voo só
    void addFlight(list<Flight> &flights); //adiciona uma lista de voos
    void addService(Service &service);
    void addService(queue<Service> &services);
    Date getLasService();
    void deleteService();
    int getCapacity() const;
    void setCapacity(int capacity);
    string getRegistration() const;
    void setRegistration(string registration);
    string getType() const;
    void setType(string type);
    list<Flight> getFlights(SortPossibilites sortOrder = ID , bool descending = false);
    bool deleteFlight(int id);
    bool operator == (const Plane &b);
    friend ostream& operator<<(ostream& os , const Plane& plane);
};



#endif //TP1_AED_PLANE_H
