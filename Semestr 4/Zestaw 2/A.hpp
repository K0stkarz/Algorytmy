#ifndef A_HPP
#define A_HPP

#include <iostream>
#include <string>

class SetSimple {
private:
    int* omega;
    bool* array;
    int max_element = -1;
    int size = 0;
public:
    SetSimple(int n);
    ~SetSimple();
    SetSimple(const SetSimple& other);
    void add(int);
    void remove(int);
    bool contains(int) const;
    SetSimple sum(SetSimple set);
    SetSimple intersection(SetSimple set);
    SetSimple difference(SetSimple set);
    bool identical(SetSimple set);
    void clear();
    void display() const;
    // Dodatkowe funkcje dla wyświetlania zbiorów znakowych
    void display_char() const; // Wyświetla elementy jako znaki (a-z)
    void display_two_char() const; // Wyświetla elementy jako pary znaków (aa-zz)
};

// Funkcje tworzące zbiory według podanych wzorów
SetSimple createConsecutiveSet(int n, int m);
SetSimple createEvenStepSet(int n, int m);
SetSimple createAlphabetSet();
SetSimple createTwoLetterSet();

// Implementacja konstruktorów i destruktorów
SetSimple::SetSimple(int n) {
    size = n;
    omega = new int[n];
    array = new bool[n];
    for(int i = 0; i < n; i++) {
        omega[i] = i;
        array[i] = false;
    }
    max_element = -1;
}

SetSimple::~SetSimple() {
    delete[] omega;
    delete[] array;
}

SetSimple::SetSimple(const SetSimple& other) {
    size = other.size;
    max_element = other.max_element;
    omega = new int[size];
    array = new bool[size];
    for(int i = 0; i < size; i++) {
        omega[i] = other.omega[i];
        array[i] = other.array[i];
    }
}

// Implementacja podstawowych metod
void SetSimple::add(int element) {
    if (element >= size || element < 0) {
        return;
    }
    array[element] = true;
    if (element > max_element) {
        max_element = element;
    }
}

void SetSimple::remove(int element) {
    if (element >= size || element < 0) {
        return;
    }
    array[element] = false;
    
    // Aktualizacja max_element jeśli trzeba
    if (element == max_element) {
        max_element = -1;
        for (int i = size - 1; i >= 0; i--) {
            if (array[i]) {
                max_element = i;
                break;
            }
        }
    }
}

bool SetSimple::contains(int element) const {
    if (element >= size || element < 0) {
        return false;
    }
    return array[element];
}

SetSimple SetSimple::sum(SetSimple set) {
    int max_size = (size > set.size) ? size : set.size;
    SetSimple result(max_size);
    for(int i = 0; i < max_size; i++) {
        if((i < size && array[i]) || (i < set.size && set.array[i])) {
            result.add(i);
        }
    }
    return result;
}

SetSimple SetSimple::intersection(SetSimple set) {
    int min_size = (size < set.size) ? size : set.size;
    SetSimple result(min_size);
    for(int i = 0; i < min_size; i++) {
        if(array[i] && set.array[i]) {
            result.add(i);
        }
    }
    return result;
}

SetSimple SetSimple::difference(SetSimple set) {
    SetSimple result(size);
    for(int i = 0; i < size; i++) {
        if(array[i] && (i >= set.size || !set.array[i])) {
            result.add(i);
        }
    }
    return result;
}

bool SetSimple::identical(SetSimple set) {
    int max_size = (size > set.size) ? size : set.size;
    for(int i = 0; i < max_size; i++) {
        bool in_this = (i < size) ? array[i] : false;
        bool in_other = (i < set.size) ? set.array[i] : false;
        if(in_this != in_other) {
            return false;
        }
    }
    return true;
}

void SetSimple::clear() {
    for(int i = 0; i < size; i++) {
        array[i] = false;
    }
    max_element = -1;
}

void SetSimple::display() const {
    std::cout << "[";
    bool first = true;
    for(int i = 0; i < size; i++) {
        if(array[i]) {
            if (!first) {
                std::cout << ", ";
            }
            std::cout << i;
            first = false;
        }
    }
    std::cout << "]" << std::endl;
}

// Metody wyświetlające elementy jako znaki
void SetSimple::display_char() const {
    std::cout << "[";
    bool first = true;
    for(int i = 0; i < size && i < 26; i++) {
        if(array[i]) {
            if (!first) {
                std::cout << ", ";
            }
            std::cout << static_cast<char>('a' + i);
            first = false;
        }
    }
    std::cout << "]" << std::endl;
}

void SetSimple::display_two_char() const {
    std::cout << "[";
    bool first = true;
    for(int i = 0; i < size && i < 676; i++) {
        if(array[i]) {
            if (!first) {
                std::cout << ", ";
            }
            char first_char = 'a' + (i / 26);
            char second_char = 'a' + (i % 26);
            std::cout << first_char << second_char;
            first = false;
        }
    }
    std::cout << "]" << std::endl;
}

// Implementacja funkcji tworzących zbiory
SetSimple createConsecutiveSet(int n, int m) {
    if (n >= m) {
        return SetSimple(1); // Pusty zbiór dla nieprawidłowych danych
    }
    
    SetSimple result(m + 1); // Zbiór wystarczająco duży dla wszystkich elementów
    for (int i = n; i <= m; i++) {
        result.add(i);
    }
    return result;
}

SetSimple createEvenStepSet(int n, int m) {
    if (n >= m) {
        return SetSimple(1); // Pusty zbiór dla nieprawidłowych danych
    }
    
    SetSimple result(m + 1); // Zbiór wystarczająco duży dla wszystkich elementów
    for (int i = n; i <= m; i += 2) {
        result.add(i);
    }
    return result;
}

SetSimple createAlphabetSet() {
    SetSimple result(26); // Zbiór z 26 elementami (a-z)
    
    // Dodajemy wszystkie litery od 'a' do 'z'
    for (int i = 0; i < 26; i++) {
        result.add(i);
    }
    return result;
}

SetSimple createTwoLetterSet() {
    // Potrzebujemy zbioru o rozmiarze 26*26 = 676 dla wszystkich kombinacji dwóch liter
    SetSimple result(676);
    
    // Każda kombinacja dwóch liter może być reprezentowana jako liczba od 0 do 675
    // gdzie pierwsza litera to (n / 26) a druga to (n % 26)
    for (int i = 0; i < 676; i++) {
        result.add(i);
    }
    return result;
}

#endif // A_HPP