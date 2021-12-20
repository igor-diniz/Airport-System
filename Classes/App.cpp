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
    //readPassengersFile(passengersFile);
    readPlanesFile(planesFile);
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

/*void App::readPassengersFile(const string& passengersFile){
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
*/
/*void App::readPassengersFile(const string& passengersFile){
    ifstream fileToOpen;
    fileToOpen.open(passengersFile);

    if(!fileToOpen.is_open())
        cout << "Cannot open Passengers file" << endl;
    else
    {
        string name, passport, ticketIdStr, CSVflight;
        int ticketId;

        while(!fileToOpen.eof())
        {
            //passenger
            getline(fileToOpen,name,',');
            getline(fileToOpen,passport);
            Passenger passenger = Passenger(name, passport);

            //ticketID
            getline(fileToOpen, ticketIdStr, ',');
            ticketId = stringToInt(ticketIdStr);

            //flight
            getline(fileToOpen, CSVflight);
            fileToOpen.get();
            Flight flight = Flight(CSVflight);

            //passenger.setTicket(Ticket(ticketId, flight));
            passengers.push_back(passenger);
        }
        fileToOpen.close();
    }
}
*/
void App::readAirportsFile(const string& airportsFile){
    ifstream fileToOpen;
    fileToOpen.open(airportsFile);

    if(!fileToOpen.is_open())
        cout << endl << "Cannot open Airports file" << endl;
    else
    {
        string name, initials, CSVtransport;

        while(!fileToOpen.eof())
        {
            //airport
            getline(fileToOpen,name,',');
            getline(fileToOpen,initials);
            Airport airport = Airport(name, initials);

            while(fileToOpen.peek() != '\n' && !fileToOpen.eof())
            {
                //transports
                getline(fileToOpen, CSVtransport);
                Transport transport = Transport(CSVtransport);
                airport.addTransport(transport);
            }
            fileToOpen.get();
            airports.push_back(airport);
        }
        fileToOpen.close();
    }
}

void App::readPlanesFile(const string &planesFile) {
    ifstream fileToOpen;
    fileToOpen.open(planesFile);

    if(!fileToOpen.is_open())
    {
        cout << endl << "Cannot open Planes file" << endl;
        return;
    }

    string CSVvalue, flag;

    while(!fileToOpen.eof())
    {
        getline(fileToOpen, CSVvalue);
        Plane plane = Plane(CSVvalue);
        //cout << plane << endl;
        getline(fileToOpen, CSVvalue);
        flag = "FLIGHTS";

        while(true)
        {
            switch (flag[0])
            {
                case ('F'):
                    getline(fileToOpen, CSVvalue);
                    if (CSVvalue == "NEW_SERVICES")
                    {
                        flag = "NEW_SERVICE";
                        break;
                    }

                    else{
                        Flight flight = Flight(CSVvalue);
                        //cout << flight << endl;
                        plane.addFlight(flight);
                        break;
                    }

                case('N'):
                    getline(fileToOpen, CSVvalue);

                    if (CSVvalue == "OLD_SERVICES")
                    {
                        flag = "OLD_SERVICES";
                        break;
                    }

                    else{
                        Service newService = Service(CSVvalue);
                        //cout << newService.getServiceType() << endl;
                        plane.addService(newService);
                        break;
                    }


                case('O'):
                    if(fileToOpen.peek() == '\n') {
                        flag = "PLANE";
                        break;
                    }
                    getline(fileToOpen, CSVvalue);

                    Service oldService = Service(CSVvalue);
                    //cout << "OLD" << oldService.getServiceType() << endl;
                    plane.addOldService(oldService);
                    break;
            }
            if(fileToOpen.eof() || fileToOpen.peek() == '\n')
            {
                fileToOpen.get();
                break;
            }
        }
        planes.push_back(plane);
    }
    fileToOpen.close();
}


vector<int> App::possibleChoices() {
    vector<int> options = {0,1,11,12,13,14,15,21,22,23,24,31,32,33,34,35,36,41,42,43,44,45};
    return options;
}

void App::mainMenu()
{
    while(true) {
    cout << "|===========================================================================================|\n"
            "|            ____ ______ ____   ___     ____ ____    __     ____ _   __ ______ _____        |\n"
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
            "|=============================================|\n";

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
        if (value != values.end())
            choiceIsValid = true;

        if (!choiceIsValid) {
            cout << "Invalid choice!" << endl;
            continue;
        }
        switch (choice)
        {
            case 0: exit(0);
            case 1: save(); exit(0);
            case 11: airportCreation(); break;
            case 12: airportDeletion(); break;
            case 13: airportFind(); break;
            case 14: showAirports(); break;
            case 15: transportMenu(); break;
            case 21: luggageCarCreation(); break;
            case 22: luggageCarDeletion(); break;
            case 23: luggageCarFind(); break;
            case 24: showluggageCars(); break;
            case 31: planeCreation(); break;
            case 32: planeDeletion(); break;
            case 33: planeFind(); break;
            case 34: showPlanes(); break;
            case 35: flightMenu(); break;
            case 36: serviceMenu(); break;
            case 41: passengerCreation(); break;
            case 42: passengerDeletion(); break;
            case 43: passengerFind(); break;
            case 44: showPassengers(); break;
            case 45: ticketMenu(); break;
            default:
                cout << "invalid choice!";
                break;
        }
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
    cout << "What Airport should be removed" << endl;
    cout << "Name:"; cin.get(); getline(cin, name);
    cout << "Initials: "; cin >> initials; cout << endl;

    Airport airport(name,initials);
    for(Airport &a : airports)
    {
        if(a == airport)
        {
            airports.remove(a);
            cout << "Airport removed" << endl;
            return;
        }
    }
    cout <<"Airport does not exist" << endl;
    return;
}

void App::airportFind()
{
    string initials;
    cout << "Enter details of what Airport should be shown:" << endl;
    cout << "Initials: "; cin >> initials; cout << endl;

    Airport airport("",initials);
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
            else if(answer == 'n' || answer == 'N') return;
            else
            {
                cout << "invalid character! considered as a 'N'" << endl;
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
        string name;
        cout << "give the Airport name: "; cin.get(); getline(cin, name); //missing information since we searched using only the key
        airport.setName(name);
        airports.push_back(airport);
        cout << "Airport added!" << endl;
    }
    else if(answer == 'n' || answer == 'N') return;
    else
    {
        cout << "invalid character! considered as a 'N'" << endl;
        return;
    }
}

void App::updateAirport(Airport &airport)
{
    string name,initials;
    cout << "What should be the new characteristics? (type 0 to not change)" << endl
         << "Initials: "; cin >> initials; cout << endl;
    if(initials != "0")
    {
        Airport airportCheck("",initials);
        for(Airport &a: airports)
        {
            if(a == airportCheck)
            {
                cout <<"This Airport already exists" << endl;
                return;
            }
        }
        airport.setInitials(initials);
    }
     cout<< "Name:"; cin.get(); getline(cin,name);
         if(name != "0") airport.setName(name);
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
    else if(choice == 'n' || choice == 'N') aux = airports;
    else
    {
        cout << "invalid character! considered as a 'N'" << endl;
        aux = airports;;
    }

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
    Airport* a = new Airport(name, initials);
    bool exists = false;
    for (Airport& b: airports) {
        if (*a == b) {
            a = &b;
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
                "|  Remove Transport                       [2]  |\n"
                "|  Detail Transport                       [3]  |\n"
                "|  Show Transport                         [4]  |\n"
                "|  Return                                 [0]  |\n"
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
                transportCreation(*a);
                break;
            case 2:
                transportDeletion(*a);
                break;
            case 3:
                transportFind(*a);
                break;
            case 4:
                showTransports(*a);
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
    cout << "Transport removed \n";
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
        else if(answer == 'n' || answer == 'N') return;
        else
        {
            cout << "invalid character! considered as a 'N'" << endl;
            return;
        }
    }
    cout << "Transport found, details: " << endl
         << "Type - Distance - Time" << endl
         << transp << endl
         << "Do you want to update it? Y/N" << endl;

    char answer;
    cin >> answer;
    if(!cinGood()) return;
    if(answer == 'y' || answer == 'Y') {
        updateTransport(transp,airport);
        return;
    }
    else if(answer == 'n' || answer == 'N') return;
    else
    {
        cout << "invalid character! considered as a 'N'" << endl;
        return;
    }
}

void App::updateTransport(Transport &transport, Airport& airport)
{
    char type;
    float distance;
    Time time = transport.getTime();
    int hour,minute;
    Transport checkTransport = transport;

    cout << "What should be the new characteristics? (type 0 to not change)" << endl
    <<  "Type: "; cin >> type;
    if (!cinGood()) return;
    if(type != '0') checkTransport.setType(type);
    cout << "\n";
    cout << "Distance: "; cin >> distance;
    if (!cinGood()) return;
    if (distance != 0) checkTransport.setDistance(distance);
    cout << "\n";
    cout << "Hour: "; cin >> hour;
    if (!cinGood()) return;
    if(hour != 0) time.setHour(hour);
    cout << "\n";
    cout << "Minute: "; cin >> minute;
    if (!cinGood()) return;
    if(minute != 0) time.setMinute(minute);
    cout << "\n";
    checkTransport.setTime(time);
    if(airport.getTransports().find(checkTransport) == Transport ('o',0,{0,0}))
    {
        transport = checkTransport;
        cout << "Transport updated!" << endl;
        return;
    }
    cout << "Transport already exists!" << endl;
    return;
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
    else if(choice != 'n' && choice != 'N')
    {
        cout << "invalid character! considered as a 'N'" << endl;
        return;
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

void App::luggageCarCreation()
{
    Airport* airport;
    int numCarriages, stacksPerCarriage, luggagesPerStack;
    string initials;
    cout << "To what airport is this car associated?" << endl;
    cout << "Initials:"; cin >> initials;
    cout << endl;

    if(initials == "")
    {
        cout << "Invalid Airport with no specification" << endl;
        return;
    }

    airport = new Airport("",initials);
    bool exists = false;
    for(Airport &a: airports)
    {
        if(a == *airport)
        {
            airport = &a;
            exists = true;
        }
    }
    if(!exists)
    {
        cout << "Airport does not exist!" << endl;
    }
    cout << "How many carriages: "; cin >> numCarriages;
    if(!cinGood()) return;
    if(numCarriages < 0)
    {
        cout << "cant create car with negative number" << endl;
    }
    cout << "How many stacks per carriage: "; cin >> stacksPerCarriage;
    if(!cinGood()) return;
    if(stacksPerCarriage < 0)
    {
        cout << "cant create car with negative number" << endl;
    }
    cout << "How many luggages per stack: "; cin >> luggagesPerStack;
    if(!cinGood()) return;
    if(luggagesPerStack < 0)
    {
        cout << "cant create car with negative number" << endl;
    }
    LuggageCar luggageCar(*airport,numCarriages,stacksPerCarriage,luggagesPerStack);
    luggageCars.push_back(luggageCar);
    cout << "Luggage Car added!" << endl;
    return;
}

void App::luggageCarDeletion()
{
    Airport* airport;
    int numCarriages, stacksPerCarriage, luggagesPerStack;
    string initials;
    cout << "To what airport is this car associated?" << endl;
    cout << "Initials:"; cin >> initials;
    cout << endl;

    if(initials == "")
    {
        cout << "Invalid Airport with no specification" << endl;
        return;
    }

    airport = new Airport("",initials);
    bool exists = false;
    for(Airport &a: airports)
    {
        if(a == *airport)
        {
            airport = &a;
            exists = true;
        }
    }
    if(!exists)
    {
        cout << "Airport does not exist!" << endl;
    }
    cout << "How many carriages: "; cin >> numCarriages;
    if(!cinGood()) return;
    cout << "How many stacks per carriage: "; cin >> stacksPerCarriage;
    if(!cinGood()) return;
    cout << "How many luggages per stack: "; cin >> luggagesPerStack;
    if(!cinGood()) return;
    LuggageCar luggageCar(*airport,numCarriages,stacksPerCarriage,luggagesPerStack);
    if(find(luggageCars.begin(),luggageCars.end(),luggageCar) == luggageCars.end())
    {
        cout << "This luggage car does not exist!" << endl;
        return;
    }
    luggageCars.remove(luggageCar);
    cout << "Luggage removed!" << endl;
}

void App::luggageCarFind()
{
    Airport* airport;
    int numCarriages, stacksPerCarriage, luggagesPerStack;
    string initials;
    cout << "To what airport is this car associated?" << endl;
    cout << "Initials:"; cin >> initials;
    cout << endl;

    if(initials == "")
    {
        cout << "Invalid Airport with no specification" << endl;
        return;
    }

    airport = new Airport("",initials);
    bool exists = false;
    for(Airport &a: airports)
    {
        if(a == *airport)
        {
            airport = &a;
            exists = true;
        }
    }
    if(!exists)
    {
        cout << "Airport does not exist!" << endl;
    }
    cout << "How many carriages: "; cin >> numCarriages;
    if(!cinGood()) return;
    cout << "How many stacks per carriage: "; cin >> stacksPerCarriage;
    if(!cinGood()) return;
    cout << "How many luggages per stack: "; cin >> luggagesPerStack;
    if(!cinGood()) return;
    LuggageCar luggageCar(*airport,numCarriages,stacksPerCarriage,luggagesPerStack);
    if(find(luggageCars.begin(),luggageCars.end(),luggageCar) == luggageCars.end())
    {
        char answer;
        cout << "This luggage car does not exist!" << endl;
        cout << "Do you want to create it? (Y/N)"; cin >> answer;
        if(!cinGood()) return;
        if(answer == 'y' || answer == 'Y')
        {
            luggageCars.push_back(luggageCar);
            cout << "Luggage car created!" << endl;
            return;
        }
        else if(answer == 'N' || answer == 'n')
        {
            return;
        }
        else
        {
            cout << "invalid character! considered as a 'N'" << endl;
            return;
        }
    }
    cout << "Luggage car found, details: " << endl
         << "Id" << " - " << "Airport" << " - " << "NumCarriages" << " - " << "NumStacks"  << " - " << "NumLuggagesPerStack" << endl
         << luggageCar << endl
         << "Do you want to update it? Y/N" << endl;

    char answer;
    cin >> answer;
    if(!cinGood()) return;
    if(answer == 'y' || answer == 'Y')
    {
        Airport *airport1;
        cout << "What should be the new Airport of the Car: "
        << "Initials: "; cin >> initials;

        if(initials == "")
        {
            cout << "Invalid Airport with no specification" << endl;
            return;
        }

        airport1 = new Airport("",initials);
        bool exists = false;
        for(Airport &a: airports)
        {
            if(a == *airport1)
            {
                airport1 = &a;
                exists = true;
            }
        }
        if(!exists)
        {
            cout << "Airport does not exist!" << endl;
        }
        else
        {
            for(LuggageCar& luggageCar1 : luggageCars)
            {
                if(luggageCar == luggageCar1)
                {
                    luggageCar1.setAirport(*airport1);
                    cout << "Luggage car updated to new airport!" << endl;
                    cout << "should the Luggages be cleared from the car?" << endl;
                    cin >> answer;
                    if(!cinGood()) return;
                    if(answer == 'y'||answer == 'Y')
                    {
                        luggageCar1.clear();
                    }
                    else if(answer != 'N' && answer != 'n')
                    {
                        cout << "invalid character! considered as a 'N'" << endl;
                    }
                }
            }
        }
    }
    else if(answer == 'N' || answer == 'n')
    {
        return;
    }
    else
    {
        cout << "invalid character! considered as a 'N'" << endl;
        return;
    }
}

void App::showluggageCars()
{
    char choice;
    cout << "do you want to see specific Luggage cars? Y/N \n";
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
    list<LuggageCar> aux;
    if(choice == 'Y' || choice == 'y')
    {
        cout << "type '0' if you dont want to specify \n";
        Airport airport;
        int numCarriages, stacksPerCarriage, luggagesPerStack;
        string initials;
        cout << "To what airport is this car associated?" << endl;
        cout << "Initials:"; cin >> initials;
        if(initials == "0") initials = "";
        cout << endl;
        cout << "How many carriages: "; cin >> numCarriages;
        if(!cinGood()) return;
        if(numCarriages == 0) numCarriages = -1;
        cout << "How many stacks per carriage: "; cin >> stacksPerCarriage;
        if(!cinGood()) return;
        if(stacksPerCarriage == 0) stacksPerCarriage = -1;
        cout << "How many luggages per stack: "; cin >> luggagesPerStack;
        if(!cinGood()) return;
        if(luggagesPerStack == 0) luggagesPerStack = -1;
        LuggageCar lug(airport,numCarriages,stacksPerCarriage,luggagesPerStack);
        for(LuggageCar& luggageCar : luggageCars)
        {
            if(luggageCar.getAirport() == lug.getAirport() || lug.getNumStacks() == luggageCar.getNumStacks() || lug.getNumLuggagesPerStack() == luggageCar.getNumLuggagesPerStack()
            || lug.getNumCarriages() == luggageCar.getNumCarriages())
                aux.push_back(luggageCar);
        }
    }
    else if(choice == 'N' || choice == 'n')
    {
        aux = luggageCars;
    }
    else
    {
        cout << "invalid character! considered as a 'N'" << endl;
        aux = luggageCars;
    }
    cout << "how do you want the Luggage cars to be sorted? \n"
            "1 - Airport asc\n"
            "2 - Airport desc\n"
            "3 - Carriages asc\n"
            "4 - Carriages desc\n"
            "5 - Stacks asc\n"
            "6 - Stacks desc\n"
            "7 - Luggages p/stack asc\n"
            "8 - Luggages p/stack desc\n";
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
            aux.sort(sortCarsByAirportAsc);
            break;
        case 2:
            aux.sort(sortCarsByAirportDesc);
            break;
        case 3:
            aux.sort(sortCarsByCarriageAsc);
            break;
        case 4:
            aux.sort(sortCarsByCarriageDesc);
            break;
        case 5:
            aux.sort(sortCarsByStacksAsc);
            break;
        case 6:
            aux.sort(sortCarsByStacksDesc);
            break;
        case 7:
            aux.sort(sortCarsByLuggagesStackAsc);
            break;
        case 8:
            aux.sort(sortCarsByLuggagesStackDesc);
            break;
        default:
            cerr << endl << endl << "Invalid choice!\n";
            return;
    }
    int counter = 1;
    cout << "Order" << " - "<< "Id" << " - " << "Airport" << " - " << "NumCarriages" << " - " << "NumStacks"  << " - " << "NumLuggagesPerStack" << endl;
    for(LuggageCar &b: aux)
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
            cout << "Plane removed \n";
            return;
        }
    }
    cout <<"Plane does not exist \n";
    return;
}

void App::planeFind()
{
    string registration;

    cout << "The registration of the Plane to Find: \n"
            "Registration: "; cin >> registration;
    cout << "\n";
    Plane a(0,registration,"");
    cout << "Searching..." << endl;
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
            else if(answer == 'N' || answer == 'n')
            {
                return;
            }
            else
            {
                cout << "invalid character! considered as a 'N'" << endl;
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
        string type;
        int capacity;
        cout << "give the Plane specifications: ";
        cout << "Type: "; cin >> type;
        cout << "\n";
        cout << "Capacity :"; cin >> capacity;
        if(!cinGood()) return;
        if(registration == "" || type == "" ||capacity <= 0)
        {
            cout << "Invalid Plane specifications \n";
            return;
        }
        a.setType(type);
        a.setCapacity(capacity);
        planes.push_back(a);
        cout << "Plane added!" << endl;
    }
    else if(answer == 'N' || answer == 'n')
    {
        return;
    }
    else
    {
        cout << "invalid character! considered as a 'N'" << endl;
        return;
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
    else if(choice == 'N' || choice == 'n')
    {
        aux = planes;
    }
    else
    {
        cout << "invalid character! considered as a 'N'" << endl;
        aux = planes;
    }
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

void App::flightMenu() {
    string registration;
    cout << "From what Plane should we manage the flights? \n"
         << "Registration: ";
    cin >> registration;
    cout << "\n";
    Plane* a = new Plane(0, registration, "");
    bool exists = false;
    for (Plane &b: planes) {
        if (*a == b) {
            a = &b;
            exists = true;
            break;
        }
    }
    if (!exists) {
        cout << "The given Plane does not exist " << endl;
        cout << "type anything to go back" << endl;
        string choice;
        cin >> choice;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        return;
    }
    while (true) {
        cout << "|==============================================|\n"
                "|                   Flights                    |\n"
                "|  Add Flight                             [1]  |\n"
                "|  Remove Flight                          [2]  |\n"
                "|  Detail Flight                          [3]  |\n"
                "|  Show Flights                           [4]  |\n"
                "|  Get Luggage To Car                     [5]  |\n"
                "|  Return                                [0]  |\n"
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
                flightCreation(*a);
                break;
            case 2:
                flightDeletion(*a);
                break;
            case 3:
                flightFind(*a);
                break;
            case 4:
                showFlights(*a);
                break;
            case 5:
                getLuggageToCar(*a);
                break;
            default:
                cout << "not a possibilite" << endl;
        }
    }
}

void App::flightCreation(Plane &plane)
{
    Date departure;
    int day,month,year;
    Time duration;
    int hour,minute;
    Airport origin, destination;
    string initials;
    int availableSeats = plane.getCapacity();

    cout << "Give the flight specifications: \n"
            "Origin Airport (initials): "; cin >> initials;
    origin = Airport("",initials);
    if(!checkAirportExists(initials,origin))
    {
        cout << "Airport does not exist" << endl;
        return;
    }
    cout << "\n";
    cout << "Destination Airport (initials): "; cin >> initials;
    destination = Airport("",initials);
    if(!checkAirportExists(initials,destination))
    {
        cout << "Airport does not exist" << endl;
        return;
    }
    cout << "\n";
    cout << "Hour: "; cin >> hour;
    if (!cinGood()) return;
    cout << "\n";
    cout << "Minute: "; cin >> minute;
    if (!cinGood()) return;
    duration = Time(hour,minute);
    cout << "\n";
    cout << "Day: "; cin >> day;
    if (!cinGood()) return;
    cout << "\n";
    cout << "Month: "; cin >> month;
    if (!cinGood()) return;
    cout << "\n";
    cout << "Year: "; cin >> year;
    if (!cinGood()) return;
    cout << "\n";
    departure = Date(year,month,day);
    Flight flight(departure,duration,origin,destination,availableSeats);

    for(Flight b: plane.getFlights())
    {
        if(b.equals(flight))
        {
            cout << "This flight already exists" << endl;
            return;
        }
    }
    plane.addFlight(flight);
    cout << "Flight added \n";
}

void App::flightDeletion(Plane &plane)
{
    Date departure;
    int day,month,year;
    Airport origin;
    string initials;
    cout << "Give the flight specifications: \n"
            "Origin Airport (initials): "; cin >> initials;
            cout << endl;
    cout << "Day: "; cin >> day;
    if (!cinGood()) return;
    cout << "\n";
    cout << "Month: "; cin >> month;
    if (!cinGood()) return;
    cout << "\n";
    cout << "Year: "; cin >> year;
    if (!cinGood()) return;
    cout << "\n";
    departure = Date(year,month,day);
    origin = Airport("",initials);
    Flight flight = Flight(departure,origin);
    for(Flight& b: plane.getFlights())
    {
        if(b.equals(flight))
        {
            plane.deleteFlight(b.getId());
            cout << "Flight removed \n";
            return;
        }
    }
    cout << "This flight doesnt exists" << endl;
    return;
}

bool App::checkAirportExists(string initials, Airport& airport) //se existir coloca o aeroporto em airport
{
    for(Airport& air: airports)
    {
        if(air.getInitials() == initials)
        {
            airport = air;
            return true;
        }
    }
    return false;
}

void App::flightFind(Plane &plane)
{
    Date departure;
    int day,month,year;
    Airport origin;
    string initials;
    cout << "Give the flight specifications: \n"
            "Origin Airport (initials): "; cin >> initials;
            if(!checkAirportExists(initials,origin))
            {
                string choice;
                cout << "Airport does not exist!" << endl;
                cout << "type anything to go back";
                cin >> choice;
                cin.clear();
                cin.ignore(INT_MAX,'\n');
                return;
            }
    cout << endl;
    cout << "Day: "; cin >> day;
    if (!cinGood()) return;
    cout << "\n";
    cout << "Month: "; cin >> month;
    if (!cinGood()) return;
    cout << "\n";
    cout << "Year: "; cin >> year;
    if (!cinGood()) return;
    cout << "\n";
    departure = Date(year,month,day);
    origin = Airport("",initials);
    Flight flight = Flight(departure,origin);
    cout << "Searching..." << endl;

    for(Flight& b: plane.getFlights())
    {
        if(b.equals(flight))
        {
            cout << "Flight found, details: " << endl
               << "Id - DepartureDate - Duration - Origin - Destination - AvailableSeats" << endl
               << flight << endl
               << "Do you want to update it? Y/N" << endl;
            char answer;
            cin >> answer;
            if(!cinGood()) return;
            if(answer == 'y' || answer == 'Y')
            {
                updateFlight(flight,plane);
                return;
            }
            else if(answer == 'N' || answer == 'n')
            {
                return;
            }
            else
            {
                cout << "invalid character! considered as a 'N'" << endl;
                return;
            }
            return;
        }
    }
    cout << "Flight does not exist" << endl;
    cout <<"Do you want to create it? (Y/N)" << endl;
    char answer;
    cin >> answer;
    if(!cinGood()) return;
    if(answer == 'y' || answer == 'Y')
    {
        Time duration;
        int hour,minute;
        Airport destination;
        int availableSeats = plane.getCapacity();
        cout << "give the remaining Flight specifications: ";
        cout << "destination: (initials)"; cin >> initials;
        cout << "\n";
        if(!checkAirportExists(initials,destination))
        {
            string choice;
            cout << "Airport does not exist!" << endl;
            cout << "type anything to go back";
            cin >> choice;
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            return;
        }
        cout << "Hour: "; cin >> hour;
        if (!cinGood()) return;
        cout << "\n";
        cout << "Minute: "; cin >> minute;
        if (!cinGood()) return;
        duration = Time(hour,minute);
        cout << "\n";

        flight.setDestination(destination);
        flight.setAvailableSeats(availableSeats);
        flight.setDuration(duration);
        plane.addFlight(flight);
        cout << "Flight added!" << endl;
        return;
    }
    else if(answer == 'N' || answer == 'n')
    {
        return;
    }
    else
    {
        cout << "invalid character! considered as a 'N'" << endl;
        return;
    }
}

void App::updateFlight(Flight& flight,Plane &plane)
{
    Date departure;
    int day,month,year;
    Time duration;
    int hour,minute;
    Airport origin, destination;
    string initials;
    Flight checkFlight = flight;

    cout << "What should be the new characteristics? (type 0 to not change)"
            "Origin Airport (initials): "; cin >> initials;
            if(initials != "0")
            {
                origin = Airport("", initials);
                if(!checkAirportExists(initials, origin)) {
                    cout << "This Airport does not exist" << endl;
                    return;
                }
                checkFlight.setOrigin(origin);
            }
    cout << "\n";
    cout << "Destination Airport (initials): "; cin >> initials;
    if(initials != "0")
    {
        destination = Airport("",initials);
        if(!checkAirportExists(initials,destination)){
            cout << "This Airport does not exist" << endl;
            return;
        }
        checkFlight.setDestination(destination);
    }
    cout << "\n";
    cout << "Hour: "; cin >> hour;
    if (!cinGood()) return;
    if(hour != 0) duration.setHour(hour);
    cout << "\n";
    cout << "Minute: "; cin >> minute;
    if (!cinGood()) return;
    if(minute != 0) duration.setMinute(minute);
    duration = Time(hour,minute);
    cout << "\n";
    cout << "Day: "; cin >> day;
    if (!cinGood()) return;
    if(day != 0) departure.setDay(day);
    cout << "\n";
    cout << "Month: "; cin >> month;
    if (!cinGood()) return;
    if(month != 0) departure.setMonth(month);
    cout << "\n";
    cout << "Year: "; cin >> year;
    if (!cinGood()) return;
    if(year != 0) departure.setYear(year);
    cout << "\n";
    departure = Date(year,month,day);
    for(Flight& flight : plane.getFlights())
    {
        if(flight.equals(checkFlight))
        {
            cout << "Flight already exists" << endl;
            return;
        }
    }
    flight = checkFlight;
    cout << "Flight Updated!" << endl;
    return;

}

void App::showFlights(Plane &plane)
{
    char choice;
    cout << "do you want to see specific Flights? Y/N \n";
    while (true) {
        cin >> choice;
        if (cin.fail() || cin.peek() != '\n' ||
            (choice != 'N' && choice != 'n' && choice != 'Y' && choice != 'y')) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cerr << endl << endl << "Invalid answer!\n";
            continue;
        } else {
            break;
        }
    }
    list<Flight> aux;
    if (choice == 'Y' || choice == 'y') {
        Date departure;
        int day, month, year;
        Time duration;
        int hour, minute;
        Airport origin, destination;
        string initials;

        cout << "type '0' if you dont want to specify \n"
             << "Origin Airport (initials): ";
        cin >> initials;
        if (initials != "0") {
            origin = Airport("", initials);
        }
        cout << "\n";
        cout << "Destination Airport (initials): ";
        cin >> initials;
        if (initials != "0") {
            destination = Airport("", initials);
        }
        cout << "\n";
        cout << "Hour: ";
        cin >> hour;
        if (!cinGood()) return;
        if (hour != 0) duration.setHour(hour);
        cout << "\n";
        cout << "Minute: ";
        cin >> minute;
        if (!cinGood()) return;
        if (minute != 0) duration.setMinute(minute);
        duration = Time(hour, minute);
        cout << "\n";
        cout << "Day: ";
        cin >> day;
        if (!cinGood()) return;
        if (day != 0) departure.setDay(day);
        cout << "\n";
        cout << "Month: ";
        cin >> month;
        if (!cinGood()) return;
        if (month != 0) departure.setMonth(month);
        cout << "\n";
        cout << "Year: ";
        cin >> year;
        if (!cinGood()) return;
        if (year != 0) departure.setYear(year);
        cout << "\n";
        departure = Date(year, month, day);

        for (Flight &flight: plane.getFlights()) {
            if (flight.getDestination() == destination || flight.getOrigin() == origin ||
                flight.getDuration() == duration || flight.getDepartureDate() == departure)
                aux.push_back(flight);
        }
    }
    else if(choice == 'N' || choice == 'n')
    {
        aux = plane.getFlights();
    }
    else
    {
        cout << "invalid character! considered as a 'N'" << endl;
        aux = plane.getFlights();
    }
    cout << "how do you want the transports to be sorted? \n"
            "1 - departure asc\n"
            "2 - departure desc\n"
            "3 - duration asc\n"
            "4 - duration desc\n"
            "5 - origin asc\n"
            "6 - origin desc\n"
            "7 - destination asc\n"
            "8 - destination desc\n"
            "9 - available seats asc\n"
            "10 - available seats desc\n";

    int sortChoice;
    while (true) {
        cin >> sortChoice;
        if (cin.fail() || cin.peek() != '\n') {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << endl << endl << "Invalid command!\n";
            continue;
        } else {
            break;
        }
    }
    switch (sortChoice)
    {
        case 1:
            aux.sort(sortFlightByDepAsc);
            break;
        case 2:
            aux.sort(sortFlightByDepDesc);
            break;
        case 3:
            aux.sort(sortFlightByDurationAsc);
            break;
        case 4:
            aux.sort(sortFlightByDurationDesc);
            break;
        case 5:
            aux.sort(sortFlightByOriginAsc);
            break;
        case 6:
            aux.sort(sortFlightByOriginDesc);
            break;
        case 7:
            aux.sort(sortFlightByDestinationAsc);
            break;
        case 8:
            aux.sort(sortFlightByDestinationDesc);
            break;
        case 9:
            aux.sort(sortFlightByAvailableAsc);
            break;
        case 10:
            aux.sort(sortFlightByAvailableDesc);
            break;
        default:
            cout << endl << endl << "Invalid choice!\n";
            return;
    }
    int counter = 1;
    cout << "Order - Id - DepartureDate - Duration - Origin - Destination - AvailableSeats" << endl << endl;
    for(Flight &b: aux)
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

void App::getLuggageToCar(Plane &plane)
{
    int flightId;
    cout << "From what fly should the luggages be processed? ";
    cout << "ID: "; cin >> flightId;
    if(!cinGood()) return;
    bool exists = false;
    Flight* flight;
    for(Flight& f: plane.getFlights())
    {
        if(f.getId() == flightId)
        {
            exists = true;
            flight = &f;
            break;
        }
    }
    if(!exists)
    {
        cout << "This Flight does not exist!";
        return;
    }
    int LuggageId;
    cout << "Give the Car ID: "; cin >> LuggageId;
    if(!cinGood()) return;
    exists = false;
    LuggageCar* luggageCar;
    for(LuggageCar& lug: luggageCars)
    {
        if(lug.getId() == LuggageId)
        {
            exists = true;
            luggageCar = &lug;
            break;
        }
    }
    if(!exists)
    {
        cout << "This Luggage Car does not exist!";
        return;
    }
    (*flight).luggagesToCar(*luggageCar);
    if((*flight).getLuggagesOutCar().size() > 0)
    {
        cout << "all ok, but there are still Luggages left to be processed" << endl;
        return;
    }
    cout << "There are no more luggages out of the car for this flight" << endl;
    return;
}

void App::serviceMenu()
{
    string registration;
    cout << "From what Plane should we manage the Services? \n"
         << "Registration: ";
    cin >> registration;
    cout << "\n";
    Plane* a = new Plane(0, registration, "");
    bool exists = false;
    for (Plane &b: planes) {
        if (*a == b) {
            a = &b;
            exists = true;
            break;
        }
    }
    if (!exists) {
        cout << "The given Plane does not exist " << endl;
        cout << "type anything to go back" << endl;
        string choice;
        cin >> choice;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        return;
    }
    while (true)
    {
        cout<< "|==============================================|\n"
               "|                   Service                    |\n"
               "|  Add Service                            [1]  |\n"
               "|  Remove Oldest Service                  [2]  |\n"
               "|  Show Services To Do                    [3]  |\n"
               "|  Show Service Done                      [4]  |\n"
               "|  Return                                 [0]  |\n"
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
        switch (choice)
        {
            case 0:
                return;
            case 1:
                serviceCreation(*a);
                break;
            case 2:
                serviceDeletion(*a);
                break;
            case 3:
                showServicesToDo(*a);
                break;
            case 4:
                showServicesDone(*a);
                break;
            default:
                cout << "not a possibilite" << endl;
                break;
        }
    }
}

void App::serviceCreation(Plane &plane)
{
    char serviceType;
    Date date;
    int day,month,year;
    string accountable;

    cout << "give the Service specifications : \n"
         << "serviceType (m/l): "; cin >> serviceType;    cout << "\n";
    if(serviceType != 'm' && serviceType != 'M' && serviceType != 'l' && serviceType != 'L') {
        cout << "Invalid service type!" << endl;
        return;
    }
    if(!cinGood()) return;
    cout << "accountable: "; cin >> accountable;
    cout << "\n";
    cout << "year :"; cin >> year;
    if(!cinGood()) return;
    cout << "\n";
    cout << "month :"; cin >> month;
    if(!cinGood()) return;
    cout << "\n";
    cout << "day :"; cin >> day;

    date = Date(year,month,day);
    if(plane.getServicesToDo().empty())
    {
        Service service(serviceType,{year,month,day},accountable);
        cout << "Service added! \n";
        plane.addService(service);
        return;
    }
    if(date < plane.getServicesToDo().back().getDate())
    {
        cout << "Services need to be created in chronological order!\n";
        return;
    }
    Service service(serviceType,{year,month,day},accountable);
    cout << "Service added! \n";
    plane.addService(service);
}

void App::serviceDeletion(Plane &plane)
{
    if(plane.getServicesToDo().empty())
    {
        cout << "No services to do in this plane" << endl;
        return;
    }
    plane.popService();
    cout << "oldest service deleted" << endl;
}

void App::showServicesToDo(Plane &plane)
{
    int order = 1;
    queue<Service> services = plane.getServicesToDo();
    cout << "Order - Date - Accountable - ServiceType\n";
    while(!services.empty())
    {
        cout << services.front() << endl;
        services.pop();
    }
}

void App::showServicesDone(Plane &plane)
{
    int order = 1;
    stack<Service> services = plane.getServicesDone();
    cout << "Order - Date - Accountable - ServiceType\n";
    while(!services.empty())
    {
        cout << services.top() << endl;
        services.pop();
    }
}

void App::passengerCreation()
{
    //não cria lista de tickets
    string name,passport;
    cout << "give the Passenger specifications : \n"
         << "name: "; cin >> name;    cout << "\n";
    cout << "passport: "; cin >> passport;
    cout << "\n";
    if(!cinGood()) return;
    if(name == "" || passport == "")
    {
        cout << "Invalid Passenger specifications \n";
        return;
    }
    Passenger a(name,passport);
    for(Passenger &b : passengers)
    {
        if(b == a)
        {
            cout <<"This Passenger already exists \n";
            return;
        }
    }
    passengers.push_back(a);
    cout << "Passenger added! \n";
    return;
}

void App::passengerDeletion()
{
    string name,passport;
    cout << "give the Passenger specifications : \n"
            "Name "; cin >> name;
    cout << "\n";
    cout << "Passport: "; cin >> passport;
    cout << "\n";
    if(!cinGood()) return;
    Passenger a(name,passport);
    for(Passenger &b : passengers)
    {
        if(b == a)
        {
            passengers.remove(b);
            cout << "Passenger removed \n";
            return;
        }
    }
    cout <<"Passenger does not exist \n";
    return;
}

void App::passengerFind()
{
    string passport;

    cout << "Please insert the passport of the passenger to find: \n"
            "Passport: "; cin >> passport;
    cout << "\n";
    Passenger a("",passport);
    cout << "Searching..." << endl;
    for(Passenger &b : passengers)
    {
        if(b == a)
        {
            cout << "Passenger found, details: \n"
                 << "Name - Passport" << endl << b << endl
                 << "Do you want to update it? Y/N" << endl;

            char answer;
            cin >> answer;
            if(!cinGood()) return;
            if(answer == 'y' || answer == 'Y')
            {
                updatePassenger(b);
                return;
            }
            else if(answer == 'N' || answer == 'n')
            {
                return;
            }
            else
            {
                cout << "invalid character! considered as a 'N'" << endl;
                return;
            }
        }
    }
    cout << "Passenger does not exist" << endl;
    cout <<"Do you want to create it? (Y/N)" << endl;
    char answer;
    cin >> answer;
    if(!cinGood()) return;
    if(answer == 'y' || answer == 'Y')
    {
        string name;
        cout << "give the remaining Passenger specifications: ";
        cout << "Name: "; cin >> name;
        cout << "\n";
        if(!cinGood()) return;
        if(name == "" || passport == "")
        {
            cout << "Invalid Passenger specifications \n";
            return;
        }
        a.setName(name);
        passengers.push_back(a);
        cout << "Passenger added!" << endl;
    }
    else if(answer == 'N' || answer == 'n')
    {
        return;
    }
    else
    {
        cout << "invalid character! considered as a 'N'" << endl;
        return;
    }
}

void App::updatePassenger(Passenger &passenger)
{
    string name,passport;
    cout << "What should be the new characteristics? (type 0 to not change): \n"
            "Name: "; cin >> name;
    cout << "\n";
    cout << "Passport: "; cin >> passport;
    cout << "\n";
    if(!cinGood()) return;
    if(name == "" || passport == "")
    {
        cout << "Invalid Passenger specifications \n";
        return;
    }
    Passenger a(name,passport);
    if(a.getName() == "0")a.setName(passenger.getName());
    if(a.getPassport() == "0")a.setPassport(passenger.getPassport());
    for(Passenger &b : passengers)
    {
        if(b == a)
        {
            cout <<"This Passenger already exists \n";
            return;
        }
    }
    passenger = a;
    return;
}

void App::showPassengers()
{
    char choice;
    cout << "Do you want to see specific Passengers? Y/N \n";
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

    list<Passenger> aux;
    if(choice == 'Y' || choice == 'y')
    {
        string name,passport;
        cout << "type '0' if you dont want to specify \n";
        cout << "Name:"; cin.get(); getline(cin,name);
        cout << "Passport: "; cin >> passport; cout << endl;

        for(Passenger &a : passengers)
        {
            if(a.getName() == name || a.getPassport() == passport)
            {
                aux.push_back(a);
            }
        }
    }
    else if(choice == 'N' || choice == 'n')
    {
        aux = passengers;;
    }
    else
    {
        cout << "invalid character! considered as a 'N'" << endl;
        aux = passengers;
    }
    cout << "how do you want the Passengers to be sorted? \n"
         << "1 - Name asc\n"
         << "2 - Name desc\n"
         << "3 - Passport asc\n"
         << "4 - Passport desc\n";
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
    switch(sortChoice) {
        case 1:
            aux.sort(sortPassengersByNameAsc);
            break;
        case 2:
            aux.sort(sortPassengersByNameDesc);
            break;
        case 3:
            aux.sort(sortPassengersByPassAsc);
            break;
        case 4:
            aux.sort(sortPassengersByPassDesc);
            break;
        default:
            cerr << endl << endl << "Invalid choice!\n";
            return;
    }
    int counter = 1;
    cout << "Order - Name - Passport" << endl;
    for(Passenger &b: aux)
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

void App::ticketMenu() {
    string passport;
    cout << "From what Passenger should we manage the tickets? \n"
         << "Passport: ";
    cin >> passport;
    cout << "\n";
    Passenger* passenger = new Passenger("", passport);
    bool exists = false;
    for (Passenger &b: passengers) {
        if (*passenger == b) {
            passenger = &b;
            exists = true;
            break;
        }
    }
    if (!exists) {
        cout << "The given Passenger does not exist " << endl;
        cout << "Type anything to go back" << endl;
        string choice;
        cin >> choice;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        return;
    }
    while (true) {
        cout << "|==============================================|\n"
                "|                   Tickets                    |\n"
                "|  Add Ticket                             [1]  |\n"
                "|  Remove Ticket                          [2]  |\n"
                "|  Detail Ticket                          [3]  |\n"
                "|  Show Tickets                           [4]  |\n"
                "|  Checkin                                [5]  |\n"
                "|  Return                                 [0]  |\n"
                "|==============================================|\n";
        cout << "\n Please choose an option: ";
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
                ticketCreation(*passenger);
                break;
            case 2:
                ticketDeletion(*passenger);
                break;
            case 3:
                ticketFind(*passenger);
                break;
            case 4:
                showTicket(*passenger);
                break;
            default:
                cout << "not a possibilite" << endl;
        }
    }
}

void App::ticketCreation(Passenger& passenger)
{
    string passport;
    int id;
    Date departure;
    int day,month,year;
    Airport origin;
    string initials;
    cout << "What flight shall the ticked be created for?\n";
    cout << "Origin Airport (initials): "; cin >> initials;
    if(!checkAirportExists(initials,origin))
    {
        string choice;
        cout << "Airport does not exist!" << endl;
        cout << "Type anything to go back";
        cin >> choice;
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        return;
    }
    cout << endl;
    cout << "Day: "; cin >> day;
    if (!cinGood()) return;
    cout << "\n";
    cout << "Month: "; cin >> month;
    if (!cinGood()) return;
    cout << "\n";
    cout << "Year: "; cin >> year;
    if (!cinGood()) return;
    cout << "\n";
    departure = Date(year,month,day);
    Flight* flight = new Flight(departure,origin);
    cout << "\n";
    Plane* plane;
    bool exists = false;
    for (Plane &b: planes) {
        for(Flight &c: b.getFlights()){
            if (c.equals(*flight)) {
                plane = &b;
                flight = &c;
                exists = true;
                break;
            }
        }
    }
    if (!exists) {
        cout << "The given flight does not exist " << endl;
        cout << "Type anything to go back" << endl;
        string choice;
        cin >> choice;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        return;
    }
    Ticket a = Ticket(*flight);
    /*for(Ticket &b : passenger.getTickets())
    {
        if(b == a)
        {
            cout <<"This ticket already exists \n";
            return;
        }
    }*/
    int numBag;
    cout << "How many luggages is the passenger taking to the flight?"<< endl;
    cin >> numBag;
    for(numBag != 0; numBag--;){
        Luggage l = Luggage();
        a.addLuggage(l);
    }
    if(!passenger.addTicket(a)){
        cout << "This flight has no seats remaining" <<endl;
        return;
    }
    cout << "Ticket created!" << endl;
    while(true) {
        cout << "Do you want to buy another ticket for the same flight?(Y/N)" << endl;
        char answer;
        cin >> answer;
        if (!cinGood()) return;
        if(answer == 'N' || answer == 'n')
        {
            break;
        }
        else if (answer == 'y' || answer == 'Y') {
            cout << "What is the other passenger passport?" << endl;
            cin >> passport;
            cout << "\n";
            Passenger* a = new Passenger("",passport);
            cout << "Searching..." << endl;
            exists = false;
            for(Passenger &b : passengers)
            {
                if(b == *a)
                {
                    exists = true;
                    a = &b;
                    cout << "Passenger found!" << endl;
                    Ticket t = Ticket(*flight);
                    for(Ticket &ticket : a->getTickets())
                    {
                        if(ticket == t)
                        {
                            cout <<"This ticket already exists \n"; //A passenger cant buy ticket for the same flight twice.
                            return;
                        }
                    }

                    cout << "How many luggages is it tacking?" << endl;

                    cin >> numBag;
                    for(numBag != 0; numBag--;){
                        Luggage l = Luggage();
                        t.addLuggage(l);
                    }
                    if(!a->addTicket(t)){
                        cout << "This flight has no seats remaining" <<endl;
                        return;
                    }
                    cout << "Ticket created!" << endl;
                    break;
                }
            }
            if(!exists)
            cout << "Passenger does not exist" << endl;
        }
        else
        {
            cout << "invalid character! considered as a 'N'" << endl;
            break;
        }
    }
}

void App::ticketDeletion(Passenger& passenger)
{
    int id;
    Date departure;
    int day,month,year;
    Airport origin;
    string initials;
    cout << "What flight shall the ticked be deleted from?\n";
    cout << "Origin Airport (initials): "; cin >> initials;
    if(!checkAirportExists(initials,origin))
    {
        string choice;
        cout << "Airport does not exist!" << endl;
        cout << "type anything to go back";
        cin >> choice;
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        return;
    }
    cout << endl;
    cout << "Day: "; cin >> day;
    if (!cinGood()) return;
    cout << "\n";
    cout << "Month: "; cin >> month;
    if (!cinGood()) return;
    cout << "\n";
    cout << "Year: "; cin >> year;
    if (!cinGood()) return;
    cout << "\n";
    departure = Date(year,month,day);
    Flight* flight = new Flight(departure,origin);
    cout << "\n";
    Plane* plane;
    bool exists = false;
    for (Plane &b: planes) {
        for(Flight &c: b.getFlights()){
            if (c.equals(*flight)) {
                plane = &b;
                flight = &c;
                exists = true;
                break;
            }
        }
        if(exists) break;
    }
    if (!exists) {
        cout << "The given flight does not exist " << endl;
        cout << "Type anything to go back" << endl;
        string choice;
        cin >> choice;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        return;
    }

    for(Ticket &t : passenger.getTickets())
    {
        if(*flight == t.getFlightAssocited())
        {
            passenger.removeTicket(t);
            cout << "Ticket deleted!" << endl;
            return;
        }
        cout << "Ticket not found" << endl;
        return;
    }
}

void App::ticketFind(Passenger& passenger){

    int id;
    Date departure;
    int day,month,year;
    Airport origin;
    string initials;
    cout << "What flight shall the ticked be deleted from?\n";
    cout << "Origin Airport (initials): "; cin >> initials;
    if(!checkAirportExists(initials,origin))
    {
        string choice;
        cout << "Airport does not exist!" << endl;
        cout << "type anything to go back";
        cin >> choice;
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        return;
    }
    cout << endl;
    cout << "Day: "; cin >> day;
    if (!cinGood()) return;
    cout << "\n";
    cout << "Month: "; cin >> month;
    if (!cinGood()) return;
    cout << "\n";
    cout << "Year: "; cin >> year;
    if (!cinGood()) return;
    cout << "\n";
    departure = Date(year,month,day);
    Flight* flight = new Flight(departure,origin);
    cout << "\n";
    Plane* plane;
    bool exists = false;
    for (Plane &b: planes) {
        for(Flight &c: b.getFlights()){
            if (c.equals(*flight)) {
                plane = &b;
                flight = &c;
                exists = true;
                break;
            }
        }
        if(exists) break;
    }
    if (!exists) {
        cout << "The given flight does not exist " << endl;
        cout << "Type anything to go back" << endl;
        string choice;
        cin >> choice;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        return;
    }

    for(Ticket &t : passenger.getTickets())
    {
        if(*flight == t.getFlightAssocited())
        {
            cout << "Ticket found!" << endl;
            cout << "Id - Flight" << endl;
            cout << t << endl;
            cout << "Do you want to update it? (Y/N)"<< endl;
            char answer;
            cin >> answer;
            if (!cinGood()) return;
            if (answer == 'n' || answer == 'N') {break;}
            else if (answer == 'y' || answer == 'Y'){
                updateTicket(t);
            }
            else
            {
                cout << "invalid character! considered as a 'N'" << endl;
                break;
            }
        }
        cout << "Ticket not found" << endl;
        cout << "Do you want to create it? (Y/N)"<< endl;
        char answer;
        cin >> answer;
        if (!cinGood()) return;
        if (answer == 'n' || answer == 'N') {break;}
        else if (answer == 'y' || answer == 'Y'){
            Ticket a = Ticket(*flight);
            int numBag;
            cout << "How many luggages is the passenger taking to the flight?"<< endl;
            cin >> numBag;
            for(numBag != 0; numBag--;){
                Luggage l = Luggage();
                a.addLuggage(l);
            }
            if(!passenger.addTicket(a)){
                cout << "This flight has no seats remaining" <<endl;
                return;
            }
            cout << "Ticket created!" << endl;
        }
        else
        {
            cout << "invalid character! considered as a 'N'" << endl;
            break;
        }
        //return;
    }

}

void App::updateTicket(Ticket& ticket){
    int newLug;
    cout << "Are you adding or removing luggages? (A/R)" << endl;
    char answer;
    cin >> answer;
    if (!cinGood()) return;
    if (answer == 'a' || answer == 'A') {
        cout << "How many?" << endl;
        cin >> newLug;
        if (!cinGood()) return;
        for(newLug != 0; newLug--;){
            Luggage l = Luggage();
            ticket.addLuggage(l);
        }
    }
    else if (answer == 'r' || answer == 'R') {
        if(ticket.getTicketLuggages().empty()){cout << "This tickets has no luggages to remove"; return;}
        cout << "How many?" << endl;
        cin >> newLug;
        if (!cinGood()) return;
        for(newLug != 0; newLug--;){
            if(ticket.getTicketLuggages().empty()){cout << "This tickets has no luggages left to remove";}
            ticket.removeLuggage();
        }
    }
    cout << "Ticket updated!" << endl;
}

void App::showTicket(Passenger& passenger)
{
    //m faz sentido ele espeficicar nada do ticket pq o ticket so tem flight e n se pode um passageiro ter 2 ticket do msmo flight
    list<Ticket> aux = passenger.getTickets();
    cout << "how do you want the Tickets to be sorted? \n"
         << "1 - Flight asc\n"
         << "2 - Flight desc\n";
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
    switch(sortChoice) {
        case 1:
            aux.sort(sortTicketByFlightAsc);
            break;
        case 2:
            aux.sort(sortTicketByFlightDesc);
            break;
        default:
            cerr << endl << endl << "Invalid choice!\n";
            return;
    }
    int counter = 1;
    cout << "Order - Ticket.Id - Flight.Id - DepartureDate - Duration - Origin - Destination - AvailableSeats\" -" << endl;
    for(Ticket &t: aux)
    {
        cout << counter << " - " << t << "\n";
        counter ++;
    }

    string choice;
    cout << "type anything to go back";
    cin >> choice;
    cin.clear();
    cin.ignore(INT_MAX,'\n');
    return;

}

void App::checkin(Passenger& passenger)
{
    int id;
    Date departure;
    int day,month,year;
    Airport origin;
    string initials;
    cout << "What flight shall the ticked be deleted from?\n";
    cout << "Origin Airport (initials): "; cin >> initials;
    if(!checkAirportExists(initials,origin))
    {
        string choice;
        cout << "Airport does not exist!" << endl;
        cout << "type anything to go back";
        cin >> choice;
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        return;
    }
    cout << endl;
    cout << "Day: "; cin >> day;
    if (!cinGood()) return;
    cout << "\n";
    cout << "Month: "; cin >> month;
    if (!cinGood()) return;
    cout << "\n";
    cout << "Year: "; cin >> year;
    if (!cinGood()) return;
    cout << "\n";
    departure = Date(year,month,day);
    Flight* flight = new Flight(departure,origin);
    cout << "\n";
    Plane* plane;
    bool exists = false;
    for (Plane &b: planes) {
        for(Flight &c: b.getFlights()){
            if (c.equals(*flight)) {
                plane = &b;
                flight = &c;
                exists = true;
                break;
            }
        } if(exists) break;
    }
    if (!exists) {
        cout << "The given flight does not exist " << endl;
        cout << "Type anything to go back" << endl;
        string choice;
        cin >> choice;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        return;
    }

    for(Ticket &t : passenger.getTickets())
    {
        if(*flight == t.getFlightAssocited())
        {
            cout << "Ticket found!" << endl;
            t.setCheckin();
            cout << "Checkin completed" <<endl;
        }
    }
}



