#include "../libft.h"

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
    char *res = ft_strnew(len);
    size_t i = 0;

    if (!s || !res)
    {
        return NULL;
    }
    while (i < len)
    {
        res[i] = s[start];
        i++;
        start++;
    }
    res[i] = '\0';
    return (res);
}
