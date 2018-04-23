//
// Created by thamian on 10.06.17.
//

#ifndef P3_EDGE_H
#define P3_EDGE_H


class Edge {
    int weight;
    int sourceVertex;
    int destinationVertex;

public:
    Edge(int weight, int sourceVertex, int destinationVertex);
    ~Edge();

    int getWeight();
    int getSourceVertex();
    int getDestinationVertex();

    bool operator <(const Edge& edge);
    bool operator >(const Edge& edge);
};


#endif //P3_EDGE_H
