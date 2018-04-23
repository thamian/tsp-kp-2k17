//
// Created by thamian on 17.06.17.
//

#include <iostream>
#include "Item.h"

Item::Item(int size, int value) {
    this->size = size;
    this->value = value;
}

Item::~Item() {

}

double Item::calculateRatio() {
    return static_cast<double>(value) / static_cast<double>(size);
}

int Item::getSize() const {
    return size;
}

int Item::getValue() const {
    return value;
}

double Item::getComparableValue() const{
    return comparableValue;
}

void Item::setComparableValue(double comparableValue) {
    this->comparableValue = comparableValue;
}

bool Item::operator <(const Item& item) {
    return this->comparableValue < item.comparableValue;
}

bool Item::operator >(const Item& item) {
    return this->comparableValue > item.comparableValue;
}

void Item::display() {
    std::cout << size << "\t" << value << "\t" << comparableValue << "\n";
}
