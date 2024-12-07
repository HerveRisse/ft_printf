#include "ft_printf.h"

int ft_putptr(unsigned long ptr)
{
    int len = 0;

    len += ft_putstr("0x");
    if (ptr == 0)
        len += ft_putchar('0');
    else
        len += ft_putnbr_hex(ptr, 'x');
    return len;
}