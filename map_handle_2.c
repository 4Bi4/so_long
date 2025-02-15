/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handle_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:50:19 by labia-fe          #+#    #+#             */
/*   Updated: 2025/02/15 18:20:16 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	flood_fill(t_struct *vars, int y, int x)
{
	int	coins;

	coins = 0;
	if (x < 0 || x >= (vars->map_x / SIZE) || y < 0 || y >= (vars->map_y / SIZE)
		|| vars->mapcpy[y][x] == '1' || vars->mapcpy[y][x] == 'F')
		return (0);
	if (vars->mapcpy[y][x] == 'E')
	{
		vars->exitable = true;
		return (0);
	}
	if (vars->mapcpy[y][x] == 'C')
	{
		vars->mapcpy[y][x] = 'F';
		coins = 1;
	}
	else
		vars->mapcpy[y][x] = 'F';
	coins += flood_fill(vars, y, x + 1);
	coins += flood_fill(vars, y + 1, x);
	coins += flood_fill(vars, y, x - 1);
	coins += flood_fill(vars, y - 1, x);
	return (coins);
}

int	ff(t_struct *vars)
{
	int	coins;

	vars->exitable = false;
	coins = 0;
	coins = flood_fill(vars, (vars->pos_y / SIZE), (vars->pos_x / SIZE));
	if (coins != vars->points || vars->exitable == false)
		return (-1);
	return (0);
}

int	checker_1(t_struct *vars)
{
	if (vars->mapcpy[vars->j][vars->i] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->floor, (vars->i
				* SIZE), (vars->j * SIZE));
	if (vars->mapcpy[vars->j][vars->i] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wall, (vars->i
				* SIZE), (vars->j * SIZE));
	if (vars->mapcpy[vars->j][vars->i] == 'P')
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
	if (vars->mapcpy[vars->j][vars->i] == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->coin, (vars->i
				* SIZE), (vars->j * SIZE));
		vars->points += 1;
	}
	if (vars->mapcpy[vars->j][vars->i] == 'E')
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
	while (vars->mapcpy[vars->j])
	{
		vars->i = 0;
		while (vars->mapcpy[vars->j][vars->i])
		{
			player_count += checker_1(vars);
			exit_count += checker_2(vars);
			vars->i++;
		}
		vars->j++;
	}
	if (player_count != 1 || exit_count != 1)
		return (-1);
	ft_printf("TOTAL COINS🪙: %i\n", vars->points);
	return (0);
}
