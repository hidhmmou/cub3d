/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 23:16:13 by ramhouch          #+#    #+#             */
/*   Updated: 2023/03/20 23:14:47 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

static int	help_movements(float angle, int *x, int *y)
{
	float	radians;
	int		dx;
	int		dy;
	int		steps;

	radians = angle * PI / 180;
	dx = 200 * cos(radians) * -1;
	dy = 200 * sin(radians);
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	*x = dx;
	*y = dy;
	return (steps);
}

void	up(t_cub3d *cub3d, int dx, int dy, int i)
{
	int		steps;
	float	increment[2];
	float	increment2[2];

	steps = help_movements(cub3d->map->player.angle, &dx, &dy);
	increment[0] = dx / (float)steps;
	increment[1] = dy / (float)steps;
	increment2[0] = cub3d->map->player.x;
	increment2[1] = cub3d->map->player.y;
	while (i < SPEED)
	{
		i++;
		increment2[0] -= increment[0];
		increment2[1] -= increment[1];
		if (cub3d->map->square_map[(int)increment2[1] / SIZE] \
			[(int)increment2[0] / SIZE] == '1')
			break ;
		cub3d->map->player.x = increment2[0];
		cub3d->map->player.y = increment2[1];
	}
	if (i > 1)
		render_map(cub3d, 0, 0, 0);
	else
		wall_collisions(cub3d, increment2);
}

void	down(t_cub3d *cub3d, int dx, int dy, int i)
{
	int		steps;
	float	increment[2];
	float	increment2[2];

	steps = help_movements(cub3d->map->player.angle, &dx, &dy);
	increment[0] = dx / (float)steps;
	increment[1] = dy / (float)steps;
	increment2[0] = cub3d->map->player.x;
	increment2[1] = cub3d->map->player.y;
	while (i < SPEED)
	{
		i++;
		increment2[0] += increment[0];
		increment2[1] += increment[1];
		if (cub3d->map->square_map[(int)increment2[1] / SIZE] \
			[(int)increment2[0] / SIZE] == '1')
			break ;
		cub3d->map->player.x = increment2[0];
		cub3d->map->player.y = increment2[1];
	}
	if (i > 1)
		render_map(cub3d, 0, 0, 0);
	else
		wall_collisions(cub3d, increment2);
}

void	left(t_cub3d *cub3d, int dx, int dy, int i)
{
	int		steps;
	float	increment[2];
	float	increment2[2];

	steps = help_movements(cub3d->map->player.angle + 90, &dx, &dy);
	increment[0] = dx / (float)steps;
	increment[1] = dy / (float)steps;
	increment2[0] = cub3d->map->player.x;
	increment2[1] = cub3d->map->player.y;
	while (i < SPEED)
	{
		i++;
		increment2[0] += increment[0];
		increment2[1] += increment[1];
		if (cub3d->map->square_map[(int)increment2[1] / SIZE] \
			[(int)increment2[0] / SIZE] == '1')
			break ;
		cub3d->map->player.x = increment2[0];
		cub3d->map->player.y = increment2[1];
	}
	if (i)
		render_map(cub3d, 0, 0, 0);
}

void	right(t_cub3d *cub3d, int dx, int dy, int i)
{
	int		steps;
	float	increment[2];
	float	increment2[2];

	steps = help_movements(cub3d->map->player.angle - 90, &dx, &dy);
	increment[0] = dx / (float)steps;
	increment[1] = dy / (float)steps;
	increment2[0] = cub3d->map->player.x;
	increment2[1] = cub3d->map->player.y;
	while (i < SPEED)
	{
		i++;
		increment2[0] += increment[0];
		increment2[1] += increment[1];
		if (cub3d->map->square_map[(int)increment2[1] / SIZE] \
			[(int)increment2[0] / SIZE] == '1')
			break ;
		cub3d->map->player.x = increment2[0];
		cub3d->map->player.y = increment2[1];
	}
	if (i)
		render_map(cub3d, 0, 0, 0);
}
