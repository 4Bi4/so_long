/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:04:46 by labia-fe          #+#    #+#             */
/*   Updated: 2024/12/18 17:00:36 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_struct *vars)
{
	exit(0);
}
int	init_process(t_struct *vars)
{
	if(!(vars->mlx = mlx_init(&vars)))
		return (-1);
	if (!(vars->win = mlx_new_window(vars->mlx, 1600, 900, "Quemando Rastrojos")))
		return (-1);
	vars->pos_x = 0;
	vars->pos_y = 0;
	vars->pixels = 64;
	vars->player = malloc(sizeof(void *));
	vars->player = mlx_xpm_file_to_image(vars->mlx, "./sprites/Player-1L.xpm", &vars->pixels, &vars->pixels);
}

int	key_hook(int keycode, t_struct *vars)
{
	if (keycode == XK_Escape)
		close_window(vars);
}

void	render_image(t_struct *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->player, vars->pos_x, vars->pos_y);
}

int main(void)
{
	t_struct	vars;

	init_process(&vars);
	render_image(&vars);
	mlx_hook(vars.win, 17, 0, close_window, NULL);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
