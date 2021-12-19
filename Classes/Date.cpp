#include "Date.h"
#include <sstream>
#include <iomanip>

unsigned stringDateToInt(string str) //converte uma string para inteiro
{
    unsigned int number;
    stringstream convert_string(str);
    convert_string >> number;
    return number;
}

Date::Date(int y, int m, int d):year(y),month(m),day(d){}

Date::Date(string date){
    stringstream ssDay, ssMonth, ssYear;
    string day, month, year;

    ssDay << date[8] << date[9];
    ssDay >> day;
    ssMonth << date[5] << date[6];
    ssMonth >> month;
    ssYear << date[0] << date[1] << date[2] << date[3];
    ssYear >> year;

    this->year = stringDateToInt(year);
    this->month = stringDateToInt(month);
    this->day = stringDateToInt(day);
}


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

bool Date::operator == (const Date& d1) const{
    return (
    year == d1.getYear() &&
    month == d1.getMonth() &&
    day == d1.getDay()
    );
}
ostream& operator<<(ostream& os , const Date& date)
{
    os << setw(4) << setfill('0') << date.getYear() <<"/"
       << setw(2) << setfill('0') << date.getMonth() << "/"
       << setw(2) << setfill('0') << date.getDay();
    return os;
}

