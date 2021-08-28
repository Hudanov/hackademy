#include "../printf.h"

unsigned int ft_strlen(char *str)
{
    if (!str)
    {
        return 0;
    }
    int count = 0;
    while (*str != '\0') 
    {
        count++;
        str++;
    }
    return count;
}
