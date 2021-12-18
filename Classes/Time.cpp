#include "Time.h"
#include <sstream>
/*unsigned stringToInt(string str) //converte uma string para inteiro
{
    unsigned int number;
    stringstream convert_string(str);
    convert_string >> number;
    return number;
}*/

Time::Time(int hour, int minute):hour(hour),minute(minute){}

Time::Time(string time){
    stringstream ssHours, ssMinutes;
    ssMinutes << time[3] << time[4];
    ssHours << time[0] << time[1];
    ssHours >> hour;
    ssMinutes >> minute;

}


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
ostream& operator<<(ostream& os , const Time& time)
{
    os << time.getHour() << ":" << time.getMinute();
    return os;
}
