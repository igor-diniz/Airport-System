//
// Created by Ian on 28/11/2021.
//

#include "Luggage.h"
//Detail: dá cout dos atributos de um item.
//Select: abre outra tela para selecionar o que fazer com o item, por exemplo botar bagagem de flight em carrinhos.
//Show: abre outra tela para escolher tipo de sort e ranges.
/*
"|===========================================================================================|\n"
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
"|  Show Airports                         [14] |  Show Transport                        [24] |\n" // Open new sort page │ Open new sort page
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
--------------------------------------------------------------------------------------------------

 "|==============================================|\n"
 "|                   Flights                    |\n"
 "|  Add Flight                            [21]  |\n"
 "|  Delete Flight                         [22]  |\n"
 "|  Detail Flight                         [23]  |\n"
 "|  Show Flights                          [24]  |\n"
 "|  Get Luggage To Car                    [25]  |\n"
 "|==============================================|\n"

 "|==============================================|\n"
 "|                   Tickets                    |\n"
 "|  Add Ticket                            [21]  |\n"
 "|  Delete Ticket                         [22]  |\n"
 "|  Detail Ticket                         [23]  |\n"
 "|  Show Tickets                          [24]  |\n"
 "|  Checkin                               [25]  |\n"
 "|==============================================|\n"
 */