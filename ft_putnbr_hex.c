#include "ft_printf.h"

int ft_putnbr_hex(unsigned int n, char format)
{
    int len = 0;
    char *base;

    if (format == 'x')
        base = "0123456789abcdef";
    else
        base = "0123456789ABCDEF";
    if (n >= 16)
        len += ft_putnbr_hex(n / 16, format);
    len += ft_putchar(base[n % 16]);
    return len;
}