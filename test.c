#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>

char *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return (char *)s;
        s++;
    }
    return (c == '\0') ? (char *)s : NULL;
}

int ft_putchar(char c)
{
    return write(1, &c, 1);
}

int ft_putstr(char *str)
{
    int len = 0;
    if (!str)
        return write(1, "(null)", 6);
    while (*str)
        len += ft_putchar(*str++);
    return len;
}

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

int ft_putnbr_hex(unsigned int n, char format)
{
    int len = 0;
    char *base;

    base = (format == 'x') ? "0123456789abcdef" : "0123456789ABCDEF";
    if (n >= 16)
        len += ft_putnbr_hex(n / 16, format);
    len += ft_putchar(base[n % 16]);
    return len;
}

int ft_putadd(unsigned long ptr)
{
    int len = 0;

    len += ft_putstr("0x");
    if (ptr == 0)
        len += ft_putchar('0');
    else
        len += ft_putnbr_hex(ptr, 'x');
    return len;
}

int ft_printconversions(const char **s, va_list args)
{
    int len = 0;

    if (**s == 'c')
    {
        char c = (char)va_arg(args, int);
        len += ft_putchar(c);
    }
    else if (**s == 's')
    {
        char *str = va_arg(args, char *);
        if (!str)
            len += ft_putstr("(null)");
        else
            len += ft_putstr(str);
    }
    else if (**s == 'p')
        len += ft_putadd(va_arg(args, unsigned long));
    else if (**s == 'd' || **s == 'i')
        len += ft_putnbr(va_arg(args, int));
    else if (**s == 'u')
        len += ft_putnbr_unsigned(va_arg(args, unsigned int));
    else if (**s == 'x' || **s == 'X')
        len += ft_putnbr_hex(va_arg(args, unsigned int), **s);
    else if (**s == '%')
        len += ft_putchar('%');
    (*s)++;
    return len;
}

int ft_printf(const char *s, ...)
{
    int len = 0;
    va_list args;

    va_start(args, s);
    while (*s)
    {
        if (*s == '%')
        {
            s++;
            if (*s && ft_strchr("disuxXcp%", *s))
                len += ft_printconversions(&s, args);
            else
            {
                len += ft_putchar('%');
                if (*s)
                    len += ft_putchar(*s++);
            }
        }
        else
            len += ft_putchar(*s++);
    }
    va_end(args);
    return len;
}

int main(void)
{
    ft_printf("Number: %d, HexLow: %x, HexUPP: %X, Number: %d, HexLow: %x, HexUPP: %X  \n", 21, 21, 21, 42, 42, 42);
    ft_printf("Number: %d, HexLow: %x, HexUPP: %X, Number: %d, HexLow: %x, HexUPP: %X  \n", 42, 42, 42, 21, 21, 21);
    ft_printf("Char: %c, String: %s, Number: %d, HexLow: %x, HexUPP: %X \n", 'A', "Hello there", 42, 42, 42);
    ft_printf("Number: %d, HexLow: %x, HexUPP: %X, Char: %c, String: %s \n", 42, 42, 42, 'A', "Hello there");
    return (0);
}
