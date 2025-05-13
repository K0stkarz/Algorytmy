#include "B.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

// Lista wszystkich ruchów na skrzyżowaniu
vector<string> getMovements() {
    return {
        "A->B", "A->C", "A->D",
        "B->A", "B->C", "B->D",
        "D->A", "D->B", "D->C",
        "E->A", "E->B", "E->C", "E->D"
    };
}

// Sprawdza, czy dwa ruchy są w konflikcie
bool doConflict(const string& m1, const string& m2) {
    // Obsługa ruchów z E:
    // - Jeśli oba ruchy pochodzą z E, nie konfliktują.
    // - Jeśli tylko jeden z ruchów pochodzi z E, to konfliktuje z ruchem z innego kierunku.
    if (m1[0] == 'E' || m2[0] == 'E') {
        if (!(m1[0] == 'E' && m2[0] == 'E')) {
            return true;
        }
    }
    
    // Ruchy z tego samego kierunku (A, B lub D) konfliktują ze sobą.
    if (m1[0] == m2[0] && m1[0] != 'E') {
        return true;
    }
    
    // Ruchy przeciwne – przykładowo A->B i B->A.
    if (m1[0] == m2[3] && m1[3] == m2[0]) {
        return true;
    }
    
    return false;
}

// Buduje graf konfliktów
Graph<string, int, int> buildConflictGraph() {
    Graph<string, int, int> conflictGraph;
    vector<string> movements = getMovements();
    
    for (const auto& m : movements) {
        conflictGraph.addVertex(m);
    }
    
    for (size_t i = 0; i < movements.size(); ++i) {
        for (size_t j = i + 1; j < movements.size(); ++j) {
            if (doConflict(movements[i], movements[j])) {
                conflictGraph.addEdge(movements[i], movements[j]);
                conflictGraph.addEdge(movements[j], movements[i]); // Graf nieskierowany
            }
        }
    }
    
    return conflictGraph;
}

// Algorytm kolorowania grafu (algorytm zachłanny)
map<string, int> colorGraph(const Graph<string, int, int>& graph, const vector<string>& vertices) {
    map<string, int> colorMap;
    
    // Sortowanie wierzchołków malejąco według liczby sąsiadów
    vector<string> sortedVertices = vertices;
    sort(sortedVertices.begin(), sortedVertices.end(), [&](const string& a, const string& b) {
        return graph.neighbours(a).size() > graph.neighbours(b).size();
    });
    
    for (const auto& v : sortedVertices) {
        set<int> usedColors;
        for (const auto& n : graph.neighbours(v)) {
            if (colorMap.find(n) != colorMap.end()) {
                usedColors.insert(colorMap[n]);
            }
        }
        
        int color = 0;
        while (usedColors.count(color)) color++;
        
        colorMap[v] = color;
    }
    
    return colorMap;
}

int main() {
    // Budowanie grafu konfliktów
    Graph<string, int, int> conflictGraph = buildConflictGraph();
    vector<string> movements = getMovements();
    
    // Kolorowanie grafu
    map<string, int> colorAssignment = colorGraph(conflictGraph, movements);
    
    // Grupowanie ruchów w fazy
    map<int, vector<string>> phases;
    for (const auto& m : movements) {
        phases[colorAssignment[m]].push_back(m);
    }
    
    // Wyświetlanie wyników
    cout << "Minimalna liczba faz: " << phases.size() << endl;
    for (const auto& phase : phases) {
        cout << "Faza " << phase.first + 1 << ": ";
        for (const auto& m : phase.second) {
            cout << m << " ";
        }
        cout << endl;
    }
    
    return 0;
}
