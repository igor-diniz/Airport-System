#ifndef CMAKECACHE_TXT_TIME_H
#define CMAKECACHE_TXT_TIME_H
#include <string>
using namespace std;

class Time {
    int hour;
    int minute;

public:
    Time(){};
    Time(int hour, int minutes = 0);
    Time(string time); /// "HH:MM" format
    int getHour() const;
    int getMinute() const;
    void setHour(int hour);
    void setMinute(int minute);
    bool operator < (const Time& t1) const;
    bool operator == (const Time& t1) const;
    friend ostream& operator<<(ostream& os , const Time& time);
};


#endif //CMAKECACHE_TXT_TIME_H
