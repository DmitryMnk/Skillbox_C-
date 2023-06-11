#include <iostream>
#include <limits>
#include <numeric>
#include <cctype>

bool isStringDigital(std::string str) {
    for (int i = 0; i < str.length(); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

bool notValidNumber(std::string number) {
    if (isStringDigital(number)) {
        if ((std::stoi(number) < 0 || std::stoi(number) > 255) || number.length() > 1 && number[0] == '0') {
            return true;
        }
    } else {
        return true;
    }
    
    return false;
}

bool isCorrectPoint(std::string str) {
    int pointCount = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '.') {
            pointCount++;
        }
    }
    return pointCount == 3 ? true : false;
}

bool isTwoPoints(std::string str) {
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == '.' && str[i - 1] == '.') {
            return false;
        }
    }
    return true;
}

bool validateAddress(std::string str) {
    std::string number = "";
    for (int i = 0; i <= str.length(); i++) {
        if (str[i] != '.' && i != str.length()) {
            number += str[i];
        } else if (str[i] == '.' && i != str.length()) {
            if (notValidNumber(number)) {
                return false;
            }
            number = "";
        } else if (str[i] == '.' && i == str.length()) {
            return false;
        } else if (str[i] == '.' && i == str.length()) {
            number += str[i];
            if (notValidNumber(number)) {
                return false;
            }
        }
    }
    return true;
}


int main() {
    setlocale(0, "");
    while(true) {
        std::string ipAddress;

        std::wcout << L"\nВведите ip-адрес: ";
        std::cin >> ipAddress;

        while (std::cin.fail() || std::cin.peek() != '\n') {
            std::wcerr << L"Ошибка ввода данных.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::wcout << L"\nВведите ip-адрес: ";
            std::cin >> ipAddress;
        }

        if (isCorrectPoint(ipAddress) && isTwoPoints(ipAddress) && validateAddress(ipAddress)) {
                std::wcout << L"ip-адресс - корректный.\n" << std::endl;
        } else {
            std::wcout << L"ip-адресс - не корректный.\n" << std::endl;
        }
    }
}