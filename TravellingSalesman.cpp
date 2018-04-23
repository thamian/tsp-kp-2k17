//
// Created by thamian on 19.06.17.
//

#include <iostream>
#include <chrono>
#include "TravellingSalesman.h"

TravellingSalesman::TravellingSalesman(File& file) {
    cities = new Graph(file);

    numberOfCities = cities->getNumberOfVertices();
    firstCity = cities->getFirstVertexNumber();
    lastCity = firstCity;

    overallRoad = 0;
    visitedCities = new int [numberOfCities + 1];
}

TravellingSalesman::~TravellingSalesman() {
    delete cities;
    delete [] visitedCities;
}

int TravellingSalesman::bruteForce() {
    int* permutation = new int [numberOfCities];
    overallRoad = INT32_MAX;
    for (int i = 0; i < numberOfCities; ++i)
        permutation[i] = i;

    permute(permutation, 1, numberOfCities - 1);

    //delete [] permutation;

    return overallRoad;
}

int TravellingSalesman::greedyAlgorithm() {
    int lastVisitedCity = firstCity;
    int currentCity = firstCity;
    int nextCity;

    visitedCities[0] = firstCity;

    bool* visitedCitiesBool = new bool [numberOfCities];
    for (int i = 0; i < numberOfCities; ++i)
        visitedCitiesBool[i] = false;
    visitedCitiesBool[firstCity] = true;

    for (int i = 1; i < numberOfCities; ++i) {
        int shortestRoad = INT32_MAX;
        for (int j = 0; j < numberOfCities; ++j) {
            if (!visitedCitiesBool[j] && j != currentCity) {
                int nextRoad = cities->getEdgeWeight(lastVisitedCity, j);
                if (shortestRoad > nextRoad) {
                    shortestRoad = nextRoad;
                    nextCity = j;
                }
            }
        }
        overallRoad += shortestRoad;
        visitedCities[i] = nextCity;
        visitedCitiesBool[nextCity] = true;
        lastVisitedCity = visitedCities[i];
        currentCity = nextCity;
    }
    int lastRoad = cities->getEdgeWeight(visitedCities[numberOfCities - 1], 0);
    overallRoad += lastRoad;
    visitedCities[numberOfCities] = firstCity;

    return overallRoad;
}

int TravellingSalesman::getNumberOfCities() {
    return numberOfCities;
}

int TravellingSalesman::getFirstCity() {
    return firstCity;
}

int TravellingSalesman::getLastCity() {
    return lastCity;
}

Graph *TravellingSalesman::getCities() {
    return cities;
}

int *TravellingSalesman::getVisitedCities() {
    return visitedCities;
}

void TravellingSalesman::clear() {
    overallRoad = 0;
    delete visitedCities;
    visitedCities = new int [numberOfCities + 1];
}

void TravellingSalesman::permute(int *permutation, int firstElement, int lastElement) {
    if (firstElement == lastElement) {
        calculateRoad(permutation);
    }
    else {
        for (int i = firstElement; i <= lastElement; ++i) {
            swap((permutation + firstElement), (permutation + i));
            permute(permutation, firstElement + 1, lastElement);
            swap((permutation + firstElement), (permutation + i));
        }
    }
}

void TravellingSalesman::swap(int* x, int* y) {
    int temporary;
    temporary = *x;
    *x = *y;
    *y = temporary;
}

void TravellingSalesman::calculateRoad(int *permutation) {
    int road = 0;
    for (int i = 0; i < numberOfCities - 1; ++i) {
        road += cities->getEdgeWeight(permutation[i], permutation[i + 1]);
    }
    road += cities->getEdgeWeight(permutation[numberOfCities - 1], permutation[0]);

    if (road < overallRoad) {
        overallRoad = road;

        for (int i = 0; i < numberOfCities; ++i) {
            visitedCities[i] = permutation[i];
        }
        visitedCities[numberOfCities] = 0;
    }
}

