/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:27:20 by labia-fe          #+#    #+#             */
/*   Updated: 2025/02/20 17:09:04 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <X11/keysym.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>

# include "../printf/ft_printf.h"

# define SIZE 64
# define BUFFER 9999

typedef struct s_struct
{
	int		resolution;
	void	*mlx;
	void	*win;

	void	*player;
	void	*player_r;
	void	*player_l;
	int		pos_x;
	int		pos_y;
	size_t	count;

	int		points;

	int		map_x;
	int		map_y;
	int		exit_x;
	int		exit_y;
	bool	exit;
	bool	exitable;
	char	**map;
	char	**mapcpy;
	void	*floor;
	void	*wall;
	void	*exit_no;
	void	*exit_yes;
	void	*coin;

	int		i;
	int		j;

}			t_struct;

char		**ft_split(char const *s, char c);

int			ff(t_struct *vars);
int			read_map(t_struct *vars);
int			load_img(t_struct *vars);
int			load_img2(t_struct *vars);
int			map_check(t_struct *vars);
int			map_meter(int fd, t_struct *vars);

void		clean_mtrx(char **mtrx);
void		clean_imgs(t_struct *vars);

#endif