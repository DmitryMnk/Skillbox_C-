#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main()
{
    std::string file_string,
                first_name,
                last_name,
                date,
                full_name;

    int pay,
        max_sum = 0;

    std::fstream task_3;
    task_3.open("task_3.txt");

    while(getline(task_3, file_string))
    {
        std::stringstream temp_stream(file_string);
        temp_stream >> first_name >> last_name >> pay >> date;
        if (pay > max_sum)
        {
            full_name = first_name + " " + last_name;
            max_sum = pay;
        }
    }
    task_3.close();


    std::cout << max_sum << ' ' << full_name << std::endl;
    return 0;
}