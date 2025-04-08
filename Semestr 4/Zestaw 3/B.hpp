#include "ArrayList.hpp"
#include <stdexcept>
#include <iostream>

template <typename T>
class PriorityQueueBinary {
    private:
        ArrayList<T> queue;
        void percolate_up();
        void percolate_down(int index);
        int min_child(int index);  // Zmieniony typ zwracany z T na int
    public:
        PriorityQueueBinary() = default;
        PriorityQueueBinary(const PriorityQueueBinary<T>& other) : queue(other.queue) {}
        ~PriorityQueueBinary() = default;
        void add(T value);
        T delete_min();
        void display();
        bool isEmpty() const { return queue.isEmpty(); }
        int size() const { return queue.size(); }
};

template <typename T>
void PriorityQueueBinary<T>::percolate_up() {
    int index = queue.size();
    while ((int) index / 2 > 0) {
        if (queue.get(index) < queue.get(index / 2)) {
            T temp = queue.get(index);
            queue.set(index, queue.get(index / 2));
            queue.set(index / 2, temp);
        }
        index = index / 2;
    }
}

template <typename T>
void PriorityQueueBinary<T>::percolate_down(int index) {
    while (index * 2 <= queue.size()) {
        int child = min_child(index);
        if (queue.get(index) > queue.get(child)) {
            T temp = queue.get(index);
            queue.set(index, queue.get(child));
            queue.set(child, temp);
        }
        index = child;
    }
}

template <typename T>
int PriorityQueueBinary<T>::min_child(int index) {
    if (index * 2 + 1 > queue.size()) {
        return index * 2;
    } 

    if (queue.get(index * 2) < queue.get(index * 2 + 1)) {
        return index * 2;
    } 
    
    return index * 2 + 1;     
}

template <typename T>
void PriorityQueueBinary<T>::add(T value) {
    queue.add(value);
    percolate_up();
}

template <typename T>
T PriorityQueueBinary<T>::delete_min() {
    if (queue.isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    T min_value = queue.get(1); 
    queue.set(1, queue.get(queue.size()));
    queue.remove(queue.size());
    if (queue.size() > 0) {
        percolate_down(1);
    }
    return min_value;
}

template <typename T>
void PriorityQueueBinary<T>::display() {
    std::cout << "[";
    for (int i = 1; i <= queue.size(); i++) {
        std::cout << queue.get(i);
        if (i < queue.size()) std::cout << ", ";
    }
    std::cout << "]";
}