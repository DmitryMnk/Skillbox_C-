#include <iostream>
#include <limits>
#include <numeric>

bool isValidInput() {
    if (std::cin.fail() || std::cin.peek() != '\n') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

void printArray(char array[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << array[i][j] << "\t"; 
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

bool isNobody(char array[][3]) {
    int spaceCount = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (array[i][j] == '_') {
                spaceCount++;
            }
        }
    }
    if (spaceCount == 0) {
        return true;
    }
    return false;
}

bool isEmpty(char array[][3], int row, int col) {
    if (array[row][col] != '_') return false;
    return true;
}

int* coord(int array[]) {
    int rowNumber, columnNumber;
    std::wcout << L"Введите номер строки: ";
    std::cin >> rowNumber;
    while (!isValidInput() || rowNumber < 1 || rowNumber > 3) {
        std::wcerr << L"Ошибка ввода данных.\n";
        std::wcout << L"Введите номер строки: ";
        std::cin >> rowNumber;
    }

    std::wcout << L"Введите номер столбца: ";
    std::cin >> columnNumber;
    while (!isValidInput() || columnNumber < 1 || columnNumber > 3) {
        std::wcerr << L"Ошибка ввода данных.\n";
        std::wcout << L"Введите номер столбца: ";
        std::cin >> columnNumber;
    }
    array[0] = rowNumber - 1;
    array[1] = columnNumber - 1;
    return array;
} 

char isWinner(char array[][3]) {
    int crossCount;
    int zeroCount;
    for (int i = 0; i < 3; i++) {
        crossCount = 0;
        zeroCount = 0;
        for (int j = 0; j < 3; j++) {
            if (array[i][j] == 'X') {
                crossCount++;
            } else if (array[i][j] == 'O') {
                zeroCount++;
            }
            
        }
        if (crossCount == 3) {
            return 'X';
        } else if (zeroCount == 3) {
            return 'O';
        }
    }

    for (int i = 0; i < 3; i++) {
        crossCount = 0;
        zeroCount = 0;
        for (int j = 0; j < 3; j++) {
            if (array[j][i] == 'X') {
                crossCount++;
            } else if (array[j][i] == 'O') {
                zeroCount++;
            }
            
        }
        if (crossCount == 3) {
            return 'X';
        } else if (zeroCount == 3) {
            return 'O';
        }
    }
    return 'e';
}

int main() {
    int step = 1;
    int coordinats[2];
    setlocale(0, "");
    char crosses[3][3]
    {
        {'_', '_', '_'},
        {'_', '_', '_'},
        {'_', '_', '_'}
    };

    while (step <= 9) {
        if (step % 2 == 0) {
            std::wcout << L"Ход O" << "\n";    
        } else {
            std::wcout << L"Ход X" << "\n";  
        }

        coord(coordinats);
        while (!isEmpty(crosses, coordinats[0], coordinats[1]))
        {   
            std::wcout << L"Позиция занята." << "\n"; 
            coord(coordinats);
        }
        

        if (step % 2 == 0) {
            crosses[coordinats[0]][coordinats[1]] = 'O';    
        } else {
            crosses[coordinats[0]][coordinats[1]] = 'X'; 
        }
        printArray(crosses);
        if (isWinner(crosses) == 'X') {
            std::wcout << L"Победили крестики" << std::endl;
            break;
        } else if (isWinner(crosses) == 'O') {
            std::wcout << L"Победили нолики" << std::endl;
            break;
        } else if (step == 9) {
            std::wcout << L"Ничья" << std::endl;
        }
        step++;
    }
}