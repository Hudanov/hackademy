#include "../libft.h"

char *ft_strcat(char *s1, const char *s2)
{
    int len = ft_strlen(s1);
    int i = 0;

    while (s2[i] != 0)
    {
        s1[len++] = s2[i++];
    }
    s1[len] = '\0';
    return (s1);
}
