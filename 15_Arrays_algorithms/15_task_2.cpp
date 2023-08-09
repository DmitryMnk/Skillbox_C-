#include <iostream>
#include <vector>

int main() {
    std::vector vec = {2, 7, 11, 15};
    int result = 9;
    bool is_result = false;

    for (int i = 0; i < vec.size() - 1; i++) 
    {
        for (int j = i + 1; j < vec.size(); j++) 
        {
            if (vec[i] + vec[j] == result) 
            {
                std::cout << vec[i] << ' ' << vec[j] << std::endl;
                is_result = true;
                break;
            }
        }
        
        if (is_result)
        {
            break;
        }
        
    } 
}