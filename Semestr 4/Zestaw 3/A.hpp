#include "../Zestaw 1/B.hpp"

template <typename T>
class PriorityQueue {
private:
    setLinked<T> queue;
public:
    PriorityQueue() = default;
    PriorityQueue(const PriorityQueue<T>& other) : queue(other.queue) {}
    ~PriorityQueue() = default;
    void add(T value);
    T delete_min();
    void display();
};

template <typename T>
void PriorityQueue<T>::add(T value) {
    queue.add(value);
}

template <typename T>
T PriorityQueue<T>::delete_min() {
    try {
        return queue.removeFirst();
    } catch (const std::out_of_range& e) {
        throw std::runtime_error("Queue is empty");
    }    
}

template <typename T>
void PriorityQueue<T>::display() {
    queue.display();
}

