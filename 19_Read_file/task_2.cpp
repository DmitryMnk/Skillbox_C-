#include <iostream>
#include <fstream>
#include <string>

int main()
{
    setlocale(0, "");
    std::string filePath;
    std::string filePart;

    std::wcout << L"Введите путь к файлу: ";
    std::cin >> filePath;

    std::fstream task_2;
    task_2.open(filePath);

    while(!task_2.is_open())
    {
        std::wcout << L"Неккоретный путь к файлу. Введите ещё раз: ";
        std::cin >> filePath;
        task_2.open(filePath);
    }

    while (getline(task_2, filePart))
    {
        std::cout << filePart << '\n';
    }
    task_2.close();

    std::cout << std::endl;
    return 0;
}