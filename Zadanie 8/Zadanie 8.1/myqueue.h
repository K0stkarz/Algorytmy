#include <cassert>
#include <iostream>
#include <stdexcept>
#include <utility>

template <typename T>
class MyQueue {
    T* tab;
    std::size_t msize; // największa możliwa liczba elementów plus jeden
    std::size_t head; // pierwszy do pobrania
    std::size_t tail; // pierwsza wolna pozycja
public:
    MyQueue(std::size_t s = 10) : msize(s + 1), head(0), tail(0) {
        tab = new T[s + 1];
        assert(tab != nullptr);
    } // default constructor
    ~MyQueue() { delete[] tab; }
    MyQueue(const MyQueue& other); // copy constructor
    MyQueue(MyQueue&& other) noexcept; // move constructor
    MyQueue& operator=(const MyQueue& other); // copy assignment operator, return *this
    MyQueue& operator=(MyQueue&& other) noexcept; // move assignment operator, return *this

    bool empty() const { return head == tail; }
    bool full() const { return (tail + 1) % msize == head; }
    std::size_t size() const { return (tail + msize - head) % msize; }
    std::size_t max_size() const { return msize - 1; }
    void push(const T& item); // dodanie na koniec
    void push(T&& item); // dodanie na koniec
    T& front() { 
        if (empty()) throw std::underflow_error("Queue is empty.");
        return tab[head]; 
    } // zwraca początek
    T& back() { 
        if (empty()) throw std::underflow_error("Queue is empty.");
        return tab[(tail + msize - 1) % msize]; 
    } // zwraca koniec
    void pop(); // usuwa początek
    void clear(); // czyszczenie listy z elementów
    void display(); // wyświetla elementy kolejki
};

// Konstruktor kopiujący
template <typename T>
MyQueue<T>::MyQueue(const MyQueue& other)
    : msize(other.msize), head(other.head), tail(other.tail) {
    tab = new T[msize];
    assert(tab != nullptr);
    for (std::size_t i = 0; i < msize; ++i) {
        tab[i] = other.tab[i];
    }
}

// Konstruktor przenoszący
template <typename T>
MyQueue<T>::MyQueue(MyQueue&& other) noexcept
    : tab(other.tab), msize(other.msize), head(other.head), tail(other.tail) {
    other.tab = nullptr;
    other.msize = 1;
    other.head = 0;
    other.tail = 0;
}

// Operator przypisania kopiującego
template <typename T>
MyQueue<T>& MyQueue<T>::operator=(const MyQueue& other) {
    if (this != &other) {
        delete[] tab;
        msize = other.msize;
        head = other.head;
        tail = other.tail;
        tab = new T[msize];
        assert(tab != nullptr);
        for (std::size_t i = 0; i < msize; ++i) {
            tab[i] = other.tab[i];
        }
    }
    return *this;
}

// Operator przypisania przenoszącego
template <typename T>
MyQueue<T>& MyQueue<T>::operator=(MyQueue&& other) noexcept {
    if (this != &other) {
        delete[] tab;
        tab = other.tab;
        msize = other.msize;
        head = other.head;
        tail = other.tail;
        other.tab = nullptr;
        other.msize = 1;
        other.head = 0;
        other.tail = 0;
    }
    return *this;
}

// Dodanie elementu do kolejki (kopiowanie)
template <typename T>
void MyQueue<T>::push(const T& item) {
    if (full()) {
        throw std::overflow_error("Queue overflow: Cannot push onto a full queue.");
    }
    tab[tail] = item;
    tail = (tail + 1) % msize;
}

// Dodanie elementu do kolejki (przenoszenie)
template <typename T>
void MyQueue<T>::push(T&& item) {
    if (full()) {
        throw std::overflow_error("Queue overflow: Cannot push onto a full queue.");
    }
    tab[tail] = std::move(item);
    tail = (tail + 1) % msize;
}

// Usuwanie elementu z kolejki
template <typename T>
void MyQueue<T>::pop() {
    if (empty()) {
        throw std::underflow_error("Queue underflow: Cannot pop from an empty queue.");
    }
    head = (head + 1) % msize;
}

// Czyszczenie kolejki
template <typename T>
void MyQueue<T>::clear() {
    head = tail = 0;
}

// Wyświetlanie elementów kolejki
template <typename T>
void MyQueue<T>::display() {
    if (empty()) {
        std::cout << "Queue is empty.\n";
        return;
    }
    std::cout << "Queue elements: ";
    for (std::size_t i = head; i != tail; i = (i + 1) % msize) {
        std::cout << tab[i] << " ";
    }
    std::cout << "\n";
}
