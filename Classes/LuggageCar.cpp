#include "LuggageCar.h"
#include <sstream>
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

LuggageCar::LuggageCar(string CSVluggageCar){

    stringstream ssLuggageCar;
    ssLuggageCar << CSVluggageCar;

    string strID, nameAirport, initials, nCarriages, stacks, nLuggage;

    getline(ssLuggageCar, strID, ',');
    getline(ssLuggageCar, nameAirport, ',');
    getline(ssLuggageCar, initials, ',');
    getline(ssLuggageCar, nCarriages, ',');
    getline(ssLuggageCar, stacks, ',');
    getline(ssLuggageCar, nLuggage);

    id = stoi(strID);
    airport = Airport(nameAirport, initials);
    numCarriages = stoi(nCarriages);
    stacksPerCarriage = stoi(stacks);
    luggagesPerStack = stoi(nLuggage);
    availability = numCarriages * stacksPerCarriage * luggagesPerStack;
}

Airport LuggageCar::getAirport() const {
    return airport;
}

list<Luggage> LuggageCar::getLuggage() const
{
    list<list<stack<Luggage>>> aux = luggageInCar;
    list<Luggage> listaaux;
    for(list<stack<Luggage>> lista : luggageInCar)
    {
        for(stack<Luggage> stack : lista)
        {
            while(!stack.empty())
            {
                listaaux.push_back(stack.top());
                stack.pop();
            }
        }
    }
    return listaaux;

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

void LuggageCar::clear()
{
    while(!luggageInCar.empty())
    {
        luggageInCar.pop_back();
    }
    availability = luggagesPerStack * stacksPerCarriage * numCarriages;
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
