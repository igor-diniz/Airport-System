#ifndef CMAKECACHE_TXT_TIME_H
#define CMAKECACHE_TXT_TIME_H
#include <string>
using namespace std;

class Time {
    int hour;
    int minute;

public:
    Time(){};
    ///
    /// \param type the transport type
    /// \param distance the transport distance to the airport
    /// \param time time of the day the transport is leaving the airport station/stop
    ///
    Time(int hour, int minutes = 0);
    ///
    /// \param type the transport type
    /// \param distance the transport distance to the airport
    /// \param time time of the day the transport is leaving the airport station/stop
    /// this constructor is used to get dates read from file manipulation
    ///
    Time(string time); /// "HH:MM" format
    int getHour() const;
    int getMinute() const;
    void setHour(int hour);
    void setMinute(int minute);
    ///tocomment
    bool operator < (const Time& t1) const;
    ///
    /// \param t1 checks if the time minute and hour are equal to the equivalent time parameters
    ///
    bool operator == (const Time& t1) const;
    ///
    /// \param os
    /// \param t1 Times are show in the order hour - minute
    ///
    friend ostream& operator<<(ostream& os , const Time& time);
};


#endif //CMAKECACHE_TXT_TIME_H
