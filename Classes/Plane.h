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
    string type; ///The project utterance refers to this as "type", but the correct name would be "model"
    list<int> flightsId; ///Aircraft flight plan
    queue<Service> servicesToDo;
    stack<Service> servicesDone;

public:
    Plane() = default;
    ///
    /// \param capacity the Plane capacity
    /// \param registration the Plane registration (PRIMARY KEY)
    /// \param type the Plane type (A310,B737,...)
    ///
    Plane(int capacity,string registration,string type);
    ///
    /// \param CSVplane Plane in string format
    /// this constructor is used to get Plane read from file manipulation
    ///
    explicit Plane(string CSVplane);
    ///
    /// \param flight Flight that will be added to the flights list
    ///
    void addFlight(int flightId);
    ///
    /// \param service that will be added to the services to do list
    ///
    void addService(Service &service);
    ///
    /// \param oldService Service that will be added to the services done stack
    /// this method is mostly used by the read from file manipulation
    ///
    void addOldService(Service &oldService);
    ///
    /// puts the first Service on the queue into the services done stack
    ///
    void popService();
    queue<Service> getServicesToDo();
    stack<Service> getServicesDone();
    int getCapacity() const;
    void setCapacity(int capacity);
    string getRegistration() const;
    void setRegistration(string registration);
    string getType() const;
    void setType(string type);
    list<int> getFlightsId();
    ///
    /// \param id from the Flight to be deleted, returns true if it was successfully deleted
    ///
    bool deleteFlight(int flightId);
    ///
    /// \param plane planes are compared by registration
    ///
    bool operator == (const Plane &plane);
    ///
    /// \param os
    /// \param plane planes are showed in the form Registration - Type - Capacity
    ///
    friend ostream& operator<<(ostream& os , const Plane& plane);

};



#endif //TP1_AED_PLANE_H
