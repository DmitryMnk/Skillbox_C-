#include <iostream>
#include <cassert>
#include <limits>
#include <numeric>

bool isInputError() {
    if (std::cin.fail() || std::cin.peek() != '\n') {
        std::wcerr << L"Ошибка ввода данных.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return true;
    }
    return false;
}

float travelTime(float distance, float speed) {
    assert(speed > 0);
    float time = distance / speed; 
    return time;    
}

int main() {
    setlocale(0, "");
    float distance, speed;

    std::wcout << L"Введите перемещение: ";
    std::cin >> distance;
    while(isInputError()) {
        std::wcout << L"Введите перемещение: ";
        std::cin >> distance;
    }
    

    std::wcout << L"Введите среднюю скорость: ";
    std::cin >> speed;
    while(isInputError()) {
        std::wcout << L"Введите среднюю скорость: ";
        std::cin >> speed;
    }

    std::cout << "Time: " << travelTime(distance, speed) << std::endl;

}