#include <iostream>

bool isSubstring(const char *string, const char *substring)
{
    int i = 0;
    int stringLength = *(&string + 1) - string;
    while (*(string + i) != '\0')
    {
        if (*(string + i) == *substring)
        {
            bool flag = true;
            int k = 0;
            while (*(substring + k) != '\0')
            {
                if (*(string + i + k) == '\0')
                {
                    return false;
                }

                if (*(substring + k) != *(string + i + k))
                {
                    flag = false;
                }
                k++;
            }
            if (flag)
            {
                return true;
            }
        }

        i++;
    }
    return false;
}

int main()
{
const char* a = "Hello world";
const char* b = "OHell";
const char* c = "banana";
std::cout << isSubstring(a, b) << " " << isSubstring(a, c) << std::endl;

return 0;
}
