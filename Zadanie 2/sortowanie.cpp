#include <iostream>
#include <vector>

template <typename T>
int partition(std::vector<T>& arr, int low, int high) {
    T pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

template <typename T>
void quickSort(std::vector<T>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

template <typename T>
void insertSort(std::vector<T>& arr) {
    using size_type = typename std::vector<T>::size_type;
    for (size_type i = 1; i < arr.size(); ++i) {
        T key = arr[i];
        size_type j = i;
        while (j > 0 && key < arr[j - 1]) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = key;
    }
}

int main() {
    std::vector<int> vec = {64, 34, 25, 12, 22, 11, 90};

    std::cout << "Unsorted array: ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    insertSort(vec);

    std::cout << "Sorted array by insertSort: ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    vec = {64, 34, 25, 12, 22, 11, 90};

    quickSort(vec, 0, vec.size() - 1);

    std::cout << "Sorted array by quickSort: ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
