#include <iostream>
#include <cassert>
#include <stdexcept>

template <typename T>
class ArrayList {
    T* tab;
    int msize;
    int last;

    void resize(int new_size) {
        T* new_tab = new T[new_size];
        for (int i = 0; i < last; ++i) {
            new_tab[i] = tab[i];
        }
        delete[] tab;
        tab = new_tab;
        msize = new_size;
    }

public:
    ArrayList(int s=4) : msize(s), last(0) {
        assert(s > 0);
        tab = new T[s];
        assert(tab != nullptr);
    }

    ArrayList(const ArrayList<T>& other) : msize(other.msize), last(other.last) {
        tab = new T[msize];
        for (int i = 0; i < last; ++i) {
            tab[i] = other.tab[i];
        }
    }

    ~ArrayList() { delete[] tab; }

    // Oryginalny interfejs
    bool empty() const { return last == 0; }
    bool full() const { return last == msize; }
    int size() const { return last; }
    int max_size() const { return msize; }

    void push_back(const T& item) {
        if (full()) {
            resize(msize * 2);
        }
        tab[last++] = item;
    }

    void pop_back() {
        assert(!empty());
        --last;
        if (last < msize / 4 && msize > 4) {
            resize(msize / 2);
        }
    }

    T& back() {
        assert(!empty());
        return tab[last - 1];
    }

    void display() const {
        for (int i = 0; i < last; ++i) {
            std::cout << tab[i] << " ";
        }
        std::cout << std::endl;
    }

    // Dodatkowe metody do współpracy z PriortyQueueBinary
    bool isEmpty() const { return empty(); }
    
    // Metoda get - zwraca element na podanej pozycji 
    // (uwaga: w PriortyQueueBinary indeksowanie jest od 1)
    T get(int index) const {
        if (index < 1 || index > last) {
            throw std::out_of_range("Index out of range");
        }
        return tab[index - 1];  // Konwersja z indeksowania od 1 do od 0
    }
    
    // Metoda set - ustawia wartość elementu na podanej pozycji
    void set(int index, const T& value) {
        if (index < 1 || index > last) {
            throw std::out_of_range("Index out of range");
        }
        tab[index - 1] = value;  // Konwersja z indeksowania od 1 do od 0
    }
    
    // Metoda add - dodaje element (alias dla push_back)
    void add(const T& item) {
        push_back(item);
    }
    
    // Metoda remove - usuwa element z podanej pozycji
    void remove(int index) {
        if (index < 1 || index > last) {
            throw std::out_of_range("Index out of range");
        }
        
        // Przesuwamy wszystkie elementy o jeden do tyłu
        for (int i = index - 1; i < last - 1; ++i) {
            tab[i] = tab[i + 1];
        }
        
        // Zmniejszamy rozmiar
        --last;
        
        // Sprawdzamy, czy trzeba zmniejszyć tablicę
        if (last < msize / 4 && msize > 4) {
            resize(msize / 2);
        }
    }
};