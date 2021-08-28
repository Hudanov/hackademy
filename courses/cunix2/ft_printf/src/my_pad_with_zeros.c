#include "../printf.h"

void my_pad_with_zeros(int num, int len)
{
    if (num < 0)
    {
        num *= -1;
        write(1, "-", 1);
        len--;
    }
    char *str = ft_itoa(num, 10);
    size_t str_len = ft_strlen(str);
    int pad = len - str_len;
    if (pad < 0)
    {
        pad = 0;
    }
    while (pad--)
    {
        write(1, "0", 1);
    }
    write(1, str, str_len);
}

