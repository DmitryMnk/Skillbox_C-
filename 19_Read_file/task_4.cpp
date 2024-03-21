#include <iostream>
#include <fstream>
#include <string>

int main()
{
    setlocale(0, "");
    std::string filePath;
    char f_string[6];
    std::ifstream task_4;
    std::string lastSymbols;

    std::wcout << L"Введите путь к файлу: ";
    std::cin >> filePath;

    if (filePath.substr(filePath.size() - 3, 3) != "PNG" && filePath.substr(filePath.size() - 3, 3) != "png")
    {
        std::wcout << L"Данный файл не является PNG." << std::endl;
        return 0;
    }

    task_4.open(filePath, std::ios_base::binary);
    task_4.read(f_string, sizeof(f_string));
    std::string subs(f_string);
    
    if ((int) f_string[0] == -119 && subs.substr(1, 3) == "PNG")
    {
        std::wcout << L"Данный файл является PNG." << std::endl;
    } else
    {
       std::wcout << L"Данный файл не является PNG." << std::endl;
    }
    
    task_4.close();
    return 0;
}