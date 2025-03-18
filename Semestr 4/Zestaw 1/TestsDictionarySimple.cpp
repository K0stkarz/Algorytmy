#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <algorithm>
#include "C.hpp"

int main() {
    const int size = 50;
    const int iterations = 10;
    double time[iterations];
    
    dictionarySimple dict(size * iterations);

    std::cout << "dictionarySimple add" << std::endl;
    for(int i = 0; i < iterations; i++) {
        dictionarySimple dict1(size * i);
        auto start = std::chrono::high_resolution_clock::now();
        for (int k = 0; k < 100; k++) {
            for (int j = 0; j < size * i; j++) {
                dict1.add("word" + std::to_string(j));
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto avgTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 100;
        std::cout << i << " " << avgTime << std::endl;
    } 
    
    dictionarySimple dict1(size * iterations);

    std::vector<std::string> words(size * iterations);
    for (int l = 0; l < size * iterations; l++) {
        words[l] = "word" + std::to_string(l);
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(words.begin(), words.end(), gen); 

    std::cout << "dictionarySimple remove" << std::endl;
    for(int i = 0; i < iterations; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int k = 0; k < 100; k++) {
            for (int j = 0; j < size * i; j++) {
                dict1.remove(words[j]);
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto avgTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 100;
        std::cout << i << " " << avgTime << std::endl;
    }  

    for (int j = 0; j < size * iterations; j++) {
        dict1.add("word" + std::to_string(j));
    }

    std::cout << "dictionarySimple contains" << std::endl;
    for(int i = 0; i < iterations; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int k = 0; k < 100; k++) {
            for (int j = 0; j < size * i; j++) {
                dict1.contains("word" + std::to_string(j));
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto avgTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 100;
        std::cout << i << " " << avgTime << std::endl;
    }

    return 0;
}
