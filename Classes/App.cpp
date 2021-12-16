#include "App.h"
#include "SortForms.cpp"

void App::menuPrincipal()
{
    while(true) {
        cout << "╒═══════════════════════════════════════════════════════════════════════════════════════════╕\n"
                "│            ____ ______ ____   ___     ____ ____   __     ____ _   __ ______ _____         │\n"
                "│           /  _// ____//  _/  /   |   /  _// __ \\ / /    /  _// | / // ____// ___/        │\n"
                "│           / / / __/   / /   / /| |   / / / /_/ // /     / / /  |/ // __/   \\__ \\        │\n"
                "│         _/ / / /___ _/ /   / ___ | _/ / / _, _// /___ _/ / / /|  // /___  ___/ /          │\n"
                "│        /___//_____//___/  /_/  |_|/___//_/ |_|/_____//___//_/ |_//_____/ /____/           │\n"
                "│                                                                                           │\n"
                "╞═════════════════════════════════════════════╪═════════════════════════════════════════════╡\n"
                "│                  Airports                   │                   Flights                   │\n"
                "╞═════════════════════════════════════════════╪═════════════════════════════════════════════╡\n"
                "│  Add Airport                           [11] │  Add Flight                            [21] │\n"
                "│  Delete Airport                        [12] │  Delete Flight                         [22] │\n"
                "│  Detail Airport                        [13] │  Detail Flight                         [23] │\n"
                "│  Show Airports                         [14] │  Show Flights                          [24] │\n"
                "│                                             │  Solve Flight Luggage                  [25] │\n"
                "╞═════════════════════════════════════════════╪═════════════════════════════════════════════╡\n"
                "│                 Luggage Car                 │                  Passenger                  │\n"
                "╞═════════════════════════════════════════════╪═════════════════════════════════════════════╡\n"
                "│  Add Luggage Car                       [31] │  Add Passenger                         [41] │\n"
                "│  Delete Luggage Car                    [32] │  Delete Passenger                      [42] │\n"
                "│  Detail Luggage Car                    [33] │  Detail Passenger                      [43] │\n"
                "│  Show Luggage Cars                     [34] │  Show Passengers                       [44] │\n"
                "╞═════════════════════════════════════════════╪═════════════════════════════════════════════╡\n"
                "│                    Plane                    │                   Service                   │\n"
                "╞═════════════════════════════════════════════╪═════════════════════════════════════════════╡\n"
                "│  Add Plane                             [51] │  Add Service                           [61] │\n"
                "│  Delete Plane                          [52] │  Delete Service                        [62] │\n"
                "│  Detail Plane                          [53] │  Detail Service                        [63] │\n"
                "│  Show Planes                           [54] │  Show Services                         [64] │\n"
                "╞═════════════════════════════════════════════╪═════════════════════════════════════════════╡\n"
                "│                   Ticket                    │                  Transport                  │\n"
                "╞═════════════════════════════════════════════╪═════════════════════════════════════════════╡\n"
                "│  Add Ticket                            [71] │  Add Transport                         [81] │\n"
                "│  Delete Ticket                         [72] │  Delete Transport                      [82] │\n"
                "│  Detail Ticket                         [73] │  Detail Transport                      [83] │\n"
                "│  Show Tickets                          [74] │  Show Transport                        [84] │\n"
                "│  Checkin                               [75] │                                             │\n"
                "╞═════════════════════════════════════════════╡                                             │\n"
                "│                Other operations             │                                             │\n"
                "╞═════════════════════════════════════════════╡                                             │\n"
                "│  Close                                  [0] │                                             │\n"
                "╘═════════════════════════════════════════════╧═════════════════════════════════════════════╛\n";
        int choice;
        while(true) {
            cin >> choice;
            if (cin.fail() || cin.peek() != '\n') {
                cin.clear();
                cin.ignore(INT_MAX,'\n');
                cerr << endl << endl << "Invalid command!\n";
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
        break;
    }
}

void App::airportCreation()
{
    string name,initials;
    cout << "give the Airport especifications : \n"
            "Name: ";
    getline(cin,name);
    cout << "\n";
    cout << "Initials: ";
    getline(cin,initials);
    cout << "\n";
    Airport a(name,initials);
    if(name == "" || initials == "")
    {
        cout << "Invalid Airport with no especification\n";
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
            "Name: ";
    getline(cin,name);
    cout << "\n";
    cout << "Initials: ";
    getline(cin,initials);
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
            "Name: ";
    getline(cin,name);
    cout << "\n";
    cout << "Initials: ";
    getline(cin,initials);
    cout << "\n";
    Airport a(name,initials);
    for(Airport b : airports)
    {
        if(a == b)
        {
            cout << "Airport found, details: \n"
            << &b;
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
        cout << "type enter if you dont want to especify \n" <<
        "Name: ";
        getline(cin,name);
        cout << "\n";
        cout << "Initials: ";
        getline(cin,initials);
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
    switch(choice)
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
    for(Airport b: aux)
    {
        cout << &b << "\n";
    }

    cout << "type anything to go back";
    cin >> choice;
    cin.clear();
    cin.ignore(INT_MAX,'\n');
    return;
}

