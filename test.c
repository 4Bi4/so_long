/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:42:04 by labia-fe          #+#    #+#             */
/*   Updated: 2024/12/13 23:17:26 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

int	close(void *p)
{
	(void)p;
	exit(0);
}

int main(void)
{
	void	*mlx;
	void	*window;
	size_t	i = 300;
	size_t	j = 600;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	window = mlx_new_window(mlx, 1600, 900, "Quemando Rastrojos");
	if (!window)
		return (1);
	mlx_hook(window, 17, 0, close, NULL);
	while (j <= 1000)
	{
		i = 300;
		while(i <= 600)
			mlx_pixel_put(mlx, window, j, i++, 0xAB7BA4);
		j++;
	}
	mlx_loop(mlx);
	return (0);
}