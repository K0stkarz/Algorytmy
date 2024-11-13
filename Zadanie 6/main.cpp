#include <cassert>
#include <iostream>
#include "mydeque.h"

void test_push_back() {
    MyDeque<int> deque(5);
    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(3);
    assert(deque.size() == 3);
    assert(deque.back() == 3);
    assert(deque.front() == 1);
}

void test_push_front() {
    MyDeque<int> deque(5);
    deque.push_front(1);
    deque.push_front(2);
    deque.push_front(3);
    assert(deque.size() == 3);
    assert(deque.back() == 1);
    assert(deque.front() == 3);
}

void test_pop_back() {
    MyDeque<int> deque(5);
    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(3);
    deque.pop_back();
    assert(deque.size() == 2);
    assert(deque.back() == 2);
}

void test_pop_front() {
    MyDeque<int> deque(5);
    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(3);
    deque.pop_front();
    assert(deque.size() == 2);
    assert(deque.front() == 2);
}

void test_display_reversed() {
    MyDeque<int> deque(5);
    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(3);
    std::cout << "Expected reversed display: 3 2 1" << std::endl;
    std::cout << "Actual reversed display: ";
    deque.display_reversed();
}

void test_clear() {
    MyDeque<int> deque(5);
    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(3);
    deque.clear();
    assert(deque.size() == 0);
    assert(deque.empty());
}

int main() {
    test_push_back();
    test_push_front();
    test_pop_back();
    test_pop_front();
    test_display_reversed();
    test_clear();

    std::cout << "Wszystkie testy przeszły pomyślnie!" << std::endl;
    return 0;
}
