#ifndef TP1_AED_LUGGAGE_H
#define TP1_AED_LUGGAGE_H


class Luggage {
private:
    static int nextId; ///incrementor for next luggage creation
    int id; ///actual luggage id
public:
    Luggage();
    int getId() const;
    ///
    /// \param luggage luggages are compared by ID
    ///
    bool operator==(const Luggage& luggage);
};


#endif //TP1_AED_LUGGAGE_H
