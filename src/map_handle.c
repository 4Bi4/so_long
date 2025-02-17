/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 05:56:20 by labia-fe          #+#    #+#             */
/*   Updated: 2025/02/17 16:05:00 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	map_meter(int fd, t_struct *vars)
{
	char	*buff;
	int		f;
	int		i;
	int		j;

	i = 0;
	j = 0;
	buff = (char *)malloc(sizeof(char) * (BUFFER + 1));
	if (!buff)
		return (-1);
	f = read(fd, buff, BUFFER);
	buff[f] = '\0';
	vars->map = ft_split(buff, '\n');
	vars->mapcpy = ft_split(buff, '\n');
	free(buff);
	if (!vars->map || !vars->mapcpy)
		return (-1);
	while (vars->map[j])
		j++;
	while (vars->map[0][i])
		i++;
	vars->map_x = i * SIZE;
	vars->map_y = j * SIZE;
	return (0);
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
	return (0);
}

int	wall_check(t_struct *vars)
{
	int	i;

	i = 0;
	while (i < (vars->map_x / SIZE))
	{
		if (vars->map[0][i] != '1' || vars->map[(vars->map_y / SIZE)
			- 1][i] != '1')
			return (-1);
		i++;
	}
	i = 0;
	while (i < (vars->map_y / SIZE))
	{
		if (vars->map[i][0] != '1' || vars->map[i][(vars->map_x / SIZE)
			- 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	map_check(t_struct *vars)
{
	if (is_square(vars))
		return (write(2, "¡[ERROR]! Map is not Rectangular\n", 35), -1);
	if (wall_check(vars))
		return (write(2, "¡[ERROR]! Map is not Surrounded by walls\n", 43), -1);
	if (read_map(vars))
		return (write(2, "¡[ERROR]! Wrong number of Player/s or Exit/s💀💀\n",
				55), -1);
	if (ff(vars))
		return (write(2,
				"¡[ERROR]! No valid path to coins or exit was found.\n", 54),
			-1);
	ft_printf("Map is good 👍\n🕒Loading...\n");
	return (0);
}
