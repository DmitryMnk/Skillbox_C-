#include <iostream>
#include <vector>

std::vector<int> vecSort(std::vector<int> vec) {
   for (int j = 0; j < vec.size(); j++)
   {
    for (int i = 0; i < vec.size() - 1; i++)
    {
        if (abs(vec[i]) > abs(vec[i + 1]))
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
    std::vector<int> vec = {-100,-50, -5, 1, 10, 15};
    
    vec = vecSort(vec);
    printVec(vec);
}