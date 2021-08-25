#include "../libft.h"

char **ft_strsplit(char const *s, char c)
{
    char **r;
    size_t flag;
    size_t index;
    size_t i;
    size_t start;

    if (!s)
    {
        return NULL;
    }
    if (!(r = (char **)ft_memalloc(sizeof(char *) * (ft_count(s, c) + 1))))
    {
        return NULL;
    }
    flag = 0;
    i = -1;
    index = 0;
    start = 0;
    while (s[++i])
    {
        if (s[i] == c && flag)
        {
            r[index++] = ft_strsub(s, start, i - start);
        }
        if (!flag && s[i] != c)
        {
            start = i;
        }
        flag = (s[i] == c) ? 0 : 1;
    }
    if (flag)
    {
        r[index] = ft_strsub(s, start, i - start);
    }
	return (r);
}
