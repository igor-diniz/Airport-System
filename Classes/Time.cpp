#include "Time.h"
Time::Time(int hour, int minute):hour(hour),minute(minute){}

void Time::setMinute(int minute) {this->minute = minute;}

void Time::setHour(int hour) {this->hour = hour;}

int Time::getMinute() const {return minute;}

int Time::getHour() const {return hour;}

bool Time::operator == (const Time &t1) const
{
    return (hour == t1.getHour()) && (minute == t1.getMinute());
}

bool Time::operator<(const Time &t1) const
{
    if (hour != t1.getHour()) return hour < t1.getHour();
    return minute < t1.getMinute();

}
