#include <iostream>

void swap(int* a, int* b)
{
    int f1 = *a;
    *a = *b;
    *b = f1;
}

int main()
{
    int a = 10;
    int b = 15;

    swap(&a, &b);

    std::cout << "first: "<< a << " second: " << b << std::endl;
    return 0;
}