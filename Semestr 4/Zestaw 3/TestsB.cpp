#include <iostream>
#include <stdexcept>
#include "B.hpp"

int main() {
    try {
        PriortyQueueBinary<int> pq;

        // Test 1: Dodawanie elementów i wyświetlanie
        std::cout << "Test 1: Dodawanie elementów 5, 3, 8\n";
        pq.add(5);
        pq.add(3);
        pq.add(8);
        std::cout << "Zawartość kolejki: ";
        pq.display(); // Oczekiwane: [3, 5, 8]
        std::cout << std::endl;

        // Test 2: Usuwanie elementu o najmniejszym priorytecie
        std::cout << "\nTest 2: Usuwanie minimum\n";
        std::cout << "Usunięto: " << pq.delete_min() << std::endl; // Oczekiwane: 3
        std::cout << "Zawartość kolejki: ";
        pq.display(); // Oczekiwane: [5, 8]
        std::cout << std::endl;

        // Test 3: Kolejność usuwania
        std::cout << "\nTest 3: Kolejność usuwania\n";
        std::cout << "Usunięto: " << pq.delete_min() << std::endl; // Oczekiwane: 5
        std::cout << "Usunięto: " << pq.delete_min() << std::endl; // Oczekiwane: 8
        std::cout << "Zawartość kolejki: ";
        pq.display(); // Oczekiwane: []
        std::cout << std::endl;

        // Test 4: Obsługa duplikatów
        std::cout << "\nTest 4: Duplikaty\n";
        pq.add(2);
        pq.add(2);
        std::cout << "Zawartość kolejki po dodaniu dwóch 2: ";
        pq.display(); // Oczekiwane: [2, 2]
        std::cout << std::endl;

        // Test 5: Testowanie kopca binarnego z większą ilością danych
        std::cout << "\nTest 5: Testowanie kopca binarnego\n";
        pq.add(10);
        pq.add(1);
        pq.add(5);
        pq.add(7);
        std::cout << "Zawartość kolejki: ";
        pq.display(); // Oczekiwane: [1, 2, 5, 7, 10] lub inna struktura zachowująca porządek
        std::cout << std::endl;

        // Test 6: Usuwanie z większej kolejki
        std::cout << "\nTest 6: Usuwanie z większej kolejki\n";
        std::cout << "Usunięto: " << pq.delete_min() << std::endl; // Oczekiwane: 1
        std::cout << "Usunięto: " << pq.delete_min() << std::endl; // Oczekiwane: 2
        std::cout << "Zawartość kolejki: ";
        pq.display(); // Oczekiwane: [5, 7, 10] lub inna struktura zachowująca porządek
        std::cout << std::endl;

        // Test 7: Testowanie pustej kolejki
        std::cout << "\nTest 7: Testowanie pustej kolejki\n";
        PriortyQueueBinary<int> empty_pq;
        try {
            empty_pq.delete_min();
            std::cout << "Błąd: Powinien być zgłoszony wyjątek dla pustej kolejki" << std::endl;
        } catch (const std::runtime_error& e) {
            std::cout << "Poprawnie zgłoszono wyjątek: " << e.what() << std::endl;
        }

        // Test 8: Opróżnianie kolejki
        std::cout << "\nTest 8: Opróżnianie kolejki\n";
        while (pq.size() > 0) {
            std::cout << "Usunięto: " << pq.delete_min() << std::endl;
        }
        std::cout << "Kolejka jest pusta: " << (pq.isEmpty() ? "Tak" : "Nie") << std::endl;

    } catch (const std::exception& e) {
        std::cout << "\nWyjątek: " << e.what() << std::endl;
    }

    std::cout << "\nWszystkie testy zakończone!" << std::endl;
    return 0;
}