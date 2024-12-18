/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:27:20 by labia-fe          #+#    #+#             */
/*   Updated: 2024/12/18 18:26:03 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <X11/keysym.h>

# define SIZE 64

typedef struct s_struct
{
	int		pixels;
	void	*mlx;
	void	*win;

	void	*player;
	int		pos_x;
	int		pos_y;

}	t_struct;

#endif