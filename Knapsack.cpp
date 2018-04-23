//
// Created by thamian on 17.06.17.
//

#include <iostream>
#include "Knapsack.h"

void Knapsack::addItems(File &file) {
    for (int i = 0; i < numberOfItems; ++i) {
        int size = file.get();
        int value = file.get();
        items->addElement(new Item(size, value));
    }
}

Knapsack::Knapsack(File &file) {
    capacity = file.get();
    numberOfItems = file.get();

    items = new ArrayList(numberOfItems);
    knapsack = new ArrayList();

    addItems(file);
    file.backToBeginning();
}

void Knapsack::greedyAlgorithmValue() {
    Item* item;
    for (int i = 0; i < numberOfItems; ++i) {
        item = items->getElement(i);
        item->setComparableValue(static_cast<double>(item->getValue()));
    }
    items->sort();

    int capacityLeft = capacity;
    for (int i = 0; i < numberOfItems; ++i) {
        item = items->getElement(i);
        int size = item->getSize();

        if (size <= capacityLeft) {
            knapsack->addElement(item);
            capacityLeft -= size;
        }
    }
}

void Knapsack::greedyAlgorithmRatio() {
    Item* item;
    for (int i = 0; i < numberOfItems; ++i) {
        item = items->getElement(i);
        item->setComparableValue(item->calculateRatio());
    }
    items->sort();

    int capacityLeft = capacity;
    int size;
    for (int i = 0; i < numberOfItems; ++i) {
        item = items->getElement(i);
        size = item->getSize();

        if (size <= capacityLeft) {
            knapsack->addElement(item);
            capacityLeft -= size;
        }
    }
}

void Knapsack::dynamicProgramming() {
    int **valueTable = new int * [numberOfItems + 1];
    for (int i = 0; i < (numberOfItems + 1); ++i) {
        valueTable[i] = new int [capacity + 1];
        valueTable[i][0] = 0;
    }
    for (int k = 0; k < (capacity + 1); ++k)
        valueTable[0][k] = 0;

    bool **keepTable = new bool * [numberOfItems + 1];
    for (int i = 0; i < (numberOfItems + 1); ++i) {
        keepTable[i] = new bool [capacity + 1];
        keepTable[i][0] = false;
    }
    for (int k = 0; k < (capacity + 1); ++k)
        keepTable[0][k] = false;

    for (int currentItem = 1; currentItem < (numberOfItems + 1); ++currentItem) {
        int itemSize = items->getElement(currentItem - 1)->getSize();
        int itemValue = items->getElement(currentItem - 1)->getValue();

        for (int currentKnapsackSize = 1; currentKnapsackSize < (capacity + 1); ++currentKnapsackSize) {
            if (itemSize <= currentKnapsackSize) {
                int spaceLeft = currentKnapsackSize - itemSize;

                if (itemValue + valueTable[currentItem - 1][spaceLeft] > valueTable[currentItem - 1][currentKnapsackSize]) {
                    valueTable[currentItem][currentKnapsackSize] = itemValue + valueTable[currentItem - 1][spaceLeft];
                    keepTable[currentItem][currentKnapsackSize] = true;
                }
                else {
                    valueTable[currentItem][currentKnapsackSize] = valueTable[currentItem - 1][currentKnapsackSize];
                    keepTable[currentItem][currentKnapsackSize] = false;
                }
            }
            else {
                valueTable[currentItem][currentKnapsackSize] = valueTable[currentItem - 1][currentKnapsackSize];
                keepTable[currentItem][currentKnapsackSize] = false;
            }
        }
    }

    int item = numberOfItems;
    int size = capacity;
    for (int i = (numberOfItems - 1); i > -1; --i) {
        int itemValue = items->getElement(i)->getValue();
        int itemSize = items->getElement(i)->getSize();

        if (keepTable[item][size]) {
            knapsack->addElement(new Item(itemSize, itemValue));
            item -= 1;
            size -= itemSize;
        } else
            item -= 1;
    }

    for (int i = 0; i < (numberOfItems + 1); ++i) {
        delete [] valueTable[i];
        delete [] keepTable[i];
    }
    delete [] valueTable;
    delete [] keepTable;
}

int Knapsack::getCapacity() const {
    return capacity;
}

int Knapsack::getNumberOfItems() const{
    return numberOfItems;
}

ArrayList* Knapsack::getItems() const {
    return items;
}

ArrayList* Knapsack::getKnapsack() const {
    return knapsack;
}

void Knapsack::clear() {
    knapsack->fillWithNullptr();
    delete knapsack;
    knapsack = new ArrayList();
}

int Knapsack::calculateOverallSize() {
    int overallSize = 0;
    for (int i = 0; i < knapsack->getNumberOfElements(); ++i)
        overallSize += knapsack->getElement(i)->getSize();
    return overallSize;
}

int Knapsack::calculateOverallValue() {
    int overallValue = 0;
    for (int i = 0; i < knapsack->getNumberOfElements(); ++i)
        overallValue += knapsack->getElement(i)->getValue();
    return overallValue;
}
