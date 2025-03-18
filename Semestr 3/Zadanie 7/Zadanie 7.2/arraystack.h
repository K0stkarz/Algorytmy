#include <array>
#include <iostream>
#include <stdexcept>

template <typename T, std::size_t Capacity>
class ArrayStack {
private:
    std::size_t topIndex;        
    std::array<T, Capacity> arr; 
public:
    ArrayStack() : topIndex(0) {}
    ~ArrayStack() { clear(); }
    ArrayStack(const ArrayStack& other) : arr(other.arr), topIndex(other.topIndex) {}
    ArrayStack(ArrayStack&& other) noexcept; // move constructor
    ArrayStack& operator=(const ArrayStack& other); // copy assignment operator, return *this
    ArrayStack& operator=(ArrayStack&& other) noexcept; // move assignment operator, return *this
    bool empty() const { return topIndex == 0; }
    bool full() const { return topIndex == Capacity; }
    std::size_t size() const { return topIndex; }
    std::size_t max_size() const { return Capacity; }
    void push(const T& item);
    void push(T&& item);
    T& top(); // zwraca koniec, nie usuwa
    void pop(); // usuwa koniec
    void clear() { topIndex = 0; }
    void display() const;
};

// Konstruktor przenoszący
template <typename T, std::size_t Capacity>
ArrayStack<T, Capacity>::ArrayStack(ArrayStack&& other) noexcept 
    : arr(std::move(other.arr)), topIndex(other.topIndex) {
    other.topIndex = 0;
}

// Operator przypisania kopiującego
template <typename T, std::size_t Capacity>
ArrayStack<T, Capacity>& ArrayStack<T, Capacity>::operator=(const ArrayStack& other) {
    if (this != &other) {
        arr = other.arr;
        topIndex = other.topIndex;
    }
    return *this;
}

// Operator przypisania przenoszącego
template <typename T, std::size_t Capacity>
ArrayStack<T, Capacity>& ArrayStack<T, Capacity>::operator=(ArrayStack&& other) noexcept {
    if (this != &other) {
        arr = std::move(other.arr);
        topIndex = other.topIndex;
        other.topIndex = 0;
    }
    return *this;
}

// Dodanie elementu na stos (przez kopię)
template <typename T, std::size_t Capacity>
void ArrayStack<T, Capacity>::push(const T& item) {
    if (full()) {
        throw std::overflow_error("Stack overflow: Cannot push onto a full stack.");
    }
    arr[topIndex++] = item;
}

// Dodanie elementu na stos (przez przeniesienie)
template <typename T, std::size_t Capacity>
void ArrayStack<T, Capacity>::push(T&& item) {
    if (full()) {
        throw std::overflow_error("Stack overflow: Cannot push onto a full stack.");
    }
    arr[topIndex++] = std::move(item);
}

// Usunięcie elementu ze stosu
template <typename T, std::size_t Capacity>
void ArrayStack<T, Capacity>::pop() {
    if (empty()) {
        throw std::underflow_error("Stack underflow: Cannot pop from an empty stack.");
    }
    --topIndex;
}

// Pobranie elementu na szczycie stosu
template <typename T, std::size_t Capacity>
T& ArrayStack<T, Capacity>::top() {
    if (empty()) {
        throw std::underflow_error("Stack underflow: Stack is empty.");
    }
    return arr[topIndex - 1];
}

// Wyświetlenie zawartości stosu
template <typename T, std::size_t Capacity>
void ArrayStack<T, Capacity>::display() const {
    if (empty()) {
        std::cout << "Stack is empty.\n";
        return;
    }
    std::cout << "Stack elements (top to bottom): ";
    for (std::size_t i = topIndex; i > 0; --i) {
        std::cout << arr[i - 1] << " ";
    }
    std::cout << "\n";
}
