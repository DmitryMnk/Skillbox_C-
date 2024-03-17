#include <iostream>
#include <vector>

void printVec(std::vector<int> vec)
{
    for (int i: vec)
    {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

void swapvec(std::vector<int>& vec_1, std::vector<int>& vec_2)
{
    for (int i = 0; i < vec_1.size(); i++)
    {
        int temp = vec_2[i];
        vec_2[i] = vec_1[i];
        vec_1[i] = temp;
    }
}

int main()
{
    std::vector<int> vec_1 {1, 2, 3, 4},
                    vec_2 {5, 6, 7, 8};

    printVec(vec_1);
    printVec(vec_2);

    swapvec(vec_1, vec_2);

    printVec(vec_1);
    printVec(vec_2);

    return 0;
}