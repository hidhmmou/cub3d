/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 23:16:13 by ramhouch          #+#    #+#             */
/*   Updated: 2023/03/19 21:45:15 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

void	up(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (cub3d->map->square_map[(cub3d->map->player.y - i - 1) / 32] \
		[cub3d->map->player.x / 32] != '1' && i < SPEED)
		i++;
	if (i)
	{
		cub3d->map->player.y -= i;
		render_map(cub3d, 0, 0, 0);
	}
}

void	down(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (cub3d->map->square_map[(cub3d->map->player.y + i + 1) / 32] \
		[cub3d->map->player.x / 32] != '1' && i < SPEED)
		i++;
	if (i)
	{
		cub3d->map->player.y += i;
		render_map(cub3d, 0, 0, 0);
	}
}

void	left(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (cub3d->map->square_map[cub3d->map->player.y / 32] \
		[(cub3d->map->player.x - i - 1) / 32] != '1' && i < SPEED)
		i++;
	if (i)
	{
		cub3d->map->player.x -= i;
		render_map(cub3d, 0, 0, 0);
	}
}

void	right(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (cub3d->map->square_map[cub3d->map->player.y / 32] \
		[(cub3d->map->player.x + i + 1) / 32] != '1' && i < SPEED)
		i++;
	if (i)
	{
		cub3d->map->player.x += i;
		render_map(cub3d, 0, 0, 0);
	}
}
