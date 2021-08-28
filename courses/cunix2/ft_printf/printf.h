#ifndef LIB_H
#define LIB_H

    #include <stdlib.h>
    #include <stdarg.h>
    #include <unistd.h>

    void ft_printf(char *format, ...);    

    char *ft_itoa(int val, int base);
    
    unsigned int ft_strlen(char *str); 
    
    int ft_atoi(const char *str);

    void my_print_buf(char *buf, int align, int len);

    void my_print_char(char ch, int align);

    void my_print_str(char *str, int align);

    void my_pad_with_zeros(int num, int len);

#endif
