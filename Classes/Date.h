#ifndef TP1_AED_DATE_H
#define TP1_AED_DATE_H
#include <string>
using namespace std;

class Date
{
private:
    int year;
    int month;
    int day;
public:
    Date(){};
    Date(int y, int m , int d);
    Date(string date); // "YYYY/MM/DD" format
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);
    bool operator < (const Date& d1) const;
    bool operator != (const Date& d1) const;
    bool operator == (const Date& d1) const;
    friend ostream& operator<<(ostream& os , const Date& date);
};
#endif //TP1_AED_DATE_H
