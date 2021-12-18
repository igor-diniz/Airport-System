#include "App.h"
#include "SortForms.cpp"
#include <algorithm>

unsigned App::stringToInt(string str) //converte uma string para inteiro
{
    unsigned int number;
    stringstream convert_string(str);
    convert_string >> number;
    return number;
}

App::App(const string& passengersFile, const string& planesFile, const string& luggageCarsFile, const string& airportsFile){
    readPassengersFile(passengersFile);
    //this->readPlanesFile(planesFile);
    //this->readLuggageCarsFile(luggageCarsFile);
    readAirportsFile(airportsFile);
}

bool cinGood()
{
    if (cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << endl << endl << "Invalid Input! \n";
        cout << "Type '0' to go back: ";
        string choice;
        cin >> choice;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        return false;
    }
    return true;
}

Transport getTransportInfos()
{
    char type;
    float distance;
    int hour,minute;

    Transport transp('o',0,{0,0}); //not found
    cout << "Give the Transport specifications: \n"
            "Type: "; cin >> type;
    if (!cinGood()) return transp;
    cout << "\n";
    cout << "Distance: "; cin >> distance;
    if (!cinGood()) return transp;
    cout << "\n";
    cout << "Hour: "; cin >> hour;
    if (!cinGood()) return transp;
    cout << "\n";
    cout << "Minute: "; cin >> minute;
    if (!cinGood()) return transp;
    cout << "\n";
    transp = Transport(type,distance,{hour,minute});
    return transp;
}

void App::readPassengersFile(const string& passengersFile){
    ifstream fileToOpen;
    fileToOpen.open(passengersFile);

    if(!fileToOpen.is_open())
        cout << "Cannot open this file" << endl;
    else
    {
        string name, passport, airport, initials, date, durationStr, availableSeatsStr, ticketIdStr;
        Date departure;
        Time duration;
        Airport origin, destination;
        int availableSeats, ticketId;

        while(!fileToOpen.eof())
        {

            //passenger
            getline(fileToOpen,name,',');
            getline(fileToOpen,passport);
            Passenger passenger = Passenger(name, passport);

            //ticketID
            getline(fileToOpen, ticketIdStr, ',');
            ticketId = stringToInt(ticketIdStr);

            //departureDate
            getline(fileToOpen,date,',' );
            departure = Date(date);

            //duration
            getline(fileToOpen,durationStr,',' );
            duration = Time(duration);

            //origin
            getline(fileToOpen,airport,',' );
            getline(fileToOpen,initials,',' );
            origin = Airport(airport, initials);

            //destination
            getline(fileToOpen,airport,',' );
            getline(fileToOpen,initials,',' );
            destination = Airport(airport, initials);

            //availableSeats
            getline(fileToOpen, availableSeatsStr);
            availableSeats = stringToInt(availableSeatsStr);
            fileToOpen.get();

            Flight flight = Flight(departure, duration, origin, destination, availableSeats);
            passenger.setTicket(Ticket(ticketId, flight));
            passengers.push_back(passenger);
        }
        fileToOpen.close();
    }
}

void App::readAirportsFile(const string& airportsFile){
    ifstream fileToOpen;
    fileToOpen.open(airportsFile);

    if(!fileToOpen.is_open())
        cout << endl << "Cannot open this file" << endl;
    else
    {
        string name, initials, time, distance;
        char transportType;
        int transportDistance;
        Time waitingTime;
        Transport transport;
        Airport airport;

        while(!fileToOpen.eof())
        {

            //airportName
            getline(fileToOpen,name,',');
            getline(fileToOpen,initials);
            airport = Airport(name, initials);

            while(fileToOpen.peek() != '\n' && !fileToOpen.eof())
            {
                //transportType
                fileToOpen.get(transportType); fileToOpen.get();

                //transportDistance
                getline(fileToOpen, distance, ',');
                transportDistance = stringToInt(distance);

                //waitingTime
                getline(fileToOpen, time);
                waitingTime = Time(time);
            }
            fileToOpen.get();
            transport = Transport(transportType,transportDistance,waitingTime);
            airport.addTransport(transport);
            airports.push_back(airport);
        }
        fileToOpen.close();
    }
}

vector<int> App::possibleChoices() {
    vector<int> options = {0,1,11,12,13,14,15,21,22,23,24,31,32,33,34,35,36,41,42,43,44,45};
    return options;
}

int App::mainMenu()
{
    cout << "|===========================================================================================|\n"
            "|            ____ ______ ____   ___     ____ ____   __     ____ _   __ ______ _____         |\n"
            "|           /  _// ____//  _/  /   |   /  _// __ |  / /    /  _// | / // ____// ___/        |\n"
            "|           / / / __/   / /   / /| |   / / / /_/ // /     / / /  |/ // __/    |__|          |\n"
            "|         _/ / / /___ _/ /   / ___ | _/ / / _, _// /___ _/ / / /|  // /___  ___/ /          |\n"
            "|        /___//_____//___/  /_/  |_|/___//_/ |_|/_____//___//_/ |_//_____/ /____/           |\n"
            "|                                                                                           |\n"
            "|===========================================================================================|\n"
            "|                  Airports                   |                 Luggage Car                 |\n"
            "|=============================================|=============================================|\n"
            "|  Add Airport                           [11] |  Add Luggage Car                       [21] |\n"
            "|  Remove Airport                        [12] |  Remove Luggage Car                    [22] |\n"
            "|  Detail Airport                        [13] |  Detail Luggage Car                    [23] |\n"
            "|  Show Airports                         [14] |  Show Luggage Car                      [24] |\n"
            "|  Transports                            [15] |                                             |\n"
            "|=============================================|=============================================|\n"
            "|                    Plane                    |                  Passenger                  |\n"
            "|=============================================|=============================================|\n"
            "|  Add Plane                             [31] |  Add Passenger                         [41] |\n"
            "|  Remove Plane                          [32] |  Remove Passenger                      [42] |\n"
            "|  Detail Plane                          [33] |  Detail Passenger                      [43] |\n"
            "|  Show Plane                            [34] |  Show Passengers                       [44] |\n"
            "|  Flights                               [35] |  Tickets                               [45] |\n"
            "|  Services                              [36] |                                             |\n"
            "|=============================================|=============================================|\n"
            "|               Other operations              |                                              \n"
            "|=============================================|                                              \n"
            "|  Exit                                   [0] |                                              \n"
            "|  Save                                   [1] |                                              \n"
            "|===========================================================================================|\n";

    while(true) {
        cout << endl;
        cout << "Choose an option:";
        int choice;

        cin >> choice;
        if (cin.fail() || cin.peek() != '\n') {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid input!" << endl;
            continue;
        }
        vector<int> values = possibleChoices();
        vector<int>::iterator value = find(values.begin(), values.end(), choice);
        bool choiceIsValid = false;
        if (value != possibleChoices().end())
            choiceIsValid = true;

        if (!choiceIsValid) {
            cout << "Invalid choice!" << endl;
            continue;
        }
        return choice;
    }
}

void App::airportCreation()
{
    string name,initials;
    cout << "Give the Airport specifications:" << endl;
    cout << "Name:"; cin.get(); //necessary because '\n' keep in buffer
    getline(cin, name);
    cout << "Initials:"; cin >> initials;
    cout << endl;

    if(name == "" || initials == "")
    {
        cout << "Invalid Airport with no specification" << endl;
        return;
    }

    Airport airport(name,initials);
    for(Airport &a: airports)
    {
        if(a == airport)
        {
            cout <<"This Airport already exists" << endl;
            return;
        }
    }
    airports.push_back(airport);
    cout << "Airport added" << endl << endl;
    return;
}

void App::airportDeletion()
{
    string name,initials;
    cout << "What Airport should be deleted?" << endl;
    cout << "Name:"; cin.get(); getline(cin, name);
    cout << "Initials: "; cin >> initials; cout << endl;

    Airport airport(name,initials);
    for(Airport &a : airports)
    {
        if(a == airport)
        {
            airports.remove(a);
            cout << "Airport deleted" << endl;
            return;
        }
    }
    cout <<"Airport does not exist" << endl;
    return;
}

void App::airportFind()
{
    string name,initials;
    cout << "Enter details of what Airport should be shown:" << endl;
    cout << "Initials: "; cin >> initials; cout << endl;

    Airport airport(name,initials);
    cout << "Searching..." << endl;

    for(Airport &a : airports)
    {
        if(a == airport)
        {
            cout << "Airport found, details:" << endl
                 << airport << endl
                 << "Do you want to update it? Y/N" << endl;

            char answer;
            cin >> answer;
            if(!cinGood()) return;
            if(answer == 'y' || answer == 'Y')
            {
                updateAirport(airport);
                return;
            }
        }
    }
    cout <<"Airport does not exist." << endl;
    cout <<"Do you want to create it? (Y/N)" << endl;
    char answer;
    cin >> answer;
    if(!cinGood()) return;

    if(answer == 'y' || answer == 'Y')
    {
        airports.push_back(airport);
        cout << "Airport added!" << endl;
    }
    return;
}

void App::updateAirport(Airport &airport)
{
    string name,initials;
    cout << "What should be the new characteristics?" << endl
         << "Name:"; cin.get(); getline(cin,name);
    cout << "Initials: "; cin >> initials; cout << endl;

    Airport airportUpdated(name,initials);
    for(Airport &a: airports)
    {
        if(a == airportUpdated)
        {
            cout <<"This Airport already exists" << endl;
            return;
        }
    }
    airports.remove(airport);
    airport = airportUpdated;
    airports.push_back(airport);
    cout << "Airport Updated" << endl;
    return;
}

void App::showAirports()
{
    char choice;
    cout << "Do you want to see specific Airports? Y/N \n";
    while(true) {
        cin >> choice;
        if (cin.fail() || cin.peek() != '\n' || (choice != 'N' && choice != 'n' && choice != 'Y' && choice != 'y')) {
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            cerr << endl << endl << "Invalid answer!\n";
            continue;
        }
        break;
    }

    list<Airport> aux;
    if(choice == 'Y' || choice == 'y')
    {
        string name,initials;
        cout << "Name:"; cin.get(); getline(cin,name);
        cout << "Initials: "; cin >> initials; cout << endl;

        Airport airport(name,initials);

        for(Airport &a : airports)
        {
            if(a.getName() == name || a.getInitials() == initials)
            {
                aux.push_back(a);
            }
        }
    }

    else aux = airports; //in case the choice was "N"
    cout << "How do you want to sort the Airports? \n"
            "1 - Name ascending\n"
            "2 - Name descending\n"
            "3 - Initials ascending\n"
            "4 - Initials descending\n";
    int sortChoice;
    while(true) {
        cin >> sortChoice;
        if (cin.fail() || cin.peek() != '\n') {
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            cerr << endl << endl << "Invalid choice!\n";
            continue;
        }
        break;
    }

    switch(sortChoice)
    {
        case 1:
            aux.sort(sortAirportByNameAsc);
            break;
        case 2:
            aux.sort(sortAirportByNameDesc);
            break;
        case 3:
            aux.sort(sortAirportByInitialsAsc);
            break;
        case 4:
            aux.sort(sortAirportByInitialsDesc);
            break;
        default:
            cerr << endl << endl << "Invalid choice!\n";
            return;
    }
    int counter = 1;
    cout << "Order - Name - Initials" << endl;
    for(Airport &b: aux)
    {
        cout << counter << " - " << b << "\n";
        counter ++;
    }

    cout << "type anything to go back";
    cin >> choice;
    cin.clear();
    cin.ignore(INT_MAX,'\n');
    return;
}

void App::transportMenu()
{
    string name, initials;
    cout << "From what Airport should we manage the transports?\n"
            "Name:";cin.get(); getline(cin, name);
    cout << "Initials: ";
    cin >> initials;
    cout << "\n";
    Airport a(name, initials);
    bool exists = false;
    for (Airport b: airports) {
        if (a == b) {
            a = b;
            exists = true;
            break;
        }
    }
    if (!exists) {
        cout << "The given Airport does not exist " << endl;
        cout << "type anything to go back" << endl;
        string choice;
        cin >> choice;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        return;
    }
    while(true) {
        cout << "|==============================================|\n"
                "|                   Transport                  |\n"
                "|  Add Transport                          [1]  |\n"
                "|  Delete Transport                       [2]  |\n"
                "|  Detail Transport                       [3]  |\n"
                "|  Show Transport                         [4]  |\n"
                "|==============================================|\n";
        cout << "\nchoose an option : ";
        int choice;
        while (true) {
            cin >> choice;
            if (cin.fail() || cin.peek() != '\n') {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << endl << endl << "Invalid command!\n";
                continue;
            } else {
                break;
            }
        }
        switch (choice) {
            case 0:
                return;
            case 1:
                transportCreation(a);
                break;
            case 2:
                transportDeletion(a);
                break;
            case 3:
                transportFind(a);
                break;
            case 4:
                showTransports(a);
                break;
            default:
                cout << "not a possibilite" << endl;
        }
    }
}

void App::transportCreation(Airport &airport)
{
    Transport transp = getTransportInfos();
    Transport transpnotfound('o',0,{0,0});
    if (transp == transpnotfound) return;
    if(!(airport.getTransports().find(transp) == transpnotfound))
    {
        cout << "This transport already exists" << endl;
        return;
    }
    if(airport.addTransport(transp))
    cout << "Transport added \n";
    else cout << "Transport not added \n";
    return;
}

void App::transportDeletion(Airport &airport)
{
    Transport transp = getTransportInfos();
    if (transp == Transport('o',0,{0,0})) return;
    if((airport.getTransports().find(transp) == Transport('o',0,{0,0})))
    {
        cout << "This transport doesnt exists" << endl;
        return;
    }
    airport.deleteTransport(transp);
    cout << "Transport deleted \n";
    return;
}

void App::transportFind(Airport &airport)
{
    Transport transp = getTransportInfos();
    if (transp == Transport('o',0,{0,0})) return;
    cout << "Searching... \n";
    if((airport.getTransports().find(transp) == Transport('o',0,{0,0})))
    {
        cout << "This transport doesnt exists" << endl;
        cout <<"Do you want to create it? (Y/N)" << endl;
        char answer;
        cin >> answer;
        if(!cinGood()) return;
        if(answer == 'y' || answer == 'Y')
        {
            airport.addTransport(transp);
            cout << "Transport added!" << endl;
        }
        return;
    }
    cout << "Transport found, details: " << endl
         << "Type - Distance - Time" << endl
         << transp << endl
         << "Do you want to update it? Y/N" << endl;

    char answer;
    cin >> answer;
    if(!cinGood()) return;
    if(answer == 'y' || answer == 'Y') {
        cout << "New specifications: " << endl;
        Transport t = getTransportInfos();
        airport.addTransport(t);
        return;
    }
}

void App::showTransports(Airport &airport)
{
    char choice;
    cout << "do you want to see specific Transports? Y/N \n";
    while(true) {
        cin >> choice;
        if (cin.fail() || cin.peek() != '\n' || (choice != 'N' && choice != 'n' && choice != 'Y' && choice != 'y')) {
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            cerr << endl << endl << "Invalid answer!\n";
            continue;
        }
        else
        {
            break;
        }
    }
    list<Transport> aux;
    if(choice == 'Y' || choice == 'y')
    {
        string name, initials;
        cout << "type '0' if you dont want to specify \n";
        Transport transport = getTransportInfos();
        for (auto i = airport.getTransports().begin(); i != airport.getTransports().end(); i++)
        {
            if (transport.getTime() == (*i).getTime() || transport.getDistance() == (*i).getDistance() ||
                transport.getType() == (*i).getType())
            {
                aux.push_back(*i);
            }
        }
    }
    else
    {
        for (iteratorBST<Transport> i = airport.getTransports().begin(); i != airport.getTransports().end(); i++)
        {
            aux.push_back(*i);
        }
    }
    cout << "how do you want the transports to be sorted? \n"
            "1 - type asc\n"
            "2 - type desc\n"
            "3 - time asc\n"
            "4 - time desc\n"
            "5 - distance asc\n"
            "6 - distance desc\n";
    int sortChoice;
    while(true) {
        cin >> sortChoice;
        if (cin.fail() || cin.peek() != '\n') {
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            cerr << endl << endl << "Invalid choice!\n";
            continue;
        }
        else
        {
            break;
        }
    }
    switch(sortChoice)
    {
        case 1:
            aux.sort(sortTransportByTypeAsc);
            break;
        case 2:
            aux.sort(sortTransportByTypeDesc);
            break;
        case 3:
            aux.sort(sortTransportByTimeAsc);
            break;
        case 4:
            aux.sort(sortTransportByTimeDesc);
            break;
        case 5:
            aux.sort(sortTransportByDistanceAsc);
            break;
        case 6:
            aux.sort(sortTransportByDistanceDesc);
            break;
        default:
            cerr << endl << endl << "Invalid choice!\n";
            return;
    }
    int counter = 1;
    cout << "Order - Type - Distance - Time" << endl;
    for(Transport &b: aux)
    {
        cout << counter << " - " << b << "\n";
        counter ++;
    }
    cout << "type anything to go back";
    cin >> choice;
    cin.clear();
    cin.ignore(INT_MAX,'\n');
    return;
}

void App::planeCreation()
{
    string registration,type;
    int capacity;
    cout << "give the Plane specifications : \n"
         << "Registration: "; cin >> registration;    cout << "\n";
    cout << "Type: "; cin >> type;
    cout << "\n";
    cout << "Capacity :"; cin >> capacity;
    if(!cinGood()) return;
    if(registration == "" || type == "" ||capacity <= 0)
    {
        cout << "Invalid Plane specifications \n";
        return;
    }
    Plane a(capacity,registration,type);
    for(Plane &b : planes)
    {
        if(b == a)
        {
            cout <<"This Plane already exists \n";
            return;
        }
    }
    planes.push_back(a);
    cout << "Plane added \n";
    return;
}

void App::planeDeletion()
{
    string registration,type;
    int capacity;
    cout << "give the Plane specifications : \n"
            "Registration: "; cin >> registration;
    cout << "\n";
    cout << "Type: "; cin >> type;
    cout << "\n";
    cout << "Capacity :"; cin >> capacity;
    if(!cinGood()) return;
    Plane a(capacity,registration,type);
    for(Plane &b : planes)
    {
        if(b == a)
        {
            planes.remove(b);
            cout << "Plane deleted \n";
            return;
        }
    }
    cout <<"Plane does not exist \n";
    return;
}

void App::planeFind()
{
    string registration;
    string type = "";
    int capacity = 0;
    cout << "The registration of the Plane to Find: \n"
            "Registration: "; cin >> registration;
    cout << "\n";
    Plane a(capacity,registration,type);
    for(Plane &b : planes)
    {
        if(b == a)
        {
            cout << "Plane found, details: \n"
                 << "Registration - Type - Capacity" << endl
                 << b << endl
                 << "Do you want to update it? Y/N" << endl;

            char answer;
            cin >> answer;
            if(!cinGood()) return;
            if(answer == 'y' || answer == 'Y')
            {
                updatePlane(b);
                return;
            }
        }
    }
    cout << "Plane does not exist" << endl;
    cout <<"Do you want to create it? (Y/N)" << endl;
    char answer;
    cin >> answer;
    if(!cinGood()) return;
    if(answer == 'y' || answer == 'Y')
    {
        planes.push_back(a);
        cout << "Plane added!" << endl;
    }
    return;
}

void App::updatePlane(Plane &plane)
{
    string registration,type;
    int capacity;
    cout << "What should be the new characteristics?: \n"
            "Registration: "; cin >> registration;
    cout << "\n";
    cout << "Type: "; cin >> type;
    cout << "\n";
    cout << "Capacity :"; cin >> capacity;
    if(!cinGood()) return;
    if(registration == "" || type == "" ||capacity <= 0)
    {
        cout << "Invalid Plane specifications \n";
        return;
    }
    Plane a(capacity,registration,type);
    for(Plane &b : planes)
    {
        if(b == a)
        {
            cout <<"This Plane already exists \n";
            return;
        }
    }
    plane = a;
    return;
}

void App::showPlanes()
{
    char choice;
    cout << "do you want to see specific Planes? Y/N \n";
    while(true) {
        cin >> choice;
        if (cin.fail() || cin.peek() != '\n' || (choice != 'N' && choice != 'n' && choice != 'Y' && choice != 'y')) {
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            cerr << endl << endl << "Invalid choice!\n";
            continue;
        }
        else
        {
            break;
        }
    }
    list<Plane> aux;
    if(choice == 'Y' || choice == 'y')
    {
        string registration,type;
        int capacity;
        cout << "type '0' if you dont want to specify \n"
             << "Registration: "; cin >> registration;
        cout << "\n";
        cout << "Type: "; cin >> type;
        cout << "\n";
        cout << "Capacity :"; cin >> capacity;

        for(Plane &b : planes)
        {
            if(b.getRegistration() == registration || b.getCapacity() == capacity || b.getType() == type)
            {
                aux.push_back(b);
            }
        }
    }
    else aux = planes;
    cout << "how do you want the Planes to be sorted? \n"
         << "1 - Registration asc\n"
         << "2 - Registration desc\n"
         << "3 - Capacity asc\n"
         << "4 - Capacity desc\n"
         << "5 - Type asc\n"
         << "6 - Type desc\n";
    int sortChoice;
    while(true) {
        cin >> sortChoice;
        if (cin.fail() || cin.peek() != '\n') {
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            cerr << endl << endl << "Invalid choice!\n";
            continue;
        }
        else
        {
            break;
        }
    }
    switch(sortChoice)
    {
        case 1:
            aux.sort(sortPlaneByRegAsc);
            break;
        case 2:
            aux.sort(sortPlaneByRegDesc);
            break;
        case 3:
            aux.sort(sortPlaneByCapacityAsc);
            break;
        case 4:
            aux.sort(sortPlaneByCapacityDesc);
            break;
        case 5:
            aux.sort(sortPlaneByTypeAsc);
            break;
        case 6:
            aux.sort(sortPlaneByTypeDesc);
            break;
        default:
            cerr << endl << endl << "Invalid choice!\n";
            return;
    }
    int counter = 1;
    cout << "Order - Registration - Type - Capacity" << endl;
    for(Plane &b: aux)
    {
        cout << counter << " - " << b << "\n";
        counter ++;
    }

    cout << "type anything to go back";
    cin >> choice;
    cin.clear();
    cin.ignore(INT_MAX,'\n');
    return;
}

