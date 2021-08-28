#include "../printf.h"

void ft_printf(char *format, ...)
{
    va_list list;
    va_start(list, format);
    int num = 0;
    int format_mode = 0;
    int align_len = 0;
    int plus_found = 0, minus_found = 0, number_found = 0, space_found = 0, zero_found = 0;
    char *parsed = NULL;
    while (*format)
    {
        if (format_mode)
        {
            switch (*format)
            {
                case '%':
                    write(1, "%", 1);
                    format_mode = 0;
                    break;
                case ' ':
                    space_found = 1;
                    break;
                case 'd':
                case 'i':
                    num = va_arg(list, int);
                    if (zero_found)
                    {
                        my_pad_with_zeros(num, align_len);
                        break;
                    }
                    if (space_found && num >= 0 && !align_len)
                    {
                        my_print_str(" ", 0);
                    }
                    if (plus_found && num >= 0)
                    {
                        my_print_str("+", 0);
                    }
                    parsed = ft_itoa(num, 10);
                    my_print_str(parsed, align_len);
                    align_len = format_mode = number_found = 0;
                    break;
                case 's':
                    my_print_str(va_arg(list, char *), align_len);
                    align_len = format_mode = number_found = 0;
                    break;
                case 'c':
                    my_print_char(va_arg(list, int), align_len);
                    align_len = format_mode = number_found = 0;
                    break;
                case '+':
                    plus_found = 1;
                    break;
                case '-':
                    minus_found = 1;
                    break;
                default:
                    if (*format < 48 || *format > 59)
                    {
                        write(1, format, 1);
                        format_mode = 0;
                    }
                    else
                    {
                        if (!number_found)
                        {
                            if (*format == '0')
                            {
                                zero_found = 1;
                            }
                            number_found = 1;
                            if (minus_found)
                            {
                                align_len = (-1) * ft_atoi(format);
                                minus_found = 0;
                            }
                            else if (plus_found || number_found)
                            {
                                align_len = ft_atoi(format);
                                plus_found = 0;
                            }
                        }
                    }
                    break;
            }
        }
        else
        {
            if (*format == '%')
            {
                format_mode = 1;
            }
            else
            {
                write(1, format, 1);
            }
        }
        format++;
    }
    va_end(list);
}

