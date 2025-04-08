#include <iostream>
#include <cassert>
#include "B2.hpp" // Plik nagłówkowy z implementacją SetHashed

// Funkcja do testowania podstawowych funkcjonalności klasy SetHashed
void testSetHashed() {
    std::cout << "=== Testowanie podstawowych funkcjonalności SetHashed ===" << std::endl;

    // Test konstruktora i dodawania elementów
    SetHashed<int> set1;
    set1.add(1);
    set1.add(3);
    set1.add(5);
    std::cout << "Set1: " << std::endl;
    set1.display();
    assert(set1.contains(1) && set1.contains(3) && set1.contains(5));
    assert(!set1.contains(0) && !set1.contains(2) && !set1.contains(4));

    // Test metody remove
    set1.remove(3);
    std::cout << "Set1 po usunięciu 3: " << std::endl;
    set1.display();
    assert(set1.contains(1) && !set1.contains(3) && set1.contains(5));

    std::cout << "Wszystkie testy podstawowych funkcjonalności przeszły pomyślnie!" << std::endl;
}

// Funkcja do testowania operacji na zbiorach
void testSetOperations() {
    std::cout << "\n=== Testowanie operacji na zbiorach ===" << std::endl;

    // Test sumy zbiorów
    SetHashed<int> set1;
    set1.add(1);
    set1.add(3);
    set1.add(5);

    SetHashed<int> set2;
    set2.add(3);
    set2.add(4);
    set2.add(6);

    SetHashed<int> sumSet = set1.sum(set2);
    std::cout << "Suma zbiorów: " << std::endl;
    sumSet.display();
    assert(sumSet.contains(1) && sumSet.contains(3) && sumSet.contains(4) && sumSet.contains(5) && sumSet.contains(6));

    // Test części wspólnej zbiorów
    SetHashed<int> intersectionSet = set1.intersection(set2);
    std::cout << "Część wspólna zbiorów: " << std::endl;
    intersectionSet.display();
    assert(intersectionSet.contains(3) && !intersectionSet.contains(1) && !intersectionSet.contains(4));

    // Test różnicy zbiorów
    SetHashed<int> differenceSet = set1.difference(set2);
    std::cout << "Różnica zbiorów: " << std::endl;
    differenceSet.display();
    assert(differenceSet.contains(1) && differenceSet.contains(5) && !differenceSet.contains(3));

    // Test identyczności zbiorów
    std::cout << "Identyczność zbiorów: " << set1.identical(set2) <<std::endl;

    std::cout << "Wszystkie testy operacji na zbiorach przeszły pomyślnie!" << std::endl;
}

// Funkcja do testowania przypadków granicznych
void testEdgeCases() {
    std::cout << "\n=== Testowanie przypadków granicznych ===" << std::endl;

    // Test pustego zbioru
    SetHashed<int> emptySet;
    std::cout << "Pusty zbiór: " << std::endl;
    emptySet.display();
    assert(!emptySet.contains(0));

    // Test zbioru z jednym elementem
    SetHashed<int> singleElement;
    singleElement.add(3);
    std::cout << "Zbiór z jednym elementem: " << std::endl;
    singleElement.display();
    assert(singleElement.contains(3));

    // Test zbioru z wieloma elementami
    SetHashed<int> fullSet;
    for (int i = 0; i < 10; i++) {
        fullSet.add(i);
    }
    std::cout << "Pełny zbiór: " << std::endl;
    fullSet.display();
    for (int i = 0; i < 10; i++) {
        assert(fullSet.contains(i));
    }

    // Test usuwania elementów z pełnego zbioru
    for (int i = 0; i < 10; i += 2) {
        fullSet.remove(i);
    }
    std::cout << "Pełny zbiór po usunięciu elementów parzystych: " << std::endl;
    fullSet.display();
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            assert(!fullSet.contains(i));
        } else {
            assert(fullSet.contains(i));
        }
    }
    std::cout << "Wszystkie testy przypadków granicznych przeszły pomyślnie!" << std::endl;
}

int main() {
    testSetHashed();
    testSetOperations();
    testEdgeCases();

    std::cout << "\nWszystkie testy zakończone pomyślnie!" << std::endl;
    return 0;
}