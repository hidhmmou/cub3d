/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:18:07 by ramhouch          #+#    #+#             */
/*   Updated: 2023/03/26 01:22:11 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

static int	check_x(t_cub3d *cub3d, int n)
{
	int	i;

	i = 0;
	if (!n)
	{
		while (i < COLLISIONS_SPEED)
		{
			if (cub3d->map->square_map[cub3d->map->player.y / SIZE] \
				[(cub3d->map->player.x + i + 1) / SIZE] == '1' && no(cub3d, &i))
				break ;
			i++;
		}
	}
	else
	{
		while (i < COLLISIONS_SPEED)
		{
			if (cub3d->map->square_map[cub3d->map->player.y / SIZE] \
				[(cub3d->map->player.x - i - 1) / SIZE] == '1' && no(cub3d, &i))
				break ;
			i++;
		}
	}
	return (i);
}

static int	check_y(t_cub3d *cub3d, int n)
{
	int	i;

	i = 0;
	if (!n)
	{
		while (i < COLLISIONS_SPEED)
		{
			if (cub3d->map->square_map[(cub3d->map->player.y + i + 1) / SIZE] \
				[(cub3d->map->player.x) / SIZE] == '1' && no(cub3d, &i))
				break ;
			i++;
		}
	}
	else
	{
		while (i < COLLISIONS_SPEED)
		{
			if (cub3d->map->square_map[(cub3d->map->player.y - i - 1) / SIZE] \
				[(cub3d->map->player.x) / SIZE] == '1' && no(cub3d, &i))
				break ;
			i++;
		}
	}
	return (i);
}

static int	wall_collisions_x(t_cub3d *cub3d, float *increment2)
{
	if (cub3d->map->square_map[((int)increment2[1] - 1) / SIZE] \
		[((int)increment2[0]) / SIZE] != '1' && \
		cub3d->map->square_map[((int)increment2[1] + 1) / SIZE] \
		[((int)increment2[0] + 1) / SIZE] == '1')
	{
		if (abs((cub3d->map->player.angle) % 180) > 90)
			cub3d->map->player.x += check_x(cub3d, 0);
		else
			cub3d->map->player.x -= check_x(cub3d, 1);
		render_map(cub3d, 0, 0, 0);
		return (1);
	}
	else if (cub3d->map->square_map[((int)increment2[1] + 1) / SIZE] \
		[((int)increment2[0]) / SIZE] != '1' && \
		cub3d->map->square_map[((int)increment2[1] - 1) / SIZE] \
		[((int)increment2[0] + 1) / SIZE] == '1')
	{
		if (abs((cub3d->map->player.angle) % 180) > 90)
			cub3d->map->player.x -= check_x(cub3d, 1);
		else
			cub3d->map->player.x += check_x(cub3d, 0);
		render_map(cub3d, 0, 0, 0);
		return (1);
	}
	return (0);
}

static int	wall_collisions_y(t_cub3d *cub3d, float *increment2)
{
	if (cub3d->map->square_map[((int)increment2[1]) / SIZE] \
		[((int)increment2[0] + 1) / SIZE] != '1' && \
		cub3d->map->square_map[((int)increment2[1] - 1) / SIZE] \
		[((int)increment2[0] - 1) / SIZE] == '1')
	{
		if (abs((cub3d->map->player.angle) % 180) > 90)
			cub3d->map->player.y -= check_y(cub3d, 1);
		else
			cub3d->map->player.y += check_y(cub3d, 0);
		render_map(cub3d, 0, 0, 0);
		return (1);
	}
	else if (cub3d->map->square_map[((int)increment2[1]) / SIZE] \
		[((int)increment2[0] - 1) / SIZE] != '1' && \
		cub3d->map->square_map[((int)increment2[1] - 1) / SIZE] \
		[((int)increment2[0] + 1) / SIZE] == '1')
	{
		if (abs((cub3d->map->player.angle) % 180) > 90)
			cub3d->map->player.y += check_y(cub3d, 0);
		else
			cub3d->map->player.y -= check_y(cub3d, 1);
		render_map(cub3d, 0, 0, 0);
		return (1);
	}
	return (0);
}

void	wall_collisions(t_cub3d *cub3d, float *increment2)
{
	if (abs((cub3d->map->player.angle) % 180) != 90)
	{
		if (wall_collisions_y(cub3d, increment2))
			return ;
		wall_collisions_x(cub3d, increment2);
	}
}
