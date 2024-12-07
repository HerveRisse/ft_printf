#include "ft_printf.h"

int ft_putstr(char *str)
{
    int len = 0;
    if (!str)
        return write(1, "(null)", 6);
    while (*str)
        len += ft_putchar(*str++);
    return len;
}