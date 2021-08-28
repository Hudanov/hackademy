#include "../libft.h"

char *ft_strrchr(const char *str, int c)
{
    int i = ft_strlen(str);

    while (i >= 0)
    {
        if (str[i] == (char)c)
        {
            return (&((char *)str)[i]);
        }
        else 
        {
            i--;
        }
    }
    return NULL;
}
