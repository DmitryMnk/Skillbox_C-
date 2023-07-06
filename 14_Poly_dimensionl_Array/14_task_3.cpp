#include <iostream>
#include <limits>
#include <numeric>


bool isValidInput() {
    if (std::cin.fail() || std::cin.peek() != '\n') {
        std::wcerr << L"Ошибка ввода данных.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

int* fillMatrix(int array[][4]) {
    int number;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::wcout << L"Введите " << j + 1 << L"-й элемент " << i + 1 << L"-ой строки: ";
            std::cin >> number;
            while (!isValidInput()) {
                std::wcout << L"Введите " << j + 1 << L"-й элемент " << i + 1 << L"-ой строки: ";
                std::cin >> number;
            }
            array[i][j] = number;
        }
        std::cout << "\n";
    }
    std::wcout << L"Матрица заполнена! \n\n";
    return *array;
}

void printArray(int array[][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << array[i][j] << "\t"; 
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void compareMatrix (int array_A[][4], int array_B[][4]) {
    bool isEqual = true;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (array_A[i][j] != array_B[i][j]) {
                isEqual = false;
                break;
            }
            if (i != j) {
                array_A[i][j] = 0;
            }     
        }
        if (!isEqual) {
            break;
        }
    }
    if (isEqual) {
        std::wcout << L"Матрицы равны.\n";
        printArray(array_A);
    } else {
        std::wcout << L"Матрицы не равны.";
    }
}

int main() {
    setlocale(0, "");
    int matrix_A[4][4], matrix_B[4][4];
    int element = 1;

    std::wcout << L"Заполните матрицу А\n";
    fillMatrix(matrix_A);
    std::wcout << L"Заполните матрицу В\n";
    fillMatrix(matrix_B);

    printArray(matrix_A);
    printArray(matrix_B);

    compareMatrix(matrix_A, matrix_B);
}