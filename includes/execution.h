/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:34:46 by ramhouch          #+#    #+#             */
/*   Updated: 2023/03/26 16:39:13 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H
# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../includes/parsing.h"

# define ROTATE_ANGLE 5
# define P 3.14159265
# define SPEED 5

int     press(int key, t_cub3d *cub3d);
int     close_window(t_cub3d *cub3d);
void	render_map_2d(t_cub3d *cub3d);
void	render_player(t_cub3d *cub3d);
void    put_player(t_cub3d *cub3d, float *tmp);
void	cast_mid_ray(t_cub3d *cub3d);
int     check_hit_wall(t_cub3d *cub3d, float pixel_y, float pixel_x);
void	init_draw(t_cub3d *cub3d);
void	move_up(t_cub3d *cub3d);
void	move_down(t_cub3d *cub3d);
void	move_left(t_cub3d *cub3d);
void	move_right(t_cub3d *cub3d);
void    check_direction(t_cub3d *cub3d, float y, float x);

#endif
