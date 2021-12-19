#ifndef TP1_AED_PLANE_H
#define TP1_AED_PLANE_H

#include "Flight.h"
#include <list>
#include <string>
#include <queue>
#include "Service.h"
#include <exception>
using namespace std;
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
    Plane(int capacity,string registration,string type);
    explicit Plane(string CSVplane);
    void addFlight(Flight &flight);
    void addService(Service &service);
    void addOldService(Service &oldService);
    void popService();
    queue<Service> getServicesToDo();
    stack<Service> getServicesDone();
    int getCapacity() const;
    void setCapacity(int capacity);
    string getRegistration() const;
    void setRegistration(string registration);
    string getType() const;
    void setType(string type);
    list<Flight> getFlights();
    bool deleteFlight(int id);
    bool operator == (const Plane &b);
    friend ostream& operator<<(ostream& os , const Plane& plane);

};



#endif //TP1_AED_PLANE_H
