#ifndef TP1_AED_LUGGAGE_H
#define TP1_AED_LUGGAGE_H
#include <string>

using namespace std;


class Luggage {
private:
    static int nextid; ///incrementor for next luggage creation
    int luggageId, ticketId; ///current ticket id and luggage id
public:
    Luggage(){};
    Luggage(int ticketId);
    Luggage(string CSVluggage);
    int getTicketId() const;
    int getId() const;
    ///
    /// \param luggage luggages are compared by ID
    ///
    bool operator==(const Luggage& luggage);
    ///
    /// \param os
    /// \param luggage luggage is showed in the form luggage id - associated ticket id
    /// \return
    friend ostream& operator<<(ostream& os , const Luggage& luggage);
};


#endif //TP1_AED_LUGGAGE_H
