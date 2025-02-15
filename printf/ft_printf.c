/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:20:50 by labia-fe          #+#    #+#             */
/*   Updated: 2024/10/30 12:50:20 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %c single character.
// %s string (multiple characters).
// %p pointer (void *) printed in hexadecimal.
// %i number (base 10).
// %d decimal number (base 10).
// %u unsigned decimal number (base 10).
// %x hexadecimal number (base 16) in lowercase.
// %X hexadecimal number (base 16) in uppercase.
// %% print the "%" symbol.

int	ft_type_detect(va_list parameters, char full_str)
{
	int		count;

	count = 0;
	if (full_str == 'c')
		count += ft_putchar(va_arg(parameters, int));
	else if (full_str == 's')
		count += ft_putstr(va_arg(parameters, char *));
	else if (full_str == 'p')
		count += ft_putptr(va_arg(parameters, unsigned long long int));
	else if (full_str == 'i')
		count += ft_putnbr(va_arg(parameters, int));
	else if (full_str == 'd')
		count += ft_putnbr(va_arg(parameters, int));
	else if (full_str == 'u')
		count += ft_putnbr_unsigned(va_arg(parameters, unsigned int));
	else if (full_str == 'x')
		count += ft_putnbr_hexadecimal(va_arg(parameters, unsigned int),
				"0123456789abcdef");
	else if (full_str == 'X')
		count += ft_putnbr_hexadecimal(va_arg(parameters, unsigned int),
				"0123456789ABCDEF");
	else if (full_str == '%')
		count += ft_putchar(full_str);
	return (count);
}

int	ft_printf(char const *str, ...)
{
	va_list	parameters;
	int		count;

	count = 0;
	va_start(parameters, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += ft_type_detect(parameters, *str);
			if (*str)
				str++;
		}
		else
			count += ft_putchar(*str++);
	}
	va_end(parameters);
	return (count);
}
