/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:27:20 by labia-fe          #+#    #+#             */
/*   Updated: 2024/12/22 15:23:18 by labia-fe         ###   ########.fr       */
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

	char	**map;
	void	*floor;
	void	*wall;
	void	*exit;

}	t_struct;

char	**ft_split(char const *s, char c);
void	read_map(int fd, t_struct *vars);

#endif