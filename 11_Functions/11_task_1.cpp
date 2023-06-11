#include <iostream>
#include <limits>
#include <numeric>

std::string encrypt_caesar(std::string text, int shift) {
    std::string caesarText = "";
    for (int i = 0; i < text.length(); i++) {
        if (text[i] >= 'a' && text[i]<= 'z') {
            caesarText += int('a') + (shift + int(text[i]) - int('a')) % 26;
        } else if (text[i] >= 'A' && text[i]<= 'Z') {
            caesarText += int('A') + (shift + int(text[i]) - int('A')) % 26;    
        } else {
            caesarText += text[i];
        }
    }
    return caesarText;
}

std::string decrypt_caesar(std::string text, int shift) {
    std::string decryptText = encrypt_caesar(text, 26 - shift);
    return decryptText;
}

int main() {
    setlocale(LC_ALL, "");
    std::string text;
    int shift;

    std::wcout << L"Введите текст: ";
    std::getline(std::cin, text);

    std::wcout << L"Введите сдвиг: ";
    std::cin >> shift;

    while (std::cin.fail() || std::cin.peek() != '\n' || shift <= 0) {
        std::wcerr << L"Ошибка ввода данных.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::wcout << L"Введите сдвиг: ";
        std::cin >> shift;
    }
    std::cout << encrypt_caesar(text, shift) << '\t';
    std::cout << decrypt_caesar(encrypt_caesar(text, shift), shift);
}