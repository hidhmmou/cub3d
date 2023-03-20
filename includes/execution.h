/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:34:46 by ramhouch          #+#    #+#             */
/*   Updated: 2023/03/20 23:23:44 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H
# include "../includes/parsing.h"

# define HEIGHT 720
# define WIDTH 1080
# define PI 3.14159265
# define TWO_PI 6.2831853
# define VEW_ANGLE 60
# define NUM_RAYS WIDTH
# define SPEED 10
# define RET_ANGLE 5
# define SIZE 32

int		press(int key, t_cub3d *cub3d);
int		close_window(t_cub3d *cub3d);
void	k21(char **str);
void	render_map(t_cub3d *cub3d, int x, int y, int i);
int		get_color(char *text);
void	up(t_cub3d *cub3d, int dx, int dy, int i);
void	left(t_cub3d *cub3d, int dx, int dy, int i);
void	right(t_cub3d *cub3d, int dx, int dy, int i);
void	down(t_cub3d *cub3d, int dx, int dy, int i);
void	wall_collisions(t_cub3d *cub3d, float *increment2);
#endif
