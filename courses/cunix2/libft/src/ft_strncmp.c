#include "../libft.h"

int ft_strncmp(const char *str1, const char *str2, size_t n)
{
    size_t i = 0;
    unsigned char *str1_cp = (unsigned char *)str1;
    unsigned char *str2_cp = (unsigned char *)str2;

    while ((str1_cp[i] || str2_cp[i]) != 0 && i < n)
    {
        if (str1_cp[i] == str2_cp[i]) 
        {
            i++;
        }
        else
        {
            return (str1_cp[i] - str2_cp[i]);
        }
    }
    return 0;
}
