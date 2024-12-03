#include "mypriorityqueue.h"
#include <iostream>
#include <cassert>

int main() {
    MyPriorityQueue<int> pq;

    // Test: Dodanie elementów
    pq.push(10);
    pq.push(20);
    pq.push(15);
    std::cout << "Po dodaniu 10, 20, 15: ";
    pq.display();

    // Test: Rozmiar kolejki
    assert(pq.size() == 3);
    std::cout << "Rozmiar kolejki: " << pq.size() << std::endl;

    // Test: Największy element
    assert(pq.top() == 20);
    std::cout << "Największy element (top): " << pq.top() << std::endl;

    // Test: Usunięcie największego elementu
    pq.pop();
    assert(pq.size() == 2);
    assert(pq.top() == 15);
    std::cout << "Po usunięciu największego elementu: ";
    pq.display();

    // Test: Dodanie kolejnych elementów
    pq.push(5);
    pq.push(25);
    std::cout << "Po dodaniu 5 i 25: ";
    pq.display();
    assert(pq.top() == 25);

    // Test: Wyczyszczenie kolejki
    pq.clear();
    assert(pq.empty());
    std::cout << "Po wyczyszczeniu kolejki: ";
    pq.display();

    // Test: Kopiowanie kolejki
    MyPriorityQueue<int> pq_copy(pq);
    assert(pq_copy.empty());

    // Test: Przeniesienie kolejki
    pq.push(100);
    MyPriorityQueue<int> pq_move(std::move(pq));
    assert(pq.empty());
    assert(pq_move.top() == 100);
    std::cout << "Po przeniesieniu kolejki: ";
    pq_move.display();

    std::cout << "Wszystkie testy zakończone sukcesem!" << std::endl;
    return 0;
}
