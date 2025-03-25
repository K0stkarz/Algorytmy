#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <algorithm>
#include "A.hpp"

int main() {
    const int size = 50;
    const int iterations = 10;
    double time[iterations];

    SetSimple simpleSet2 = createTwoLetterSet();

    std::cout << "setSimple(createTwoLetterSet) add" << std::endl;
    for (int i = 0; i < iterations; i++) {
        SetSimple simpleSet1 = createTwoLetterSet();
        auto start = std::chrono::high_resolution_clock::now();
        for (int k = 0; k < 100; k++) {
            for (int j = 0; j < size * i; j++) {
                simpleSet1.add(j);
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto avgTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 100;
        std::cout << i << " " << avgTime << std::endl;
    }

    SetSimple simpleSet1 = createTwoLetterSet();

    std::vector<int> numbers(size * iterations);
    for (int l = 0; l < size * iterations; l++) {
        numbers[l] = l;
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(numbers.begin(), numbers.end(), gen);

    std::cout << "setSimple(createTwoLetterSet) remove" << std::endl;
    for (int i = 0; i < iterations; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int k = 0; k < 100; k++) {
            for (int j = 0; j < size * i; j++) {
                simpleSet1.remove(numbers[j]);
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto avgTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 100;
        std::cout << i << " " << avgTime << std::endl;
    }

    for (int j = 0; j < size * iterations; j++) {
        simpleSet1.add(j);
    }

    std::cout << "setSimple(createTwoLetterSet) contains" << std::endl;
    for (int i = 0; i < iterations; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int k = 0; k < 100; k++) {
            for (int j = 0; j < size * i; j++) {
                simpleSet1.contains(j);
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto avgTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 100;
        std::cout << i << " " << avgTime << std::endl;
    }

    for (int j = 0; j < size * iterations; j++) {
        simpleSet2.add(j + size);
    }

    std::cout << "setSimple(createTwoLetterSet) sum" << std::endl;
    for (int i = 0; i < iterations; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int k = 0; k < 100; k++) {
            simpleSet1.sum(simpleSet2);
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto avgTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 100;
        std::cout << i << " " << avgTime << std::endl;
    }

    std::cout << "setSimple(createTwoLetterSet) intersection" << std::endl;
    for (int i = 0; i < iterations; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int k = 0; k < 100; k++) {
            simpleSet1.intersection(simpleSet2);
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto avgTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 100;
        std::cout << i << " " << avgTime << std::endl;
    }

    std::cout << "setSimple(createTwoLetterSet) difference" << std::endl;
    for (int i = 0; i < iterations; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int k = 0; k < 100; k++) {
            simpleSet1.difference(simpleSet2);
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto avgTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 100;
        std::cout << i << " " << avgTime << std::endl;
    }

    std::cout << "setSimple(createTwoLetterSet) identical" << std::endl;
    for (int i = 0; i < iterations; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int k = 0; k < 100; k++) {
            simpleSet1.identical(simpleSet2);
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto avgTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 100;
        std::cout << i << " " << avgTime << std::endl;
    }

    return 0;
}