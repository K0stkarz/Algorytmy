#include <iostream>
#include <cassert>
#include "B.hpp" // Plik nagłówkowy z implementacją SetHashed

// Funkcja do testowania podstawowych funkcjonalności klasy SetHashed
void testSetHashed() {
    std::cout << "=== Testowanie podstawowych funkcjonalności SetHashed ===" << std::endl;

    // Test konstruktora i dodawania elementów
    SetHashed<int> set1;
    set1.insert(1);
    set1.insert(3);
    set1.insert(5);
    std::cout << "Set1: ";
    set1.print();
    assert(set1.contains(1) && set1.contains(3) && set1.contains(5));
    assert(!set1.contains(0) && !set1.contains(2) && !set1.contains(4));

    // Test metody remove
    set1.remove(3);
    std::cout << "Set1 po usunięciu 3: ";
    set1.print();
    assert(set1.contains(1) && !set1.contains(3) && set1.contains(5));

    // Test metody unionSet (suma zbiorów)
    SetHashed<int> set2;
    set2.insert(2);
    set2.insert(4);
    set2.insert(5);
    std::cout << "Set2: ";
    set2.print();

    SetHashed<int> set3 = set1.unionSet(set2);
    std::cout << "Set3 (suma Set1 i Set2): ";
    set3.print();
    assert(set3.contains(1) && set3.contains(2) && !set3.contains(3) &&
           set3.contains(4) && set3.contains(5));

    // Test metody intersection (części wspólnej)
    SetHashed<int> set4 = set1.intersection(set2);
    std::cout << "Set4 (część wspólna Set1 i Set2): ";
    set4.print();
    assert(!set4.contains(1) && !set4.contains(2) && !set4.contains(3) &&
           !set4.contains(4) && set4.contains(5));

    // Test metody difference (różnicy zbiorów)
    SetHashed<int> set5 = set1.difference(set2);
    std::cout << "Set5 (różnica Set1 - Set2): ";
    set5.print();
    assert(set5.contains(1) && !set5.contains(2) && !set5.contains(3) &&
           !set5.contains(4) && !set5.contains(5));

    // Test metody equals
    SetHashed<int> set6;
    set6.insert(1);
    set6.insert(5);
    std::cout << "Set6: ";
    set6.print();

    bool equals1 = set1.equals(set6);
    bool equals2 = set1.equals(set2);
    std::cout << "Set1 równy Set6: " << (equals1 ? "Tak" : "Nie") << std::endl;
    std::cout << "Set1 równy Set2: " << (equals2 ? "Tak" : "Nie") << std::endl;
    assert(equals1);
    assert(!equals2);

    std::cout << "Wszystkie testy podstawowych funkcjonalności przeszły pomyślnie!" << std::endl;
}

// Funkcja do testowania przypadków granicznych
void testEdgeCases() {
    std::cout << "\n=== Testowanie przypadków granicznych ===" << std::endl;

    // Test pustego zbioru
    SetHashed<int> emptySet;
    std::cout << "Pusty zbiór: ";
    emptySet.print();
    assert(emptySet.getSize() == 0);

    // Test zbioru z jednym elementem
    SetHashed<int> singleElement;
    singleElement.insert(3);
    std::cout << "Zbiór z jednym elementem: ";
    singleElement.print();
    assert(singleElement.contains(3));
    assert(singleElement.getSize() == 1);

    // Test zbioru z wieloma elementami
    SetHashed<int> fullSet;
    for (int i = 0; i < 10; i++) {
        fullSet.insert(i);
    }
    std::cout << "Pełny zbiór: ";
    fullSet.print();
    assert(fullSet.getSize() == 10);

    // Test operacji na pustych zbiorach
    SetHashed<int> sumEmpty = emptySet.unionSet(emptySet);
    std::cout << "Suma dwóch pustych zbiorów: ";
    sumEmpty.print();
    assert(sumEmpty.getSize() == 0);

    SetHashed<int> intersectionEmpty = emptySet.intersection(fullSet);
    std::cout << "Część wspólna pustego i pełnego zbioru: ";
    intersectionEmpty.print();
    assert(intersectionEmpty.getSize() == 0);

    // Test różnicy pustego zbioru i pełnego zbioru
    SetHashed<int> differenceEmpty = emptySet.difference(fullSet);
    std::cout << "Różnica pustego i pełnego zbioru: ";
    differenceEmpty.print();
    assert(differenceEmpty.getSize() == 0);

    std::cout << "Wszystkie testy przypadków granicznych przeszły pomyślnie!" << std::endl;
}

int main() {
    testSetHashed();
    testEdgeCases();

    std::cout << "\nWszystkie testy zakończone pomyślnie!" << std::endl;
    return 0;
}