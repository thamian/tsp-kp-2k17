//
// Created by thamian on 10.06.17.
//

#include "Message.h"

const std::string Message::CONSOLE_prompt = ":> ";
const std::string Message::MENU_information =
                "Struktury danych i złożoność obliczeniowa - projekt 3\n"
                "by Damian Korzekwa";
const std::string Message::MENU_description =
                "0 | Lista dostępnych opcji\n"
                "1 | Problem plecakowy\n"
                "2 | Problem komiwojażera\n"
                "3 | Wyjście z programu";
const std::string Message::MENU_wrongInput = "ERR: Polecenie nie zostało rozpoznane";
const std::string Message::FILE_getFilename = "Proszę podać nazwę pliku: ";
const std::string Message::FILE_loadSuccess = "Plik został wczytany poprawnie!";
const std::string Message::FILE_loadFailure = "ERR: Plik nie został wczytany";
const std::string Message::GRAPH_created = "Graf został utworzony!";
const std::string Message::GRAPH_notExist = "Graf jest pusty!";
const std::string Message::GRAPH_display = "Graf w postaci macierzy wag:";
const std::string Message::KNAPSACK_created = "Przedmioty zostały utworzone!";
const std::string Message::KNAPSACK_notExist = "Graf jest pusty!";
const std::string Message::KNAPSACK_displayAllItems = "Knapsack problem:";
const std::string Message::KNAPSACK_displayKnapsack = "Zawartość plecaka:";
const std::string Message::KNAPSACK_greedyAlgorithmRatio = "Algorytm zachłanny (value/size):";
const std::string Message::KNAPSACK_greedyAlgorithmValue = "Algorytm zachłanny (value):";
const std::string Message::KNAPSACK_dynamicProgramming = "Programowanie dynamiczne:";
const std::string Message::SALESMAN_displayAllItems = "Travelling Salesman Problem:";
const std::string Message::SALESMAN_bruteForce = "Przegląd zupełny:";
const std::string Message::SALESMAN_greedyAlgorithm = "Algorytm zachłanny:";
