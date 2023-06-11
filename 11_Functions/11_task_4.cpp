#include <iostream>
#include <limits>
#include <numeric>

char getXY(int x, int y, std::string firstStr, std::string secondStr, std::string thirdStr) {
    if (x == 0) {
        return firstStr[y];
    } else if (x == 1) {
        return secondStr[y];
    } else {
        return thirdStr[y];
    }
}

char isWinner(std::string firstStr, std::string secondStr, std::string thirdStr) {
    for (int x = 0; x <= 2; x++) {
        int xCount = 0;
        int yCount = 0;
        for (int y = 0; y <= 2; y++) {
            char obj = getXY(x, y, firstStr, secondStr, thirdStr);
            if (obj == 'X') {
                xCount++;
            } else if (obj == 'O') {
                yCount++;
            }
        }
        if (xCount == 3) {
            return 'X';
        } else if (yCount == 3) {
            return 'O';
        }
    }

    for (int y = 0; y <= 2; y++) {
        int xCount = 0;
        int yCount = 0;
        for (int x = 0; x <= 2; x++) {
            char obj = getXY(x, y, firstStr, secondStr, thirdStr);
            if (obj == 'X') {
                xCount++;
            } else if (obj == 'O') {
                yCount++;
            }
        }
        if (xCount == 3) {
            return 'X';
        } else if (yCount == 3) {
            return 'O';
        }
    }

    {
        int xCount = 0;
        int yCount = 0;
        for (int x = 0; x <= 2; x++) {
            for (int y = 0; y <= 2; y++) {
                char obj = getXY(x, y, firstStr, secondStr, thirdStr);
                if (x == y && obj == 'X') {
                    xCount++;
                } else if (x == y && obj == 'O') {
                    yCount++;
                }
            }
        }
        if (xCount == 3) {
            return 'X';
        } else if (yCount == 3) {
            return 'O';
        }
    }
    
       {
        int xCount = 0;
        int yCount = 0;
        for (int x = 0; x <= 2; x++) {
            for (int y = 0; y <= 2; y++) {
                char obj = getXY(x, y, firstStr, secondStr, thirdStr);
                if (x == 0 && y == 2 && obj == 'X' || x == 2 && y == 0 && obj == 'X' || x == 1 && y == 1 && obj == 'X') {
                    xCount++;
                } else if (x == 0 && y == 2 && obj == 'O' || x == 2 && y == 0 && obj == 'O' || x == 1 && y == 1 && obj == 'O') {
                    yCount++;
                }
            }
        }
        if (xCount == 3) {
            return 'X';
        } else if (yCount == 3) {
            return 'O';
        }
    }
    return 'N';
}

bool isValidSymbols(std::string firstStr, std::string secondStr, std::string thirdStr) {

    for (int x = 0; x <= 2; x++) {
        for (int y = 0; y <= 2; y++) {
            char obj = getXY(x, y, firstStr, secondStr, thirdStr);
            if (obj != 'X' && obj != 'O' && obj != '.') {
                return false;
            }
        }
    }
    return true;
}

char validWinner(std::string firstStr, std::string secondStr, std::string thirdStr) {
    char winner = isWinner(firstStr, secondStr, thirdStr);
    int xCount = 0;
    int yCount = 0;
    int pointCount = 0;
    for (int x = 0; x <= 2; x++) {
        for (int y = 0; y <= 2; y++) {
            char obj = getXY(x, y, firstStr, secondStr, thirdStr); {
                if (obj == 'X') {
                    xCount++;
                } else if (obj == 'O') {
                    yCount++;
                } else if (obj == '.') {
                    pointCount++;
                }
            }
        }
    }
    if (xCount > yCount && winner == 'X') {
        return 'X';
    } else if (xCount < yCount) {
        return 'I';
    } else if (xCount == yCount && winner == 'X') {
        return 'I';
    } else if (xCount == yCount && winner == 'O') {
        return 'O';
    } else if (xCount >= yCount && winner == 'O') {
        return 'I';
    } else if (xCount == yCount && winner == 'N' && pointCount > 0) {
        return 'N';
    } else if (xCount > yCount && winner == 'N' && pointCount == 0) {
        return 'N';
    }
    return 'I';

}

int main() {
    setlocale(0, "");
    while(true) {
        std::string first;
        std::string second;
        std::string third;

        std::wcout << L"Введите первую строку:\t";
        std::cin >> first;

        std::wcout << L"Введите вторую строку:\t";
        std::cin >> second;

        std::wcout << L"Введите третью строку:\t";
        std::cin >> third;

        if (validWinner(first, second, third) == 'I') {
            std::wcout << L"Некорректный ввод\n" << std::endl;
        } else if (validWinner(first, second, third) == 'X' && isValidSymbols(first, second, third)) {
            std::wcout << L"Петя победил!\n" << std::endl;
        } else if (validWinner(first, second, third) == 'O' && isValidSymbols(first, second, third)) {
            std::wcout << L"Ваня победил!\n" << std::endl;
        } else if (validWinner(first, second, third) == 'N' && isValidSymbols(first, second, third)) {
            std::wcout << L"Ничья!\n" << std::endl;
        } else if (!isValidSymbols(first, second, third)) {
            std::wcout << L"Некорректный ввод\n" << std::endl;
        }
    }
}