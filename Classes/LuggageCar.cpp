#include "LuggageCar.h"
int LuggageCar::nextid = 0;
LuggageCar::LuggageCar(Airport airport, int numCarriages, int stacksPerCarriage, int luggagesPerStack){
    nextid++;
    id = nextid;
    this-> numCarriages = numCarriages;
    this-> stacksPerCarriage = stacksPerCarriage;
    this-> luggagesPerStack = luggagesPerStack;
    this-> airport = airport;
    capacity = numCarriages * stacksPerCarriage * luggagesPerStack;
    availability = capacity;

}

Airport LuggageCar::getAirport(const Airport &airport) const {
    return airport;
}

queue<Luggage> LuggageCar::setLuggageInCar(queue<Luggage> &luggageOutCar)
{
    if (luggageOutCar.empty())  return luggageOutCar;

    stack<Luggage> pilha;
    list<stack<Luggage>> carruagens;

    while (luggageInCar.size() < numCarriages)
    {
        while(carruagens.size() < stacksPerCarriage)
        {
            while(pilha.size() < luggagesPerStack)
            {
                pilha.push(luggageOutCar.front());
                luggageOutCar.pop();
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

int LuggageCar::getId() {
    return id;
}