#include <sstream>
#include "Transport.h"
Transport::Transport(char type, float distance, Time time)
{
    this->type = type;
    this->distance = distance;
    this->time = time;
}

Transport::Transport(string CSVtransport){
    stringstream ssTransport;
    string strTime, strDistance;

    ssTransport << CSVtransport;
    //transportType
    ssTransport.get(type); ssTransport.get();

    //transportDistance
    getline(ssTransport, strDistance, ',');
    distance = stoi(strDistance);

    //waitingTime
    getline(ssTransport, strTime);
    time = Time(strTime);
}



void Transport::setDistance(float distance) {this->distance = distance;}

void Transport::setTime(Time time) {this->time = time;}

void Transport::setType(char type) {this->type = type;}

Time Transport::getTime() const {return this->time;}

float Transport::getDistance() const {return this->distance;}

char Transport::getType() const {return this->type;}

bool Transport::operator==(const Transport &transp) const
{
    return (time == transp.getTime()) && (distance == transp.getDistance()) && (type == transp.getType());
}

bool Transport::operator<(const Transport &transp) const
{
    if(!(time == transp.getTime())) return time < transp.getTime();
    if(distance != transp.getDistance()) return distance < transp.getDistance();
    return type < transp.getType();
}
std::ostream& operator<<(std::ostream& os , const Transport& transport)
{
    os << transport.getType() << " - " << transport.getDistance() << " - " << transport.getTime();
    return os;
}




