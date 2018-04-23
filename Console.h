//
// Created by thamian on 10.06.17.
//

#ifndef P3_CONSOLE_H
#define P3_CONSOLE_H


#include <iostream>

class Console {
protected:
    int getPositiveNumber();
    int getPositiveNumber(std::string string);
    std::string getInput();
    std::string getInput(std::string string);
    int convert(std::string string);

public:
    void print(std::string string);
    void println();
    void println(std::string string);
};


#endif //P3_CONSOLE_H
