#include <iostream>
#include <numeric>
#include <limits>
#include <sstream>
#include <string>

enum switches
{ 
    LIGHTS_INSIDE = 1, 
    LIGHTS_OUTSIDE = 2, 
    HEATERS = 4, 
    WATER_PIPE_HEATING = 8, 
    CONDITIONER = 16 
};

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

main()
{
    setlocale(0, "");
    std::string input;
    int time = 0;
    int switches_state = LIGHTS_INSIDE | LIGHTS_OUTSIDE | HEATERS | WATER_PIPE_HEATING | CONDITIONER;

    while (true)
    {
        if (time < 10)
        {
            std::wcout << L"Время: 0"<< time << ":00\n";
        } else
        {
            std::wcout << L"Время: "<< time << ":00\n";
        }

        std::cout << "Temperature inside, temperature outside, movement, lights: ";
        std::cin.clear();
        std::getline(std::cin, input);
        

        while (!isValidInput())
        {
            std::wcout << L"Ошибка! Введите ещё раз: ";
            std::getline(std::cin, input);
        }

        std::stringstream buffer_stream(input);
        int temp_inside,
            temp_out;
        
        std::string movement,
                    lights;
        
        buffer_stream >> temp_inside >> temp_out >> movement >> lights;
        if ((switches_state & LIGHTS_OUTSIDE) && (movement == "no")) {
            std::cout << "Lights outside off\n";
            switches_state &= ~LIGHTS_OUTSIDE;
        } else if (!(switches_state & LIGHTS_OUTSIDE) && movement == "yes" && (time >= 16 || time <= 5))
        {
            std::cout << "Lights outside on\n";
            switches_state |= LIGHTS_OUTSIDE;
        }

        if ((switches_state &  LIGHTS_INSIDE) && lights == "off") {
            std::cout << "Lights inside off\n";
            switches_state &= ~LIGHTS_INSIDE;
        } else if (!(switches_state & LIGHTS_INSIDE) && lights == "on") {
            std::cout << "Lights inside on\n";
            switches_state |= LIGHTS_INSIDE;
        }

        if ((switches_state &  LIGHTS_INSIDE) && (time < 16 || time > 20))
        {
            std::wcout << L"Цветовая температура: 5000K\n";
        } else if ((switches_state &  LIGHTS_INSIDE) && (time >= 16 && time <= 20))
        {
            int color_temp = 5000 - 575 * (time - 16);
            std::wcout << L"Цветовая температура: " << color_temp << '\n';
        }

        if ((switches_state & HEATERS) && (temp_inside >= 25))
        {
            std::cout << "Heaters off\n";
            switches_state &= ~HEATERS;
        } else if (!(switches_state & HEATERS) && (temp_inside <= 22))
        {
            std::cout << "Heaters on\n";
            switches_state |= HEATERS;
        }

        if ((switches_state & CONDITIONER) && (temp_inside <= 25))
        {
            std::cout << "Conditioner off\n";
            switches_state &= ~CONDITIONER;
        } else if (!(switches_state & CONDITIONER) && (temp_inside >= 30))
        {
            std::cout << "Conditioner on\n";
            switches_state |= CONDITIONER;
        } 

        if (!(switches_state & WATER_PIPE_HEATING) && temp_out <= 0)
        {
            std::cout << "Water pipe heateing on\n";
            switches_state |= WATER_PIPE_HEATING;
        } else if ((switches_state & WATER_PIPE_HEATING) && temp_out >= 5)
        {
            std::cout << "Water pipe heateing off\n";
            switches_state &= ~WATER_PIPE_HEATING;
        }

        time++;
        if (time == 24)
        {
            time = 0;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    

}