#include <cassert>
#include <iostream>

#include "bst.h"

void test_find_min_max() {
    // Test 1: Puste drzewo
    BinarySearchTree<int> empty_tree;
    assert(empty_tree.find_min() == nullptr);
    assert(empty_tree.find_max() == nullptr);
    std::cout << "Test 1 zaliczony: Puste drzewo zwraca nullptr\n";

    // Test 2: Drzewo z jednym elementem
    BinarySearchTree<int> single_node;
    single_node.insert(5);
    assert(*single_node.find_min() == 5);
    assert(*single_node.find_max() == 5);
    std::cout << "Test 2 zaliczony: Drzewo z jednym elementem zwraca poprawne min/max\n";

    // Test 3: Drzewo z wieloma elementami
    BinarySearchTree<int> multi_node;
    multi_node.insert(10);
    multi_node.insert(5);
    multi_node.insert(15);
    multi_node.insert(3);
    multi_node.insert(7);
    multi_node.insert(12);
    multi_node.insert(17);

    assert(*multi_node.find_min() == 3);
    assert(*multi_node.find_max() == 17);
    std::cout << "Test 3 zaliczony: Drzewo z wieloma elementami zwraca poprawne min/max\n";

    // Test 4: Drzewo z ujemnymi liczbami
    BinarySearchTree<int> negative_tree;
    negative_tree.insert(0);
    negative_tree.insert(-5);
    negative_tree.insert(5);
    negative_tree.insert(-10);
    negative_tree.insert(-2);
    negative_tree.insert(2);
    negative_tree.insert(10);

    assert(*negative_tree.find_min() == -10);
    assert(*negative_tree.find_max() == 10);
    std::cout << "Test 4 zaliczony: Drzewo z ujemnymi liczbami zwraca poprawne min/max\n";

    // Test 5: Test z typem string
    BinarySearchTree<std::string> string_tree;
    string_tree.insert("banana");
    string_tree.insert("apple");
    string_tree.insert("zebra");
    string_tree.insert("cat");

    assert(*string_tree.find_min() == "apple");
    assert(*string_tree.find_max() == "zebra");
    std::cout << "Test 5 zaliczony: Drzewo z typem string zwraca poprawne min/max\n";
}

int main() {
    std::cout << "Rozpoczynanie testów...\n";
    test_find_min_max();
    std::cout << "Wszystkie testy zaliczone pomyślnie!\n";
    return 0;
}