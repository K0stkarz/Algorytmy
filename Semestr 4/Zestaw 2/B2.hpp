#include "doublelist.hpp"

template <typename T>
class SetHashed {
private:
    int size;
    DoubleList<T> *array;
public:
    SetHashed();
    SetHashed(int size);
    ~SetHashed();
    SetHashed(const SetHashed& other);
    void add(T element);
    void remove(T element);
    bool contains(T element) const;
    SetHashed sum(SetHashed other);
    SetHashed intersection(SetHashed other);
    SetHashed difference(SetHashed other);
    bool identical(SetHashed other);
    void display();
};

template <typename T>
SetHashed<T>::SetHashed(int size) : size(size) {

    array = new DoubleList<T>[size];
}

template <typename T>
SetHashed<T>::SetHashed() : SetHashed(5) {}

template <typename T>
SetHashed<T>::~SetHashed() {
    delete[] array;
}

template <typename T>
SetHashed<T>::SetHashed(const SetHashed& other) : size(other.size) {
    array = new DoubleList<T>[size];
    for (int i = 0; i < size; i++) {
        array[i] = other.array[i];
    }
}

template <typename T>
void SetHashed<T>::add(T element) {
    int index = element % size;
    if (index < 0) index += size; // Ensure non-negative index
    if (!array[index].contains(element)) {
        array[index].push_back(element);
    }
}

template <typename T>
void SetHashed<T>::remove(T element) {
    int index = element % size;
    if (index < 0) index += size; // Ensure non-negative index
    DoubleList<T>& list = array[index];
    DoubleNode<T>* current = list.head;
    DoubleNode<T>* prev = nullptr;

    while (current != nullptr) {
        if (current->value == element) {
            if (prev == nullptr) { // Removing head
                list.head = current->next;
                if (list.head) {
                    list.head->prev = nullptr;
                } else {
                    list.tail = nullptr;
                }
            } else {
                prev->next = current->next;
                if (current->next) {
                    current->next->prev = prev;
                } else {
                    list.tail = prev;
                }
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

template <typename T>
bool SetHashed<T>::contains(T element) const {
    int index = element % size;
    if (index < 0) index += size; // Ensure non-negative index
    DoubleNode<T>* current = array[index].head;
    while (current != nullptr) {
        if (current->value == element) {
            return true;
        }
        current = current->next;
    }  
    return false;
}

template <typename T>
SetHashed<T> SetHashed<T>::sum(SetHashed other) {
    SetHashed<T> result(std::max(size, other.size));
    // Add elements from this set
    for (int i = 0; i < size; i++) {
        DoubleNode<T>* current = array[i].head;
        while (current != nullptr) {
            result.add(current->value);
            current = current->next;
        }
    }
    // Add elements from the other set
    for (int i = 0; i < other.size; i++) {
        DoubleNode<T>* current = other.array[i].head;
        while (current != nullptr) {
            result.add(current->value);
            current = current->next;
        }
    }
    return result;
}

template <typename T>
SetHashed<T> SetHashed<T>::intersection(SetHashed other) {
    SetHashed<T> result;
    for (int i = 0; i < size; i++) {
        DoubleNode<T>* current = array[i].head;
        while (current != nullptr) {
            if (other.contains(current->value)) {
                result.add(current->value);
            }
            current = current->next;
        }
    }
    return result;
}

template <typename T>
SetHashed<T> SetHashed<T>::difference(SetHashed other) {
    SetHashed<T> result(*this);
    for (int i = 0; i < other.size; i++) {
        DoubleNode<T>* current = other.array[i].head;
        while (current != nullptr) {
            result.remove(current->value);
            current = current->next;
        }
    }
    return result;
}

template <typename T>
bool SetHashed<T>::identical(SetHashed other) {
    // Sprawdź, czy wszystkie elementy tego zbioru są w 'other'
    for (int i = 0; i < size; i++) {
        DoubleNode<T>* current = array[i].head;
        while (current != nullptr) {
            if (!other.contains(current->value)) {
                return false;
            }
            current = current->next;
        }
    }
    // Sprawdź, czy wszystkie elementy 'other' są w tym zbiorze
    for (int i = 0; i < other.size; i++) {
        DoubleNode<T>* current = other.array[i].head;
        while (current != nullptr) {
            if (!contains(current->value)) {
                return false;
            }
            current = current->next;
        }
    }
    return true;
}

template <typename T>
void SetHashed<T>::display() {
    for (int i = 0; i < size; i++) {
        std::cout << "Index " << i << ": ";
        array[i].display();
    }
}