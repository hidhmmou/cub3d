/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:34:46 by ramhouch          #+#    #+#             */
/*   Updated: 2023/03/21 18:17:55 by hidhmmou         ###   ########.fr       */
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

# define WIDTH 1080
# define ROTATE_ANGLE 5

int     press(int key, t_cub3d *cub3d);
int     close_window(t_cub3d *cub3d);
void	render_map_2d(t_cub3d *cub3d);
void	render_player(t_cub3d *cub3d);
void    put_center_view(t_cub3d *cub3d, float *tmp, float pixel_x, float pixel_y);
#endif
