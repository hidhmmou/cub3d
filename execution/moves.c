/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 23:16:13 by ramhouch          #+#    #+#             */
/*   Updated: 2023/03/19 22:49:39 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

void	up(t_cub3d *cub3d, int dx, int dy, int i)
{
	float	radians;
	int		steps;
	float	increment[2];
	float	increment2[2];

	radians = cub3d->map->player.angle * PI / 180;
	dx = 200 * cos(radians) * -1;
	dy = 200 * sin(radians);
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	increment[0] = dx / (float)steps;
	increment[1] = dy / (float)steps;
	i = 0;
	increment2[0] = cub3d->map->player.x;
	increment2[1] = cub3d->map->player.y;
	while (i < SPEED)
	{
		i++;
		increment2[0] -= increment[0];
		increment2[1] -= increment[1];
		if (cub3d->map->square_map[(int)increment2[1] / 32][(int)increment2[0] / 32] == '1')
			break ;
		cub3d->map->player.x = increment2[0];
		cub3d->map->player.y = increment2[1];
	}
	if (i)
		render_map(cub3d, 0, 0, 0);
}

void	down(t_cub3d *cub3d, int dx, int dy, int i)
{
	float	radians;
	int		steps;
	float	increment[2];
	float	increment2[2];

	radians = cub3d->map->player.angle * PI / 180;
	dx = 200 * cos(radians) * -1;
	dy = 200 * sin(radians);
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	increment[0] = dx / (float)steps;
	increment[1] = dy / (float)steps;
	i = 0;
	increment2[0] = cub3d->map->player.x;
	increment2[1] = cub3d->map->player.y;
	while (i < SPEED)
	{
		i++;
		increment2[0] += increment[0];
		increment2[1] += increment[1];
		if (cub3d->map->square_map[(int)increment2[1] / 32][(int)increment2[0] / 32] == '1')
			break ;
		cub3d->map->player.x = increment2[0];
		cub3d->map->player.y = increment2[1];
	}
	if (i)
		render_map(cub3d, 0, 0, 0);
}

void	left(t_cub3d *cub3d, int dx, int dy, int i)
{
	float	radians;
	int		steps;
	float	increment[2];
	float	increment2[2];

	radians = (cub3d->map->player.angle + 90.0) * PI / 180;
	dx = 200 * cos(radians) * -1;
	dy = 200 * sin(radians);
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	increment[0] = dx / (float)steps;
	increment[1] = dy / (float)steps;
	i = 0;
	increment2[0] = cub3d->map->player.x;
	increment2[1] = cub3d->map->player.y;
	while (i < SPEED)
	{
		i++;
		increment2[0] += increment[0];
		increment2[1] += increment[1];
		if (cub3d->map->square_map[(int)increment2[1] / 32][(int)increment2[0] / 32] == '1')
			break ;
		cub3d->map->player.x = increment2[0];
		cub3d->map->player.y = increment2[1];
	}
	if (i)
		render_map(cub3d, 0, 0, 0);
}

void	right(t_cub3d *cub3d, int dx, int dy, int i)
{
	float	radians;
	int		steps;
	float	increment[2];
	float	increment2[2];

	radians = (cub3d->map->player.angle - 90.0) * PI / 180;
	dx = 200 * cos(radians) * -1;
	dy = 200 * sin(radians);
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	increment[0] = dx / (float)steps;
	increment[1] = dy / (float)steps;
	i = 0;
	increment2[0] = cub3d->map->player.x;
	increment2[1] = cub3d->map->player.y;
	while (i < SPEED)
	{
		i++;
		increment2[0] += increment[0];
		increment2[1] += increment[1];
		if (cub3d->map->square_map[(int)increment2[1] / 32][(int)increment2[0] / 32] == '1')
			break ;
		cub3d->map->player.x = increment2[0];
		cub3d->map->player.y = increment2[1];
	}
	if (i)
		render_map(cub3d, 0, 0, 0);
}
