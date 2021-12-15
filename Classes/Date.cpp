#include "Date.h"
Date::Date(int y, int m, int d):year(y),month(m),day(d){}

int Date::getYear() const {return year;}

int Date::getMonth() const {return month;}

int Date::getDay() const {return day;}

void Date::setYear(int year) {this->year = year;}

void Date::setMonth(int month) {this->month = month;}

void Date::setDay(int day) {this->day = day;}

bool Date::operator<(const Date &d1) const{
    if(year != d1.getYear()) return year < d1.getYear();
    else if(month != d1.getMonth()) return month < d1.getMonth();
    return day < d1.getDay();
}

bool Date::operator!=(const Date &d1) const {
    return (year != d1.getYear()) || (month != d1.getMonth()) || (day != d1.getDay());
}

