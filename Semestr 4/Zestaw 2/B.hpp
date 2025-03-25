#include <vector>
#include <iostream>
#include <functional>

template <typename T>
class SetHashed {
private:
    struct Entry {
        T value;
        bool occupied = false;
        bool deleted = false;
    };

    std::vector<Entry> table;
    size_t size = 0;
    size_t tableSize;
    const float loadFactor = 0.7;

    size_t hash(const T& value) const;
    size_t findPosition(const T& value) const;
    void rehash();
    size_t findNextPrime(size_t n) const;
    bool isPrime(size_t n) const;

public:
    SetHashed(size_t initialSize = 17);
    void add(const T& value);
    void remove(const T& value);
    bool contains(const T& value) const;
    SetHashed<T> sum(const SetHashed<T>& other) const;
    SetHashed<T> intersection(const SetHashed<T>& other) const;
    SetHashed<T> difference(const SetHashed<T>& other) const;
    bool identical(const SetHashed<T>& other) const;
    void print() const;
    size_t getSize() const;
};

template <typename T>
size_t SetHashed<T>::hash(const T& value) const {
    return std::hash<T>{}(value) % tableSize;
}

template <typename T>
size_t SetHashed<T>::findPosition(const T& value) const {
    size_t startPos = hash(value);
    size_t pos = startPos;

    do {
        if (!table[pos].occupied || (table[pos].occupied && !table[pos].deleted && table[pos].value == value)) {
            return pos;
        }
        pos = (pos + 1) % tableSize;
    } while (pos != startPos);

    return tableSize;
}

template <typename T>
void SetHashed<T>::rehash() {
    size_t oldTableSize = tableSize;
    std::vector<Entry> oldTable = table;

    tableSize = findNextPrime(tableSize * 2);
    table.clear();
    table.resize(tableSize);
    size = 0;

    for (size_t i = 0; i < oldTableSize; i++) {
        if (oldTable[i].occupied && !oldTable[i].deleted) {
            add(oldTable[i].value);
        }
    }
}

template <typename T>
size_t SetHashed<T>::findNextPrime(size_t n) const {
    while (!isPrime(n)) {
        n++;
    }
    return n;
}

template <typename T>
bool SetHashed<T>::isPrime(size_t n) const {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (size_t i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

template <typename T>
SetHashed<T>::SetHashed(size_t initialSize) {
    tableSize = findNextPrime(initialSize);
    table.resize(tableSize);
}

template <typename T>
void SetHashed<T>::add(const T& value) {
    if (contains(value)) {
        return;
    }

    if ((double)(size + 1) / tableSize > loadFactor) {
        rehash();
    }

    size_t pos = findPosition(value);
    table[pos].value = value;
    table[pos].occupied = true;
    table[pos].deleted = false;
    size++;
}

template <typename T>
void SetHashed<T>::remove(const T& value) {
    size_t pos = findPosition(value);

    if (table[pos].occupied && !table[pos].deleted && table[pos].value == value) {
        table[pos].deleted = true;
        size--;
    }
}

template <typename T>
bool SetHashed<T>::contains(const T& value) const {
    size_t pos = findPosition(value);
    return pos < tableSize && table[pos].occupied && !table[pos].deleted && table[pos].value == value;
}

template <typename T>
SetHashed<T> SetHashed<T>::sum(const SetHashed<T>& other) const {
    SetHashed<T> result(std::max(tableSize, other.tableSize));

    for (size_t i = 0; i < tableSize; i++) {
        if (table[i].occupied && !table[i].deleted) {
            result.add(table[i].value);
        }
    }

    for (size_t i = 0; i < other.tableSize; i++) {
        if (other.table[i].occupied && !other.table[i].deleted) {
            result.add(other.table[i].value);
        }
    }

    return result;
}

template <typename T>
SetHashed<T> SetHashed<T>::intersection(const SetHashed<T>& other) const {
    SetHashed<T> result;

    for (size_t i = 0; i < tableSize; i++) {
        if (table[i].occupied && !table[i].deleted) {
            if (other.contains(table[i].value)) {
                result.add(table[i].value);
            }
        }
    }

    return result;
}

template <typename T>
SetHashed<T> SetHashed<T>::difference(const SetHashed<T>& other) const {
    SetHashed<T> result;

    for (size_t i = 0; i < tableSize; i++) {
        if (table[i].occupied && !table[i].deleted) {
            if (!other.contains(table[i].value)) {
                result.add(table[i].value);
            }
        }
    }

    return result;
}

template <typename T>
bool SetHashed<T>::identical(const SetHashed<T>& other) const {
    if (size != other.size) {
        return false;
    }

    for (size_t i = 0; i < tableSize; i++) {
        if (table[i].occupied && !table[i].deleted) {
            if (!other.contains(table[i].value)) {
                return false;
            }
        }
    }

    return true;
}

template <typename T>
void SetHashed<T>::print() const {
    std::cout << "{ ";
    bool first = true;
    for (size_t i = 0; i < tableSize; i++) {
        if (table[i].occupied && !table[i].deleted) {
            if (!first) std::cout << ", ";
            std::cout << table[i].value;
            first = false;
        }
    }
    std::cout << " }" << std::endl;
}

template <typename T>
size_t SetHashed<T>::getSize() const {
    return size;
}