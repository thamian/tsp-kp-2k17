//
// Created by thamian on 10.06.17.
//

#ifndef P3_CONTROLLER_H
#define P3_CONTROLLER_H


#include "Menu.h"
#include "File.h"
#include "Knapsack.h"
#include "TravellingSalesman.h"

class Controller {
    Menu menu;
    File file;

    Knapsack* knapsack;
    TravellingSalesman* travellingSalesman;

    bool loadFile();
    void loadKnapsack();
    void loadTravellingSalesman();

    void knapsackProblem();
    void knapsackGreedyAlgorithmRatio();
    void knapsackGreedyAlgorithmValue();
    void knapsackDynamicProgramming();

    void travellingSalesmanProblem();
    void travellingSalesmanBruteForce();
    void travellingSalesmanGreedyAlgorithm();

public:
    Controller();
    ~Controller();

    void start();
    void testSalesman();
    void testKnapsack();
    void test();
};


#endif //P3_CONTROLLER_H
