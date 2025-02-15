/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:04:46 by labia-fe          #+#    #+#             */
/*   Updated: 2025/02/15 21:13:59 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	close_window(t_struct *vars)
{
	clean_mtrx(vars->map);
	clean_mtrx(vars->mapcpy);
	clean_imgs(vars);
	if (vars->win)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = NULL;
	}
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		vars->mlx = NULL;
	}
	exit(0);
}

int	init_process(t_struct *vars)
{
	vars->mlx = mlx_init(&vars);
	vars->pos_x = 0;
	vars->pos_y = 0;
	vars->exit_x = 0;
	vars->exit_y = 0;
	vars->resolution = SIZE;
	vars->count = 0;
	vars->points = 0;
	vars->player_r = NULL;
	vars->player_l = NULL;
	vars->floor = NULL;
	vars->exit_no = NULL;
	vars->exit_yes = NULL;
	vars->wall = NULL;
	vars->coin = NULL;
	if (load_img(vars) < 0)
	{
		write(2, "[ERROR]: Can't load texture.\n", 30);
		close_window(vars);
	}
	vars->player = vars->player_r;
	vars->exit = false;
	vars->win = mlx_new_window(vars->mlx, vars->map_x, vars->map_y,
			"Minecraft 2 a todo gas");
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
	if (cell == 'E' && vars->points == 0)
		close_window(vars);
	if (cell == '1' || cell == 'E')
		return ;
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
	ft_printf("counter: %d\n", (int)++vars->count);
}

int	key_hook(int keycode, t_struct *vars)
{
	if (vars->points == 0 && vars->exit == false)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exit_yes,
			vars->exit_x, vars->exit_y);
		ft_printf("THE GATES HAVE BEEN OPENED!🟣\n");
		vars->exit = true;
	}
	if (keycode == XK_Escape)
		close_window(vars);
	if (keycode == XK_d || keycode == XK_Right)
	{
		vars->player = vars->player_r;
		move_player(vars, 0, SIZE);
	}
	if (keycode == XK_a || keycode == XK_Left)
	{
		vars->player = vars->player_l;
		move_player(vars, 0, -SIZE);
	}
	if (keycode == XK_s || keycode == XK_Down)
		move_player(vars, SIZE, 0);
	if (keycode == XK_w || keycode == XK_Up)
		move_player(vars, -SIZE, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_struct	vars;
	int			fd;
	int			error;

	if (argc != 2)
		return (write(2, "¡[ERROR]! Enter the map route as an argument\n", 47),
			-1);
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		return (write(2, "¡[ERROR]! Failed to load map :(\n", 34), -1);
	map_meter(fd, &vars);
	init_process(&vars);
	close(fd);
	error = map_check(&vars);
	if (error != 0)
		close_window(&vars);
	mlx_hook(vars.win, 17, 0, close_window, NULL);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
