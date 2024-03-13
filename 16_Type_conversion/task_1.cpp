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

main()
{   
    setlocale(0, "");
    float currentSpeed = 0;
    float delta;
    do 
    {
        std::wcout << L"Введите дельту: ";
        std::cin >> delta;
        char speed_str[5];

        while (!isValidInput()) {
            std::wcout << L"Ошибка! Введите еще раз.";
            std::cin >> delta;
        }
        currentSpeed += delta;

        if (currentSpeed > 150) {
            currentSpeed = 150;
        } else if (currentSpeed < 0.01) {
            currentSpeed = 0;
        }
        std::sprintf(speed_str, "%.1f", currentSpeed);
        std::wcout << L"Скорость: " << speed_str << '\n';

    } while (currentSpeed > 0);

    std::wcout << std::endl;
    return 0;
}