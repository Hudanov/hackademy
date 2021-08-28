#include "../libft.h"

void *ft_memalloc(size_t size)
{
    void *res = malloc((size));

    if (res == 0)
    {
        return NULL;
    }
    ft_bzero(res, size);
    return (res);
}
