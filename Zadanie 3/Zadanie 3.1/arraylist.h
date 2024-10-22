// arraylist.h

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
#include <cassert>

template <typename T>
class ArrayList {
    T* tab;
    int msize;
    int last;

public:
    ArrayList(int s=10) : msize(s), last(0) {
        assert(s > 0);
        tab = new T[s];
        assert(tab != nullptr);
    }

    ~ArrayList() { delete[] tab; }

    ArrayList(const ArrayList& other) : msize(other.msize), last(other.last) {
        tab = new T[msize];
        for (int i = 0; i < last; ++i) {
            tab[i] = other.tab[i];
        }
    }

    ArrayList& operator=(const ArrayList& other) {
        if (this != &other) {
            delete[] tab;
            msize = other.msize;
            last = other.last;
            tab = new T[msize];
            for (int i = 0; i < last; ++i) {
                tab[i] = other.tab[i];
            }
        }
        return *this;
    }

    bool empty() const { return last == 0; }
    bool full() const { return last == msize; }
    int size() const { return last; }
    int max_size() const { return msize; }

    void push_back(const T& item) {
        assert(!full());
        tab[last++] = item;
    }

    void pop_back() {
        assert(!empty());
        --last;
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
};

#endif
