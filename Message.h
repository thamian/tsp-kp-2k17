//
// Created by thamian on 10.06.17.
//

#ifndef P3_MESSAGE_H
#define P3_MESSAGE_H


#include <iostream>

class Message {
public:
    static const std::string CONSOLE_prompt;
    static const std::string MENU_description;
    static const std::string MENU_information;
    static const std::string MENU_wrongInput;
    static const std::string FILE_getFilename;
    static const std::string FILE_loadSuccess;
    static const std::string FILE_loadFailure;
    static const std::string GRAPH_created;
    static const std::string GRAPH_notExist;
    static const std::string GRAPH_display;
    static const std::string KNAPSACK_created;
    static const std::string KNAPSACK_notExist;
    static const std::string KNAPSACK_displayAllItems;
    static const std::string KNAPSACK_displayKnapsack;
    static const std::string KNAPSACK_greedyAlgorithmRatio;
    static const std::string KNAPSACK_greedyAlgorithmValue;
    static const std::string KNAPSACK_dynamicProgramming;
    static const std::string SALESMAN_displayAllItems;
    static const std::string SALESMAN_bruteForce;
    static const std::string SALESMAN_greedyAlgorithm;
};


#endif //P3_MESSAGE_H
