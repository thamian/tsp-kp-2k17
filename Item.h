//
// Created by thamian on 17.06.17.
//

#ifndef P3_ITEM_H
#define P3_ITEM_H


class Item {
    int size;
    int value;
    double comparableValue;

public:
    Item(int size, int value);
    ~Item();

    double calculateRatio();

    int getSize() const;
    int getValue() const;
    double getComparableValue() const;
    
    void setComparableValue(double comparableValue);

    bool operator <(const Item& item);
    bool operator >(const Item& item);

    void display();
};


#endif //P3_ITEM_H
