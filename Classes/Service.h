#ifndef TP1_AED_SERVICE_H
#define TP1_AED_SERVICE_H
#include <string>
#include "Date.h"
using namespace std;
class Service {
private:
    char serviceType;
    Date date;
    string accountable; ///The worker that is responsible for the service

public:
    ///
    /// \param serviceType the type of the service
    /// \param date date the service is happening
    /// \param accountable The worker that is responsible for the service
    /// this constructor is used to get dates read from file manipulation
    ///
    explicit Service(string CSVservice);
    ///
    /// \param serviceType the type of the service
    /// \param date date the service is happening
    /// \param accountable The worker that is responsible for the service
    ///
    Service(char serviceType, Date date, string accountable);
    char getServiceType() const;
    Date getDate() const;
    string getAccountable() const;
    void setDate(Date date);
    void setServiceType(char type);
    void setAccountable(string accountable);
    ///
    /// \param s the service is compared by date, then by accountable
    ///
    bool operator< (Service &s);
    ///
    /// \param os
    /// \param s Services are show in the order serviceType - date - accountable
    ///
    friend ostream& operator<<(ostream& os , const Service& service);
};


#endif //TP1_AED_SERVICE_H
