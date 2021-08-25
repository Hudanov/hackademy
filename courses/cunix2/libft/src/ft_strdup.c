#include "../libft.h"

char *strdup(const char *str)
{
    int len = ft_strlen(str);
    char *cp = (char *)malloc(sizeof(char) * (len + 1));

    for (int i = 0; i <= len; i++)
    {
        cp[i] = str[i];
    }

    return cp;
}

