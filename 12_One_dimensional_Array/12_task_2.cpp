#include <iostream>
#include <limits>
#include <numeric>
void print_array(float array[], int length) {
    std::cout << "\n";
    for (int i = 0; i < length; i++) {
        std::cout << array[i]<< "\t";
    }
    std::cout << std::endl;
}

void heapify(float array[], int length, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < length && array[left] > array[largest]) {
        largest = left;
    }

    if (right < length && array[right] > array[largest]) {
        largest = right;
    } 

    if (largest != root) {
        std::swap(array[root], array[largest]);
        heapify(array, length, largest);
    }
}

void heapSort(float array[], int length) {
    for (int i = length / 2 - 1; i >= 0; i--) {
        heapify(array, length, i);
    }

    for (int i = length - 1; i >= 0; i--) {
        std::swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

int main() {
    setlocale(0, "");
    float numbers[15] = {1.2, 2.3, 1.11, 3.4, 5.5, 5.4, 5.3, 5.1, 1.5, 1.25, 5.41, 5.31, 5.11, 1.51, 1.251 };
    
    heapSort(numbers, 15);
    print_array(numbers, 15);
} 