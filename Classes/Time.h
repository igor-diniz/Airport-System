#ifndef CMAKECACHE_TXT_TIME_H
#define CMAKECACHE_TXT_TIME_H


class Time {
    int hour;
    int minute;
    int second;

public:
    Time(){};
    Time(int hour, int minutes = 0, int seconds = 0);
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    void setHour(int hour);
    void setMinute(int minute);
    void setSecond(int second);
    bool operator < (const Time& t1) const;
    bool operator == (const Time& t1) const;
};


#endif //CMAKECACHE_TXT_TIME_H
