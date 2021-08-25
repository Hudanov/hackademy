#include "../libft.h"

char *ft_strstr(const char *haystack, const char *needle)
{
    int i = 0;
    int j = 0;

    if (needle[j] == 0)
    {
        return (&((char *)haystack)[i]);
    }

    while (haystack[i] != 0)
    {
        j = 0;

        while (needle[j] == haystack[i + j])
        {
            if (needle[j + 1] == '\0')
            {
                return (&((char *)haystack)[i]);
            }

            j++;
        }
        i++;
    }
    return (NULL);
}
    
