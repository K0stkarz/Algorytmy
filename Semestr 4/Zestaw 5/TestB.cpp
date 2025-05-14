#include "B.hpp"

int main() {
    Graph<std::string, int, float> g;
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addEdge("A", "B");
    g.addEdge("B", "A");
    g.addEdge("A", "C");
    g.addEdge("C", "A");
    g.addEdge("B", "C");
    g.addEdge("C", "B");

    g.generateDotFile("graph.dot"); 
    return 0;
}
