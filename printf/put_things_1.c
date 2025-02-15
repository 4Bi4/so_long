/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_things_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:56:25 by labia-fe          #+#    #+#             */
/*   Updated: 2024/10/29 14:40:55 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	long int	num;
	int			count;

	num = nb;
	count = 0;
	if (num < 0)
	{
		num = num * -1;
		count += ft_putchar('-');
	}
	if (num > 9)
	{
		count += ft_putnbr(num / 10);
		count += ft_putchar((num % 10) + '0');
	}
	else
		count += ft_putchar(num + '0');
	return (count);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	unsigned int	num;
	int				count;

	num = nb;
	count = 0;
	if (num > 9)
	{
		count += ft_putnbr_unsigned(num / 10);
		count += ft_putchar((num % 10) + '0');
	}
	else
		count += ft_putchar(num + '0');
	return (count);
}
