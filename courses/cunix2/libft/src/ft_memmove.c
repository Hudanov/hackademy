#include "../libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
    size_t i = 0;
    char *d = (char *)dst;
    char *s = (char *)src;
    i = 0;
    if (s > d)
    {
        while (i < len)
        {
            *(d + i) = *(s + i);
            i++;
        }
    }
    if (d > s)
    {
        while (len > 0)
        {
            len--;
            *(d + len) = *(s + len);
        }
    }
    return (dst);

}
