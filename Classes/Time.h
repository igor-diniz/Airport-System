#ifndef CMAKECACHE_TXT_TIME_H
#define CMAKECACHE_TXT_TIME_H


class Time {
    int hour;
    int minute;

public:
    Time(){};
    Time(int hour, int minutes = 0);
    int getHour() const;
    int getMinute() const;
    void setHour(int hour);
    void setMinute(int minute);
    bool operator < (const Time& t1) const;
    bool operator == (const Time& t1) const;
};


#endif //CMAKECACHE_TXT_TIME_H
