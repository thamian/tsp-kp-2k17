//
// Created by thamian on 10.06.17.
//

#ifndef P3_GRAPH_H
#define P3_GRAPH_H


#include "File.h"

class Graph {
    int numberOfEdges;
    int numberOfVertices;
    int firstVertexNumber;
    int lastVertexNumber;

    int** adjacencyMatrix;

    void initializeArray(File& file);
    void initializeArray(int value);
    void createEdge(int sourceVertex, int destinationVertex, int weight);
    void createArray();

public:
    Graph();
    Graph(File& file);
    ~Graph();

    int getNumberOfEdges() const;
    int getNumberOfVertices() const;
    int getFirstVertexNumber() const;
    int getLastVertexNumber() const;

    int getEdgeWeight(int sourceVertex, int destinationVertex);
};


#endif //P3_GRAPH_H
