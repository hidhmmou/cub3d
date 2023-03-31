/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:34:46 by ramhouch          #+#    #+#             */
/*   Updated: 2023/03/31 03:16:41 by ramhouch         ###   ########.fr       */
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
# define SPEED 20
# define RET_ANGLE 4
# define SIZE 100
# define ON2D 0
# define ON3D 1

void    init(t_cub3d *cub3d);
int     close_window3d(t_cub3d *cub3d);
int	    close_window2d(t_cub3d *cub3d);
int     get_color(char *text);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	render_map(t_cub3d *cub3d, int x, int y, int i);
void	up(t_cub3d *cub3d, int x, int y);
void	down(t_cub3d *cub3d, int x, int y);
void	left(t_cub3d *cub3d, int x, int y);
void	right(t_cub3d *cub3d, int x, int y);
int     inter(t_cub3d *cub3d);
void	raycasting(t_cub3d *cub3d, int i);
int     check_movements(t_cub3d *cub3d, int x, int y);
void	up3d(t_cub3d *cub3d, int x, int y);
void	down3d(t_cub3d *cub3d, int x, int y);
void	left3d(t_cub3d *cub3d, int x, int y);
void	right3d(t_cub3d *cub3d, int x, int y);
int     key_hook(int keycode, t_cub3d *cub3d);
int     press(int keycode, t_cub3d *cub3d);
int     depress(int keycode, t_cub3d *cub3d);
int     action(t_cub3d *cub3d);

#endif
