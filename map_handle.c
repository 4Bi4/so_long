/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 05:56:20 by labia-fe          #+#    #+#             */
/*   Updated: 2024/12/21 18:52:38 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(int fd, t_struct *vars)
{
	char	*buff;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	buff = malloc(sizeof(char) * 1024);
	read(fd, buff, 1024);
	vars->map = ft_split(buff, '\n');
	free(buff);
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
			if (vars->map[j][i] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->exit, (i * SIZE), (j * SIZE));
			i++;
		}
		j++;
	}
}
