#include <iostream>
#include <limits>
#include <numeric>
#include <string>

bool isValidInput() {
    if (std::cin.fail() || std::cin.peek() != '\n') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

bool isAllDigits(std::string numbersString) {
    for (int i = 0; i <= numbersString.length() - 1; i++) {
        if (numbersString[i] < '0' || numbersString[i] > '9') {
            return false;
        }
    }
    return true;
}

main()
{
    setlocale(0, "");
    std::string int_part,
                fract_part,
                double_number;
    double result;

    std::wcout << L"Введите целую часть числа: ";
    std::cin >> int_part;
    while (!isValidInput || !isAllDigits(int_part)) {
        std::wcout << L"Ошибка! Введите ещё раз: ";
        std::cin >> int_part;
    }

    std::wcout << L"Введите дробную часть числа: ";
    std::cin >> fract_part;
    while (!isValidInput || !isAllDigits(fract_part)) {
        std::wcout << L"Ошибка! Введите ещё раз: ";
        std::cin >> fract_part;
    }

    double_number = int_part + "," + fract_part;
    result = std::stod(double_number);
    std::wcout << L"Результат: " << result << std::endl;
    return 0;
}