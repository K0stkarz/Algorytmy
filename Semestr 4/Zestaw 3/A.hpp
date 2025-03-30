#include "../Zestaw 1/B.hpp"

template <typename T>
class PriortyQueue {
private:
    setLinked<T> queue;
public:
    PriortyQueue() = default;
    PriortyQueue(const PriortyQueue<T>& other) : queue(other.queue) {}
    ~PriortyQueue() = default;
    void add(T value);
    T delete_min();
    void display();
};

template <typename T>
void PriortyQueue<T>::add(T value) {
    queue.add(value);
}

template <typename T>
T PriortyQueue<T>::delete_min() {
    try {
        return queue.removeFirst();
    } catch (const std::out_of_range& e) {
        throw std::runtime_error("Queue is empty");
    }    
}

template <typename T>
void PriortyQueue<T>::display() {
    queue.display();
}

