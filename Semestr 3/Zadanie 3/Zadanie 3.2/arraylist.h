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

    ~ArrayList() { delete[] tab; }

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
};

#endif
