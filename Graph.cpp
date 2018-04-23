//
// Created by thamian on 10.06.17.
//

#include "Graph.h"

Graph::Graph() {

}

Graph::Graph(File& file) {
    numberOfVertices = file.get();
    firstVertexNumber = 0;

    createArray();
    initializeArray(file);
    file.backToBeginning();
}

void Graph::createArray() {
    adjacencyMatrix = new int* [numberOfVertices];
    for (int i = 0; i < numberOfVertices; i++)
        adjacencyMatrix[i] = new int[numberOfVertices];
}

void Graph::initializeArray(int value) {
    for (int i = 0; i < numberOfVertices; i++)
        for (int j = 0; j < numberOfVertices; j++)
            adjacencyMatrix[i][j] = value;
}

void Graph::initializeArray(File& file) {
    for (int i = 0; i < numberOfVertices; ++i)
        for (int j = 0; j < numberOfVertices; ++j)
            createEdge(i, j, file.get());
}

Graph::~Graph() {
    for (int i = 0; i < numberOfVertices; i++)
        delete [] adjacencyMatrix[i];
    delete [] adjacencyMatrix;
}

int Graph::getNumberOfEdges() const {
    return numberOfEdges;
}

int Graph::getNumberOfVertices() const {
    return numberOfVertices;
}

int Graph::getFirstVertexNumber() const {
    return firstVertexNumber;
}

int Graph::getLastVertexNumber() const {
    return lastVertexNumber;
}

int Graph::getEdgeWeight(int firstVertex, int secondVertex) {
    return adjacencyMatrix[firstVertex][secondVertex];
}

void Graph::createEdge(int sourceVertex, int destinationVertex, int weight) {
    adjacencyMatrix[sourceVertex][destinationVertex] = weight;
    numberOfEdges++;
}
