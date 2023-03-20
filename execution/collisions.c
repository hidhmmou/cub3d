/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:18:07 by ramhouch          #+#    #+#             */
/*   Updated: 2023/03/20 22:29:14 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

static void	wall_collisions_y(t_cub3d *cub3d, float *increment2)
{
	if (cub3d->map->square_map[((int)increment2[1] - 1) / 32] \
		[((int)increment2[0]) / 32] == '0')
	{
		if (abs((cub3d->map->player.angle) % 180) > 90)
			cub3d->map->player.x += SPEED;
		else
			cub3d->map->player.x -= SPEED;
		render_map(cub3d, 0, 0, 0);
	}
	else if (cub3d->map->square_map[((int)increment2[1] + 1) / 32] \
		[((int)increment2[0]) / 32] == '0')
	{
		if (abs((cub3d->map->player.angle) % 180) > 90)
			cub3d->map->player.x -= SPEED;
		else
			cub3d->map->player.x += SPEED;
		render_map(cub3d, 0, 0, 0);
	}
}

static void	wall_collisions_x(t_cub3d *cub3d, float *increment2)
{
	if (cub3d->map->square_map[((int)increment2[1]) / 32] \
		[((int)increment2[0] + 1) / 32] == '0')
	{
		if (abs((cub3d->map->player.angle) % 180) > 90)
			cub3d->map->player.y -= SPEED;
		else
			cub3d->map->player.y += SPEED;
		render_map(cub3d, 0, 0, 0);
	}
	else if (cub3d->map->square_map[((int)increment2[1]) / 32] \
		[((int)increment2[0] - 1) / 32] == '0')
	{
		if (abs((cub3d->map->player.angle) % 180) > 90)
			cub3d->map->player.y += SPEED;
		else
			cub3d->map->player.y -= SPEED;
		render_map(cub3d, 0, 0, 0);
	}
}

void	wall_collisions(t_cub3d *cub3d, float *increment2)
{
	if (abs((cub3d->map->player.angle) % 180) != 90)
	{
		wall_collisions_y(cub3d, increment2);
		wall_collisions_x(cub3d, increment2);
	}
}
