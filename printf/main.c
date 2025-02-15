/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:52:40 by labia-fe          #+#    #+#             */
/*   Updated: 2024/10/30 10:32:44 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int		nice;
	char	*oso;
	int		ret;
	char	*null;

	nice = 69;
	oso = "in the biningin";
	null = NULL;
	ret = ft_printf("TEST FT 0: sin ningún = %%\n");
	ft_printf("return %d\n", ret);
	ret = printf("TEST OG 0: sin ningún = %%\n");
	printf("return %d\n", ret);
	ret = ft_printf("TEST FT 1: string = %s\n", oso);
	ft_printf("return %d\n", ret);
	ret = printf("TEST OG 1: string = %s\n", oso);
	printf("return %d\n", ret);
	ret = ft_printf("TEST FT 2: void * en hexa = %p\n", oso);
	ft_printf("return %d\n", ret);
	ret = printf("TEST OG 2: void * en hexa = %p\n", oso);
	printf("return %d\n", ret);
	ret = ft_printf("TEST FT 3: numero = %i\n", nice);
	ft_printf("return %d\n", ret);
	ret = printf("TEST OG 3: numero = %i\n", nice);
	printf("return %d\n", ret);
	ret = ft_printf("TEST FT 4: decimal = %d\n", (nice / 10));
	ft_printf("return %d\n", ret);
    ret = printf("TEST OG 4: decimal = %d\n", (nice / 10));
	printf("return %d\n", ret);
	ret = ft_printf("TEST FT 5: unsigned decimal = %u\n", nice);
	ft_printf("return %d\n", ret);
	ret = printf("TEST OG 5: unsigned decimal = %u\n", nice);
	printf("return %d\n", ret);
	ret = ft_printf("TEST FT 6: hexadecimal = %x\n", nice);
	ft_printf("return %d\n", ret);
	ret = printf("TEST OG 6: hexadecimal = %x\n", nice);
	printf("return %d\n", ret);
	ret = ft_printf("TEST FT 7: HEXADECIMAL = %X\n", nice);
	ft_printf("return %d\n", ret);
	ret = printf("TEST OG 7: HEXADECIMAL = %X\n", nice);
	printf("return %d\n", ret);
	ret = ft_printf("TEST FT 8: string = %s\n", null);
	ft_printf("return %d\n", ret);
	ret = printf("TEST OG 8: string = %s\n", null);
	printf("return %d\n", ret);
	ret = ft_printf("TEST FT 9: void * en hexa = %p\n", null);
	ft_printf("return %d\n", ret);
	ret = printf("TEST OG 9: void * en hexa = %p\n", null);
	printf("return %d\n", ret);
	return (0);
}
