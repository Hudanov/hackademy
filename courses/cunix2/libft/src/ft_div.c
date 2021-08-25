#include "../libft.h"

div_t ft_div(int num, int denom)
{
    div_t div;
    div.quot = num / denom;
    div.rem = num % denom;
    return div;
}
