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
    ///
    /// \param y the Date year
    /// \param m the Date month
    /// \param d the Date day
    ///
    Date(int y, int m , int d);
    ///
    /// \param date string in "YYYY/MM/DD" format
    /// this constructor is used to get dates read from file manipulation
    ///
    explicit Date(string date);
    ///
    /// returns the Date year
    ///
    int getYear() const;
    ///
    /// returns the Date month
    ///
    int getMonth() const;
    ///
    /// returns the Date day
    ///
    int getDay() const;
    ///
    /// \param year an integer
    /// changes the date year to the parameter year
    ///
    void setYear(int year);
    ///
    /// \param month an integer
    /// changes the date month to the parameter month
    ///
    void setMonth(int month);
    ///
    /// \param day an integer
    /// changes the date day to the parameter day
    ///
    void setDay(int day);
    ///
    /// \param d1 a Date
    /// return true if the date d1 is >= them the this Date
    ///
    bool operator < (const Date& d1) const;
    ///
    /// \param d1 a Date
    /// return true if the date d1 is != them the this Date
    ///
    bool operator != (const Date& d1) const;
    ///
    /// \param d1 a Date
    /// return true if the date d1 is == this Date
    ///
    bool operator == (const Date& d1) const;
    ///
    /// \param os
    /// \param date a Date
    /// the dates are show in the form year/month/day
    /// \return
    friend ostream& operator<<(ostream& os , const Date& date);
};
#endif //TP1_AED_DATE_H
