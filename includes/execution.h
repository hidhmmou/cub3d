/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:34:46 by ramhouch          #+#    #+#             */
/*   Updated: 2023/03/16 22:12:40 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H
# include "../includes/parsing.h"

# define HEIGHT 720
# define WIDTH 1080
# define PI 3.14159265
# define TWO_PI 6.2831853
# define VEW_ANGLE (60 * (PI / 180))
# define NUM_RAYS WIDTH

int		press(int key, t_cub3d *cub3d);
int		close_window(t_cub3d *cub3d);
void 	k21(char **str);
void	render_map(t_cub3d *cub3d, int x, int y);
int	    get_color(char *text);
void	render_player(t_cub3d *cub3d);
#endif
