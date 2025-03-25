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
    
    SetHashed<int> hashedSet2;

    std::cout << "SetHashed add" << std::endl;
    for(int i = 0; i < iterations; i++) {
    SetHashed<int> hashedSet1;
        auto start = std::chrono::high_resolution_clock::now();\
        for (int k = 0; k < 100; k++) {
            for (int j = 0; j < size * i; j++) {
                    hashedSet1.add(j);
                }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto avgTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 100;
        std::cout << i << " " << avgTime << std::endl;
    } 
    
    SetHashed<int> hashedSet1;

    std::vector<int> numbers(size * iterations);
    for (int l = 0; l < size * iterations; l++) {
        numbers[l] = l;
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(numbers.begin(), numbers.end(), gen); 

    std::cout << "SetHashed remove" << std::endl;
    for(int i = 0; i < iterations; i++) {
        auto start = std::chrono::high_resolution_clock::now();\
        for (int k = 0; k < 100; k++) {
            for (int j = 0; j < size * i; j++) {
                    hashedSet1.remove(numbers[j]);
                }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto avgTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 100;
        std::cout << i << " " << avgTime << std::endl;
    }  

    for (int j = 0; j < size * iterations; j++) {
        hashedSet1.add(j);
    }

    std::cout << "SetHashed contains" << std::endl;
    for(int i = 0; i < iterations; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int k = 0; k < 100; k++) {
            for (int j = 0; j < size * i; j++) {
                hashedSet1.contains(j);
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto avgTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 100;
        std::cout << i << " " << avgTime << std::endl;
    }

    for (int j = 0; j < size * iterations; j++) {
        hashedSet2.add(j + size);
    }

    std::cout << "SetHashed sum" << std::endl;
    for(int i = 0; i < iterations; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int k = 0; k < 100; k++) {
            for (int j = 0; j < size * i; j++) {
                hashedSet1.sum(hashedSet2);
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto avgTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 100;
        std::cout << i << " " << avgTime << std::endl;
    }

    std::cout << "SetHashed intersection" << std::endl;
    for(int i = 0; i < iterations; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int k = 0; k < 100; k++) {
            for (int j = 0; j < size * i; j++) {
                hashedSet1.intersection(hashedSet2);
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto avgTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 100;
        std::cout << i << " " << avgTime << std::endl;
    }

    std::cout << "SetHashed difference" << std::endl;
    for(int i = 0; i < iterations; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int k = 0; k < 100; k++) {
            for (int j = 0; j < size * i; j++) {
                hashedSet1.difference(hashedSet2);
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto avgTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 100;
        std::cout << i << " " << avgTime << std::endl;
    }

    std::cout << "SetHashed identical" << std::endl;
    for(int i = 0; i < iterations; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int k = 0; k < 100; k++) {
            for (int j = 0; j < size * i; j++) {
                hashedSet1.identical(hashedSet2);
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto avgTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 100;
        std::cout << i << " " << avgTime << std::endl;
    }

    return 0;
}