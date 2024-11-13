template <typename T>
class MyDeque {
    T* tab;
    std::size_t msize;
    std::size_t head;
    std::size_t tail;
public:
    MyDeque(std::size_t s=10) : msize(s+1), head(0), tail(0) {
        tab = new T[s+1];
        assert( tab != nullptr );
    }
    ~MyDeque() { delete [] tab; }
    MyDeque(const MyDeque& other);
    MyDeque& operator=(const MyDeque& other);
    bool empty() const { return head == tail; }
    bool full() const { return (tail + 1) % msize == head; }
    std::size_t size() const { return (tail - head + msize) % msize; }
    std::size_t max_size() const { return msize-1; }
    void push_front(const T& item);
    void push_back(const T& item);
    T& front() { return tab[head]; }
    T& back() { return tab[(tail + msize -1) % msize]; }
    void pop_front();
    void pop_back();
    void clear();
    void display();
    void display_reversed();
};

template <typename T>
MyDeque<T>& MyDeque<T>::operator=(const MyDeque& other) {
    if(this != &other){
        delete [] tab;
        msize = other.msize;
        head = other.head;
        tail = other.tail;
        tab = new T[msize];

        for (std::size_t i = head; i != tail; i=(i+1) % msize) {
            tab[i] = other[i];
        }
    }
    other.msize = 1;
    other.head = 0;
    other.tail = 0;

    return *this;
}

template <typename T>
MyDeque<T>::MyDeque(const MyDeque& other) {
    msize = other.msize;
    head = other.head;
    tail = other.tail;
    other.msize = 1;
    other.head = 0;
    other.tail = 0;
}

template <typename T>
void MyDeque<T>::push_front(const T& item) {
    assert(!full());
    head = (head + msize -1) % msize;
    tab[head] = item;
}

template <typename T>
void MyDeque<T>::push_back(const T& item) {
    assert(!full());
    tab[tail] = item;
    tail = (tail + 1) % msize;
}

template <typename T>
void MyDeque<T>::pop_front() {
    assert(!empty());
    head = (head + 1) % msize;
}

template <typename T>
void MyDeque<T>::pop_back() {
    assert(!empty());
    tail = (tail - 1) % msize;
}

template <typename T>
void MyDeque<T>::clear() {
    assert(!empty());
    head = 0;
    tail = 0;
}

template <typename T>
void MyDeque<T>::display() {
    for (std::size_t i = head; i != tail; i=(i+1) % msize) {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void MyDeque<T>::display_reversed() {
    for (std::size_t i = (tail == 0 ? msize - 1 : tail - 1); i != head; i = (i == 0 ? msize - 1 : i - 1)) {
        std::cout << tab[i] << " ";
    }
    std::cout << tab[head];
    std::cout << std::endl;
}
