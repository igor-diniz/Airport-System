#ifndef TP1_AED_LUGGAGE_H
#define TP1_AED_LUGGAGE_H


class Luggage {
private:
    static int nextId;
    int id;
public:
    Luggage();
    int getId() const;
    bool operator==(const Luggage& luggage);
};


#endif //TP1_AED_LUGGAGE_H
