#include <iostream>
#include <vector>
#include <chrono>
#include "A.hpp"

using namespace std;

int main() {
    // Większe wartości n (do 20 000) i gęstsze kroki
    vector<int> vertex_counts = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000}; 
    const int EDGES_PER_VERTEX = 100; // Zwiększona liczba krawędzi na wierzchołek

    cout << "vertex_count,time_ms" << endl;

    for (int n : vertex_counts) {
        Graph<int, int, double> graph;

        // Dodawanie wierzchołków
        for (int i = 0; i < n; ++i) {
            graph.addVertex(i);
        }

        // Dodawanie krawędzi (każdy wierzchołek łączy się z 100 następnymi)
        if (n > 1) {
            for (int i = 0; i < n; ++i) {
                for (int j = 1; j <= EDGES_PER_VERTEX; ++j) {
                    int target = (i + j) % n;
                    graph.addEdge(i, target);
                }
            }
        }

        // Pomiar czasu usuwania wierzchołka 0 (najgorszy przypadek)
        auto start = chrono::high_resolution_clock::now();
        graph.removeVertex(0);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

        cout << n << "," << duration << endl;
    }

    return 0;
}