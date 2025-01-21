/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:04:46 by labia-fe          #+#    #+#             */
/*   Updated: 2025/01/19 23:10:38 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_struct *vars)
{
	//función de liberar memoria y tal :p
	exit(0);
}

int	init_process(t_struct *vars)
{
	if (!(vars->mlx = mlx_init(&vars)))
		return (-1);
	vars->win = mlx_new_window(vars->mlx, vars->map_x, vars->map_y, "Minecraft 2 a todo gas");
	vars->pos_x = 0;
	vars->pos_y = 0;
	vars->exit_x = 0;
	vars->exit_y = 0;
	vars->resolution = SIZE;
	vars->count = 0;
	vars->points = 0;
	vars->player = mlx_xpm_file_to_image(vars->mlx, "sprites/player-1R.xpm", &vars->resolution, &vars->resolution);
	vars->floor = mlx_xpm_file_to_image(vars->mlx, "sprites/floor.xpm", &vars->resolution, &vars->resolution);
	vars->exit = mlx_xpm_file_to_image(vars->mlx, "sprites/exit-no.xpm", &vars->resolution, &vars->resolution);
	vars->wall = mlx_xpm_file_to_image(vars->mlx, "sprites/wall.xpm", &vars->resolution, &vars->resolution);
	vars->coin = mlx_xpm_file_to_image(vars->mlx, "sprites/coin.xpm", &vars->resolution, &vars->resolution);
	return (0);
}

void	render_image(t_struct *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->player, vars->pos_x, vars->pos_y);
}

void	move_player(t_struct *vars, int incr_y, int incr_x)
{
	if (vars->map[((vars->pos_y + incr_y)/SIZE)][((vars->pos_x + incr_x)/SIZE)] != '1')
	{
		if (vars->map[((vars->pos_y + incr_y)/SIZE)][((vars->pos_x + incr_x)/SIZE)] == 'C')
		{
			vars->points -= 1;
			printf("COINS LEFT🪙:%i\n", vars->points);
		}
		mlx_put_image_to_window(vars->mlx, vars->win, vars->floor, vars->pos_x, vars->pos_y);
		vars->pos_x += incr_x;
		vars->pos_y += incr_y;
		render_image(vars);
	}
	else
		printf("BONK!🔨\n");
}

int	key_hook(int keycode, t_struct *vars)
{
	if (vars->points == 0 && (vars->pos_x == vars->exit_x) && (vars->pos_y == vars->exit_y))
	{
		printf("🏆!!!YOU WON!!!🏆\n");
		close_window(vars);
	}
	if (keycode == XK_Escape)
		close_window(vars);
	if (keycode == XK_d)
	{
		vars->player = mlx_xpm_file_to_image(vars->mlx, "sprites/player-1R.xpm", &vars->resolution, &vars->resolution);
		move_player(vars, 0, SIZE);
		vars->count += 1;
	}
	if (keycode == XK_a)
	{
		vars->player = mlx_xpm_file_to_image(vars->mlx, "sprites/player-1L.xpm", &vars->resolution, &vars->resolution);
		move_player(vars, 0, -SIZE);
		vars->count += 1;
	}
	if (keycode == XK_s)
	{
		move_player(vars, SIZE, 0);
		vars->count += 1;
	}
	if (keycode == XK_w)
	{
		move_player(vars, -SIZE, 0);
		vars->count += 1;
	}
	printf("counter: %d\n", vars->count);
	return (0);
}

int	main(int argc, char **argv)
{
	t_struct	vars;
	int	i;
	int	j;
	int fd;

	if (argc != 2)
		return(printf("![ERROR]! Enter the map route as an argument\n"));
	j = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		return(printf("![ERROR]! Failed to load map :(\n"));
	map_meter(fd, &vars);
	init_process(&vars);
	read_map(&vars);
	mlx_hook(vars.win, 17, 0, close_window, NULL);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
