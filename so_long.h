/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:27:20 by labia-fe          #+#    #+#             */
/*   Updated: 2025/02/12 21:02:00 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <X11/keysym.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SIZE 64
# define BUFFER 1024

typedef struct s_struct
{
	int		resolution;
	void	*mlx;
	void	*win;

	void	*player;
	int		pos_x;
	int		pos_y;
	size_t	count;

	int		points;

	int		map_x;
	int		map_y;
	int		exit_x;
	int		exit_y;
	bool	exit;
	char	**map;
	void	*floor;
	void	*wall;
	void	*exit_no;
	void	*exit_yes;
	void	*coin;

	int		i;
	int		j;

}			t_struct;

char		**ft_split(char const *s, char c);

int			map_check(t_struct *vars);
int			read_map(t_struct *vars);

void		map_meter(int fd, t_struct *vars);

#endif