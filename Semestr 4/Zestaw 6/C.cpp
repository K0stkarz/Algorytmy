#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "graph.hpp"

using namespace std;

void dfs(const string& node, 
         const Graph<string, int, int>& graph, 
         unordered_map<string, bool>& visited, 
         vector<string>& order) {
    visited[node] = true;
    for (const auto& neighbor : graph.neighbours(node)) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, order);
        }
    }
    order.push_back(node);
}

vector<string> topological_sort_dfs(const Graph<string, int, int>& graph) {
    vector<string> vertices = {"jajko", "olej", "mleko", "proszek", "syrop", "patelnia",
                               "nagrzej_patelnię", "wymieszaj", "wylej_ciasto", "przewróć", "podgrzej_syrop", "zjedz"};
    unordered_map<string, bool> visited;
    vector<string> order;

    for (const auto& node : vertices) {
        if (!visited[node]) {
            dfs(node, graph, visited, order);
        }
    }

    reverse(order.begin(), order.end());

    // Filtruj składniki
    vector<string> steps;
    vector<string> ingredients = {"jajko", "olej", "mleko", "proszek", "syrop", "patelnia"};
    for (const auto& node : order) {
        if (find(ingredients.begin(), ingredients.end(), node) == ingredients.end()) {
            steps.push_back(node);
        }
    }

    return steps;
}

int main() {
    Graph<string, int, int> graph;

    // Dodaj wierzchołki (składniki i czynności)
    vector<string> nodes = {"jajko", "olej", "mleko", "proszek", "syrop", "patelnia",
                            "nagrzej_patelnię", "wymieszaj", "wylej_ciasto", "przewróć", "podgrzej_syrop", "zjedz"};
    for (const auto& node : nodes) {
        graph.addVertex(node);
    }

    // Dodaj krawędzie (zależności)
    graph.addEdge("patelnia", "nagrzej_patelnię");
    graph.addEdge("jajko", "wymieszaj");
    graph.addEdge("olej", "wymieszaj");
    graph.addEdge("mleko", "wymieszaj");
    graph.addEdge("proszek", "wymieszaj");
    graph.addEdge("nagrzej_patelnię", "wylej_ciasto");
    graph.addEdge("wymieszaj", "wylej_ciasto");
    graph.addEdge("wylej_ciasto", "przewróć");
    graph.addEdge("syrop", "podgrzej_syrop");
    graph.addEdge("przewróć", "zjedz");
    graph.addEdge("podgrzej_syrop", "zjedz");

    vector<string> steps_order = topological_sort_dfs(graph);

    cout << "Kolejność czynności:\n";
    for (const auto& step : steps_order) {
        cout << "→ " << step << "\n";
    }

    return 0;
}