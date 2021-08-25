#include "../libft.h"

char *ft_strnstr(const char *hay, const char *need, size_t len)
{
    size_t i = 0;
    size_t j = 0;
    char *s1 = (char *)hay;
    char *s2 = (char *)need;
    size_t n = ft_strlen(s2);

    if (s2[j] == 0)
    {
        return (&s1[i]);
    }

    while (s1[i] != 0 && n <= len--)
    {
        j = 0;
        while (s2[j] == s1[i + j])
        {
            if (s2[j + 1] == '\0')
            {
                return (&s1[i]);
            }
            j++;
        }
        i++;
    }
    return (NULL);
}
