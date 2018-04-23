//
// Created by thamian on 17.06.17.
//

#include <iostream>
#include "ArrayList.h"

ArrayList::ArrayList() {
    size = 0;
    numberOfElements = 0;
    arrayList = new Item* [1];
}

ArrayList::ArrayList(int size) {
    this->size = size;
    numberOfElements = 0;
    arrayList = new Item* [size];
}

ArrayList::~ArrayList() {
    for (int i = 0; i < numberOfElements; i++)
        delete arrayList[i];
    delete [] arrayList;
}

void ArrayList::rebuildDown(int index) {
    int currentElement = index;
    int leftChild = 2 * currentElement + 1;
    int rightChild = 2 * currentElement + 2;

    while ((0 < leftChild) && (leftChild < numberOfElements)) {
        if (rightChild < numberOfElements) {
            if (*arrayList[currentElement] > *arrayList[leftChild] || *arrayList[currentElement] > *arrayList[rightChild]) {
                if (*arrayList[leftChild] < *arrayList[rightChild]) {
                    replace(currentElement, leftChild);

                    currentElement = leftChild;
                }
                else {
                    replace(currentElement, rightChild);

                    currentElement = rightChild;
                }
            }
            else return;
        }
        else if (leftChild < numberOfElements) {
            if (*arrayList[currentElement] > *arrayList[leftChild]) {
                replace(currentElement, leftChild);

                currentElement = leftChild;
            }
            else return;
        }
        else return;

        leftChild = 2 * currentElement + 1;
        rightChild = 2 * currentElement + 2;
    }
}

void ArrayList::replace(int firstElement, int secondElement) {
    Item* temporaryElement = arrayList[firstElement];
    arrayList[firstElement] = arrayList[secondElement];
    arrayList[secondElement] = temporaryElement;
}

void ArrayList::addElement(Item* item) {
    if (numberOfElements < size) {
        arrayList[numberOfElements] = item;
        numberOfElements++;
    }

    else {
        int newSize = size * 2 + 1;
        Item** newArray = new Item* [newSize];

        for (int i = 0; i < numberOfElements; ++i) {
            newArray[i] = arrayList[i];
        }
        newArray[numberOfElements] = item;

        delete [] arrayList;

        arrayList = newArray;

        size = newSize;
        numberOfElements++;
    }
}

void ArrayList::sort() {
    int oldNumberOfElements = numberOfElements;
    for (int i = numberOfElements - 1; i > -1; --i)
        rebuildDown(i);

    for (int i = numberOfElements - 1; i > -1 ; --i) {
        replace(0, i);
        numberOfElements--;
        rebuildDown(0);
    }
    numberOfElements = oldNumberOfElements;
}

int ArrayList::getNumberOfElements() const {
    return numberOfElements;
}

Item *ArrayList::getElement(int index) const{
    bool isFit = 0 <= index < numberOfElements;
    if (isFit)
        return arrayList[index];
    return nullptr;
}

void ArrayList::rebuildUp(int index) {
    int currentElement = index;
    int parent = (currentElement - 1) / 2;

    while ((-1 < parent) && (parent < numberOfElements)) {
        if (*arrayList[currentElement] < *arrayList[parent]) {
            replace(currentElement, parent);

            currentElement = parent;
            parent = (currentElement - 1) / 2;
        }
        else return;
    }
}

void ArrayList::display() {
    std::cout << "Item\tWeight\tValue\t\n";
    std::cout << "----------------------------\n";
    for (int i = 0; i < numberOfElements; ++i) {
        std::cout << i << "\t";
        arrayList[i]->display();
    }
    std::cout << "----------------------------\n";
}

void ArrayList::fillWithNullptr() {
    for (int i = 0; i < size; ++i)
        arrayList[i] = nullptr;
}
