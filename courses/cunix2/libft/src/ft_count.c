#include "../libft.h"

int	ft_count(char const *str, char c)
{
    int i = 0;
    int flag = 0;
    int count = 0;

    while (*str)
    {
        if (!flag && *str != c)
        {
            count++;
        }
        flag = (str[i] == c) ? 0 : 1;
        str++;
    }
    return (count);
}
