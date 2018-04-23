//
// Created by thamian on 10.06.17.
//

#include "Console.h"

int Console::getPositiveNumber() {
    return convert(getInput());
}

int Console::getPositiveNumber(std::string message) {
    return convert(getInput(message));
}

std::string Console::getInput() {
    std::string input;
    std::cin >> input;
    return input;
}

std::string Console::getInput(std::string message) {
    print(message);
    return getInput();
}

int Console::convert(std::string string) {
    int intInput;
    try {
        intInput = std::stoi(string);
    } catch (std::invalid_argument& e) {
        return -1;
    }
    return intInput;
}

void Console::print(std::string message) {
    std::cout << message;
}

void Console::println() {
    std::cout << "\n";
}

void Console::println(std::string message) {
    std::cout << message << "\n";
}
