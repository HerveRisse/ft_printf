#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *format, ...);
void ft_putchar(char c, int *len);
void ft_putstr(char *str, int *len);
void ft_putnbr(long n, int *len);
void ft_putnbr_base(unsigned long n, char *base, int base_len, int *len);
void ft_handle_format(char format, va_list args, int *len);

#endif