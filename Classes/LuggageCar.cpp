#include "LuggageCar.h"

LuggageCar::LuggageCar(Airport airport,int c,int n,int m){
    this-> c = c;
    this-> n = n;
    this-> m = m;
    this-> airport = airport;
    capacity = c * n * m;
    availability = capacity;

}

Airport LuggageCar::getAirport(const Airport &airport) const {
    return airport;
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