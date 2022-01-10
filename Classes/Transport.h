
#ifndef TP1_AED_TRANSPORT_H
#define TP1_AED_TRANSPORT_H
#include <list>
#include "Time.h"
#include <iostream>

class Transport{
    char type;
    float distance;
    Time time;
public:
    ///
    /// \param type the transport type
    /// \param distance the transport distance to the airport
    /// \param time time of the day the transport is leaving the airport station/stop
    /// this constructor is used to get dates read from file manipulation
    ///
    explicit Transport(string CSVtransport);

    Transport(){};
    ///
    /// \param type the transport type
    /// \param distance the transport distance to the airport
    /// \param time time of the day the transport is leaving the airport station/stop
    ///
    Transport(char type,float distance,Time time);
    char getType() const;
    float getDistance() const;
    Time getTime() const;
    void setType(char type);
    void setDistance(float distance);
    void setTime(Time time);
    ///
    /// \param transp the transport is compared by time, then by distance, then by type
    ///
    bool operator<(const Transport& transp) const;
    ///
    /// \param transp checks if the Transport type, distance and time are equal to the equivalent transport parameters
    ///
    bool operator==(const Transport& transp) const;
    ///
    /// \param os
    /// \param transp Transports are show in the order type - distance - time
    ///
    friend std::ostream& operator<<(std::ostream& os , const Transport& transport);
};


#endif //TP1_AED_TRANSPORT_H
