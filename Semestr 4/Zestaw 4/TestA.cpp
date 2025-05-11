#include <iostream>
#include <stdexcept>
#include "A.hpp"

int main() {
    try {
        Graph<std::string, int, double> graph;

        // Test 1: Dodawanie wierzchołków
        std::cout << "Test 1: Dodawanie wierzchołków A, B, C\n";
        graph.addVertex("A");
        graph.addVertex("B");
        graph.addVertex("C");
        std::cout << "Wierzchołki dodane poprawnie.\n";

        // Test 2: Dodawanie krawędzi
        std::cout << "\nTest 2: Dodawanie krawędzi A->B i B->C\n";
        graph.addEdge("A", "B");
        graph.addEdge("B", "C");
        std::cout << "Czy A sąsiaduje z B? " << graph.adjacent("A", "B") << " (Oczekiwane: 1)\n";
        std::cout << "Czy B sąsiaduje z C? " << graph.adjacent("B", "C") << " (Oczekiwane: 1)\n";

        // Test 3: neighbours()
        std::cout << "\nTest 3: Sąsiedzi wierzchołka B\n";
        auto neighbours = graph.neighbours("B");
        std::cout << "Sąsiedzi B: ";
        for (const auto& n : neighbours) std::cout << n << " ";
        std::cout << "(Oczekiwane: C )\n";

        // Test 4: Usuwanie krawędzi
        std::cout << "\nTest 4: Usuwanie krawędzi A->B\n";
        graph.removeEdge("A", "B");
        std::cout << "Czy A sąsiaduje z B? " << graph.adjacent("A", "B") << " (Oczekiwane: 0)\n";

        // Test 5: setVertexValue i getVertexValue
        std::cout << "\nTest 5: Przypisywanie wartości wierzchołkom\n";
        graph.setVertexValue("A", 100);
        graph.setVertexValue("B", 200);
        std::cout << "Wartość A: " << graph.getVertexValue("A") << " (Oczekiwane: 100)\n";
        std::cout << "Wartość B: " << graph.getVertexValue("B") << " (Oczekiwane: 200)\n";

        // Test 6: setEdgeValue i getEdgeValue
        std::cout << "\nTest 6: Przypisywanie wartości krawędziom\n";
        graph.addEdge("A", "C"); // Dodajemy nową krawędź
        graph.setEdgeValue("A", "C", 5.5);
        std::cout << "Wartość krawędzi A->C: " << graph.getEdgeValue("A", "C") << " (Oczekiwane: 5.5)\n";

        // Test 7: Usuwanie wierzchołka (powinno usunąć powiązane krawędzie)
        std::cout << "\nTest 7: Usuwanie wierzchołka B\n";
        graph.removeVertex("B");
        std::cout << "Czy B istnieje? " << graph.adjacent("B", "C") << " (Oczekiwane: 0)\n";
        std::cout << "Czy krawędź B->C istnieje? " << graph.adjacent("B", "C") << " (Oczekiwane: 0)\n";

        // Test 8: Obsługa wyjątków
        std::cout << "\nTest 8: Obsługa błędów\n";
        try {
            graph.getVertexValue("X"); // Nieistniejący wierzchołek
            std::cout << "Błąd: Brak wyjątku!\n";
        } catch (const std::runtime_error& e) {
            std::cout << "Przechwycono wyjątek (Vertex): " << e.what() << "\n";
        }

        try {
            graph.getEdgeValue("A", "X"); // Nieistniejąca krawędź
            std::cout << "Błąd: Brak wyjątku!\n";
        } catch (const std::runtime_error& e) {
            std::cout << "Przechwycono wyjątek (Edge): " << e.what() << "\n";
        }

        // Test 9: Sprawdzanie macierzy po usunięciu
        std::cout << "\nTest 9: Spójność struktury po usunięciach\n";
        graph.addVertex("D");
        graph.addEdge("C", "D");
        std::cout << "Czy C sąsiaduje z D? " << graph.adjacent("C", "D") << " (Oczekiwane: 1)\n";

    } catch (const std::exception& e) {
        std::cout << "\nWyjątek: " << e.what() << std::endl;
    }

    std::cout << "\nWszystkie testy zakończone!" << std::endl;
    return 0;
}