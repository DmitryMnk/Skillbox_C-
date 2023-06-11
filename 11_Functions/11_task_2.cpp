#include <iostream>
#include <limits>
#include <numeric>

std::string getFirstPart(std::string mail) {
    std::string partMail = "";
    for (int i = 0; i < mail.length(); i++) {
        if (mail[i] == '@') {
            break;
        }
        partMail += mail[i];
    }
    return partMail;
}

std::string getSecondPart(std::string mail) {
    std::string partMail = "";
    int k = mail.find('@') + 1;
     for (int i = k; i < mail.length(); i++) {
            partMail += mail[i];
        }
    return partMail;
}

bool isCorrectPoint(std::string mail) {
    int pointCount = 0;
    char prevSymb = ' ';
    for (int i = 0; i < mail.length(); i++) {
        if (mail[i] == '.' && prevSymb == '.') {
            pointCount++;
        }
        prevSymb = mail[i];
    }
    if (mail[0] != '.' && mail[mail.length() - 1] != '.' && pointCount == 0) {
        return true;
    }
    return false;
}

bool isCorrectFirstPart(std::string mail) {
    int symbolsCount = 0;
    for (int i = 0; i < mail.length(); i++) {
        if (mail[i] != '!' && (mail[i] < '#' || mail[i] > '\'') && 
        (mail[i] < '*' || mail[i] > '9') && mail[i] != '=' && (mail[i] < '?' || mail[i] > '~')) {
            return false;
        }
        symbolsCount++;
    }
    if (symbolsCount >= 1 && symbolsCount <= 64) {
        return true;
    } else {
        return false;
    }
}

bool isCorrectSecondPart(std::string mail) {
    int symbolsCount = 0;
    for (int i = 0; i < mail.length(); i++) {
        if (mail[i] != '.' && mail[i] != '-' && (mail[i] < '0' || mail[i] > '9') && 
        (mail[i] < 'A' || mail[i] > 'Z') && (mail[i] < 'a' || mail[i] > 'z')) {
            return false;
        }
        symbolsCount++;
    }
    if (symbolsCount >= 1 && symbolsCount <= 63) {
        return true;
    } else {
        return false;
    }
    
}

bool isMailContaineArobas(std::string mail) {
    int arobasCount = 0;
    for (int i = 0; i < mail.length(); i++) {
        if (mail[i] == '@') {
            arobasCount++;
        }
    }
    if (arobasCount == 1) {
        return true;
    }
    return false;
}

int main() {
    setlocale(0, "");
    while (true) {
        
        std::string mail;

        std::wcout << L"\nВведите e-mail: ";
        std::cin >> mail;

        while (std::cin.fail() || std::cin.peek() != '\n') {
            std::wcerr << L"Ошибка ввода данных.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::wcout << L"\nВведите e-mail: ";
            std::cin >> mail;
        }

        std::string firstPart = getFirstPart(mail);
        std::string secondPart = getSecondPart(mail);

        if (isCorrectPoint(mail) && 
        isCorrectFirstPart(firstPart) && 
        isCorrectSecondPart(secondPart) && 
        isMailContaineArobas(mail)
        ) 
        {
            std::wcout << L"e-mail - корректный.\n" << std::endl;
        } else {
            std::wcout << L"e-mail - не корректный.\n" << std::endl;
        }
    }

}