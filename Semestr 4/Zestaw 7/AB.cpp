#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>
#include "../Zestaw 6/graph.hpp"

using namespace std;

// Struktura pomocnicza do przechowywania ścieżki i kosztu
struct PathResult {
    int cost;
    vector<string> path;
};

// Algorytm Dijkstry dla grafu skierowanego
PathResult dijkstra(const Graph<string, int, int>& graph, const string& start, const string& end) {
    unordered_map<string, int> distances;
    unordered_map<string, string> predecessors;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

    // Inicjalizacja odległości
    for (const auto& vertex : graph.neighbours(start)) {
        auto all_vertices = graph.neighbours(start); // HACK: tymczasowe pobranie wszystkich wierzchołków
        // W rzeczywistości należy mieć metodę do pobierania wszystkich wierzchołków w grafie
    }
    distances[start] = 0;
    pq.emplace(0, start);

    while (!pq.empty()) {
        auto [current_dist, current] = pq.top();
        pq.pop();

        if (current == end) break;
        if (current_dist > distances[current]) continue;

        try {
            for (const auto& neighbor : graph.neighbours(current)) {
                int edge_cost = graph.getEdgeValue(current, neighbor);
                int new_dist = current_dist + edge_cost;

                if (!distances.count(neighbor) || new_dist < distances[neighbor]) {
                    distances[neighbor] = new_dist;
                    predecessors[neighbor] = current;
                    pq.emplace(new_dist, neighbor);
                }
            }
        } catch (const exception& e) {
            continue; // Brak sąsiadów
        }
    }

    // Rekonstrukcja ścieżki
    vector<string> path;
    if (!predecessors.count(end) && start != end) {
        return {numeric_limits<int>::max(), {}}; // Brak ścieżki
    }

    string current = end;
    while (current != start) {
        path.push_back(current);
        if (!predecessors.count(current)) {
            return {numeric_limits<int>::max(), {}};
        }
        current = predecessors[current];
    }
    path.push_back(start);
    reverse(path.begin(), path.end());

    return {distances.count(end) ? distances[end] : numeric_limits<int>::max(), path};
}

// Funkcja pomocnicza do inicjalizacji grafu
void initializeBuildingGraph(Graph<string, int, int>& graph) {
    vector<string> vertices = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
    for (const auto& v : vertices) {
        graph.addVertex(v);
    }

    // Dodawanie krawędzi zgodnie z definicją
    vector<tuple<string, string, int>> edges = {
        {"A", "B", 3},
        {"B", "C", 2}, {"B", "D", 1},
        {"C", "B", 2}, {"C", "H", 2},
        {"D", "B", 1}, {"D", "E", 1},
        {"E", "D", 1}, {"E", "F", 1},
        {"F", "E", 1}, {"F", "G", 1}, {"F", "H", 2},
        {"G", "F", 1}, {"G", "H", 1},
        {"H", "C", 2}, {"H", "F", 2}, {"H", "G", 1}, {"H", "I", 2}, {"H", "J", 1},
        {"I", "H", 2},
        {"J", "H", 1}
    };

    for (const auto& [from, to, cost] : edges) {
        graph.addEdge(from, to);
        graph.setEdgeValue(from, to, cost);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <start_room> <end_room>\n";
        return 1;
    }

    string start = argv[1];
    string end = argv[2];

    Graph<string, int, int> building;
    initializeBuildingGraph(building);

    try {
        PathResult result = dijkstra(building, start, end);
        
        if (result.cost == numeric_limits<int>::max()) {
            cout << "No path from " << start << " to " << end << " exists\n";
        } else {
            cout << "Shortest time: " << result.cost << " minutes\nPath: ";
            for (size_t i = 0; i < result.path.size(); ++i) {
                cout << result.path[i];
                if (i != result.path.size() - 1) cout << " -> ";
            }
            cout << endl;
        }
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}