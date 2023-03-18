/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 23:16:13 by ramhouch          #+#    #+#             */
/*   Updated: 2023/03/18 23:50:20 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

void	up(t_cub3d *cub3d)
{
	int	n;

	n = (cub3d->map->player.y - 1) / 32;
	if (cub3d->map->square_map[n][cub3d->map->player.x / 32] != '1')
	{
		cub3d->map->player.y -= 1;
		render_map(cub3d, 0, 0, 0);
	}
	n = (cub3d->map->player.y - 1) / 32;
	if (cub3d->map->square_map[n][cub3d->map->player.x / 32] != '1')
	{
		cub3d->map->player.y -= 1;
		render_map(cub3d, 0, 0, 0);
	}
}

void	down(t_cub3d *cub3d)
{
	int	n;

	n = (cub3d->map->player.y + 1) / 32;
	if (cub3d->map->square_map[n][cub3d->map->player.x / 32] != '1')
	{
		cub3d->map->player.y += 1;
		render_map(cub3d, 0, 0, 0);
	}
	n = (cub3d->map->player.y + 1) / 32;
	if (cub3d->map->square_map[n][cub3d->map->player.x / 32] != '1')
	{
		cub3d->map->player.y += 1;
		render_map(cub3d, 0, 0, 0);
	}
}

void	left(t_cub3d *cub3d)
{
	int	n;

	n = (cub3d->map->player.x - 1) / 32;
	if (cub3d->map->square_map[cub3d->map->player.y / 32][n] != '1')
	{
		cub3d->map->player.x -= 1;
		render_map(cub3d, 0, 0, 0);
	}
	n = (cub3d->map->player.x - 1) / 32;
	if (cub3d->map->square_map[cub3d->map->player.y / 32][n] != '1')
	{
		cub3d->map->player.x -= 1;
		render_map(cub3d, 0, 0, 0);
	}
}

void	right(t_cub3d *cub3d)
{
	int	n;

	n = (cub3d->map->player.x + 1) / 32;
	if (cub3d->map->square_map[cub3d->map->player.y / 32][n] != '1')
	{
		cub3d->map->player.x += 1;
		render_map(cub3d, 0, 0, 0);
	}
	n = (cub3d->map->player.x + 1) / 32;
	if (cub3d->map->square_map[cub3d->map->player.y / 32][n] != '1')
	{
		cub3d->map->player.x += 1;
		render_map(cub3d, 0, 0, 0);
	}
}
