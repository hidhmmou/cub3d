/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:34:46 by ramhouch          #+#    #+#             */
/*   Updated: 2023/03/29 06:55:29 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H
# include "../includes/parsing.h"

# define HEIGHT 720
# define WIDTH 1280
# define PI 3.14159265
# define TWO_PI 6.2831853
# define VEW_ANGLE 60
# define NUM_RAYS WIDTH
# define SPEED 10
# define RET_ANGLE 5
# define SIZE 32
# define ON2D 1
# define ON3D 0
# define COLLISIONS_SPEED 5

int		close_window(t_cub3d *cub3d);
void	render_map(t_cub3d *cub3d, int x, int y, int i);
int		get_color(char *text);
void	up(t_cub3d *cub3d, int dx, int dy, int i);
void	left(t_cub3d *cub3d, int dx, int dy, int i);
void	right(t_cub3d *cub3d, int dx, int dy, int i);
void	down(t_cub3d *cub3d, int dx, int dy, int i);
void	wall_collisions(t_cub3d *cub3d, float *increment2);
int		check_movements(t_cub3d *cub3d, int x, int y);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int     close_window3d(t_cub3d *cub3d);
int     inter(t_cub3d *cub3d, float *increment2);
void	raycasting(t_cub3d *cub3d, float a, float b);
int     help_draw_line(t_cub3d *cub3d, float *increment2);
void	up3d(t_cub3d *cub3d, int dx, int dy, int i);
void	left3d(t_cub3d *cub3d, int dx, int dy, int i);
void	right3d(t_cub3d *cub3d, int dx, int dy, int i);
void	down3d(t_cub3d *cub3d, int dx, int dy, int i);
#endif
