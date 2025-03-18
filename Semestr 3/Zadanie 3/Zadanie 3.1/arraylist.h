// arraylist.h

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
#include <cassert>

template <typename T>
class ArrayList {
    T* tab;
    size_t msize;
    size_t last;

public:
    ArrayList(size_t s=10) : msize(s), last(0) {
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
    size_t size() const { return last; }
    size_t max_size() const { return msize; }

    void push_front(const T& item) {
        assert(!full());
        for (int i = last; i > 0; --i) {
            tab[i] = tab[i - 1];
        }
        tab[0] = item;
        last++;
    }

    void push_back(const T& item) {
        assert(!full());
        tab[last++] = item;
    }

    T& front() {
        assert(!empty());
        return tab[0];
    }

    T& back() {
        assert(!empty());
        return tab[last - 1];
    }

    void pop_front() {
        assert(!empty());
        for (int i = 0; i < last - 1; ++i) {
            tab[i] = tab[i + 1];
        }
        last--;
    }

    void pop_back() {
        assert(!empty());
        --last;
    }

    void clear() {
        last = 0;
    }

    void display() const {
        for (int i = 0; i < last; ++i) {
            std::cout << tab[i] << " ";
        }
        std::cout << std::endl;
    }

    void reverse() {
        for (int i = 0; i < last / 2; ++i) {
            std::swap(tab[i], tab[last - 1 - i]);
        }
    }

    void sort() {
        for (int i = 0; i < last - 1; ++i) {
            for (int j = 0; j < last - i - 1; ++j) {
                if (tab[j] > tab[j + 1]) {
                    std::swap(tab[j], tab[j + 1]);
                }
            }
        }
    }

    T& operator[](size_t pos) {
        assert(pos >= 0 && pos < last);
        return tab[pos];
    }

    const T& operator[](size_t pos) const {
        assert(pos >= 0 && pos < last);
        return tab[pos];
    }

    void erase(size_t pos) {
        assert(pos >= 0 && pos < last);
        for (int i = pos; i < last - 1; ++i) {
            tab[i] = tab[i + 1];
        }
        last--;
    }

    int index(const T& item) {
        for (int i = 0; i < last; ++i) {
            if (tab[i] == item) return i;
        }
        return -1;
    }

    void insert(std::size_t pos, const T& item) {
        assert(pos >= 0 && pos <= last && !full());
        for (int i = last; i > pos; --i) {
            tab[i] = tab[i - 1];
        }
        tab[pos] = item;
        last++;
    }

    void insert(std::size_t pos, T&& item) {
        assert(pos <= last);      
        assert(!full());           
        for (std::size_t i = last; i > pos; --i) {
            tab[i] = std::move(tab[i - 1]);
        }       
        tab[pos] = std::move(item);
        last++;                     
}

    friend std::ostream& operator<<(std::ostream& os, const ArrayList& L) {
        for (int i = 0; i < L.last; ++i) {
            os << L.tab[i] << " ";
        }
        return os;
    }
};

#endif
