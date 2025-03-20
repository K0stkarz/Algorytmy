class SetSimple{
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
};

SetSimple::SetSimple(int n){
    size = n;
    omega = new int[n];
    array = new bool[n];
    for(int i = 0; i < n; i++){
        omega[i] = i;
        array[i] = false;
    }
}

SetSimple::~SetSimple(){
    delete[] omega;
    delete[] array;
}

SetSimple::SetSimple(const SetSimple& other){
    size = other.size;
    omega = new int[size];
    array = new bool[size];
    for(int i = 0; i < size; i++){
        omega[i] = other.omega[i];
        array[i] = other.array[i];
    }
}

void SetSimple::add(int element){
    if (element > size && element < 0) {
        return;
    }
    if ( element > max_element){
        max_element = element;
    }
    array[element] = true;
}

void SetSimple::remove(int element){
    if (element > size) {
        return;
    }
    array[element] = false;
}

bool SetSimple::contains(int element) const{
    if (element > size) {
        return false;
    }
    return array[element];
}

SetSimple SetSimple::sum(SetSimple set){
    SetSimple result(size);
    for(int i = 0; i < size; i++){
        if(array[i] || set.array[i]){
            result.add(i);
        }
    }
    return result;
}

SetSimple SetSimple::intersection(SetSimple set){
    SetSimple result(size);
    for(int i = 0; i < size; i++){
        if(array[i] && set.array[i]){
            result.add(i);
        }
    }
    return result;
}

SetSimple SetSimple::difference(SetSimple set){
    SetSimple result(size);
    for(int i = 0; i < size; i++){
        if(array[i] && !set.array[i]){
            result.add(i);
        }
    }
    return result;
}

bool SetSimple::identical(SetSimple set){
    for(int i = 0; i < size; i++){
        if(array[i] != set.array[i]){
            return false;
        }
    }
    return true;
}

void SetSimple::clear(){
    for(int i = 0; i < size; i++){
        array[i] = false;
    }
}

void SetSimple::display() const{
    std::cout << "[";
    for(int i = 0; i < size; i++){
        if(array[i]){
            if (omega[i] == max_element){
                std::cout << omega[i];
            } else {
                std::cout << omega[i] << ", ";
            }
        }
    }
    std::cout << "]" <<std::endl;
}

