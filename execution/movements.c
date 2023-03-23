/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 23:16:13 by ramhouch          #+#    #+#             */
/*   Updated: 2023/03/23 18:43:32 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

void	init_movement(t_cub3d *cub3d, int to_add)
{
	cub3d->draw->radiant = (cub3d->map->player.angle + to_add) * PI / 180;
	cub3d->draw->dx = 500 * cos(cub3d->draw->radiant) * -1;
	cub3d->draw->dy = 500 * sin(cub3d->draw->radiant);
	if (abs(cub3d->draw->dx) > abs(cub3d->draw->dy))
		cub3d->draw->pixel_nbr = abs(cub3d->draw->dx);
	else
		cub3d->draw->pixel_nbr = abs(cub3d->draw->dy);
	cub3d->draw->increment_x = cub3d->draw->dx / (float)cub3d->draw->pixel_nbr;
	cub3d->draw->increment_y = cub3d->draw->dy / (float)cub3d->draw->pixel_nbr;
}

int collusion_up_down(t_cub3d *cub3d, float *pixel_y, float *pixel_x)
{
	printf("collusion_up_down\n");
	if (!check_hit_wall(cub3d, *pixel_y + 1, *pixel_x + 1)
		|| !check_hit_wall(cub3d, *pixel_y - 1, *pixel_x + 1))
		return (*pixel_y += cub3d->draw->increment_y, 1);
	return (0);
}

int collusion_left_right(t_cub3d *cub3d, float *pixel_y, float *pixel_x)
{
	printf("collusion_left_right\n");
	if (!check_hit_wall(cub3d, *pixel_y - 1, *pixel_x + 1)
		|| !check_hit_wall(cub3d, *pixel_y + 1, *pixel_x - 1))
		return (*pixel_x += cub3d->draw->increment_x, 1);
	return (0);
}

void	move_up(t_cub3d *cub3d)
{
	int		moves_nbr;
	float	pixel_x;
	float	pixel_y;


	init_movement(cub3d, 0);
	moves_nbr = 0;
	pixel_x = cub3d->map->player.x;
	pixel_y = cub3d->map->player.y;
	while (moves_nbr++ < SPEED)
	{
		pixel_x -= cub3d->draw->increment_x;
		pixel_y -= cub3d->draw->increment_y;
		if (check_hit_wall(cub3d, pixel_y, pixel_x))
		{
			if (cub3d->map->player.direction == 1
				||cub3d->map->player.direction == 3)
				collusion_up_down(cub3d, &pixel_y, &pixel_x);
			else
				collusion_left_right(cub3d, &pixel_y, &pixel_x);
		}
		if (check_hit_wall(cub3d, pixel_y, pixel_x))
			break ;
		cub3d->map->player.x = pixel_x;
		cub3d->map->player.y = pixel_y;
	}
	if (moves_nbr > 1)
		render_map_2d(cub3d);
}


void	move_down(t_cub3d *cub3d)
{
	int		moves_nbr;
	float	pixel_x;
	float	pixel_y;


	init_movement(cub3d, 0);
	moves_nbr = 0;
	pixel_x = cub3d->map->player.x;
	pixel_y = cub3d->map->player.y;
	while (moves_nbr++ < SPEED)
	{
		pixel_x += cub3d->draw->increment_x;
		pixel_y += cub3d->draw->increment_y;
		if (check_hit_wall(cub3d, pixel_y, pixel_x))
		{
			//if (cub3d->map->player.direction == 1
			//	||cub3d->map->player.direction == 3)
			//	collusion_up_down(cub3d, &pixel_y, &pixel_x);
			//else
			//	collusion_left_right(cub3d, &pixel_y, &pixel_x);
		}
		if (check_hit_wall(cub3d, pixel_y, pixel_x))
			break ;
		cub3d->map->player.x = pixel_x;
		cub3d->map->player.y = pixel_y;
	}
	if (moves_nbr > 1)
		render_map_2d(cub3d);
}


void	move_right(t_cub3d *cub3d)
{
	int		moves_nbr;
	float	pixel_x;
	float	pixel_y;


	init_movement(cub3d, 90);
	moves_nbr = 0;
	pixel_x = cub3d->map->player.x;
	pixel_y = cub3d->map->player.y;
	while (moves_nbr++ < SPEED)
	{
		pixel_x += cub3d->draw->increment_x;
		pixel_y += cub3d->draw->increment_y;
		if (check_hit_wall(cub3d, pixel_y, pixel_x) 
			&& !check_hit_wall(cub3d, pixel_y + 1, pixel_x - 1))
			pixel_x -= cub3d->draw->increment_y;
		if (check_hit_wall(cub3d, pixel_y, pixel_x))
			break ;
		cub3d->map->player.x = pixel_x;
		cub3d->map->player.y = pixel_y;
	}
	if (moves_nbr > 1)
		render_map_2d(cub3d);
}

void	move_left(t_cub3d *cub3d)
{
	int		moves_nbr;
	float	pixel_x;
	float	pixel_y;


	init_movement(cub3d, -90);
	moves_nbr = 0;
	pixel_x = cub3d->map->player.x;
	pixel_y = cub3d->map->player.y;
	while (moves_nbr++ < SPEED)
	{
		pixel_x += cub3d->draw->increment_x;
		pixel_y += cub3d->draw->increment_y;
		if (check_hit_wall(cub3d, pixel_y, pixel_x) 
			&& !check_hit_wall(cub3d, pixel_y - 1, pixel_x + 1))
			pixel_y -= cub3d->draw->increment_y;
		if (check_hit_wall(cub3d, pixel_y, pixel_x))
			break ;
		cub3d->map->player.x = pixel_x;
		cub3d->map->player.y = pixel_y;
	}
	if (moves_nbr > 1)
		render_map_2d(cub3d);
}