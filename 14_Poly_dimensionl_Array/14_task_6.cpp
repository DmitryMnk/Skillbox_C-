#include <iostream>

void printArray(int array[][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << array[i][j] << "\t"; 
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

int main() {
    int digits[5][5];
    for (int i = 0; i < 25; i++) {
        if ( i / 5 % 2 == 0) {
            digits[i / 5][i % 5] = i;  
        } else {
            digits[i / 5][4 - i % 5] = i;
        }
    }
    printArray(digits);
}