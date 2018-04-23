//
// Created by thamian on 17.06.17.
//

#ifndef P3_ARRAYLIST_H
#define P3_ARRAYLIST_H


#include "Item.h"

class ArrayList {
    Item **arrayList;
    int size;
    int numberOfElements;

public:
    ArrayList();
    ArrayList(int size);
    ~ArrayList();

    int getNumberOfElements() const;

    void rebuildDown(int index);
    void addElement(Item *item);
    void replace(int firstElement, int secondElement);
    void sort();
    void rebuildUp(int index);
    void display();
    void fillWithNullptr();

    Item* getElement(int index) const;
};




#endif //P3_ARRAYLIST_H
