#include <iostream>
#include <vector>
#include <chrono>
#include "A.hpp"

using namespace std;

int main() {
    vector<int> vertex_counts = {10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000}; 
    const int EDGES_PER_VERTEX = 1000; // Mniej krawędzi, aby skrócić czas przygotowania grafu
    const int REPEATS = 100; // Mniej powtórzeń ze względu na długi czas wykonania

    cout << "vertex_count,time_ms" << endl;

    for (int n : vertex_counts) {
        Graph<int, int, double> graph;

        // Dodawanie wierzchołków
        for (int i = 0; i < n; ++i) {
            graph.addVertex(i);
        }

        // Dodawanie krawędzi (każdy wierzchołek łączy się z 10 następnymi)
        if (n > 1) {
            for (int i = 0; i < n; ++i) {
                for (int j = 1; j <= EDGES_PER_VERTEX; ++j) {
                    int target = (i + j) % n;
                    graph.addEdge(i, target);
                }
            }
        }

        // Pomiar czasu z powtórzeniami
        double total_duration = 0;

        for (int r = 0; r < REPEATS; ++r) {
            // Dodawanie wierzchołka 0 na nowo przed każdym pomiarem
            if (r > 0) {
                graph.addVertex(0);
                for (int j = 1; j <= EDGES_PER_VERTEX; ++j) {
                    int target = (0 + j) % n;
                    graph.addEdge(0, target);
                    graph.addEdge(target, 0);
                }
            }

            // Pomiar usuwania wierzchołka 0
            auto start = chrono::high_resolution_clock::now();
            graph.removeVertex(0);
            auto end = chrono::high_resolution_clock::now();
            total_duration += chrono::duration_cast<chrono::milliseconds>(end - start).count();
        }

        // Średni czas usuwania
        cout << n << "," << total_duration / REPEATS << endl;
    }

    return 0;
}