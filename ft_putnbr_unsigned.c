#include "ft_printf.h"

int ft_putnbr_unsigned(unsigned int n)
{
    int len = 0;
    char c;

    if (n > 9)
        len += ft_putnbr_unsigned(n / 10);
    c = (n % 10) + '0';
    len += ft_putchar(c);
    return len;
}