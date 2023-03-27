/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:36:04 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/03/27 16:50:20 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

int is_wall(char c)
{
	return (c == '1');
}

int	check_hit_wall(t_cub3d *cub3d, float pixel_y, float pixel_x)
{
	if (is_wall(cub3d->map->square_map[(int)pixel_y / SIZE][(int)pixel_x / SIZE]))
		return (1);
	if (is_wall(cub3d->map->square_map[((int)pixel_y + 1) / SIZE][(int)pixel_x / SIZE])
		&& is_wall(cub3d->map->square_map[(int)pixel_y / SIZE][((int)pixel_x + 1) / SIZE]))
		return (1);
	if (is_wall(cub3d->map->square_map[((int)pixel_y - 1) / SIZE][(int)pixel_x / SIZE])
		&& is_wall(cub3d->map->square_map[(int)pixel_y / SIZE][((int)pixel_x + 1) / SIZE]))
		return (1);
	return (0);
}

int	check_hit_wall_2d(t_cub3d *cub3d, float pixel_y, float pixel_x)
{
	if (is_wall(cub3d->map->square_map[(int)pixel_y / SIZE_2D][(int)pixel_x / SIZE_2D]))
		return (1);
	if (is_wall(cub3d->map->square_map[((int)pixel_y + 1) / SIZE_2D][(int)pixel_x / SIZE_2D])
		&& is_wall(cub3d->map->square_map[(int)pixel_y / SIZE_2D][((int)pixel_x + 1) / SIZE_2D]))
		return (1);
	if (is_wall(cub3d->map->square_map[((int)pixel_y - 1) / SIZE_2D][(int)pixel_x / SIZE_2D])
		&& is_wall(cub3d->map->square_map[(int)pixel_y / SIZE_2D][((int)pixel_x + 1) / SIZE_2D]))
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
		my_mlx_pixel_put(cub3d, cub3d->draw->x, i, rgb_to_int(*cub3d->map->ciel_color));
	my_mlx_pixel_put(cub3d, cub3d->draw->x, i++, 0);
	while (i <= cub3d->draw->draw_end)
		my_mlx_pixel_put(cub3d, cub3d->draw->x, i++, cub3d->draw->color);
	my_mlx_pixel_put(cub3d, cub3d->draw->x, i++, 0);
	while (i < HEIGHT)
		my_mlx_pixel_put(cub3d, cub3d->draw->x, i++, rgb_to_int(*cub3d->map->floor_color));
}

void	cast_ray(t_cub3d *cub3d)
{
	double	pixel_x;
	double	pixel_y;
	double	tmp[2];

	pixel_x = cub3d->map->player.x;
	pixel_y = cub3d->map->player.y;
	tmp[0] = pixel_x;
	tmp[1] = pixel_y;
	init_draw(cub3d);
	while (1)
	{	
		pixel_x += cub3d->draw->increment_x;
		pixel_y += cub3d->draw->increment_y;
		if (check_hit_wall(cub3d, pixel_y, pixel_x))
		{
			check_direction(cub3d, pixel_y, pixel_x);
			break ;
		}
	}
	cub3d->draw->distance = sqrt(pow(pixel_x - tmp[0], 2) + pow(pixel_y - tmp[1], 2));
	cub3d->draw->distance *= (cos(cub3d->draw->radiant - (cub3d->map->player.angle * P / 180.0)));
	double distance_to_player = (double)((WIDTH / 2.0) / tan(60.0 / 2.0 * PI / 180.0));
	double wall_height = (double)((double)SIZE / cub3d->draw->distance ) * distance_to_player;
	cub3d->draw->wall_height = wall_height;
    cub3d->draw->draw_start = (double)(HEIGHT / 2.0 - cub3d->draw->wall_height / 2.0);
    cub3d->draw->draw_end = (double)cub3d->draw->draw_start + (double)cub3d->draw->wall_height;
    if (cub3d->draw->draw_start < 0)
        cub3d->draw->draw_start = 0;
    if (cub3d->draw->draw_end >= HEIGHT)
        cub3d->draw->draw_end = HEIGHT - 1;
	draw_wall(cub3d);
	cub3d->draw->x--;
}

void	render_player(t_cub3d *cub3d)
{
	int 	i;

	i = -1;
	cub3d->draw->x = WIDTH;
	cub3d->draw->ray_angle = cub3d->map->player.angle - 30;
	while (++i <= WIDTH)
		cast_ray(cub3d);
	cast_mid_ray(cub3d);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win_3d, cub3d->img->img, 0, 0);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->img_2d->img, 0, 0);
}
