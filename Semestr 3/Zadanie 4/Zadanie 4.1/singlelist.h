#ifndef SINGLELIST_H
#define SINGLELIST_H

#include <iostream>
#include <cassert>

template <typename T>
struct SingleNode {
    T value;
    SingleNode *next;
    SingleNode() : value(T()), next(nullptr) {}
    SingleNode(const T& item, SingleNode *ptr=nullptr) : value(item), next(ptr) {}
    ~SingleNode() {}
};

template <typename T>
class SingleList {
    SingleNode<T> *head, *tail;

public:
    SingleList() : head(nullptr), tail(nullptr) {}
    ~SingleList();

    SingleList(const SingleList& other); 
    SingleList(SingleList&& other) noexcept; 
    SingleList& operator=(const SingleList& other); 
    SingleList& operator=(SingleList&& other) noexcept;

    bool empty() const { return head == nullptr; }
    std::size_t size() const;
    void push_front(const T& item);
    void push_back(const T& item);
    T& front() const { assert(!empty()); return head->value; }
    T& back() const { assert(!empty()); return tail->value; }
    void pop_front();
    void pop_back();
    void clear();
    void display() const;
    void reverse();

    T& operator[](std::size_t pos);
    const T& operator[](std::size_t pos) const;
    void erase(std::size_t pos);
    int index(const T& item) const;
    void insert(std::size_t pos, const T& item);
    void insert(std::size_t pos, T&& item); 
};

template <typename T>
SingleList<T>::~SingleList() {
    while (!empty()) {
        pop_front(); 
    }
}
template <typename T>
SingleList<T>::SingleList(const SingleList& other) : head(nullptr), tail(nullptr) {
    SingleNode<T>* current = other.head;
    while (current) {
        push_back(current->value);
        current = current->next;
    }
}

template <typename T>
SingleList<T>::SingleList(SingleList&& other) noexcept : head(other.head), tail(other.tail) {
    other.head = other.tail = nullptr;
}

template <typename T>
SingleList<T>& SingleList<T>::operator=(const SingleList& other) {
    if (this != &other) {
        clear();
        SingleNode<T>* current = other.head;
        while (current) {
            push_back(current->value);
            current = current->next;
        }
    }
    return *this;
}

template <typename T>
SingleList<T>& SingleList<T>::operator=(SingleList&& other) noexcept {
    if (this != &other) {
        clear();
        head = other.head;
        tail = other.tail;
        other.head = other.tail = nullptr;
    }
    return *this;
}

template <typename T>
std::size_t SingleList<T>::size() const {
    std::size_t count = 0;
    SingleNode<T>* node = head;
    while (node) {
        ++count;
        node = node->next;
    }
    return count;
}

template <typename T>
void SingleList<T>::push_front(const T& item) {
    head = new SingleNode<T>(item, head);
    if (tail == nullptr) {
        tail = head;
    }
}

template <typename T>
void SingleList<T>::push_back(const T& item) {
    SingleNode<T>* newNode = new SingleNode<T>(item);
    if (tail) {
        tail->next = newNode;
        tail = newNode;
    } else {
        head = tail = newNode;
    }
}

template <typename T>
void SingleList<T>::pop_front() {
    assert(!empty());
    SingleNode<T> *node = head;
    head = head->next;
    if (!head) tail = nullptr;
    delete node;
}

template <typename T>
void SingleList<T>::pop_back() {
    assert(!empty());
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        SingleNode<T> *before = head;
        while (before->next != tail) {
            before = before->next;
        }
        delete tail;
        tail = before;
        tail->next = nullptr;
    }
}

template <typename T>
void SingleList<T>::clear() {
    while (!empty()) {
        pop_front();
    }
}

template <typename T>
void SingleList<T>::display() const {
    SingleNode<T> *node = head;
    while (node) {
        std::cout << node->value << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

template <typename T>
void SingleList<T>::reverse() {
    SingleNode<T> *prev = nullptr, *current = head, *next = nullptr;
    tail = head;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

template <typename T>
T& SingleList<T>::operator[](std::size_t pos) {
    assert(pos < size());
    SingleNode<T>* node = head;
    for (std::size_t i = 0; i < pos; ++i) {
        node = node->next;
    }
    return node->value;
}

template <typename T>
const T& SingleList<T>::operator[](std::size_t pos) const {
    assert(pos < size());
    SingleNode<T>* node = head;
    for (std::size_t i = 0; i < pos; ++i) {
        node = node->next;
    }
    return node->value;
}

template <typename T>
void SingleList<T>::erase(std::size_t pos) {
    assert(pos < size());
    if (pos == 0) {
        pop_front();
    } else {
        SingleNode<T> *prev = head;
        for (std::size_t i = 0; i < pos - 1; ++i) {
            prev = prev->next;
        }
        SingleNode<T> *node = prev->next;
        prev->next = node->next;
        if (node == tail) {
            tail = prev;
        }
        delete node;
    }
}

template <typename T>
int SingleList<T>::index(const T& item) const {
    std::size_t pos = 0;
    SingleNode<T> *node = head;
    while (node) {
        if (node->value == item) return pos;
        node = node->next;
        ++pos;
    }
    return -1;
}

template <typename T>
void SingleList<T>::insert(std::size_t pos, const T& item) {
    if (pos == 0) {
        push_front(item);
    } else if (pos == size()) {
        push_back(item);
    } else {
        SingleNode<T> *prev = head;
        for (std::size_t i = 0; i < pos - 1; ++i) {
            prev = prev->next;
        }
        prev->next = new SingleNode<T>(item, prev->next);
    }
}

template <typename T>
void SingleList<T>::insert(std::size_t pos, T&& item) {
    if (pos == 0) {
        push_front(std::move(item));
    } else if (pos == size()) {
        push_back(std::move(item));
    } else {
        SingleNode<T> *prev = head;
        for (std::size_t i = 0; i < pos - 1; ++i) {
            prev = prev->next;
        }
        prev->next = new SingleNode<T>(std::move(item), prev->next);
    }
}

#endif
