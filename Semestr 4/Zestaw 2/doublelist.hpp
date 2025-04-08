#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>
#include <cassert>

template <typename T>
struct DoubleNode {
    T value;
    DoubleNode *next, *prev;
    DoubleNode() : value(T()), next(nullptr), prev(nullptr) {}
    DoubleNode(const T& item, DoubleNode *nptr=nullptr, DoubleNode *pptr=nullptr)
        : value(item), next(nptr), prev(pptr) {}
    ~DoubleNode() {}
};

template <typename T>
class DoubleList {
public:
    DoubleNode<T> *head, *tail;
    DoubleList() : head(nullptr), tail(nullptr) {}
    ~DoubleList();

    DoubleList(const DoubleList& other);
    DoubleList& operator=(const DoubleList& other);

    bool empty() const { return head == nullptr; }
    std::size_t size() const;
    void push_front(const T& item);
    void push_back(const T& item);
    T& front() const { return head->value; }
    T& back() const { return tail->value; }
    void pop_front();
    void pop_back();
    void clear();
    bool contains(const T& item) const;
    void display();
    void display_reversed();
};

template <typename T>
DoubleList<T>::~DoubleList() {
    clear();
}

template <typename T>
DoubleList<T>::DoubleList(const DoubleList& other) : head(nullptr), tail(nullptr) {
    DoubleNode<T> *current = other.head;
    while (current) {
        push_back(current->value);
        current = current->next;
    }
}

template <typename T>
DoubleList<T>& DoubleList<T>::operator=(const DoubleList& other) {
    if (this != &other) {
        clear();
        DoubleNode<T> *current = other.head;
        while (current) {
            push_back(current->value);
            current = current->next;
        }
    }
    return *this;
}

template <typename T>
std::size_t DoubleList<T>::size() const {
    std::size_t counter = 0;
    DoubleNode<T> *current = head;
    while(current) {
        counter++;
        current = current->next; 
    }
    return counter;
}

template <typename T>
void DoubleList<T>::push_front(const T& item) {
    if (!empty()) {
        head = new DoubleNode<T>(item, head);
        head->next->prev = head;
    } else {
        head = tail = new DoubleNode<T>(item);
    }
}

template <typename T>
void DoubleList<T>::push_back(const T& item) {
    if(!empty()) {
        tail = new DoubleNode<T>(item, nullptr, tail);
        tail->prev->next = tail;
    } else {
        head = tail = new DoubleNode<T>(item);
    }
}

template <typename T>
void DoubleList<T>::pop_front() {
    assert(!empty());
    DoubleNode<T> *node = head;
    if (head->next) {
        head->next->prev = nullptr;
    }
    head = head->next;
    if (!head) tail = nullptr;
    delete node;
}

template <typename T>
void DoubleList<T>::pop_back() {
    assert(!empty());
    DoubleNode<T> *node = tail;
    if (tail->prev) {
        tail->prev->next = nullptr;
    }
    tail = tail->prev;
    if (!tail) head = nullptr;
    delete node;
}

template <typename T>
void DoubleList<T>::clear() {
    while(head){
        DoubleNode<T> *node = head;
        head = head->next;
        delete node; 
    }
    tail = nullptr;
}

template <typename T>
bool DoubleList<T>::contains(const T& item) const {
    DoubleNode<T>* current = head;
    while (current != nullptr) {
        if (current->value == item) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename T>
void DoubleList<T>::display() {
    DoubleNode<T> *node = head;
    while(node){
        std::cout<< node->value << " ";
        node = node->next;
    }
    std::cout<< std::endl;
}

template <typename T>
void DoubleList<T>::display_reversed() {
    DoubleNode<T> *node = tail;
    while(node){
        std::cout<< node->value << " ";
        node = node->prev;
    }
    std::cout<< std::endl;
}

#endif