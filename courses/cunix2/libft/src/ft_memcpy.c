#include "../libft.h"

void *ft_memcpy(void *destination, const void *src, size_t n)
{
    while (n)
    {
        --n;
        ((unsigned char *)destination)[n] = ((unsigned char *)src)[n];
    }
    return destination;
}
