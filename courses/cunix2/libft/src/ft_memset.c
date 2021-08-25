#include "../libft.h"

void *ft_memset(void *destination, int c, size_t len)
{
    unsigned i = 0;
    
    while (i < len)
    {
        ((unsigned char *)destination)[i++] = (unsigned char)c;
    }
    return (destination);
}
