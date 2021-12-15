#include "Time.h"
Time::Time(int hour, int minute, int second):hour(hour),minute(minute),second(second){}

void Time::setSecond(int second) {this->second = second;}

void Time::setMinute(int minute) {this->minute = minute;}

void Time::setHour(int hour) {this->hour = hour;}

int Time::getSecond() const {return second;}

int Time::getMinute() const {return minute;}

int Time::getHour() const {return hour;}

bool Time::operator == (const Time &t1) const
{
    return (hour == t1.getHour()) && (minute == t1.getMinute()) && (second == t1.getSecond());
}

bool Time::operator<(const Time &t1) const
{
    if (hour != t1.getHour()) return hour < t1.getHour();
    if (minute != t1.getMinute()) return minute < t1.getMinute();
    return second < t1.getSecond();
}
