/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_things_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:38:52 by labia-fe          #+#    #+#             */
/*   Updated: 2024/10/29 14:49:24 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexadecimal(unsigned long long nb, char *base)
{
	int	count;

	count = 0;
	if (nb >= 16)
	{
		count += ft_putnbr_hexadecimal(nb / 16, base);
		count += ft_putchar(base[nb % 16]);
	}
	else
		count += ft_putchar(base[nb]);
	return (count);
}

int	ft_putptr(unsigned long long nb)
{
	char	*base;
	int		count;

	count = 2;
	base = "0123456789abcdef";
	if (nb == '\0')
		return (write(1, "(nil)", 5));
	ft_putstr("0x");
	if (nb >= 16)
	{
		count += ft_putnbr_hexadecimal((nb / 16), base);
		count += ft_putchar(base[nb % 16]);
	}
	else
		count += ft_putchar(base[nb]);
	return (count);
}
