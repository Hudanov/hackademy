#include "../libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    int i = 0;
    int new_n = (int)n;
    unsigned char to_find = (unsigned char)c;

    while (i < new_n)
    {
        if (((unsigned char *)s)[i] == to_find)
        {
            return (&((unsigned char *)s)[i]);
        }
        else
        {
            i++;
        }
    }
    return NULL;
}
