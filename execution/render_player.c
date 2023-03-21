/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:36:04 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/03/21 22:08:44 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

int	check_hit_wall(t_cub3d *cub3d, float pixel_y, float pixel_x)
{
	if (cub3d->map->square_map[(int)pixel_y / 32] \
			[(int)pixel_x / 32] == '1')
		return (1);
	if (cub3d->map->square_map[((int)pixel_y + 1) / 32] \
		[(int)pixel_x / 32] == '1'
		&& cub3d->map->square_map[(int)pixel_y / 32] \
		[((int)pixel_x + 1) / 32] == '1')
		return (1);
	if (cub3d->map->square_map[((int)pixel_y + 1) / 32] \
		[(int)pixel_x / 32] == '1'
		&& cub3d->map->square_map[(int)pixel_y / 32] \
		[((int)pixel_x + 1) / 32] == '1')
		return (1);
	if (cub3d->map->square_map[((int)pixel_y - 1) / 32] \
		[(int)pixel_x / 32] == '1'
		&& cub3d->map->square_map[(int)pixel_y / 32] \
		[((int)pixel_x + 1) / 32] == '1')
		return (1);
	return (0);
}

void	init_draw(t_cub3d *cub3d)
{
	cub3d->draw->radiant = cub3d->draw->ray_angle * M_PI / 180;
	cub3d->draw->dx = 200 * cos(cub3d->draw->radiant);
	cub3d->draw->dy = 200 * sin(cub3d->draw->radiant) * -1;
	if (abs(cub3d->draw->dx) > abs(cub3d->draw->dy))
		cub3d->draw->pixel_nbr = cub3d->draw->dx;
	else
		cub3d->draw->pixel_nbr = cub3d->draw->dy;
	cub3d->draw->increment_x = cub3d->draw->dx / (float)cub3d->draw->pixel_nbr;
	cub3d->draw->increment_y = cub3d->draw->dy / (float)cub3d->draw->pixel_nbr;
	if (cub3d->map->player.angle == 270 || cub3d->map->player.angle == 180)
	{
		cub3d->draw->increment_x *= -1;
		cub3d->draw->increment_y *= -1;
	}
	cub3d->draw->ray_angle += 60.0 / 1080;
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
		pixel_x += cub3d->draw->increment_x;
		pixel_y += cub3d->draw->increment_y;
		if (check_hit_wall(cub3d, pixel_y, pixel_x))
			break ;
	}
	put_center_view(cub3d, tmp, pixel_x, pixel_y);
}

void	render_player(t_cub3d *cub3d)
{
	int 	i;

	i = -1;
	cub3d->draw->ray_angle = cub3d->map->player.angle - 30;
	while (++i <= WIDTH)
		cast_ray(cub3d);
}
