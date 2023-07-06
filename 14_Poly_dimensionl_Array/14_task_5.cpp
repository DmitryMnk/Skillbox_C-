#include <iostream>
#include <limits>
#include <numeric>


bool isValidInput(int value) {
    if (std::cin.fail() || std::cin.peek() != '\n' || value <= 0 || value > 12) {
        std::wcerr << L"Ошибка ввода данных.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

bool isNotEmpty(char array[][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (array[i][j] == 'O') return true;
        }
    }
    return false;
}

void printArray(char array[][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            std::cout << array[i][j] << "\t"; 
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}



int main() {
    setlocale(0, "");
    int firstRow, secondRow, firstCol, secondCol, startRow, startCol, endRow, endCol;
    char popIt[12][12];
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            popIt[i][j] = 'O';
        }
    }
    printArray(popIt);
    while (isNotEmpty(popIt)) {
        std::wcout << L"Введите координаты первой точки: ";
        std::wcout << L"Строка: ";
        std::cin >> firstRow;
        while(!isValidInput(firstRow)) {
            std::wcout << L"Введите координаты первой точки: ";
            std::wcout << L"Строка: ";
            std::cin >> firstRow;
        }

        std::wcout << L"Столбец: ";
        std::cin >> firstCol;
        while(!isValidInput(firstCol)) {
            std::wcout << L"Введите координаты первой точки: ";
            std::wcout << L"Строка: ";
            std::cin >> firstCol;
        }

        std::wcout << L"Введите координаты второй точки: ";
        std::wcout << L"Строка: ";
        std::cin >> secondRow;
        while(!isValidInput(secondRow)) {
            std::wcout << L"Введите координаты первой точки: ";
            std::wcout << L"Строка: ";
            std::cin >> secondRow;
        }

        std::wcout << L"Столбец: ";
        std::cin >> secondCol;
        while(!isValidInput(secondCol)) {
            std::wcout << L"Введите координаты первой точки: ";
            std::wcout << L"Строка: ";
            std::cin >> secondCol;
        }
        startRow = std::min(firstRow, secondRow);
        endRow = std::max(firstRow, secondRow);
        startCol = std::min(firstCol, secondCol);
        endCol = std::max(firstCol, secondCol);
        for (int i = startRow - 1; i < endRow; i++) {
            for (int j = startCol - 1; j < endCol; j++) {
                popIt[i][j] = 'X';
            }
        }
        printArray(popIt);
    }
}