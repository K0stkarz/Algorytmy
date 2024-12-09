#include "randombinarytree.h"
#include <cassert>
#include <iostream>

int main() {
    RandomBinaryTree<int> tree;

    // Test: Puste drzewo
    std::cout << "Test: Puste drzewo" << std::endl;
    std::cout << "calc_total_rek: " << tree.calc_total_rek() << std::endl;
    std::cout << "calc_total_iter: " << tree.calc_total_iter() << std::endl;
    assert(tree.calc_total_rek() == 0);
    assert(tree.calc_total_iter() == 0);

    // Test: Drzewo z jednym elementem
    tree.insert(5);
    std::cout << "Test: Drzewo z jednym elementem (5)" << std::endl;
    std::cout << "calc_total_rek: " << tree.calc_total_rek() << std::endl;
    std::cout << "calc_total_iter: " << tree.calc_total_iter() << std::endl;
    assert(tree.calc_total_rek() == 5);
    assert(tree.calc_total_iter() == 5);

    // Test: Drzewo z kilkoma elementami
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    std::cout << "Test: Drzewo z kilkoma elementami (5, 3, 7, 2, 4, 6, 8)" << std::endl;
    std::cout << "calc_total_rek: " << tree.calc_total_rek() << std::endl;
    std::cout << "calc_total_iter: " << tree.calc_total_iter() << std::endl;
    assert(tree.calc_total_rek() == 5 + 3 + 7 + 2 + 4 + 6 + 8);
    assert(tree.calc_total_iter() == 5 + 3 + 7 + 2 + 4 + 6 + 8);

    // Test: Drzewo z wartościami ujemnymi
    RandomBinaryTree<int> tree2;
    tree2.insert(-5);
    tree2.insert(-3);
    tree2.insert(-7);
    std::cout << "Test: Drzewo z wartościami ujemnymi (-5, -3, -7)" << std::endl;
    std::cout << "calc_total_rek: " << tree2.calc_total_rek() << std::endl;
    std::cout << "calc_total_iter: " << tree2.calc_total_iter() << std::endl;
    assert(tree2.calc_total_rek() == -5 -3 -7);
    assert(tree2.calc_total_iter() == -5 -3 -7);

    // Test: Drzewo z wartościami zerowymi
    RandomBinaryTree<int> tree3;
    tree3.insert(0);
    tree3.insert(0);
    tree3.insert(0);
    std::cout << "Test: Drzewo z wartościami zerowymi (0, 0, 0)" << std::endl;
    std::cout << "calc_total_rek: " << tree3.calc_total_rek() << std::endl;
    std::cout << "calc_total_iter: " << tree3.calc_total_iter() << std::endl;
    assert(tree3.calc_total_rek() == 0);
    assert(tree3.calc_total_iter() == 0);

    std::cout << "Wszystkie testy zakończyły się powodzeniem!" << std::endl;
    return 0;
}