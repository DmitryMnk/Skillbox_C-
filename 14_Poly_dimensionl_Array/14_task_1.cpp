#include <iostream>


void printArray(int array[][6], std::wstring arrayName){
    std::wcout << arrayName << '\n';
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 6; j++) 
        {
            std::cout << array[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

int main() {
    setlocale(0, "");
    int cutlery[2][6]
    {
        {4, 3, 3, 3, 3, 3},
        {4, 3, 3, 3, 3, 3}
    };

    int dishes[2][6]
    {
        {3, 2, 2, 2, 2, 2},
        {3, 2, 2, 2, 2, 2}
    };

    int chairs[2][6]
    {
        {1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1}
    };

    printArray(cutlery, L"Столовые приборы");
    printArray(dishes, L"Тарелки");
    printArray(chairs, L"Стулья");
    
    chairs[0][4] += 1;
    cutlery[0][0] -= 1;
    dishes[0][0] -= 1;

    printArray(cutlery, L"Столовые приборы");
    printArray(dishes, L"Тарелки");
    printArray(chairs, L"Стулья");
}