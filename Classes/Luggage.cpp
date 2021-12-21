#include <sstream>
#include "Luggage.h"
#include <sstream>

int Luggage::nextid = 0;

Luggage::Luggage(int ticketId){
    nextid++;
    luggageId = nextid;
    this->ticketId = ticketId;
}

Luggage::Luggage(string CSVluggage){
    stringstream ssLuggage;
    ssLuggage << CSVluggage;
    string strLuggageId,strTicketId;
    getline(ssLuggage, strLuggageId, ',');
    getline(ssLuggage, strTicketId);
    luggageId = stoi(strLuggageId);
    nextid = luggageId;
    ticketId = stoi(strTicketId);
}

int Luggage::getId() const
{
    return luggageId;
}

int Luggage::getTicketId() const
{
    return ticketId;
}

bool Luggage::operator==(const Luggage &luggage)
{
    return luggageId == luggage.getId();
}

ostream& operator<<(ostream& os , const Luggage& luggage)
{
    os << "Luggage ID: " << luggage.getId() << endl;
    os << "Ticket ID: " << luggage.getTicketId() << endl;
    return os;
}