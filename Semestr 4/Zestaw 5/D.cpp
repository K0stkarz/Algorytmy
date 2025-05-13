#include <iostream>

#include "B.hpp"

int main(){
    Graph<std::string, int, int> intersectionGraph;
    intersectionGraph.addVertex("A");
    intersectionGraph.addVertex("B");
    intersectionGraph.addVertex("C");
    intersectionGraph.addVertex("D");
    intersectionGraph.addVertex("E");
    intersectionGraph.addEdge("A", "B");
    intersectionGraph.addEdge("A", "C");
    intersectionGraph.addEdge("A", "D");
    intersectionGraph.addEdge("B", "A");
    intersectionGraph.addEdge("B", "C");
    intersectionGraph.addEdge("B", "D");
    intersectionGraph.addEdge("D", "A");
    intersectionGraph.addEdge("D", "B");
    intersectionGraph.addEdge("D", "C");
    intersectionGraph.addEdge("E", "A");
    intersectionGraph.addEdge("E", "B");
    intersectionGraph.addEdge("E", "C");
    intersectionGraph.addEdge("E", "D");

    intersectionGraph.generateDotFile("intersection_graph.dot");
}