#include <iostream>
#include <numeric>
#include <limits>

bool isValidInput() 
{
    if (std::cin.fail() || std::cin.peek() != '\n') 
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

bool checkNotes(std::string accord)
{
    for (int i = 0; i < accord.length(); i++)
    {
        if (accord[i] < '0' || accord[i] > '7')
        {
            return false;
        }
    }

    int noteArray[7] {0};
    for (char symbol : accord)
    {
        int index = symbol - '0';
        noteArray[index - 1] += 1;
        if (noteArray[index - 1] > 1)
        {
            
            return false;
        }
    }

    return true;
}

enum note
{
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

main()
{
    setlocale(0, "");
    std::string input;
    std::wcout << L"Введите аккорд: ";
    std::cin >> input;
    while(!isValidInput() || !checkNotes(input))
    {
        std::wcout << L"Ошибка! Введите ещё раз: ";
        std::cin >> input;
    }

    int notes = 0;
    for (int i = 0; i < input.length(); i++) 
    {
        int mask = 1 << (int) input[i] - '0' - 1;
        notes = (notes | mask);
    }


    if (notes & DO)
        {
            std::cout << "DO ";
        } 
     if (notes & RE) {
            std::cout << "RE ";
        }
     if (notes & MI) {
            std::cout << "MI ";
        }
     if (notes & FA) {
            std::cout << "FA ";
        }
     if (notes & SOL) {
            std::cout << "SOL ";
        }
     if (notes & LA) {
            std::cout << "LA ";
        }
     if (notes & SI) {
            std::cout << "SI ";
        }
    std::cout << std::endl;
    return 0;
}