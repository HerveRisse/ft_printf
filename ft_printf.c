#include "ft_printf.h"

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
        len += ft_putptr(va_arg(args, unsigned long));
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
    ft_printf("Char test: %c\n", 'A');
    ft_printf("Char test: %c\n", 'Z');

    ft_printf("String test: %s\n", "Hello there");
    ft_printf("NULL String test: %s\n", NULL);

    ft_printf("Number: %d, HexLow: %x, HexUPP: %X\n", 42, 42, 42);
    ft_printf("Pointer test: %p\n", (void *)0x12345678);
    ft_printf("Percent test: %%\n");

    ft_printf("Number: %d, HexLow: %x, HexUPP: %X, Char: %c, String: %s \n", 42, 42, 42, 'A', "Hello there");
    return (0);
}
