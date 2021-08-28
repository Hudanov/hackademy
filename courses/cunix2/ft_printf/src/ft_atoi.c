#include "../printf.h"

int ft_atoi(const char *str)
{
    char ch;
    int count = 0, res = 0, digit;
    int sign = 1;
    if ((ch = *str) == '-')
    {
        str++;
        sign = -1;
    }

    while ((ch = *str) >= 48 && ch <= 57) 
    {
        str++;
        count++;
    }
    int power = 0;
    while ((power++) < count)
    {
        int multiple = 1;
        digit = *(--str) - 48;
        for (int i = 1; i < power; i++)
        {
            multiple *= 10;
        }
        res += digit * multiple;
    }
    return res * sign;
}
