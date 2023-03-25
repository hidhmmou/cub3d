/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:36:04 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/03/25 14:04:11 by hidhmmou         ###   ########.fr       */
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
	cub3d->draw->dx = 500 * cos(cub3d->draw->radiant);
	cub3d->draw->dy = 500 * sin(cub3d->draw->radiant) * -1;
	if (abs(cub3d->draw->dx) > abs(cub3d->draw->dy))
		cub3d->draw->pixel_nbr = abs(cub3d->draw->dx);
	else
		cub3d->draw->pixel_nbr = abs(cub3d->draw->dy);
	cub3d->draw->increment_x = cub3d->draw->dx / (float)cub3d->draw->pixel_nbr;
	cub3d->draw->increment_y = cub3d->draw->dy / (float)cub3d->draw->pixel_nbr;
	cub3d->draw->ray_angle += 60.0 / WIDTH;
}

void draw_wall(t_cub3d *cub3d)
{
	int i;

	i = -1;
	while (++i < cub3d->draw->draw_start)
		mlx_pixel_put(cub3d->mlx_3d, cub3d->win_3d, cub3d->draw->x, i, rgb_to_int(*cub3d->map->ciel_color));
	while (i <= cub3d->draw->draw_end)
		mlx_pixel_put(cub3d->mlx_3d, cub3d->win_3d, cub3d->draw->x, i++, 0xFF8FFF);
	while (i < HEIGHT)
		mlx_pixel_put(cub3d->mlx_3d, cub3d->win_3d, cub3d->draw->x, i++, rgb_to_int(*cub3d->map->floor_color));
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
	cub3d->draw->distance = sqrt(pow(pixel_x - tmp[0], 2) + pow(pixel_y - tmp[1], 2));
    cub3d->draw->wall_height = cub3d->draw->distance * cos(cub3d->draw->radiant - (cub3d->map->player.angle * P / 180));
	cub3d->draw->wall_height = pow(cub3d->draw->wall_height, -1) * 5000;
    cub3d->draw->draw_start = (int)(HEIGHT / 2.0 - cub3d->draw->wall_height / 2.0);
    cub3d->draw->draw_end = (int)(cub3d->draw->wall_height / 2.0 + HEIGHT / 2.0);
    if (cub3d->draw->draw_start < 0)
        cub3d->draw->draw_start = 0;
    if (cub3d->draw->draw_end >= HEIGHT)
        cub3d->draw->draw_end = HEIGHT - 1;
	draw_wall(cub3d);
	cub3d->draw->x++;
	mlx_pixel_put(cub3d->mlx, cub3d->win, pixel_x, pixel_y, 0x00FF00);
	mlx_pixel_put(cub3d->mlx, cub3d->win_3d, 32, 32, 0x00FF00);
	mlx_pixel_put(cub3d->mlx, cub3d->win, pixel_x - 1, pixel_y - 1, 0x00FF00);
}

void	render_player(t_cub3d *cub3d)
{
	int 	i;

	i = -1;
	cub3d->draw->x = 0;
	cub3d->draw->ray_angle = cub3d->map->player.angle - 30;
	while (++i <= WIDTH)
		cast_ray(cub3d);
	cast_mid_ray(cub3d);
}
