#include "../libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    char *res;

    if (s1 == NULL || s2 == NULL)
    {
        return NULL;
    }
    res = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
    if (!res)
    {
        return NULL;
    }
    ft_strcpy(res, s1);
    ft_strcat(res, s2);
    return (res);
}
