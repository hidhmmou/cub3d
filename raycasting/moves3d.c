/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 23:16:13 by ramhouch          #+#    #+#             */
/*   Updated: 2023/03/29 07:03:12 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

static int	help_movements(float angle, int *x, int *y)
{
	float	radians;
	int		dx;
	int		dy;
	int		steps;

	radians = angle * PI / 180;
	dx = 500 * cos(radians) * -1;
	dy = 500 * sin(radians);
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	*x = dx;
	*y = dy;
	return (steps);
}

void	up3d(t_cub3d *cub3d, int dx, int dy, int i)
{
	int		steps;
	float	increment[2];
	float	increment2[2];

	steps = help_movements(cub3d->map->player.angle, &dx, &dy);
	increment[0] = dx / (float)steps;
	increment[1] = dy / (float)steps;
	increment2[0] = cub3d->map->player.x;
	increment2[1] = cub3d->map->player.y;
	while (i++ < SPEED)
	{
		dx = increment2[0];
		dy = increment2[1];
		increment2[0] -= increment[0];
		increment2[1] -= increment[1];
		if (check_movements(cub3d, increment2[1], increment2[0]))
		{
			if (!check_movements(cub3d, increment2[1], dx))
				increment2[0] = dx;
			else if (!check_movements(cub3d, dy, increment2[0]))
				increment2[1] = dy;
			else
				break ;
		}
		cub3d->map->player.x = increment2[0];
		cub3d->map->player.y = increment2[1];
	}
	if (i > 1)
		raycasting(cub3d, 0, 0);
}

void	down3d(t_cub3d *cub3d, int dx, int dy, int i)
{
	int		steps;
	float	increment[2];
	float	increment2[2];

	steps = help_movements(cub3d->map->player.angle, &dx, &dy);
	increment[0] = dx / (float)steps;
	increment[1] = dy / (float)steps;
	increment2[0] = cub3d->map->player.x;
	increment2[1] = cub3d->map->player.y;
	while (i++ < SPEED)
	{
		dx = increment2[0];
		dy = increment2[1];
		increment2[0] += increment[0];
		increment2[1] += increment[1];
		if (check_movements(cub3d, increment2[1], increment2[0]))
		{
			if (!check_movements(cub3d, increment2[1], dx))
				increment2[0] = dx;
			else if (!check_movements(cub3d, dy, increment2[0]))
				increment2[1] = dy;
			else
				break ;
		}
		cub3d->map->player.x = increment2[0];
		cub3d->map->player.y = increment2[1];
	}
	if (i > 1)
		raycasting(cub3d, 0, 0);
}

void	left3d(t_cub3d *cub3d, int dx, int dy, int i)
{
	int		steps;
	float	increment[2];
	float	increment2[2];

	steps = help_movements(cub3d->map->player.angle + 90, &dx, &dy);
	increment[0] = dx / (float)steps;
	increment[1] = dy / (float)steps;
	increment2[0] = cub3d->map->player.x;
	increment2[1] = cub3d->map->player.y;
	while (i++ < SPEED)
	{
		dx = increment2[0];
		dy = increment2[1];
		increment2[0] += increment[0];
		increment2[1] += increment[1];
		if (check_movements(cub3d, increment2[1], increment2[0]))
		{
			if (!check_movements(cub3d, increment2[1], dx))
				increment2[0] = dx;
			else if (!check_movements(cub3d, dy, increment2[0]))
				increment2[1] = dy;
			else
				break ;
		}
		cub3d->map->player.x = increment2[0];
		cub3d->map->player.y = increment2[1];
	}
	if (i > 1)
		raycasting(cub3d, 0, 0);
}

void	right3d(t_cub3d *cub3d, int dx, int dy, int i)
{
	int		steps;
	float	increment[2];
	float	increment2[2];

	steps = help_movements(cub3d->map->player.angle - 90, &dx, &dy);
	increment[0] = dx / (float)steps;
	increment[1] = dy / (float)steps;
	increment2[0] = cub3d->map->player.x;
	increment2[1] = cub3d->map->player.y;
	while (i++ < SPEED)
	{
		dx = increment2[0];
		dy = increment2[1];
		increment2[0] += increment[0];
		increment2[1] += increment[1];
		if (check_movements(cub3d, increment2[1], increment2[0]))
		{
			if (!check_movements(cub3d, increment2[1], dx))
				increment2[0] = dx;
			else if (!check_movements(cub3d, dy, increment2[0]))
				increment2[1] = dy;
			else
				break ;
		}
		cub3d->map->player.x = increment2[0];
		cub3d->map->player.y = increment2[1];
	}
	if (i > 1)
		raycasting(cub3d, 0, 0);
}
