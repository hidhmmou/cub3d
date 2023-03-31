/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 03:09:37 by ramhouch          #+#    #+#             */
/*   Updated: 2023/03/31 02:58:50 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

// static int	wall_collisions_x(t_cub3d *cub3d)
// {
// 	if (cub3d->map->square_map[((int)cub3d->draw.y - 1) / SIZE] \
// 		[((int)cub3d->draw.x) / SIZE] != '1' && \
// 		cub3d->map->square_map[((int)cub3d->draw.y + 1) / SIZE] \
// 		[((int)cub3d->draw.x + 1) / SIZE] == '1')
// 	{
// 		return (cub3d->colors.w);
// 	}
// 	else if (cub3d->map->square_map[((int)cub3d->draw.y + 1) / SIZE] \
// 		[((int)cub3d->draw.x) / SIZE] != '1' && \
// 		cub3d->map->square_map[((int)cub3d->draw.y - 1) / SIZE] \
// 		[((int)cub3d->draw.x + 1) / SIZE] == '1')
// 	{
// 		return (cub3d->colors.n);
// 	}
// 	return (0);
// }

// static int	wall_collisions_y(t_cub3d *cub3d)
// {
// 	if (cub3d->map->square_map[((int)cub3d->draw.y) / SIZE] \
// 		[((int)cub3d->draw.x + 1) / SIZE] != '1' && \
// 		cub3d->map->square_map[((int)cub3d->draw.y - 1) / SIZE] \
// 		[((int)cub3d->draw.x - 1) / SIZE] == '1')
// 	{
// 		return (cub3d->colors.s);
// 	}
// 	else if (cub3d->map->square_map[((int)cub3d->draw.y) / SIZE] \
// 		[((int)cub3d->draw.x - 1) / SIZE] != '1' && \
// 		cub3d->map->square_map[((int)cub3d->draw.y - 1) / SIZE] \
// 		[((int)cub3d->draw.x + 1) / SIZE] == '1')
// 	{
// 		return (cub3d->colors.e);
// 	}
// 	return (0);
// }

int	inter(t_cub3d *cub3d)
{
	if (cub3d->draw.color == 1)
	{
		if (cub3d->map->player.x - cub3d->draw.x > 0)
			return (cub3d->colors.n);
		return (cub3d->colors.s);
	}
	if (cub3d->draw.color == 3)
	{
		if (cub3d->map->player.y - cub3d->draw.y > 0)
			return (cub3d->colors.w);
		return (cub3d->colors.e);
	}
	return (0);
	// if (wall_collisions_y(cub3d))
	// 	return (wall_collisions_y(cub3d));
	// return (wall_collisions_x(cub3d));
}
