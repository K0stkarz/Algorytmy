#include <iostream>
#include "A2.hpp"

int main() {
    SetSimple set1(10);
    SetSimple set2(10);

    // Test add
    set1.add(1);
    set1.add(2);
    set1.add(3);
    std::cout << "Set 1 after adding 1, 2, 3: ";
    set1.display();

    // Test remove
    set1.remove(2);
    std::cout << "Set 1 after removing 2: ";
    set1.display();

    // Test contains
    std::cout << "Set 1 contains 1: " << set1.contains(1) << std::endl;
    std::cout << "Set 1 contains 2: " << set1.contains(2) << std::endl;

    // Test sum
    set2.add(3);
    set2.add(4);
    set2.add(5);
    SetSimple setSum = set1.sum(set2);
    std::cout << "Sum of Set 1 and Set 2: ";
    setSum.display();

    // Test intersection
    SetSimple setIntersection = set1.intersection(set2);
    std::cout << "Intersection of Set 1 and Set 2: ";
    setIntersection.display();

    // Test difference
    SetSimple setDifference = set1.difference(set2);
    std::cout << "Difference of Set 1 and Set 2: ";
    setDifference.display();

    // Test identical
    std::cout << "Set 1 and Set 2 are identical: " << set1.identical(set2) << std::endl;

    // Test clear
    set1.clear();
    std::cout << "Set 1 after clearing: ";
    set1.display();

    std::cout << "All tests completed!" << std::endl;
    return 0;
}