#include "../printf.h"

void my_print_buf(char *buf, int align, int len)
{
    int pad = 0;
    if (!buf)
    {
        len = 6;
    }
    if (align < 0)
    {
        align *= -1;
        if (buf)
        {
            write(1, buf, len);
        }
        else
        {
            write(1, "(null)", 6);
        }
        pad = align - len;
        if (pad < 0)
        {
            pad = 0;
        }
        while (pad--)
        {
            write(1, " ", 1);
        }
    }
    else
    {
        pad = align - len;
        if (pad < 0)
        {
            pad = 0;
        }
        while (pad--)
        {
            write(1, " ", 1);
        }
        if (buf)
        {
            write(1, buf, len);
        }
        else
        {
            write(1, "(null)", 6);
        }
    }
}
