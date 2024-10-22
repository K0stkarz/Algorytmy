#include "arraylist.h"
#include <cassert>
#include <iostream>

int main() {
    ArrayList<int> list;

    // Test dynamicznego dodawania elementów
    for (int i = 0; i < 10; ++i) {
        list.push_back(i * 10);
    }
    assert(list.size() == 10); 
    assert(list.back() == 90); 
    std::cout << "Test dynamicznego dodawania elementów: OK" << std::endl;
    list.display();

    // Test zmniejszania tablicy przy usuwaniu elementów
    for (int i = 0; i < 8; ++i) {
        list.pop_back();
    }
    assert(list.size() == 2); 
    assert(list.back() == 10);
    std::cout << "Test zmniejszania tablicy: OK" << std::endl;
    list.display();

    // Sprawdzenie minimalnego rozmiaru po redukcji
    list.pop_back();
    list.pop_back();
    assert(list.empty());
    std::cout << "Test minimalnego rozmiaru po redukcji: OK" << std::endl;
    list.display();

    std::cout << "Wszystkie testy zadania 3.2 zakończone sukcesem!" << std::endl;

    return 0;
}
