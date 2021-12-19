#include "LuggageCar.h"
int LuggageCar::nextid = 0;
LuggageCar::LuggageCar(Airport airport, int numCarriages, int stacksPerCarriage, int luggagesPerStack){
    nextid++;
    id = nextid;
    this-> numCarriages = numCarriages;
    this-> stacksPerCarriage = stacksPerCarriage;
    this-> luggagesPerStack = luggagesPerStack;
    this-> airport = airport;
    availability = numCarriages * stacksPerCarriage * luggagesPerStack;
}

Airport LuggageCar::getAirport() const {
    return airport;
}

queue<Luggage> LuggageCar::setLuggageInCar(queue<Luggage> &luggageOutCar)
{ //colocar as malas do aviao no carrinho
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
                availability--;
                if (availability == 0)
                {
                    return luggageOutCar;
                }
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
}

void LuggageCar::setAirport(Airport &airport1)
{
    this->airport = airport1;
}

int LuggageCar::getNumCarriages() const {return numCarriages;}

int LuggageCar::getNumStacks() const {return stacksPerCarriage;}

int LuggageCar::getNumLuggagesPerStack() const {return luggagesPerStack;}

int LuggageCar::getId() const{
    return id;
}
bool LuggageCar::operator==(const LuggageCar &luggageCar)
{
    return airport == luggageCar.getAirport() && numCarriages == luggageCar.getNumCarriages() && stacksPerCarriage == luggageCar.getNumStacks()
    && luggagesPerStack == luggageCar.getNumLuggagesPerStack();
}
ostream& operator<<(ostream& os , const LuggageCar& luggageCar)
{
    cout << luggageCar.getId() << " - " << luggageCar.getAirport()  << " - " << luggageCar.getNumCarriages() << " - " << luggageCar.getNumStacks()  << " - " << luggageCar.getNumLuggagesPerStack();
    return os;
}
