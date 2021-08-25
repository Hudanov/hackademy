#include "../libft.h"

char *ft_strchr(const char *str, int c)
{
    size_t i = 0;

    while (i < ft_strlen(str))
    {
        if (str[i] == (char)c)
        {
            return (&((char *)str)[i]);
        }
        else
        {
            i++;
        }
    }
    return NULL;
}
