/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 05:56:20 by labia-fe          #+#    #+#             */
/*   Updated: 2025/01/25 18:31:07 by labia-fe         ###   ########.fr       */
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
				vars->pos_y = j * SIZE;
			}
			if (vars->map[j][i] == 'C')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->coin, (i * SIZE), (j * SIZE));
				vars->points += 1;
			}
			if (vars->map[j][i] == 'E')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->exit_no, (i * SIZE), (j * SIZE));
				vars->exit_x = i * SIZE;
				vars->exit_y = j * SIZE;
			}
			i++;
		}
		j++;
	}
	printf("TOTAL COINS🪙: %i\n", vars->points);
}
int	is_square(t_struct *vars)
{
	int	i;
	int	j;
	int	max_i;

	j = 0;
	max_i = 0;
	while (vars->map[j])
	{
		i = 0;
		while (vars->map[j][i])
			i++;
		if (i != max_i && max_i > 0)
			return (-1);
		max_i = i;
		j++;
	}
}

int	map_check(t_struct *vars)
{
	int	error;
	
	error = is_square(vars);
	if (error != 0)
	{
		printf("¡[ERROR]! Map is not Rectangular\n");
		return (-1);
	}
		printf("Map is good 👍\n🕒Loading...\n");
		return (0);
}

