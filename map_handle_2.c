/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handle_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:50:19 by labia-fe          #+#    #+#             */
/*   Updated: 2025/02/09 22:55:04 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checker_1(t_struct *vars)
{
	if (vars->map[vars->j][vars->i] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->floor, (vars->i
				* SIZE), (vars->j * SIZE));
	if (vars->map[vars->j][vars->i] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wall, (vars->i
				* SIZE), (vars->j * SIZE));
	if (vars->map[vars->j][vars->i] == 'P')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player, (vars->i
				* SIZE), (vars->j * SIZE));
		vars->pos_x = vars->i * SIZE;
		vars->pos_y = vars->j * SIZE;
		return (1);
	}
	return (0);
}

int	checker_2(t_struct *vars)
{
	if (vars->map[vars->j][vars->i] == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->coin, (vars->i
				* SIZE), (vars->j * SIZE));
		vars->points += 1;
	}
	if (vars->map[vars->j][vars->i] == 'E')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exit_no, (vars->i
				* SIZE), (vars->j * SIZE));
		vars->exit_x = vars->i * SIZE;
		vars->exit_y = vars->j * SIZE;
		return (1);
	}
	return (0);
}

int	read_map(t_struct *vars)
{
	int	player_count;
	int	exit_count;

	player_count = 0;
	exit_count = 0;
	vars->i = 0;
	vars->j = 0;
	while (vars->map[vars->j])
	{
		vars->i = 0;
		while (vars->map[vars->j][vars->i])
		{
			player_count += checker_1(vars);
			exit_count += checker_2(vars);
			vars->i++;
		}
		vars->j++;
	}
	if (player_count != 1 || exit_count != 1)
		return (-1);
	printf("TOTAL COINS🪙: %i\n", vars->points);
	return (0);
}
