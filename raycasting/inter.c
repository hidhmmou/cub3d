/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 03:09:37 by ramhouch          #+#    #+#             */
/*   Updated: 2023/04/03 20:49:47 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

int	get_pexel(t_cub3d *cub3d, int i, int my, float size)
{
	int	x;
	int	y;

	if (cub3d->draw.d == 1)
	{
		x = (int)cub3d->draw.y % SIZE;
		y = (i + my) / size;
		if (cub3d->draw.type == 'D')
			return (get_pexel_from_img(&cub3d->imgs.door, x, y));
		if (cub3d->map->player.x - cub3d->draw.x > 0)
			return (get_pexel_from_img(&cub3d->imgs.ea, x, y));
		return (get_pexel_from_img(&cub3d->imgs.no, x, y));
	}
	if (cub3d->draw.d == 3)
	{
		x = (int)cub3d->draw.x % SIZE;
		y = (i + my) / size;
		if (cub3d->draw.type == 'D')
			return (get_pexel_from_img(&cub3d->imgs.door, x, y));
		if (cub3d->map->player.y - cub3d->draw.y > 0)
			return (get_pexel_from_img(&cub3d->imgs.so, x, y));
		return (get_pexel_from_img(&cub3d->imgs.we, x, y));
	}
	return (0);
}
