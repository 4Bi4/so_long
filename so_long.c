/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:04:46 by labia-fe          #+#    #+#             */
/*   Updated: 2025/02/12 15:37:15 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_struct *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
	exit(0);
}

int	init_process(t_struct *vars)
{
	vars->mlx = mlx_init(&vars);
	vars->win = mlx_new_window(vars->mlx, vars->map_x, vars->map_y,
			"Minecraft 2 a todo gas");
	vars->pos_x = 0;
	vars->pos_y = 0;
	vars->exit_x = 0;
	vars->exit_y = 0;
	vars->resolution = SIZE;
	vars->count = 0;
	vars->points = 0;
	vars->player = mlx_xpm_file_to_image(vars->mlx, "sprites/player-1R.xpm",
			&vars->resolution, &vars->resolution);
	vars->floor = mlx_xpm_file_to_image(vars->mlx, "sprites/floor.xpm",
			&vars->resolution, &vars->resolution);
	vars->exit_no = mlx_xpm_file_to_image(vars->mlx, "sprites/exit-no.xpm",
			&vars->resolution, &vars->resolution);
	vars->exit_yes = mlx_xpm_file_to_image(vars->mlx, "sprites/exit-yes.xpm",
			&vars->resolution, &vars->resolution);
	vars->wall = mlx_xpm_file_to_image(vars->mlx, "sprites/wall.xpm",
			&vars->resolution, &vars->resolution);
	vars->coin = mlx_xpm_file_to_image(vars->mlx, "sprites/coin.xpm",
			&vars->resolution, &vars->resolution);
	vars->exit = false;
	return (0);
}

void	move_player(t_struct *vars, int incr_y, int incr_x)
{
	int		new_y;
	int		new_x;
	char	cell;

	new_y = (vars->pos_y + incr_y) / SIZE;
	new_x = (vars->pos_x + incr_x) / SIZE;
	cell = vars->map[new_y][new_x];
	if (cell == '1')
		return ;
	if (cell == 'E' && vars->points == 0)
		close_window(vars);
	if (cell == 'C')
	{
		vars->points--;
		vars->map[new_y][new_x] = '0';
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->floor, vars->pos_x,
		vars->pos_y);
	vars->pos_x += incr_x;
	vars->pos_y += incr_y;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->player, vars->pos_x,
		vars->pos_y);
	printf("counter: %zu\n", ++vars->count);
}

void	key_hook(int keycode, t_struct *vars)
{
	if (vars->points == 0 && vars->exit == false)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exit_yes,
			vars->exit_x, vars->exit_y);
		printf("THE GATES HAVE BEEN OPENED!🟣\n");
		vars->exit = true;
	}
	if (keycode == XK_Escape)
		close_window(vars);
	if (keycode == XK_d)
	{
		vars->player = mlx_xpm_file_to_image(vars->mlx, "sprites/player-1R.xpm",
				&vars->resolution, &vars->resolution);
		move_player(vars, 0, SIZE);
	}
	if (keycode == XK_a)
	{
		vars->player = mlx_xpm_file_to_image(vars->mlx, "sprites/player-1L.xpm",
				&vars->resolution, &vars->resolution);
		move_player(vars, 0, -SIZE);
	}
	if (keycode == XK_s)
		move_player(vars, SIZE, 0);
	if (keycode == XK_w)
		move_player(vars, -SIZE, 0);
}

int	main(int argc, char **argv)
{
	t_struct	vars;
	int			fd;
	int			error;

	if (argc != 2)
		return (printf("¡[ERROR]! Enter the map route as an argument\n"));
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		return (printf("¡[ERROR]! Failed to load map :(\n"));
	map_meter(fd, &vars);
	init_process(&vars);
	error = map_check(&vars);
	if (error != 0)
		close_window(&vars);
	mlx_hook(vars.win, 17, 0, close_window, NULL);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
