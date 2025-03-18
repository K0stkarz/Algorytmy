// main.cpp

#include "arraylist.h"
#include <iostream>
#include <cassert>

int main() {
    ArrayList<int> list(5);

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    assert(list.size() == 3);  
    assert(list.back() == 30); 

    list.push_front(5);
    assert(list.size() == 4);  
    assert(list.front() == 5); 

    assert(list.front() == 5);  
    assert(list.back() == 30);   

    list.pop_front();
    assert(list.size() == 3);    
    assert(list.front() == 10);  

    list.pop_back();
    assert(list.size() == 2);   
    assert(list.back() == 20);   

    list.push_back(40);
    list.push_back(50);
    list.reverse();
    assert(list.front() == 50);  
    assert(list.back() == 10);   

    list.sort();
    assert(list.front() == 10);  
    assert(list.back() == 50);   

    list.clear();
    assert(list.empty());        
    assert(list.size() == 0);   

    std::cout << "All tests passed successfully!" << std::endl;

    return 0;
}
