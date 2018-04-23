//
// Created by thamian on 10.06.17.
//

#ifndef P3_MENU_H
#define P3_MENU_H


#include "Console.h"
#include "Graph.h"
#include "Message.h"
#include "Knapsack.h"
#include "TravellingSalesman.h"

class Menu : public Console {
public:
    int getChoice();
    std::string getFilename();

    void display(Graph* graph);
    void display(Knapsack* knapsack);
    void display(TravellingSalesman* travellingSalesman);
    void display(ArrayList* arrayList);
    void display(Item* item);
    void displayRoad(TravellingSalesman* travellingSalesman);
};


#endif //P3_MENU_H
