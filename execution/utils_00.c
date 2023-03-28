/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:42:58 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/03/27 22:04:35 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"


void	get_wall_color(t_cub3d *cub3d, float y, float x)
{
	int i;

	i = 0;
	if (!is_wall(cub3d->map->square_map[(int)y / SIZE][(int)(x - 1) / SIZE]) && ++i)
		cub3d->draw->color = 23211;
	if (!is_wall(cub3d->map->square_map[(int)(y) / SIZE][(int)(x + 1) / SIZE]) && ++i)
		cub3d->draw->color = 54321;
	if (!is_wall(cub3d->map->square_map[(int)(y + 1) / SIZE][(int)x / SIZE]) && ++i)
		cub3d->draw->color = 3214;
	if (!is_wall(cub3d->map->square_map[(int)(y - 1) / SIZE][(int)x / SIZE]) && ++i)
		cub3d->draw->color = 34614;
	if (i > 1)
		cub3d->draw->color = 0;
}

void check_direction(t_cub3d *cub3d, float y, float x)
{
	if (!is_wall(cub3d->map->square_map[(int)y / SIZE][(int)(x - 2) / SIZE]))
		cub3d->map->player.direction = 2;
	else if (!is_wall(cub3d->map->square_map[(int)(y) / SIZE][(int)(x + 2) / SIZE]))
		cub3d->map->player.direction = 4;
	else if (!is_wall(cub3d->map->square_map[(int)(y + 2) / SIZE][(int)x / SIZE]))
		cub3d->map->player.direction = 1;
	else if (!is_wall(cub3d->map->square_map[(int)(y - 2) / SIZE][(int)x / SIZE]))
		cub3d->map->player.direction = 3;
	get_wall_color(cub3d, y, x);
}

void put_player(t_cub3d *cub3d, float *tmp)
{
	my_mlx_pixel_put(cub3d->img_2d, tmp[0] , tmp[1], 0x00FF00);
	my_mlx_pixel_put(cub3d->img_2d, tmp[0], tmp[1] - 1, 0x00FF00);
	my_mlx_pixel_put(cub3d->img_2d, tmp[0], tmp[1] + 1, 0x00FF00);
	my_mlx_pixel_put(cub3d->img_2d, tmp[0], tmp[1] - 2, 0x00FF00);
	my_mlx_pixel_put(cub3d->img_2d, tmp[0], tmp[1] + 2, 0x00FF00);
	my_mlx_pixel_put(cub3d->img_2d, tmp[0] - 1, tmp[1], 0x00FF00);
	my_mlx_pixel_put(cub3d->img_2d, tmp[0] + 1, tmp[1], 0x00FF00);
	my_mlx_pixel_put(cub3d->img_2d, tmp[0] - 2, tmp[1], 0x00FF00);
	my_mlx_pixel_put(cub3d->img_2d, tmp[0] + 2, tmp[1], 0x00FF00);
}

void	cast_mid_ray(t_cub3d *cub3d)
{
	float	pixel_x;
	float	pixel_y;
	float	tmp[2];

	pixel_x = cub3d->map->player.x;
	pixel_y = cub3d->map->player.y;
	tmp[0] = pixel_x;
	tmp[1] = pixel_y;
	cub3d->draw->ray_angle = cub3d->map->player.angle;
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
	cub3d->draw->distance = (float)sqrt(pow(pixel_x - tmp[0], 2) + pow(pixel_y - tmp[1], 2));
    cub3d->draw->wall_height = (float)HEIGHT / cub3d->draw->distance;
	cub3d->draw->wall_height = (float)pow(cub3d->draw->wall_height, -1) * 7000;
    cub3d->draw->draw_start = (float)(-cub3d->draw->wall_height / 2.0 + HEIGHT / 2.0);
    cub3d->draw->draw_end = (float)(cub3d->draw->wall_height / 2.0 + HEIGHT / 2.0);
    if (cub3d->draw->draw_start < 0)
        cub3d->draw->draw_start = 0;
    if (cub3d->draw->draw_end >= HEIGHT)
        cub3d->draw->draw_end = HEIGHT - 1;
	cub3d->draw->x++;
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
