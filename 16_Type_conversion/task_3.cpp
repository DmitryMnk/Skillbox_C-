#include <iostream>
#include <limits>
#include <cmath>
#include <numeric>
#include <sstream>

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

bool checkOperation(char oper)
{
    if (oper == '+' || oper == '-' || oper == '/' || oper == '*') 
    {
        return true;
    }
    return false;
}

bool checkMials(double first, double second)
{
    if (first < 1 * pow(10, -310) || second < 1 * pow(10, -310))
    {
        return false;
    }

    return true;
}

main() 
{
    setlocale(0, "");
    std::string input;

    std::wcout << L"Введите выражение <число><операция: +, -, * или /><число>: ";
    std::cin >> input;

    while(!isValidInput) 
    {
        std::wcout << L"Ошибка! Введите ещё раз: ";
        std::cin >> input;
    }

    std::stringstream buffer_stream(input);
    double  first_operand,
            second_operand,
            result;
    char    operation;
    buffer_stream >> first_operand >> operation >> second_operand;
    
    while (!isValidInput() || !checkOperation(operation) || !checkMials(first_operand, second_operand)) 
    {
        std::wcout << L"Ошибка! Введите ещё раз: ";
        std::cin >> input;
        std::stringstream buffer_stream(input);
        buffer_stream >> first_operand >> operation >> second_operand;
    }

    if (operation == '+')
    {
        result = first_operand + second_operand;
    } else if (operation == '-')
    {
        result = first_operand - second_operand;
    } else if (operation == '*')
    {
        result = first_operand * second_operand;
    } else 
    {
        result = first_operand / second_operand;
    }

    std::wcout << L"Результат: " << result << std::endl;

    return 0;
}