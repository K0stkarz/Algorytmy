#include <iostream>
#include <fstream>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include "graph.hpp"

using namespace std;

vector<string> find_shortest_path(const Graph<string, int, int>& graph, const string& start, const string& end) {
    if (start == end) return {start};

    queue<string> q;
    unordered_map<string, string> parent;
    unordered_set<string> visited;

    q.push(start);
    visited.insert(start);
    parent[start] = "";

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        vector<string> neighbors = graph.neighbours(current);
        for (const string& neighbor : neighbors) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                parent[neighbor] = current;
                q.push(neighbor);

                if (neighbor == end) {
                    vector<string> path;
                    string node = neighbor;
                    while (node != "") {
                        path.push_back(node);
                        node = parent[node];
                    }
                    reverse(path.begin(), path.end());
                    return path;
                }
            }
        }
    }

    return {};
}

int main() {
    ifstream file("slowa.txt");
    unordered_set<string> words_set;
    string word;

    // Wczytaj słowa i filtruj czteroliterowe
    while (file >> word) {
        if (word.size() == 4) {
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            words_set.insert(word);
        }
    }

    // Inicjalizacja grafu
    Graph<string, int, int> graph;
    for (const auto& w : words_set) {
        graph.addVertex(w);
    }

    // Dodawanie krawędzi
    for (const auto& w : words_set) {
        for (int i = 0; i < 4; ++i) {
            string temp = w;
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c == temp[i]) continue;
                temp[i] = c;
                if (words_set.count(temp)) {
                    graph.addEdge(w, temp);
                    graph.addEdge(temp, w);
                }
            }
        }
    }

    string start, end;
    cout << "Podaj słowo startowe: ";
    cin >> start;
    cout << "Podaj słowo końcowe: ";
    cin >> end;

    transform(start.begin(), start.end(), start.begin(), ::tolower);
    transform(end.begin(), end.end(), end.begin(), ::tolower);

    if (words_set.find(start) == words_set.end() || words_set.find(end) == words_set.end()) {
        cerr << "Błąd: Jedno ze słów nie istnieje w słowniku.\n";
        return 1;
    }

    vector<string> path = find_shortest_path(graph, start, end);

    if (path.empty()) {
        cout << "Nie znaleziono ścieżki.\n";
    } else {
        cout << "Najkrótsza ścieżka:\n";
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i != path.size() - 1) cout << " -> ";
        }
        cout << "\n";
    }

    return 0;
}