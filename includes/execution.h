/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:34:46 by ramhouch          #+#    #+#             */
/*   Updated: 2023/03/20 15:45:12 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../includes/parsing.h"

int     press(int key, t_cub3d *cub3d);
int     close_window(t_cub3d *cub3d);
void	render_map_2d(t_cub3d *cub3d);
#endif
