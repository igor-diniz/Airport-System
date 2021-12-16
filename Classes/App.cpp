
#include "App.h"

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
                "│                                             │  Select Flight                         [25] │\n"
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
                "│  Show Plane                            [54] │  Show Service                          [64] │\n"


                "╞═════════════════════════════════════════════╡                                             │\n"
                "│                Other operations             │                                             │\n"
                "╞═════════════════════════════════════════════╡                                             │\n"
                "│  Log out                               [31] │                                             │\n"
                "╘═════════════════════════════════════════════╧═════════════════════════════════════════════╛\n"
                "                                                                                             \n";
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
                //chama o menu dos planes
                break;
            case 13:
                //chama o menu dos passengers
                break;
            case 14:
                //chama o menu dos Airports
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
    cout << "give the Airport especifications : \n";
            ""
}