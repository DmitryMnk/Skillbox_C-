#include <iostream>
#include <vector>
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

void printVector(std::vector<int> vec, int currentIndex) {
    if (currentIndex < 20) {
        for (int i = 0; i < currentIndex; i++) {
            std::cout << vec[i] << "\t";
        }
    } else {
        for (int i = currentIndex % 20; i < currentIndex % 20 + 20; i++) {
            std::cout << vec[i % 20] << "\t";
        }
    }

    std::cout << std::endl;
}

int main() {
    setlocale(0, "");
    std::vector<int> db(20);
    int number;
    int index = 0;
    while (true) {
        std::wcout << L"Введите число: ";
        std::cin >> number;
        while (!isValidInput() && number >= 0 && number <= 9) {
            std::wcout << L"Введите число: ";
            std::cin >> number;
        }
        if (number != -1) {
          db[index % 20] = number;
          index++;  
        } else {
            printVector(db, index);
        }
    }
}