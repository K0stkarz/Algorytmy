#include <iostream>
#include <string>

class dictionarySimple {
private:
    std::string* array;
    int capacity;
    int size;

public:
    dictionarySimple(int cap);
    ~dictionarySimple();
    bool add(const std::string& str);
    bool remove(const std::string& str);
    bool contains(const std::string& str) const;
    void display() const;
};

dictionarySimple::dictionarySimple(int cap) : capacity(cap), size(0) {
    array = new std::string[capacity];
}

dictionarySimple::~dictionarySimple() {
    delete[] array;
}

bool dictionarySimple::add(const std::string& str) {
    if (str.length() > 50) return false;
    if (size >= capacity) return false;
    if (contains(str)) return false;
    array[size++] = str;
    return true;
}

bool dictionarySimple::remove(const std::string& str) {
    for (int i = 0; i < size; i++) {
        if (array[i] == str) {
            array[i] = array[--size];
            return true;
        }
    }
    return false;
}

bool dictionarySimple::contains(const std::string& str) const {
    for (int i = 0; i < size; i++) {
        if (array[i] == str) return true;
    }
    return false;
}

void dictionarySimple::display() const {
    
    std::cout<<size<<"[\"";
    for (int i = 0; i < size; i++) {
        if (i == size - 1) std::cout << array[i];
        else std::cout << array[i] << "\" \"";
    }
    std::cout <<"\"]"<< std::endl;
}
