#include "ft_printf.h"

void ft_handle_format(char format, va_list args, int *len)
{
	if (format == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (format == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (format == 'p')
	{
		ft_putstr("0x", len);
		ft_putnbr_base(va_arg(args, unsigned long),
					   "0123456789abcdef", 16, len);
	}
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if (format == 'u')
		ft_putnbr_base(va_arg(args, unsigned int),
					   "0123456789", 10, len);
	else if (format == 'x')
		ft_putnbr_base(va_arg(args, unsigned int),
					   "0123456789abcdef", 16, len);
	else if (format == 'X')
		ft_putnbr_base(va_arg(args, unsigned int),
					   "0123456789ABCDEF", 16, len);
	else if (format == '%')
		ft_putchar('%', len);
}