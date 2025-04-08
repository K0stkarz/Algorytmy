#include <iostream>
#include <stdexcept>
#include "A.hpp"

int main() {
    try {
        PriorityQueue<int> pq;

        // Test 1: Dodawanie elementów i wyświetlanie
        std::cout << "Test 1: Dodawanie elementów 5, 3, 8\n";
        pq.add(5);
        pq.add(3);
        pq.add(8);
        std::cout << "Zawartość kolejki: ";
        pq.display(); // Oczekiwane: [3, 5, 8]

        // Test 2: Usuwanie elementu o najmniejszym priorytecie
        std::cout << "\nTest 2: Usuwanie minimum\n";
        std::cout << "Usunięto: " << pq.delete_min() << std::endl; // Oczekiwane: 3
        std::cout << "Zawartość kolejki: ";
        pq.display(); // Oczekiwane: [5, 8]

        // Test 3: Kolejność usuwania
        std::cout << "\nTest 3: Kolejność usuwania\n";
        std::cout << "Usunięto: " << pq.delete_min() << std::endl; // Oczekiwane: 5
        std::cout << "Usunięto: " << pq.delete_min() << std::endl; // Oczekiwane: 8
        std::cout << "Zawartość kolejki: ";
        pq.display(); // Oczekiwane: []

        
        // Test 4: Obsługa duplikatów
        std::cout << "\nTest 4: Duplikaty\n";
        pq.add(2);
        pq.add(2);
        std::cout << "Zawartość kolejki po dodaniu dwóch 2: ";
        pq.display(); // Oczekiwane: [2]

    } catch (const std::exception& e) {
        std::cout << "\nWyjątek: " << e.what() << std::endl;
    }

    std::cout << "\nWszystkie testy zakończone!" << std::endl;
    return 0;
}