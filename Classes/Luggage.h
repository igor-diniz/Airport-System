#ifndef TP1_AED_LUGGAGE_H
#define TP1_AED_LUGGAGE_H
#include <string>

using namespace std;


class Luggage {
private:
    static int nextId; ///incrementor for next luggage creation
    int id; ///actual luggage id
public:
    Luggage();
    Luggage(string CSVluggage);
    int getId() const;
    ///
    /// \param luggage luggages are compared by ID
    ///
    bool operator==(const Luggage& luggage);
};


#endif //TP1_AED_LUGGAGE_H
