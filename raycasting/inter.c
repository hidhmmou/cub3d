/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 03:09:37 by ramhouch          #+#    #+#             */
/*   Updated: 2023/04/02 05:43:18 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

int	get_y(t_cub3d *cub3d, int i, int y, int my)
{
	float size;
	int	m;
	float	start;
	float	end;

	size = cub3d->draw.wall_height / SIZE;
	start = 0;
	end = size;
	while (1)
	{
		if (((i + my) >= start && (i + my) < end ) || end > cub3d->draw.wall_height)
			break ;
		y++;
		start = end;
		end += size;
	}
	return (y);
}

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
}

int	get_pexel(t_cub3d *cub3d, int i, int my)
{
	int	x;
	int	y;

	if (cub3d->draw.d == 1)
	{
		x = (int)cub3d->draw.y % SIZE;
		y = get_y(cub3d, i, 0, my);
		if (cub3d->map->player.x - cub3d->draw.x > 0)
			return (get_pexel_from_img(&cub3d->imgs.EA, x, y));
		return (get_pexel_from_img(&cub3d->imgs.NO, x, y));
	}
	if (cub3d->draw.d == 3)
	{
		x = (int)cub3d->draw.x % SIZE;
		y = get_y(cub3d, i, 0, my);
		if (cub3d->map->player.y - cub3d->draw.y > 0)
			return (get_pexel_from_img(&cub3d->imgs.SO, x, y));
		return (get_pexel_from_img(&cub3d->imgs.WE, x, y));
	}
	return (0);
}

