#include "doublelist.h"
#include <cassert>

int main() {
    DoubleList<int> list;

    list.push_front(10);
    assert(list.size() == 1);
    assert(list.front() == 10);
    assert(list.back() == 10);

    list.push_front(20);
    assert(list.size() == 2);
    assert(list.front() == 20);
    assert(list.back() == 10);

    list.push_back(30);
    assert(list.size() == 3);
    assert(list.front() == 20);
    assert(list.back() == 30);

    list.pop_front();
    assert(list.size() == 2);
    assert(list.front() == 10);
    assert(list.back() == 30);

    list.pop_back();
    assert(list.size() == 1);
    assert(list.front() == 10);
    assert(list.back() == 10);

    list.clear();
    assert(list.size() == 0);
    assert(list.empty());

    list.push_back(40);
    list.push_back(50);
    list.push_back(60);
    list.display();
    list.display_reversed();

    DoubleList<int> list2(list);
    assert(list2.size() == 3);
    assert(list2.front() == 40);
    assert(list2.back() == 60);

    DoubleList<int> list3;
    list3 = list;
    assert(list3.size() == 3);
    assert(list3.front() == 40);
    assert(list3.back() == 60);

    std::cout << "Wszystkie testy przeszły pomyślnie!" << std::endl;

    return 0;
}
