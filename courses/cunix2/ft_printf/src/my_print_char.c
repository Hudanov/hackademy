#include "../printf.h"

void my_print_char(char ch, int align)
{
    char *str_buf = malloc(2 * sizeof(char));
    str_buf[0] = ch;
    str_buf[1] = '\0';
    my_print_buf(str_buf, align, 1);
    free(str_buf);
}
