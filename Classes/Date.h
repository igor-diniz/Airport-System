#ifndef TP1_AED_DATE_H
#define TP1_AED_DATE_H

class Date
{
private:
    int year;
    int month;
    int day;
public:
    Date(){};
    Date(int y, int m , int d);
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);
    bool operator < (const Date& d1) const;
    bool operator != (const Date& d1) const;
};
#endif //TP1_AED_DATE_H
