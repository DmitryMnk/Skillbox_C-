#include<iostream>
#include<vector>
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

float* fillMatrix(float array[][4]) {
    float number;
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

int main() {
    setlocale(0, "");

    float number;
    float itemSum;
    float matrix[4][4];
    std::vector<float> vect(4);
    std::vector<float> resultVec(4);

    std::wcout << L"Заполните матрицу\n";
    fillMatrix(matrix);

    std::wcout << L"Заполните вектор\n";
    for (int i = 0; i < 4; i++) {
        std::wcout << L"Введите " << i + 1 << L"-й элемент вектора: ";
        std::cin >> number;
        while(!isValidInput) {
            std::wcout << L"Введите " << i + 1 << L"-й элемент вектора: ";
            std::cin >> number;
        }
        vect[i] = number;
    }

    for (int i = 0; i < 4; i++) {
        itemSum = 0;
        for (int j = 0; j < 4; j++) {
            itemSum += (matrix[i][j] * vect[j]);
        }
        resultVec[i] = itemSum;
    }

    std::wcout << L"Результат умножения: \n";
    for (int i = 0; i < 4; i++) {
        std::cout << resultVec[i] << "\n";
    }
    std::cout << std::endl;
}