#include <iostream>
#include "C.hpp"

int main() {
    dictionarySimple dict(5);

    // Test insert
    dict.add("test1");
    dict.add("test2");
    dict.add("test3");
    std::cout << "Dictionary after inserting 'test1', 'test2', 'test3': ";
    dict.display();

    // Test remove
    dict.remove("test2");
    std::cout << "Dictionary after removing 'test2': ";
    dict.display();

    // Test contains
    std::cout << "Dictionary contains 'test1': " << dict.contains("test1") << std::endl;
    std::cout << "Dictionary contains 'test2': " << dict.contains("test2") << std::endl;

    // Test capacity limit
    dict.add("test4");
    dict.add("test5");
    dict.add("test6");
    std::cout << "Dictionary after attempting to insert beyond capacity: ";
    dict.display();

    // Test string length limit
    std::string longString(51, 'a');
    std::cout << "Inserting a string longer than 50 characters: " << dict.add(longString) << std::endl;

    std::cout << "All tests completed!" << std::endl;
    return 0;
}
