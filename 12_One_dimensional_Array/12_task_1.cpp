#include <iostream>
#include <limits>
#include <numeric>

void clear_c_in() {
    std::wcerr << L"Ошибка ввода данных.\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    setlocale(0, "");
    std::string apartaments[10];
    int apartamentsNumber;

    for (int i = 0; i < 10; i++) {
        std::wcout << L"Введите фамилию жильца " << i + 1 << L"-й квартиры (англ): ";
        std::cin >> apartaments[i];
        while (std::cin.fail() || std::cin.peek() != '\n') 
        {
            clear_c_in();
            std::wcout << L"Введите фамилию жильца " << i + 1 << L"-й квартиры(англ): ";
            std::cin >> apartaments[i];
        }
    }

    for (int i = 0; i < 3; i++) {
        std::wcout << L"Введите номер квартиры: ";
        std::cin >> apartamentsNumber;
        while (std::cin.fail() || std::cin.peek() != '\n' || apartamentsNumber < 1 || apartamentsNumber > 10)
        {
            clear_c_in();
            std::wcout << L"Введите номер квартиры: ";
            std::cin >> apartamentsNumber;
        }
        std::cout << apartaments[apartamentsNumber - 1] << std::endl;
    }
    
}