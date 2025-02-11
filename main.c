/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrisse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:50:17 by hrisse            #+#    #+#             */
/*   Updated: 2025/02/11 13:11:17 by hrisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	count;
	char	*ptr = "test";

	count = ft_printf("Character: %c\n", 'A');
	count += ft_printf("Printed %d characters\n", count);

	count += ft_printf("String: %s\n", "Hello World!");
	count += ft_printf("NULL string: %s\n", NULL);
	count += ft_printf("Empty string: %s\n", "");

	count += ft_printf("Pointer: %p\n", ptr);
	count +=ft_printf("NULL pointer: %p\n", NULL);

	count += ft_printf("Integer (%d): %d\n", 42, 42);
	count += ft_printf("Negative: %d\n", -42);
	count += ft_printf("Zero: %d\n", 0);
	count += ft_printf("INT_MAX: %d\n", INT_MAX);
	count += ft_printf("INT_MIN: %d\n", INT_MIN);

	count += ft_printf("Unsigned: %u\n", 42);
	count += ft_printf("Large unsigned: %u\n", UINT_MAX);

	count = ft_printf("Hex (lowercase): %x\n", 255);
	count += ft_printf("Hex (uppercase): %X\n", 255);
	count += ft_printf("Hex zero: %x\n", 0);

	count += ft_printf("Percent sign: %%\n");

	count += ft_printf("  Multiple : %c %s %p %d %i %u %x %X %%\n",'A', "test", ptr, 42, -21, 42, 21, 42);
	printf("real printf: %c %s %p %d %i %u %x %X %%\n",'A', "test", ptr, 42, -21, 42, 21, 42);
	printf("Printed %d characters in total\n", count);
	return (0);
}
