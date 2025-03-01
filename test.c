/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:42:04 by labia-fe          #+#    #+#             */
/*   Updated: 2025/02/12 15:37:40 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>

int	close(void *p)
{
	(void)p;
	exit(0);
}

int	main(void)
{
	void	*mlx;
	void	*window;
	size_t	i;
	size_t	j;

	i = 300;
	j = 600;
	mlx = mlx_init();
	if (!mlx)
		return (1);
	window = mlx_new_window(mlx, 1600, 900, "Quemando Rastrojos");
	if (!window)
		return (1);
	mlx_hook(window, 17, 0, close, NULL);
	mlx_string_put(mlx, window, 763, 150, 0xFFFFF, "Testing...");
	while (j <= 1000)
	{
		i = 300;
		while (i <= 600)
			mlx_pixel_put(mlx, window, j, i++, 0xAB7BA4);
		j++;
	}
	mlx_loop(mlx);
	return (0);
}
