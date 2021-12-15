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

    stack<Luggage> pilha;
    list<stack<Luggage>> carruagens;

    while (luggageInCar.size() < c)
    {
        while(carruagens.size() < n)
        {
            while(pilha.size() < m)
            {
                pilha.push(luggageOutCar.back());
                luggageOutCar.pop_back();
                if (luggageOutCar.empty())
                {
                    carruagens.push_back(pilha);
                    luggageInCar.push_back(carruagens);
                    return luggageOutCar;
                }
            }
            carruagens.push_back(pilha);
        }
        luggageInCar.push_back(carruagens);
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