/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 03:09:37 by ramhouch          #+#    #+#             */
/*   Updated: 2023/04/03 20:38:22 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

int	get_y(t_cub3d *cub3d, int i, int y, int my)
{
	float	size;
	int		m;
	float	start;
	float	end;

	size = cub3d->draw.wall_height / SIZE;
	start = 0;
	end = size;
	while (1)
	{
		if (((i + my) >= start && (i + my) < end) || end > HEIGHT)
			break ;
		y++;
		start = end;
		end += size;
	}
	return (y);
}

int	get_pexel(t_cub3d *cub3d, int i, int my)
{
	int	x;
	int	y;

	if (cub3d->draw.d == 1)
	{
		x = (int)cub3d->draw.y % SIZE;
		y = get_y(cub3d, i, 0, my);
		if (cub3d->draw.type == 'D')
			return (get_pexel_from_img(&cub3d->imgs.door, x, y));
		if (cub3d->map->player.x - cub3d->draw.x > 0)
			return (get_pexel_from_img(&cub3d->imgs.ea, x, y));
		return (get_pexel_from_img(&cub3d->imgs.no, x, y));
	}
	if (cub3d->draw.d == 3)
	{
		x = (int)cub3d->draw.x % SIZE;
		y = get_y(cub3d, i, 0, my);
		if (cub3d->draw.type == 'D')
			return (get_pexel_from_img(&cub3d->imgs.door, x, y));
		if (cub3d->map->player.y - cub3d->draw.y > 0)
			return (get_pexel_from_img(&cub3d->imgs.so, x, y));
		return (get_pexel_from_img(&cub3d->imgs.we, x, y));
	}
	return (0);
}
