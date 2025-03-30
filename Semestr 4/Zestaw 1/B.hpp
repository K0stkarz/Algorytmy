#include <iostream>

template<typename T>
class setLinked {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };
    Node* head;
    int size;

    void insertSorted(T element);
    void deleteNode(Node* node);

public:
    setLinked() : head(nullptr), size(0) {}
    setLinked(const setLinked& other);
    ~setLinked();
    void add(T element);
    void remove(T element);
    T removeFirst();
    bool contains(T element);
    setLinked sum(setLinked<T> set);
    setLinked intersection(setLinked<T> set);
    setLinked difference(setLinked<T> set);
    bool identical(setLinked<T> set);
    void display();
};

template<typename T>
setLinked<T>::setLinked(const setLinked& other) {
    head = nullptr;
    size = 0;
    Node* current = other.head;
    while (current) {
        add(current->data);
        current = current->next;
    }
}

template<typename T>
setLinked<T>::~setLinked() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
void setLinked<T>::insertSorted(T element) {
    Node* newNode = new Node(element);
    if (!head || head->data >= element) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next && current->next->data < element) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    size++;
}

template<typename T>
void setLinked<T>::add(T element) {
    if (!contains(element)) {
        insertSorted(element);
    }
}

template<typename T>
void setLinked<T>::remove(T element) {
    if (!head) return;
    if (head->data == element) {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return;
    }
    Node* current = head;
    while (current->next && current->next->data != element) {
        current = current->next;
    }
    if (current->next) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
        size--;
    }
}

template<typename T>
T setLinked<T>::removeFirst() {
    if (!head) throw std::out_of_range("Set is empty");
    Node* temp = head;
    T value = head->data;
    head = head->next;
    delete temp;
    size--;
    return value;
}

template<typename T>
bool setLinked<T>::contains(T element) {
    Node* current = head;
    while (current) {
        if (current->data == element) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template<typename T>
setLinked<T> setLinked<T>::sum(setLinked<T> set) {
    setLinked<T> result;
    Node* current = head;
    while (current) {
        result.add(current->data);
        current = current->next;
    }
    current = set.head;
    while (current) {
        result.add(current->data);
        current = current->next;
    }
    return result;
}

template<typename T>
setLinked<T> setLinked<T>::intersection(setLinked<T> set) {
    setLinked<T> result;
    Node* current1 = head;
    Node* current2 = set.head;

    while (current1 && current2) {
        if (current1->data == current2->data) {
            result.add(current1->data);
            current1 = current1->next;
            current2 = current2->next;
        } else if (current1->data < current2->data) {
            current1 = current1->next;
        } else {
            current2 = current2->next;
        }
    }

    return result;
}

template<typename T>
setLinked<T> setLinked<T>::difference(setLinked<T> set) {
    setLinked<T> result;
    Node* current = head;
    while (current) {
        if (!set.contains(current->data)) {
            result.add(current->data);
        }
        current = current->next;
    }
    return result;
}

template<typename T>
bool setLinked<T>::identical(setLinked<T> set) {
    if (size != set.size) {
        return false;
    }
    Node* current = head;
    while (current) {
        if (!set.contains(current->data)) {
            return false;
        }
        current = current->next;
    }
    return true;
}

template<typename T>
void setLinked<T>::display() {
    Node* current = head;
    std::cout << "[";
    while (current) {
        std::cout << current->data;
        if (current->next) {
            std::cout << ", ";
        }
        current = current->next;
    }
    std::cout << "]" << std::endl;
}
