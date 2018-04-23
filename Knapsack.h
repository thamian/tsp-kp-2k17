//
// Created by thamian on 17.06.17.
//

#ifndef P3_KNAPSACK_H
#define P3_KNAPSACK_H


#include "ArrayList.h"
#include "File.h"
#include "Item.h"

class Knapsack {
    int capacity;
    int numberOfItems;
    ArrayList* items;
    ArrayList* knapsack;

    void addItems(File& file);

public:
    Knapsack(File& file);

    int getCapacity() const;
    int getNumberOfItems() const;
    ArrayList* getItems() const;
    ArrayList* getKnapsack() const;

    int calculateOverallSize();
    int calculateOverallValue();

    void greedyAlgorithmValue();
    void greedyAlgorithmRatio();
    void dynamicProgramming();

    void clear();
};


#endif //P3_KNAPSACK_H
