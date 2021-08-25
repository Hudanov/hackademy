#include "../libft.h"

void ft_striter(char *s, void (*f)(char *))
{
    unsigned int i;

    i = 0;
    if(!s || !f)
    {
        return ;
    }
    while (s[i] != 0)
    {
        (*f)(&s[i++]);
    }
}

