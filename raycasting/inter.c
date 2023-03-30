/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 03:09:37 by ramhouch          #+#    #+#             */
/*   Updated: 2023/03/29 02:52:04 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

static int	wall_x(t_cub3d *cub3d, float *increment2)
{
	if (cub3d->map->square_map[((int)increment2[1] - 1) / SIZE] \
		[((int)increment2[0]) / SIZE] != '1' && \
		cub3d->map->square_map[((int)increment2[1] + 1) / SIZE] \
		[((int)increment2[0] + 1) / SIZE] == '1')
	{
		return (1);
	}
	else if (cub3d->map->square_map[((int)increment2[1] + 1) / SIZE] \
		[((int)increment2[0]) / SIZE] != '1' && \
		cub3d->map->square_map[((int)increment2[1] - 1) / SIZE] \
		[((int)increment2[0] + 1) / SIZE] == '1')
	{
		return (2);
	}
	return (0);
}

static int	wall_y(t_cub3d *cub3d, float *increment2)
{
	if (cub3d->map->square_map[((int)increment2[1]) / SIZE] \
		[((int)increment2[0] + 1) / SIZE] != '1' && \
		cub3d->map->square_map[((int)increment2[1] - 1) / SIZE] \
		[((int)increment2[0] - 1) / SIZE] == '1')
	{
		return (3);
	}
	else if (cub3d->map->square_map[((int)increment2[1]) / SIZE] \
		[((int)increment2[0] - 1) / SIZE] != '1' && \
		cub3d->map->square_map[((int)increment2[1] - 1) / SIZE] \
		[((int)increment2[0] + 1) / SIZE] == '1')
	{
		return (4);
	}
	return (0);
}

int	inter(t_cub3d *cub3d, float *increment2)
{
	if (wall_y(cub3d, increment2))
		return (wall_y(cub3d, increment2));
	return (wall_x(cub3d, increment2));
}
