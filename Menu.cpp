//
// Created by thamian on 10.06.17.
//

#include "Menu.h"

int Menu::getChoice() {
    return getPositiveNumber(Message::CONSOLE_prompt);
}

std::string Menu::getFilename() {
    return getInput(Message::FILE_getFilename);
}

void Menu::display(Graph* graph) {
    int numberOfVertices = graph->getNumberOfVertices();

    print("  # ");
    for (int i = 0; i < numberOfVertices; i++) {
        std::cout << "\t" << i;
    }
    print("\n\n");

    for (int i = 0; i < numberOfVertices; i++) {
        std::cout << "  " << i << " ";
        for (int j = 0; j < numberOfVertices; j++)
                std::cout << "\t" << graph->getEdgeWeight(i, j);
        println();
    }
}

void Menu::display(ArrayList* arrayList) {
    int numberOfItems = arrayList->getNumberOfElements();

    std::cout << "Item\tSize\tValue\t\n";
    std::cout << "----------------------------\n";
    for (int i = 0; i < numberOfItems; ++i) {
        std::cout << i << "\t";
        display(arrayList->getElement(i));
    }
    std::cout << "----------------------------\n";
}

void Menu::display(Item *item) {
    std::cout << item->getSize() << "\t" << item->getValue() << "\n";
}

void Menu::display(Knapsack *knapsack) {
    std::cout << "Capacity: " << knapsack->getCapacity() << "\n";
    std::cout << "Items:\t  " << knapsack->getNumberOfItems() << "\n\n";
}

void Menu::display(TravellingSalesman *travellingSalesman) {
    std::cout << "Number of cities: " << travellingSalesman->getNumberOfCities() << "\n";
}

void Menu::displayRoad(TravellingSalesman *travellingSalesman) {
    for (int i = 0; i < travellingSalesman->getNumberOfCities(); ++i) {
        std::cout << travellingSalesman->getVisitedCities()[i] << " - ";
    }
    std::cout << travellingSalesman->getVisitedCities()[travellingSalesman->getNumberOfCities()];
    std::cout << "\n";
}
