#include "../printf.h"

void my_print_str(char *str, int align)
{
    size_t len = ft_strlen(str);
    my_print_buf(str, align, len);
}
