#include <iostream>

int jump(int lastStep, int maxStep = 3)
{

    if (lastStep == 0)
    {
        return 1;
    } else if (lastStep < 0)
    {
        return 0;
    }

    int total_sum = 0;

    for (int i = 1; i <= maxStep; i++)
    {
        total_sum += jump(lastStep - i, maxStep);
    }
    
    return total_sum;
}

int main()
{
    std::cout << jump(3, 3);
    return 0;
}