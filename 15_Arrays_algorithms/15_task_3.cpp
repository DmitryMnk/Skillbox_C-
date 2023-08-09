#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

bool isValidInput() {
    if (std::cin.fail() || std::cin.peek() != '\n') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

std::vector<int> vecSort(std::vector<int> vec) {
   for (int j = 0; j < vec.size(); j++)
   {
    for (int i = 0; i < vec.size() - 1; i++)
    {
        if (vec[i] > vec[i + 1])
        {   
            int temp = vec[i+1];
            vec[i+1] = vec[i];
            vec[i] = temp;
        }
    } 
   }
   return vec;
}

void printVec(std::vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << '\t';
    }
    std::cout << std::endl;
}

int main() {
    setlocale(0, "");
    int number;
    std::vector<int> vec;

    while(number != -2) {
        std::wcout << L"Введите число:";
        std::cin >> number;

        while (!isValidInput()) 
        {
            std::wcout << L"Ошибка! Введите число: ";
            std::cin >> number;
        } 

        while (number == -1 && vec.size() < 5) 
        {
            std::wcout << L"Ошибка! Необходимо ввести минимум 5 чисел.\n";
            std::wcout << L"Введите число: ";
            std::cin >> number;
        }

        if (number != -1) {
            vec.push_back(number);
        } else {
            vec = vecSort(vec);
            printVec(vec);
            std::cout << vec[4] << std::endl;
        }
    }
}