#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list args;
	int len;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_handle_format(*format, args, &len);
		}
		else
			ft_putchar(*format, &len);
		format++;
	}
	va_end(args);
	return (len);
}