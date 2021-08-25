#include "../libft.h"

void bzero(void *s, size_t n)
{
    char *b = s;
    size_t i;

    for (i = 0; i < n; i++)
    {
        b[i] = '\0';
    }
}
