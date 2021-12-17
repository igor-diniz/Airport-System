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
    ifstream fileToOpen;
    fileToOpen.open(passengersFile);

    string name, passport, stringFlightID, date, airport, initials, capacityString, blankLine;
    Date departure, arrival;
    Airport origin, destination;
    int capacity, flightId;

    while(!fileToOpen.eof())
    {
        //passenger
        getline(fileToOpen,name,',');
        getline(fileToOpen,passport);
        Passenger passenger = Passenger(name, passport);

        //flightID
        getline(fileToOpen,stringFlightID,',');
        flightId = stringToInt(stringFlightID);

        //departureDate
        getline(fileToOpen,date,',' );
        departure = Date(date);

        //arrivalDate
        getline(fileToOpen,date,',' );
        arrival = Date(date);

        //origin
        getline(fileToOpen,airport,',' );
        getline(fileToOpen,initials,',' );

        //destination
        origin = Airport(airport, initials);
        getline(fileToOpen,capacityString);

        //capacity
        capacity = stringToInt(capacityString);
        fileToOpen.get();

    }
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

Transport& getTransportinfos()
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

void App::menuPrincipal()
{
    while(true) {
        cout << "|===========================================================================================|\n"
                "|            ____ ______ ____   ___     ____ ____   __     ____ _   __ ______ _____         |\n"
                "|           /  _// ____//  _/  /   |   /  _// __ \\ / /    /  _// | / // ____// ___/        |\n"
                "|           / / / __/   / /   / /| |   / / / /_/ // /     / / /  |/ // __/   \\__ \\        |\n"
                "|         _/ / / /___ _/ /   / ___ | _/ / / _, _// /___ _/ / / /|  // /___  ___/ /          |\n"
                "|        /___//_____//___/  /_/  |_|/___//_/ |_|/_____//___//_/ |_//_____/ /____/           |\n"
                "|                                                                                           |\n"
                "|===========================================================================================|\n"
                "|                  Airports                   |                  Transport                  |\n"
                "|=============================================|=============================================|\n"
                "|  Add Airport                           [11] |  Add Transport                         [21] |\n" //Construtor │ Construtor
                "|  Delete Airport                        [12] |  Delete Transport                      [22] |\n" //ID │ ID
                "|  Detail Airport                        [13] |  Detail Transport                      [23] |\n" //ID │ ID
                "|  Show Airports                         [14] |  Show Transport                        [24] |\n"
                "|  Transports                            [15] |  Show Transport                        [24] |\n" // Open new sort page │ Open new sort page
                "|=============================================|=============================================|\n"
                "|                 Luggage Car                 |                  Passenger                  |\n"
                "|=============================================|=============================================|\n"
                "|  Add Luggage Car                       [31] |  Add Passenger                         [41] |\n" //Construtor │ Construtor
                "|  Delete Luggage Car                    [32] |  Delete Passenger                      [42] |\n" //ID │ ID
                "|  Detail Luggage Car                    [33] |  Detail Passenger                      [43] |\n" //ID │ ID
                "|  Show Luggage Cars                     [34] |  Show Passengers                       [44] |\n" // Open new sort page │ Open new sort page
                "|                                             |  Tickets                               [45] |\n" // null │ Open new Ticket page
                "|=============================================|=============================================|\n"
                "|                    Plane                    |                   Service                   |\n"
                "|===========================================================================================|\n"
                "|  Add Plane                             [51] |  Add Service                           [61] |\n" //Construtor │ Construtor
                "|  Delete Plane                          [52] |  Delete Service                        [62] |\n" //ID │ ID
                "|  Detail Plane                          [53] |  Detail Service                        [63] |\n" //ID │ ID
                "|  Show Planes                           [54] |  Show Services                         [64] |\n" // Open new sort page │ Open new sort page
                "|  Flights                               [55] |                                             |\n" // null │ Open new Flights page
                "|=============================================|=============================================|\n"
                "|               Other operations              |                                              \n"
                "|=============================================|                                              \n"
                "|  Close                                  [0] |                                              \n"
                "|===========================================================================================|\n"
                "                                                                                             \n";
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
                airportDetail();
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
    for(Airport b: airports)
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
    for(Airport b : airports)
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

void App::airportDetail()
{
    string name,initials;
    cout << "The details of what Airport should be shown? "
            "Name: ";cin >> name;
    cout << "\n";
    cout << "Initials: "; cin >> initials;
    cout << "\n";
    Airport a(name,initials);
    for(Airport &b : airports)
    {
        if(a == b)
        {
            cout << "Airport found, details: \n"
                 << "Name - Initials" << endl
                 << b;
        }
    }
    cout <<"Airport does not exist \n";
}

void App::showAirports()
{
    char choice;
    cout << "do you want to see specific Airports? Y/N \n";
    while(true) {
        cin >> choice;
        if (cin.fail() || cin.peek() != '\n') {
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
        cout << "type enter if you dont want to specify \n" <<
        "Name: "; cin >> name;
        cout << "\n";
        cout << "Initials: "; cin >> initials;
        cout << "\n";
        Airport a(name,initials);

        for(Airport b : airports)
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
    for(Airport b: aux)
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
    if (transp == Transport('o',0,{0,0})) return;
    if(!(airport.getTransports().find(transp) == Transport('o',0,{0,0})))
    {
        cout << "This transport already exists" << endl;
        return;
    }
    airport.addTransport(transp);
    cout << "Transport added \n";
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
    if((airport.getTransports().find(transp) == Transport('o',0,{0,0})))
    {
        cout << "This transport doesnt exists" << endl;
        return;
    }
    cout << "Transport found, details: " << endl
         << "Type - Distance - Time" << endl
         << transp;
}

void App::showTransports(Airport &airport)
{

}

