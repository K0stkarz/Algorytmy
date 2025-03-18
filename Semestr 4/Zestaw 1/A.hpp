
template<typename T>
class setSimple {
    private:
        T* arr;
        int size = 0;
    public:
        setSimple(size_t n) { arr = new T[n]; }
        setSimple(const setSimple& other);
        ~setSimple() { delete[] arr; }
        void add(T element);
        void remove(T element);
        bool contains(T element);
        setSimple sum(setSimple<T> set);
        setSimple intersection(setSimple<T> set);
        setSimple difference(setSimple<T> set);
        bool identical(setSimple<T> set);
        void display();
};

template<typename T>
setSimple<T>::setSimple(const setSimple& other) {
    size = other.size;
    arr = new T[size];
    for (int i = 0; i < size; i++) {
        arr[i] = other.arr[i];
    }
}

template<typename T>
void setSimple<T>::add(T element) {
    if (contains(element)) {
        return;
    }
    arr[size++] = element;
}

template<typename T>
void setSimple<T>::remove(T element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            size--;
            break;
        }
    }
}

template<typename T>
bool setSimple<T>::contains(T element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return true;
        }
    }
    return false;
}

template<typename T>
setSimple<T> setSimple<T>::sum(setSimple<T> set) {
    setSimple<T> result(size + set.size);
    for (int i = 0; i < size; i++) {
        result.add(arr[i]);
    }
    for (int i = 0; i < set.size; i++) {
        if (!result.contains(set.arr[i])) {
            result.add(set.arr[i]);
        }
    }
    return result;
}

template<typename T>
setSimple<T> setSimple<T>::intersection(setSimple<T> set) {
    setSimple<T> result(size);
    for (int i = 0; i < size; i++) {
        if (set.contains(arr[i])) {
            result.add(arr[i]);
        }
    }
    return result;
}

template<typename T>
setSimple<T> setSimple<T>::difference(setSimple<T> set) {
    setSimple<T> result(size);
    
    for (int i = 0; i < size; i++) {
        if (!set.contains(arr[i])) {
            result.add(arr[i]);
        }
    }
    
    return result;
}

template<typename T>
bool setSimple<T>::identical(setSimple<T> set) {
    if (size != set.size) {
        return false;
    }
    for (int i = 0; i < size; i++) {
        if (!set.contains(arr[i])) {
            return false;
        }
    }
    return true;
}

template<typename T>
void setSimple<T>::display() {
    std::cout << "[";
    for (int i = 0; i < size; i++) {
        if(i == size - 1) {
            std::cout << arr[i];
        } else {
            std::cout << arr[i] << ", ";
        }
    }
    std::cout << "]" << std::endl;
}