#include "singlelist.h"
#include <iostream>
#include <cassert>

int main() {
    SingleList<int> list;

    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    
    assert(list.size() == 3);
    assert(list.front() == 30);
    assert(list.back() == 10);

    list.push_back(40);
    list.push_back(50);
    
    assert(list.size() == 5);
    assert(list.front() == 30);
    assert(list.back() == 50);

    list.pop_front();
    
    assert(list.size() == 4);
    assert(list.front() == 20);

    list.pop_back();
    
    assert(list.size() == 3);
    assert(list.back() == 40);

    list.reverse();
    
    assert(list.front() == 40);
    assert(list.back() == 20);

    list.insert(1, 15);
    
    assert(list.size() == 4);
    assert(list[1] == 15);

    assert(list.index(40) == 0);
    assert(list.index(50) == -1);

    list.erase(1);
    
    assert(list.size() == 3);
    assert(list[1] == 10);

    std::cout << "Wszystkie testy przeszły pomyślnie!" << std::endl;

    return 0;
}
