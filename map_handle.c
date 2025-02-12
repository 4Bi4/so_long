/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 05:56:20 by labia-fe          #+#    #+#             */
/*   Updated: 2025/02/09 22:54:48 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_meter(int fd, t_struct *vars)
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
		j++;
	while (vars->map[0][i])
		i++;
	vars->map_x = i * SIZE;
	vars->map_y = j * SIZE;
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
	int	error;

	error = is_square(vars);
	if (error != 0)
	{
		printf("¡[ERROR]! Map is not Rectangular\n");
		return (-1);
	}
	error = wall_check(vars);
	if (error != 0)
	{
		printf("¡[ERROR]! Map is not Surrounded by walls\n");
		return (-1);
	}
	error = read_map(vars);
	if (error != 0)
	{
		printf("¡[ERROR DE LA MUERTE]! Wrong number of Player/s or Exit/s💀💀\n");
		return (-1);
	}
	printf("Map is good 👍\n🕒Loading...\n");
	return (0);
}
