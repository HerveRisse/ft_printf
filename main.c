#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int count;
	char *ptr = "test";

	count = ft_printf("Character: %c\n", 'A');
	ft_printf("Printed %d characters\n", count);

	count = ft_printf("String: %s\n", "Hello World!");
	ft_printf("NULL string: %s\n", NULL);
	ft_printf("Empty string: %s\n", "");

	count = ft_printf("Pointer: %p\n", ptr);
	ft_printf("NULL pointer: %p\n", NULL);

	count = ft_printf("Integer (%%d): %d\n", 42);
	ft_printf("Negative: %d\n", -42);
	ft_printf("Zero: %d\n", 0);
	ft_printf("INT_MAX: %d\n", INT_MAX);
	ft_printf("INT_MIN: %d\n", INT_MIN);

	count = ft_printf("Unsigned: %u\n", 42);
	ft_printf("Large unsigned: %u\n", UINT_MAX);

	count = ft_printf("Hex (lowercase): %x\n", 255);
	ft_printf("Hex (uppercase): %X\n", 255);
	ft_printf("Hex zero: %x\n", 0);

	count = ft_printf("Percent sign: %%\n");

	count = ft_printf("Multiple: %c %s %p %d %i %u %x %X %%\n",
					  'A', "test", ptr, 42, -42, 42, 42, 42);
	ft_printf("Printed %d characters in total\n", count);

	return (0);
}