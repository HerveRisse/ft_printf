#include "ft_printf.h"

int ft_putnbr(int n)
{
    int len = 0;
    char c;

    if (n == -2147483648)
        return ft_putstr("-2147483648");
    if (n < 0)
    {
        len += ft_putchar('-');
        n = -n;
    }
    if (n > 9)
        len += ft_putnbr(n / 10);
    c = (n % 10) + '0';
    len += ft_putchar(c);
    return len;
}