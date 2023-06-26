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

int main() {
    setlocale(0, "");
    int amount;
    int deleteNumber;

    std::wcout << L"Введите количество чисел: ";
    std::cin >> amount;

    while (!isValidInput) {
        std::wcout << L"Введите количество чисел: ";
        std::cin >> amount;
    }

    std::vector<int> numbers(amount);
    
    for (int i = 0; i < amount; i++) {
        std::wcout << L"Введите " << i + 1 <<"-e" << L" число: ";
        std::cin >> numbers[i];
        while (!isValidInput) {
            std::wcout << L"Введите " << i + 1 <<"-e" << L" число: ";
            std::cin >> numbers[i];
        }
    }

    std::wcout << L"Введите удаляемое число: ";
    std::cin >> deleteNumber;
    while (!isValidInput) {
        std::wcout << L"Введите удаляемое число: ";
        std::cin >> deleteNumber;
    }
    

    for (int i = numbers.size() - 1; i >= 0; i--) {
        if (numbers[i] == deleteNumber && i == numbers.size() - 1) {
            numbers.pop_back();
        } else if (numbers[i] == deleteNumber) {
            int k = i;
            while (numbers[numbers.size() - 1] != deleteNumber) {
                std::swap(numbers[k], numbers[k + 1]);
                k++;
            }
            numbers.pop_back();
        }
    }

    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << "\t";
    }
}