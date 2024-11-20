#include <cassert>
#include <iostream>
#include <string>
#include "myqueue.h"

void test_queue() {
    // Test konstruktorów
    MyQueue<int> q1(5);
    assert(q1.empty());
    assert(!q1.full());
    assert(q1.size() == 0);
    assert(q1.max_size() == 5);

    // Test push (kopiowanie)
    q1.push(10);
    assert(!q1.empty());
    assert(q1.size() == 1);
    assert(q1.front() == 10);
    assert(q1.back() == 10);

    q1.push(20);
    assert(q1.size() == 2);
    assert(q1.front() == 10);
    assert(q1.back() == 20);

    // Test push (przenoszenie)
    int value = 30;
    q1.push(std::move(value));
    assert(q1.size() == 3);
    assert(q1.back() == 30);

    // Test pop
    q1.pop();
    assert(q1.size() == 2);
    assert(q1.front() == 20);

    q1.pop();
    assert(q1.size() == 1);
    assert(q1.front() == 30);

    // Test clear
    q1.clear();
    assert(q1.empty());
    assert(q1.size() == 0);

    // Test cykliczności
    MyQueue<int> q2(3); // Max 3 elementy
    q2.push(1);
    q2.push(2);
    q2.push(3);
    assert(q2.full());
    q2.pop();
    assert(!q2.full());
    q2.push(4); // Powinien zacząć zapisywać na początku tablicy
    assert(q2.front() == 2);
    assert(q2.back() == 4);

    // Test konstruktorów kopiujących i przenoszących
    MyQueue<int> q3 = q2; // Konstruktor kopiujący
    assert(q3.size() == q2.size());
    assert(q3.front() == q2.front());
    assert(q3.back() == q2.back());

    MyQueue<int> q4 = std::move(q3); // Konstruktor przenoszący
    assert(q4.size() == q2.size());
    assert(q3.empty()); // Przeniesiona kolejka powinna być pusta

    // Test operatora przypisania (kopiowanie)
    MyQueue<int> q5(10);
    q5 = q2;
    assert(q5.size() == q2.size());
    assert(q5.front() == q2.front());
    assert(q5.back() == q2.back());

    // Test operatora przypisania (przenoszenie)
    MyQueue<int> q6(10);
    q6 = std::move(q2);
    assert(q6.size() == 3);
    assert(q2.empty()); // Przeniesiona kolejka powinna być pusta

    // Test wyjątku przy push do pełnej kolejki
    MyQueue<int> q7(2);
    q7.push(1);
    q7.push(2);
    try {
        q7.push(3);
        assert(false); 
    } catch (const std::overflow_error& e) {
        assert(std::string(e.what()) == "Queue overflow: Cannot push onto a full queue.");
    }

    // Test wyjątku przy pop z pustej kolejki
    MyQueue<int> q8(2);
    try {
        q8.pop();
        assert(false); 
    } catch (const std::underflow_error& e) {
        assert(std::string(e.what()) == "Queue underflow: Cannot pop from an empty queue.");
    }

    // Test metody display (weryfikacja na podstawie ręcznego porównania)
    std::cout << "Expected: 1 2\n";
    q7.display();

    std::cout << "All tests passed successfully.\n";
}

int main() {
    test_queue();
    return 0;
}
