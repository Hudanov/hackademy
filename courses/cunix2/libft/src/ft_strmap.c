#include "../libft.h"

char *ft_strmap(char const *s, char (*f)(char))
{
    int i = 0;
    char *res;

    if (!s || !f)
    {
        return NULL;
    }
    if (!(res = ft_strnew(ft_strlen(s))))
    {
        return NULL;
    }
    ft_strcpy(res, s);
    while (res[i])
    {
        res[i] = f(res[i]);
        i++;
    }
    return res;
}

