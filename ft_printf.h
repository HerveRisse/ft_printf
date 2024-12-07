#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>

char *ft_strchr(const char *s, int c);
int ft_putchar(char c);
int ft_putnbr_hex(unsigned int n, char format);
int ft_putnbr_unsigned(unsigned int n);
int ft_putnbr(int n);
int ft_putptr(unsigned long ptr);
int ft_putstr(char *str)

#endif