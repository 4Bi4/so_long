/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:27:20 by labia-fe          #+#    #+#             */
/*   Updated: 2025/01/19 22:12:01 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <stdio.h>

# define SIZE 64

typedef struct s_struct
{
	int		resolution;
	void	*mlx;
	void	*win;

	void	*player;
	int		pos_x;
	int		pos_y;
	int		count;

	int		points;

	int		map_x;
	int		map_y;
	int		exit_x;
	int		exit_y;
	char	**map;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*coin;

}	t_struct;

char	**ft_split(char const *s, char c);
void	map_meter(int fd, t_struct *vars);
void	read_map(t_struct *vars);

#endif