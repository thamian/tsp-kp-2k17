//
// Created by thamian on 10.06.17.
//

#include "Edge.h"

Edge::Edge(int weight, int sourceVertex, int destinationVertex) {
    this->weight = weight;
    this->sourceVertex = sourceVertex;
    this->destinationVertex = destinationVertex;
}

Edge::~Edge() {

}

int Edge::getWeight() {
    return weight;
}

int Edge::getSourceVertex() {
    return sourceVertex;
}

int Edge::getDestinationVertex() {
    return destinationVertex;
}

bool Edge::operator <(const Edge& edge) {
    return this->weight < edge.weight;
}

bool Edge::operator >(const Edge& edge) {
    return this->weight > edge.weight;
}
