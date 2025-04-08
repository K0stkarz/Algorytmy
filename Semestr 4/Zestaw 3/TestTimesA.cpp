#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <algorithm>
#include "A.hpp"
#include "B.hpp"

int main() {
    const int size = 50;
    const int iterations = 10;
    double time[iterations];

    PriorityQueue<int> priority_queue;
    PriorityQueueBinary<int> priority_queue_binary;
    
    for (int i = 0; i < size * iterations * 100 * 9 ; i++) {
        priority_queue.add(i);
        priority_queue_binary.add(i);
    }
    
    std::cout << "PriorityQueue remove" << std::endl;
    for (int i = 0; i < iterations; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int k = 0; k < 100; k++) {
            for (int j = 0; j < size * i; j++) {
                priority_queue.delete_min();
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto avgTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 100;
        std::cout << i << " " << avgTime << std::endl;
    }

    std::cout << "PriorityQueueBinary remove" << std::endl;
    for (int i = 0; i < iterations; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int k = 0; k < 100; k++) {
            for (int j = 0; j < size * i; j++) {
                priority_queue_binary.delete_min();
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto avgTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 100;
        std::cout << i << " " << avgTime << std::endl;
    }

    return 0;
}