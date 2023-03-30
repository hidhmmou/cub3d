/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 03:09:37 by ramhouch          #+#    #+#             */
/*   Updated: 2023/03/30 21:33:45 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

static int	wall_collisions_x(t_cub3d *cub3d)
{
	if (cub3d->map->square_map[((int)cub3d->draw.y - 1) / SIZE] \
		[((int)cub3d->draw.x) / SIZE] != '1' && \
		cub3d->map->square_map[((int)cub3d->draw.y + 1) / SIZE] \
		[((int)cub3d->draw.x + 1) / SIZE] == '1')
	{
		return (1);
	}
	else if (cub3d->map->square_map[((int)cub3d->draw.y + 1) / SIZE] \
		[((int)cub3d->draw.x) / SIZE] != '1' && \
		cub3d->map->square_map[((int)cub3d->draw.y - 1) / SIZE] \
		[((int)cub3d->draw.x + 1) / SIZE] == '1')
	{
		return (2);
	}
	return (0);
}

static int	wall_collisions_y(t_cub3d *cub3d)
{
	if (cub3d->map->square_map[((int)cub3d->draw.y) / SIZE] \
		[((int)cub3d->draw.x + 1) / SIZE] != '1' && \
		cub3d->map->square_map[((int)cub3d->draw.y - 1) / SIZE] \
		[((int)cub3d->draw.x - 1) / SIZE] == '1')
	{
		return (3);
	}
	else if (cub3d->map->square_map[((int)cub3d->draw.y) / SIZE] \
		[((int)cub3d->draw.x - 1) / SIZE] != '1' && \
		cub3d->map->square_map[((int)cub3d->draw.y - 1) / SIZE] \
		[((int)cub3d->draw.x + 1) / SIZE] == '1')
	{
		return (4);
	}
	return (0);
}

int	inter(t_cub3d *cub3d)
{
	if (wall_collisions_y(cub3d))
		return (wall_collisions_y(cub3d));
	return (wall_collisions_x(cub3d));
}
