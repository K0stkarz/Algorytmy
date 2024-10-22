#include "arraylist.h"
#include <cassert>
#include <iostream>

int main() {
    ArrayList<int> list(5);

    // Test dodawania elementów
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.display();
    assert(list.size() == 3); 
    assert(list.back() == 30);
    std::cout << "Test dodawania elementów: OK" << std::endl;
    list.display();

    // Test usuwania elementów
    list.pop_back();
    assert(list.size() == 2); 
    assert(list.back() == 20);
    std::cout << "Test usuwania elementów: OK" << std::endl;
    list.display();

    // Test kopiowania listy
    ArrayList<int> list_copy(list);
    assert(list_copy.size() == 2); 
    assert(list_copy.back() == 20);
    std::cout << "Test kopiowania listy: OK" << std::endl;
    std::cout << "Lista orginalna: "; list.display();
    std::cout << "Lista skopiowana: "; list_copy.display();

    // Test, że oryginalna lista i skopiowana są niezależne
    list.push_back(40);
    assert(list.size() == 3);
    assert(list.back() == 40);
    assert(list_copy.size() == 2);
    assert(list_copy.back() == 20);
    std::cout << "Test niezależności kopiowania: OK" << std::endl;
    list.display();

    std::cout << "Wszystkie testy zadania 3.1 zakończone sukcesem!" << std::endl;

    return 0;
}
