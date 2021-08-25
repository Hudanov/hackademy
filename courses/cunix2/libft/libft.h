#ifndef LIBFT_H
#define LIBFT_H

    #include <stddef.h>
    #include <stdlib.h>
 
    void ft_bzero(void *s, size_t n);

    char *ft_strdup(const char *s);

    unsigned int ft_strlen(const char *str);

    int ft_strncmp(const char *s1, const char *s2, size_t n);

    char *ft_strchr(const char *s, int c);

    char *ft_strrchr(const char *s, int c);

    int ft_isalpha (int c);

    int ft_isdigit(int c);

    int ft_isascii(int c);

    int ft_toupper(int c);

    int ft_tolower(int c);

    char *ft_strstr(const char *haystack, const char *needle);

    char *ft_strnstr(const char *hay, const char *need, size_t len);

    int abs(int i);
    
    div_t ft_div(int num, int denom);

    void *ft_memalloc(size_t size);

    void *ft_memccpy(void *dst, const void *src, int c, size_t n);

    void *ft_memchr(const void *s, int c, size_t n);

    int	ft_memcmp(const void *s1, const void *s2, size_t n);

    void *ft_memcpy(void *destination, const void *src, size_t n);

    void *ft_memmove(void *dst, const void *src, size_t len);

    void *ft_memset(void *destination, int c, size_t n);

    char *ft_strcat(char *s1, const char *s2);
    
    char *ft_strcpy(char *dst, const char *src);

    void ft_striter(char *s, void (*f)(char *));

    char *ft_strjoin(char const *s1, char const *s2);

    char *ft_strmap(char const *s, char (*f)(char));

    char *ft_strnew(size_t size);

    char **ft_strsplit(char const *s, char c);

    char *ft_strsub(char const *s, unsigned int start, size_t len);

    char *ft_strtrim(char const *s);

    int ft_strwhitespace(char c);

    int ft_count(char const *str, char c);

#endif
