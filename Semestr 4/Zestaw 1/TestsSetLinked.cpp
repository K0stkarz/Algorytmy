#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <algorithm>
#include "B.hpp"

int main() {
    const int size = 50;
    const int iterations = 10;
    double time[iterations];
    
    setLinked<int> linkedSet2;

    std::cout << "setLinked add" << std::endl;
    for(int i = 0; i < iterations; i++) {
        setLinked<int> linkedSet1;
        auto start = std::chrono::high_resolution_clock::now();
        for (int k = 0; k < 100; k++) {
            for (int j = 0; j < size * i; j++) {
                linkedSet1.add(j);
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto avgTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 100;
        std::cout << i << " " << avgTime << std::endl;
    } 
    
    setLinked<int> linkedSet1;

    std::vector<int> numbers(size * iterations);
    for (int l = 0; l < size * iterations; l++) {
        numbers[l] = l;
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(numbers.begin(), numbers.end(), gen); 

    std::cout << "setLinked remove" << std::endl;
    for(int i = 0; i < iterations; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int k = 0; k < 100; k++) {
            for (int j = 0; j < size * i; j++) {
                linkedSet1.remove(numbers[j]);
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto avgTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 100;
        std::cout << i << " " << avgTime << std::endl;
    }  

    for (int j = 0; j < size * iterations; j++) {
        linkedSet1.add(j);
    }

    std::cout << "setLinked contains" << std::endl;
    for(int i = 0; i < iterations; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int k = 0; k < 100; k++) {
            for (int j = 0; j < size * i; j++) {
                linkedSet1.contains(j);
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto avgTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 100;
        std::cout << i << " " << avgTime << std::endl;
    }

    for (int j = 0; j < size * iterations; j++) {
        linkedSet2.add(j + size);
    }

    std::cout << "setLinked sum" << std::endl;
    for(int i = 0; i < iterations; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int k = 0; k < 100; k++) {
            for (int j = 0; j < size * i; j++) {
                linkedSet1.sum(linkedSet2);
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto avgTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 100;
        std::cout << i << " " << avgTime << std::endl;
    }

    std::cout << "setLinked intersection" << std::endl;
    for(int i = 0; i < iterations; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int k = 0; k < 100; k++) {
            for (int j = 0; j < size * i; j++) {
                linkedSet1.intersection(linkedSet2);
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto avgTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 100;
        std::cout << i << " " << avgTime << std::endl;
    }

    std::cout << "setLinked difference" << std::endl;
    for(int i = 0; i < iterations; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int k = 0; k < 100; k++) {
            for (int j = 0; j < size * i; j++) {
                linkedSet1.difference(linkedSet2);
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto avgTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 100;
        std::cout << i << " " << avgTime << std::endl;
    }

    std::cout << "setLinked identical" << std::endl;
    for(int i = 0; i < iterations; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int k = 0; k < 100; k++) {
            for (int j = 0; j < size * i; j++) {
                linkedSet1.identical(linkedSet2);
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto avgTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 100;
        std::cout << i << " " << avgTime << std::endl;
    }

    return 0;
}
