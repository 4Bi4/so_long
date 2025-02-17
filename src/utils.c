/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:11:03 by labia-fe          #+#    #+#             */
/*   Updated: 2025/02/17 16:04:32 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	clean_mtrx(char **mtrx)
{
	int	i;

	if (mtrx)
	{
		i = 0;
		while (mtrx[i])
		{
			free(mtrx[i]);
			i++;
		}
		free(mtrx);
	}
}

void	clean_imgs(t_struct *vars)
{
	if (vars->player_r)
		mlx_destroy_image(vars->mlx, vars->player_r);
	if (vars->player_l)
		mlx_destroy_image(vars->mlx, vars->player_l);
	if (vars->floor)
		mlx_destroy_image(vars->mlx, vars->floor);
	if (vars->exit_no)
		mlx_destroy_image(vars->mlx, vars->exit_no);
	if (vars->exit_yes)
		mlx_destroy_image(vars->mlx, vars->exit_yes);
	if (vars->wall)
		mlx_destroy_image(vars->mlx, vars->wall);
	if (vars->coin)
		mlx_destroy_image(vars->mlx, vars->coin);
}

int	load_img(t_struct *vars)
{
	vars->player_r = mlx_xpm_file_to_image(vars->mlx, "./sprites/player-1R.xpm",
			&vars->resolution, &vars->resolution);
	if (!vars->player_r)
		return (-1);
	vars->player_l = mlx_xpm_file_to_image(vars->mlx, "./sprites/player-1L.xpm",
			&vars->resolution, &vars->resolution);
	if (!vars->player_l)
		return (-1);
	vars->floor = mlx_xpm_file_to_image(vars->mlx, "./sprites/floor.xpm",
			&vars->resolution, &vars->resolution);
	if (!vars->floor)
		return (-1);
	if (load_img2(vars) < 0)
		return (-1);
	return (0);
}

int	load_img2(t_struct *vars)
{
	vars->exit_no = mlx_xpm_file_to_image(vars->mlx, "./sprites/exit-no.xpm",
			&vars->resolution, &vars->resolution);
	if (!vars->exit_no)
		return (-1);
	vars->exit_yes = mlx_xpm_file_to_image(vars->mlx, "./sprites/exit-yes.xpm",
			&vars->resolution, &vars->resolution);
	if (!vars->exit_yes)
		return (-1);
	vars->wall = mlx_xpm_file_to_image(vars->mlx, "./sprites/wall.xpm",
			&vars->resolution, &vars->resolution);
	if (!vars->wall)
		return (-1);
	vars->coin = mlx_xpm_file_to_image(vars->mlx, "./sprites/coin.xpm",
			&vars->resolution, &vars->resolution);
	if (!vars->coin)
		return (-1);
	return (0);
}
