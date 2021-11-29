#ifndef TP1_AED_LUGGAGECAR_H
#define TP1_AED_LUGGAGECAR_H


class LuggageCar {
    public:
        int capacity, availability;
    private:
        int c, n, m;
        bool cheio = false;
        Ticket ticket;
        capacity = c * n * m;
};


#endif //TP1_AED_LUGGAGECAR_H
