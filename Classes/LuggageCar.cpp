#include "LuggageCar.h"

LuggageCar::LuggageCar(int c,int n,int m, Flight flight){
    this-> c = c;
    this-> n = n;
    this-> m = m;
    this-> flight = flight;
    capacity = c * n * m;
    availability = capacity;

}

list<Luggage> LuggageCar::setLuggageInCar(list<Luggage> &luggageOutCar)
{
    if (luggageOutCar.empty())  return luggageOutCar;

    stack<Luggage> pilhaaux;
    list<stack<Luggage>> carruagemsaux;

    for (int i = 0; i < c; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k< m; k++)
            {
                pilhaaux.push(luggageOutCar.back());
                luggageOutCar.pop_back();
                if (luggageOutCar.empty())
                {
                    carruagemsaux.push_back(pilhaaux);
                    luggageInCar.push_back(carruagemsaux);
                    return luggageOutCar;
                }
            }
            carruagemsaux.push_back(pilhaaux);
        }
        luggageInCar.push_back(carruagemsaux);
    }
    return luggageOutCar;
    /*for (auto carruagem: luggageInCar)
    {
        for (auto pilha: carruagem)
        {
            while (pilha.size() != m)
            {
                pilha.push(luggageOutCar.front());
                luggageOutCar.pop_front();
                availability -= 1;
                if (luggageOutCar.empty()) return luggageOutCar; //isso ta retornando uma lista vazia
            }
        }
    }
    return luggageOutCar;*/
}
void addLuggages()
{}