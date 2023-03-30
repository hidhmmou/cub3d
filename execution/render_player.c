/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:36:04 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/03/30 00:14:50 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

int is_wall(char c)
{
	return (c == '1');
}

int	check_hit_wall(t_cub3d *cub3d, float pixel_y, float pixel_x, int size)
{
	if (is_wall(cub3d->map->square_map[(int)pixel_y / size][(int)pixel_x / size]))
		return (1);
	if (is_wall(cub3d->map->square_map[((int)pixel_y + 1) / size][(int)pixel_x / size])
		&& is_wall(cub3d->map->square_map[(int)pixel_y / size][((int)pixel_x + 1) / size]))
		return (1);
	if (is_wall(cub3d->map->square_map[((int)pixel_y - 1) / size][(int)pixel_x / size])
		&& is_wall(cub3d->map->square_map[(int)pixel_y / size][((int)pixel_x + 1) / size]))
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
	int 	i;

	i = -1;
	while (++i < cub3d->draw->draw_start)
		my_mlx_pixel_put(cub3d->img, cub3d->draw->x, i, shader(rgb_to_int(*cub3d->map->ciel_color), ((HEIGHT / 2.0) - i) * 100.0 / (HEIGHT / 2.0)));
	my_mlx_pixel_put(cub3d->img, cub3d->draw->x, i--, 0);
	while (++i <= cub3d->draw->draw_end)
		my_mlx_pixel_put(cub3d->img, cub3d->draw->x, i, shader(cub3d->draw->color, cub3d->draw->wall_height * 200 / HEIGHT));
	my_mlx_pixel_put(cub3d->img, cub3d->draw->x, i--, 0);
	while (++i < HEIGHT)
		my_mlx_pixel_put(cub3d->img, cub3d->draw->x, i, shader(rgb_to_int(*cub3d->map->floor_color), ((HEIGHT / 2.0) + i - HEIGHT) * 100.0 / (HEIGHT / 2.0)));
	cub3d->draw->x--;
}

void calc(t_cub3d *cub3d, double pixel_x, double pixel_y, double tmp[2])
{
	cub3d->draw->real_distance = sqrt(pow(pixel_x - tmp[0], 2) + pow(pixel_y - tmp[1], 2));
	cub3d->draw->distance = cub3d->draw->real_distance * (cos(cub3d->draw->radiant - to_radian(cub3d->map->player.angle)));
	cub3d->draw->distance_to_player = (double)((WIDTH / 2.0) / tan(60.0 / 2.0 * PI / 180.0));
	cub3d->draw->wall_height = (double)((double)SIZE / cub3d->draw->distance ) * cub3d->draw->distance_to_player;
    cub3d->draw->draw_start = (double)(HEIGHT / 2.0 - cub3d->draw->wall_height / 2.0);
    cub3d->draw->draw_end = (double)cub3d->draw->draw_start + (double)cub3d->draw->wall_height;
    if (cub3d->draw->draw_start < 0)
        cub3d->draw->draw_start = 0;
    if (cub3d->draw->draw_end >= HEIGHT)
        cub3d->draw->draw_end = HEIGHT - 1;
}

void	cast_ray(t_cub3d *cub3d)
{
	double	pixel_x;
	double	pixel_y;
	double	tmp[2];
	int 	i;

	i = -1;
	pixel_x = cub3d->map->player.x;
	pixel_y = cub3d->map->player.y;
	tmp[0] = pixel_x;
	tmp[1] = pixel_y;
	init_draw(cub3d);
	while (++i < 4000)
	{
		pixel_x += cub3d->draw->increment_x;
		pixel_y += cub3d->draw->increment_y;
		if (check_hit_wall(cub3d, pixel_y, pixel_x, SIZE))
		{
			check_direction(cub3d, pixel_y, pixel_x);
			break ;
		}
	}
	calc(cub3d, pixel_x, pixel_y, tmp);
	draw_wall(cub3d);
}

void	erase_minimap(t_cub3d *cub3d)
{
	int x;
	int y;

	x = 99 + cub3d->map->player.x / (float)SIZE * (float)cub3d->map->minimap_size;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
			my_mlx_pixel_put(cub3d->img_2d, x, y, 0xFFFF00FF);
	}
	x = -1;
	while (++x < WIDTH)
	{
		y = 99 + cub3d->map->player.y / (float)SIZE * (float)cub3d->map->minimap_size;
		while (++y < HEIGHT)
			my_mlx_pixel_put(cub3d->img_2d, x, y, 0xFFFF00FF);
	}
}

void show_2d_map(t_cub3d *cub3d)
{
	t_img img;
	int x;
	int y;

	if (cub3d->minimap > 0)
	{
		x = 100 - cub3d->map->player.x / (float)SIZE * (float)cub3d->map->minimap_size;
		y = 100 - cub3d->map->player.y / (float)SIZE * (float)cub3d->map->minimap_size;
		erase_minimap(cub3d);
		mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->img_2d->img,  x, y);
		return ;
	}
	x = WIDTH / 2 - cub3d->map->minimap_size * cub3d->map->max_len / 2;
	y = HEIGHT / 2 - cub3d->map->minimap_size * cub3d->map->len / 2;
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->img_2d->img, x, y);
	img.img = mlx_xpm_file_to_image(cub3d->mlx, "textures/back.xpm", &img.width, &img.height);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, img.img, 32, 32);
	mlx_destroy_image(cub3d->mlx, img.img);
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
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->img->img, 0, 0);
	show_2d_map(cub3d);
}
