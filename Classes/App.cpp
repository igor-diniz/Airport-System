#include "App.h"
#include "SortForms.cpp"
unsigned stringToInt(string str) //converte uma string para inteiro
{
    unsigned int number;
    stringstream convert_string(str);
    convert_string >> number;
    return number;
}

App::App(const string& passengersFile, const string& planesFile, const string& luggageCarsFile, const string& airportsFile){
    this->readPassengersFile(passengersFile);
}


bool cinGood()
{
    if (cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cerr << endl << endl << "Invalid Input! \n";
        cout << "type anything to go back" << endl;
        string choice;
        cin >> choice;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        return false;
    }
    return true;
}

Transport getTransportinfos()
{
    char type;
    float distance;
    int hour,minute;
    Transport transp('o',0,{0,0}); //not found
    cout << "give the Transport specifications : \n"
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

}

void App::menuPrincipal()
{
    while(true) {
        cout << "|===========================================================================================|\n"
                "|            ____ ______ ____   ___     ____ ____   __     ____ _   __ ______ _____         |\n"
                "|           /  _// ____//  _/  /   |   /  _// __ \  / /    /  _// | / // ____// ___/        |\n"
                "|           / / / __/   / /   / /| |   / / / /_/ // /     / / /  |/ // __/    \__\          |\n"
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
                "|  Close                                  [0] |                                              \n"
                "|  Save                                   [1] |                                              \n"
                "|===========================================================================================|\n";
        cout << "\nchoose an option : ";
        int choice;
        while(true) {
            cin >> choice;
            if (cin.fail() || cin.peek() != '\n') {
                cin.clear();
                cin.ignore(INT_MAX,'\n');
                cerr << endl << endl << "Invalid input!\n";
                continue;
            }
            else
            {
                break;
            }
        }

        switch (choice) {
            case 0:
                exit(0);
            case 11:
                airportCreation();
                break;
            case 12:
                airportDeletion();
                break;
            case 13:
                airportFind();
                break;
            case 14:
                showAirports();
                break;
            case 15:
                transportMenu();
                break;
            case 21:
                //chama o menu dos
                break;
            case 22:
                break;
            case 23:
                break;
            default:
                cout << "not a possibilite" << endl;
        }
    }
}

void App::airportCreation()
{
    string name,initials;
    cout << "give the Airport specifications : \n"
            "Name: "; cin >> name;
    cout << "\n";
    cout << "Initials: "; cin >> initials;
    cout << "\n";
    Airport a(name,initials);
    if(name == "" || initials == "")
    {
        cout << "Invalid Airport with no specification\n";
        return;
    }
    for(Airport &b: airports)
    {
        if(b == a)
        {
            cout <<"This Airport already exists \n";
            return;
        }
    }
    airports.push_back(a);
    cout << "Airport added \n";
    return;
}

void App::airportDeletion()
{
    string name,initials;
    cout << "What Airport should be deleted? "
            "Name: ";"Name: "; cin >> name;
    cout << "\n";
    cout << "Initials: "; cin >> initials;
    cout << "\n";
    Airport a(name,initials);
    for(Airport &b : airports)
    {
        if(b == a)
        {
            airports.remove(a);
            cout << "Airport deleted \n";
            return;
        }
    }
    cout <<"Airport does not exist \n";
    return;
}

void App::airportFind()
{
    string name,initials;
    cout << "The details of what Airport should be shown? "
            "Name: ";cin >> name;
    cout << "\n";
    cout << "Initials: "; cin >> initials;
    cout << "\n";
    Airport a(name,initials);
    cout << "Searching... \n";
    for(Airport &b : airports)
    {
        if(a == b)
        {
            cout << "Airport found, details: \n"
                 << "Name - Initials" << endl
                 << b << endl
                 << "Do you want to update it? Y/N" << endl;
                //update();
        }
    }
    cout <<"Airport does not exist \n"
         <<"Do you want to creat it? Y/N" << endl;
    //criar();
    return;
}

void App::showAirports()
{
    char choice;
    cout << "do you want to see specific Airports? Y/N \n";
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
    list<Airport> aux;
    if(choice == 'Y' || choice == 'y')
    {
        string name,initials;
        cout << "type '0' if you dont want to specify \n" <<
             "Name: "; cin >> name;
        cout << "\n";
        cout << "Initials: "; cin >> initials;
        cout << "\n";
        Airport a(name,initials);

        for(Airport &b : airports)
        {
            if(b.getName() == name || b.getInitials() == initials)
            {
                aux.push_back(b);
            }
        }
    }
    cout << "how do you want the Airports to be sorted? \n"
            "1 - name asc\n"
            "2 - name desc\n"
            "3 - initials asc\n"
            "4 - initials desc\n";
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
    if(aux.empty()) aux = airports; //in case the choice was "N"
    switch(sortChoice)
    {
        case 1:
            aux.sort(Airport_sort_nameasc);
            break;
        case 2:
            aux.sort(Airport_sort_namedesc);
            break;
        case 3:
            aux.sort(Airport_sort_initialsasc);
            break;
        case 4:
            aux.sort(Airport_sort_initialsdesc);
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
    cout << "From what Airport should we manage the transports? "
            "Name: ";
    cin >> name;
    cout << "\n";
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
                cerr << endl << endl << "Invalid command!\n";
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
                transportDetail(a);
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
    Transport transp = getTransportinfos();
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
    Transport transp = getTransportinfos();
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

void App::transportDetail(Airport &airport)
{
    Transport transp = getTransportinfos();
    if (transp == Transport('o',0,{0,0})) return;
    cout << "Searching... \n";
    if((airport.getTransports().find(transp) == Transport('o',0,{0,0})))
    {
        cout << "This transport doesnt exists" << endl;
        return;
    }
    cout << "Transport found, details: " << endl
         << "Type - Distance - Time" << endl
         << transp << endl;
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
        Transport transport = getTransportinfos();
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
            aux.sort(transport_sort_typeasc);
            break;
        case 2:
            aux.sort(transport_sort_typedesc);
            break;
        case 3:
            aux.sort(transport_sort_timeasc);
            break;
        case 4:
            aux.sort(transport_sort_timedesc);
            break;
        case 5:
            aux.sort(transport_sort_distanceasc);
            break;
        case 6:
            aux.sort(transport_sort_distancedesc);
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

