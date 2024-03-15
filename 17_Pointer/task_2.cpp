#include <iostream>

void printArray(int arr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        std::cout << *(arr + i) << ' ';
    }
    std::cout << std::endl;
}

void arrSwap(int* arr, int size)
{
    int last;
    for (int i = 0; i < (size / 2); i++)
    {
        last = *(arr + size - 1 - i);
        *(arr + size - 1 - i) = *(arr + i);
        *(arr + i) = last;
    }
}

int main()
{
    int list[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = *(&list + 1) - list;
    arrSwap(list,  size);
    printArray(list, size);

    return 0;
}