/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:36:04 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/03/22 23:22:01 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

int is_wall(char c)
{
	return (c == '1');
}

int	check_hit_wall(t_cub3d *cub3d, float pixel_y, float pixel_x)
{
	/*
		1
		0
	*/
	if (is_wall(cub3d->map->square_map[(int)pixel_y / SIZE][(int)pixel_x / SIZE]))
		return (1);
	/*
		01
		10
	*/
	if (is_wall(cub3d->map->square_map[((int)pixel_y + 1) / SIZE][(int)pixel_x / SIZE])
		&& is_wall(cub3d->map->square_map[(int)pixel_y / SIZE][((int)pixel_x + 1) / SIZE]))
		return (1);
	/*
		10
		01
	*/
	if (is_wall(cub3d->map->square_map[((int)pixel_y - 1) / SIZE][(int)pixel_x /SIZE])
		&& is_wall(cub3d->map->square_map[(int)pixel_y / SIZE][((int)pixel_x + 1) /SIZE]))
		return (1);
	return (0);
}

void	init_draw(t_cub3d *cub3d)
{
	cub3d->draw->radiant = cub3d->draw->ray_angle * P / 180;
	cub3d->draw->dx = 500 * cos(cub3d->draw->radiant) * -1;
	cub3d->draw->dy = 500 * sin(cub3d->draw->radiant);
	if (abs(cub3d->draw->dx) > abs(cub3d->draw->dy))
		cub3d->draw->pixel_nbr = abs(cub3d->draw->dx);
	else
		cub3d->draw->pixel_nbr = abs(cub3d->draw->dy);
	cub3d->draw->increment_x = cub3d->draw->dx / (float)cub3d->draw->pixel_nbr;
	cub3d->draw->increment_y = cub3d->draw->dy / (float)cub3d->draw->pixel_nbr;
	cub3d->draw->ray_angle += 60.0 / WIDTH;
}

void	cast_ray(t_cub3d *cub3d)
{
	float	pixel_x;
	float	pixel_y;
	float	tmp[2];

	pixel_x = cub3d->map->player.x;
	pixel_y = cub3d->map->player.y;
	tmp[0] = pixel_x;
	tmp[1] = pixel_y;
	init_draw(cub3d);
	while (1)
	{
		mlx_pixel_put(cub3d->mlx, cub3d->win, pixel_x, pixel_y, 0xFF0000);
		pixel_x -= cub3d->draw->increment_x;
		pixel_y -= cub3d->draw->increment_y;
		if (check_hit_wall(cub3d, pixel_y, pixel_x))
			break ;
	}
	mlx_pixel_put(cub3d->mlx, cub3d->win, pixel_x, pixel_y, 0x00FF00);
	mlx_pixel_put(cub3d->mlx, cub3d->win, pixel_x - 1, pixel_y - 1, 0x00FF00);
}

void	render_player(t_cub3d *cub3d)
{
	int 	i;

	i = -1;
	cub3d->draw->ray_angle = cub3d->map->player.angle - 30;
	while (++i <= WIDTH)
		cast_ray(cub3d);
	cast_mid_ray(cub3d);
}
