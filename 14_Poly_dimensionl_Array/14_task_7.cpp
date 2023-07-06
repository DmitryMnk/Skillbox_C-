#include <iostream>
#include <limits>
#include <numeric>


bool isValidInput(int value) {
    if (std::cin.fail() || std::cin.peek() != '\n' || value < 0 || value > 9) {
        std::wcerr << L"Ошибка ввода данных.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

int* fillMatrix(int array[][5]) {
    int number;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::wcout << L"Введите " << j + 1 << L"-й элемент " << i + 1 << L"-ой строки: ";
            std::cin >> number;
            while (!isValidInput(number)) {
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

bool createCubeMatrix(int array[][5], bool cubeMatrix[5][5][10]) {
    int lastIndex = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j ++) {
            for (int k = 0; k < array[i][j] + 1; k++) {
                cubeMatrix[i][j][k] = true;
                lastIndex = k;
            }

            for (int k = lastIndex; k < 10; k++) {
                cubeMatrix[i][j][k] = false;
            }
        }
    }
    return cubeMatrix;
}

void slice(bool array[][5][10], int value) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j ++) {
            if (array[i][j][value]) {
                std::cout << 1 << "\t"; 
            } else {
                std::cout << 0 << "\t"; 
            }
        }
        std::cout << "\n";
    }
    
}

int main() {
    setlocale(0, "");
    int world[5][5];
    bool cubes[5][5][10];
    int sliceValue;

    std::wcout << L"Введите высоты:\n";
    fillMatrix(world);

    std::wcout << L"Введите значение среза: ";
    std::cin >> sliceValue;
    while (!isValidInput(sliceValue)) {
        std::wcout << L"Введите значение среза: ";
        std::cin >> sliceValue;
    }

    createCubeMatrix(world, cubes);
    slice(cubes, sliceValue - 1);
    
}