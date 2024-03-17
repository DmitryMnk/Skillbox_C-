#include <iostream>

void evenDigits(long long n, int &ans)
{
    int count = 0;
    while (n != 0)
    {
        int ost = n % 10;
        if (ost % 2 == 0)
        {
            count += 1;
        }
        n /= 10;
    }
    ans = count;
}

int main()
{
    int ans;
    evenDigits(9223372036854775806, ans);

    std::cout << ans << std::endl;
    return 0;

}