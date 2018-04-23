//
// Created by thamian on 19.06.17.
//

#ifndef P3_TRAVELLINGSALESMAN_H
#define P3_TRAVELLINGSALESMAN_H


#include "File.h"
#include "Graph.h"

class TravellingSalesman {
    int numberOfCities;
    int firstCity;
    int lastCity;

    Graph* cities;
    int* visitedCities;
    int overallRoad;

public:
    TravellingSalesman(File& file);
    ~TravellingSalesman();

    int getNumberOfCities();
    int getFirstCity();
    int getLastCity();

    Graph* getCities();
    int* getVisitedCities();

    void clear();
    int bruteForce();
    int greedyAlgorithm();
    void permute(int *permutations, int firstElement, int lastElement);
    void swap(int* x, int* y);
    void calculateRoad(int *permutation);
};


#endif //P3_TRAVELLINGSALESMAN_H
