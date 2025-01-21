/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 05:56:20 by labia-fe          #+#    #+#             */
/*   Updated: 2025/01/19 22:14:01 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_meter(int fd, t_struct *vars)
{
	char	*buff;
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	buff = malloc(sizeof(char) * 1024);
	read(fd, buff, 1024);
	vars->map = ft_split(buff, '\n');
	free(buff);
	while (vars->map[j])
		j++;
	while (vars->map[0][i])
		i++;
	vars->map_x = i * SIZE;
	vars->map_y = j * SIZE;
	printf("Map size:%ix%i\n", vars->map_x, vars->map_y);
}

void	read_map(t_struct *vars)
{
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	while (vars->map[j])
	{
		i = 0;
		while (vars->map[j][i])
		{
			if (vars->map[j][i] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->floor, (i * SIZE), (j * SIZE));
			if (vars->map[j][i] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wall, (i * SIZE), (j * SIZE));
			if (vars->map[j][i] == 'P')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->player, (i * SIZE), (j * SIZE));
				vars->pos_x = i * SIZE;
				vars->pos_y = i * SIZE;
			}
			if (vars->map[j][i] == 'C')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->coin, (i * SIZE), (j * SIZE));
				vars->points += 1;
			}
			if (vars->map[j][i] == 'E')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->exit, (i * SIZE), (j * SIZE));
				vars->exit_x = i * SIZE;
				vars->exit_y = i * SIZE;
			}
			i++;
		}
		j++;
	}
	printf("TOTAL COINS🪙: %i\n", vars->points);
}
