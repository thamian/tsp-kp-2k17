//
// Created by thamian on 10.06.17.
//

#include <chrono>
#include <random>
#include "Controller.h"

Controller::Controller() {
    travellingSalesman = nullptr;
    knapsack = nullptr;
}

Controller::~Controller() {
    delete travellingSalesman;
    delete knapsack;
}

void Controller::start() {
    menu.println(Message::MENU_information);
    menu.println();
    menu.println(Message::MENU_description);

    bool exit = false;
    while (!exit) {
        switch (menu.getChoice()) {
            case 0: {                   // Lista dostępnych opcji.
                menu.println(Message::MENU_description);
            } break;
            case 1: {                   // Problem plecakowy
                if (loadFile())
                    knapsackProblem();
            } break;
            case 2: {                   // Problem komiwojażera
                if (loadFile())
                    travellingSalesmanProblem();
            } break;
            case 3: {                   // Wyjście.
                exit = true;
            } break;
            default: {                  // Nierozpoznane polecenie.
                menu.println(Message::MENU_wrongInput);
            } break;
        }
    }
}

bool Controller::loadFile() {
    file.load(menu.getFilename());
    menu.println(file.isOpen() ? Message::FILE_loadSuccess : Message::FILE_loadFailure);
    return file.isOpen();
}

void Controller::loadTravellingSalesman() {
    delete travellingSalesman;
    travellingSalesman = new TravellingSalesman(file);

    menu.println(Message::GRAPH_created);
}

void Controller::loadKnapsack() {
    delete knapsack;
    knapsack = new Knapsack(file);

    menu.println(Message::KNAPSACK_created);
}

void Controller::knapsackProblem() {
    loadKnapsack();

    menu.println();
    menu.println(Message::KNAPSACK_displayAllItems);
    menu.display(knapsack);
    menu.display(knapsack->getItems());
    menu.println();

    knapsackGreedyAlgorithmRatio();
    knapsackGreedyAlgorithmValue();
    knapsackDynamicProgramming();
}

void Controller::knapsackGreedyAlgorithmRatio() {
    knapsack->clear();
    knapsack->greedyAlgorithmRatio();
    menu.println(Message::KNAPSACK_greedyAlgorithmRatio);
    menu.println();
    menu.display(knapsack->getKnapsack());
    std::cout << " \t" << knapsack->calculateOverallSize() << "\t" << knapsack->calculateOverallValue() << "\n\n";
}

void Controller::knapsackGreedyAlgorithmValue() {
    knapsack->clear();
    knapsack->greedyAlgorithmValue();
    menu.println(Message::KNAPSACK_greedyAlgorithmValue);
    menu.println();
    menu.display(knapsack->getKnapsack());
    std::cout << " \t" << knapsack->calculateOverallSize() << "\t" << knapsack->calculateOverallValue() << "\n\n";
}

void Controller::knapsackDynamicProgramming() {
    knapsack->clear();
    knapsack->dynamicProgramming();
    menu.println(Message::KNAPSACK_dynamicProgramming);
    menu.println();
    menu.display(knapsack->getKnapsack());
    std::cout << " \t" << knapsack->calculateOverallSize() << "\t" << knapsack->calculateOverallValue() << "\n\n";
}

void Controller::travellingSalesmanProblem() {
    loadTravellingSalesman();

    menu.println();
    menu.println(Message::SALESMAN_displayAllItems);
    menu.display(travellingSalesman);
    menu.display(travellingSalesman->getCities());
    menu.println();

    travellingSalesmanBruteForce();
    travellingSalesmanGreedyAlgorithm();
}

void Controller::travellingSalesmanBruteForce() {
    travellingSalesman->clear();
    menu.println(Message::SALESMAN_bruteForce);
    menu.println();
    std::cout << "Road: " << travellingSalesman->bruteForce() << "\n";
    menu.displayRoad(travellingSalesman);
    std::cout << "\n\n";
}

void Controller::travellingSalesmanGreedyAlgorithm() {
    travellingSalesman->clear();
    menu.println(Message::SALESMAN_greedyAlgorithm);
    menu.println();
    std::cout << "Road: " << travellingSalesman->greedyAlgorithm() << "\n";
    menu.displayRoad(travellingSalesman);
    std::cout << "\n\n";
}

void Controller::testSalesman() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> roadDistribution(10, 500);

    std::ofstream file;
    file.open("out.txt");
    menu.println("salesman");

    int numberOfCities = 14;

    file << numberOfCities << "\n";

    for (int i = 0; i < numberOfCities; i++) {
        for (int j = 0; j < numberOfCities; ++j) {
            if (i == j) {
                file << 0 << " ";
            } else {
                int road = roadDistribution(gen);
                file << road << " ";
            }
        }
        file << "\n";
    }
}

void Controller::testKnapsack() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> sizeDistribution(10, 500);
    std::uniform_int_distribution<> valueDistribution(100, 10000);

    std::ofstream file;
    file.open("out.txt");
    menu.println("knapsack");

    int capacity = 5000;
    int numberOfItems = 500;

    file << capacity << " ";
    file << numberOfItems << "\n";

    for (int i = 0; i < numberOfItems; i++) {
        int size = sizeDistribution(gen);
        int value = valueDistribution(gen);

        file << size << " ";
        file << value << "\n";
    }

    /*for (int i = 0; i < 100; i++) {


        std::chrono::high_resolution_clock::time_point startTime;
        std::chrono::high_resolution_clock::time_point stopTime;
        std::chrono::duration<double> spanTime;

        for (int j = 0; j < 10; j++) {
            startTime = std::chrono::high_resolution_clock::now();
            dijkstra_->execute(listGraph_);
            stopTime = std::chrono::high_resolution_clock::now();
            spanTime = std::chrono::duration_cast<std::chrono::duration<double>>(stopTime - startTime);
            rDijkstraList[j] = spanTime.count();

            startTime = std::chrono::high_resolution_clock::now();
            dijkstra_->execute(matrixGraph_);
            stopTime = std::chrono::high_resolution_clock::now();
            spanTime = std::chrono::duration_cast<std::chrono::duration<double>>(stopTime - startTime);
            rDijkstraMatrix[j] = spanTime.count();


            startTime = std::chrono::high_resolution_clock::now();
            bellmanFord_->execute(listGraph_);
            stopTime = std::chrono::high_resolution_clock::now();
            spanTime = std::chrono::duration_cast<std::chrono::duration<double>>(stopTime - startTime);
            rBellmanList[j] = spanTime.count();

            startTime = std::chrono::high_resolution_clock::now();
            bellmanFord_->execute(matrixGraph_);
            stopTime = std::chrono::high_resolution_clock::now();
            spanTime = std::chrono::duration_cast<std::chrono::duration<double>>(stopTime - startTime);
            rBellmanMatrix[j] = spanTime.count();
        }

        double averageDijkstraList = 0;
        for (int k = 0; k < 10; ++k) {
            averageDijkstraList += rDijkstraList[k];
            averageDijkstraList = averageDijkstraList / 10;
        }

        double averageDijkstraMatrix = 0;
        for (int l = 0; l < 10; ++l) {
            averageDijkstraMatrix += rDijkstraMatrix[l];
            averageDijkstraMatrix = averageDijkstraMatrix / 10;
        }

        double averageBellmanList = 0;
        for (int m = 0; m < 10; ++m) {
            averageBellmanList += rBellmanList[m];
            averageBellmanList = averageBellmanList / 10;
        }

        double averageBellmanMatrix = 0;
        for (int n = 0; n < 10; ++n) {
            averageBellmanMatrix += rBellmanMatrix[n];
            averageBellmanMatrix = averageBellmanMatrix / 10;
        }

        greedyAlgorithmValue << averageDijkstraList << ";\n";
        greedyAlgorithmRatio << averageDijkstraMatrix << ";\n";
        bellmanList << averageBellmanList << ";\n";
        bellmanMatrix << averageBellmanMatrix << ";\n";
    }
*/
    file.close();
}

void Controller::test() {
    std::ofstream knapsackGAR;
    std::ofstream knapsackGAV;
    std::ofstream knapsackDP;

    std::ofstream salesmanBF;
    std::ofstream salesmanGA;

    knapsackGAR.open("knapsackGAR.txt");
    knapsackGAV.open("knapsackGAV.txt");
    knapsackDP.open("knapsackDP.txt");

    salesmanBF.open("salesmanBF.txt");
    salesmanGA.open("salesmanGA.txt");

    std::chrono::high_resolution_clock::time_point startTime;
    std::chrono::high_resolution_clock::time_point stopTime;
    std::chrono::duration<double> spanTime;
    double result;

    loadFile();
    loadKnapsack();

    loadFile();
    loadTravellingSalesman();

    for (int i = 0; i < 1; ++i) {
        knapsack->clear();
        startTime = std::chrono::high_resolution_clock::now();
        knapsack->greedyAlgorithmRatio();
        stopTime = std::chrono::high_resolution_clock::now();
        spanTime = std::chrono::duration_cast<std::chrono::duration<double>>(stopTime - startTime);
        knapsackGAR << spanTime.count() << "\n";

        knapsack->clear();
        startTime = std::chrono::high_resolution_clock::now();
        knapsack->greedyAlgorithmValue();
        stopTime = std::chrono::high_resolution_clock::now();
        spanTime = std::chrono::duration_cast<std::chrono::duration<double>>(stopTime - startTime);
        knapsackGAV << spanTime.count() << "\n";

        knapsack->clear();
        startTime = std::chrono::high_resolution_clock::now();
        knapsack->dynamicProgramming();
        stopTime = std::chrono::high_resolution_clock::now();
        spanTime = std::chrono::duration_cast<std::chrono::duration<double>>(stopTime - startTime);
        knapsackDP << spanTime.count() << "\n";



        travellingSalesman->clear();
        startTime = std::chrono::high_resolution_clock::now();
        travellingSalesman->bruteForce();
        stopTime = std::chrono::high_resolution_clock::now();
        spanTime = std::chrono::duration_cast<std::chrono::duration<double>>(stopTime - startTime);
        salesmanBF << spanTime.count() << "\n";

        travellingSalesman->clear();
        startTime = std::chrono::high_resolution_clock::now();
        travellingSalesman->greedyAlgorithm();
        stopTime = std::chrono::high_resolution_clock::now();
        spanTime = std::chrono::duration_cast<std::chrono::duration<double>>(stopTime - startTime);
        salesmanGA << spanTime.count() << "\n";
    }
}
