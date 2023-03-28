/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2d_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:42:34 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/03/28 15:54:07 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

int get_color(char c)
{
	if (c == 'K' || c == ' ')
		return (0xFF4392F1);
	if (c == '1')
		return (0x002C54);
	if (c == '0' || in_set(c, "NSWE"))
		return (0x4CFF5733);
	if (c == '\n')
		return (0xFF00FF00);
	return (0);
}


// fdc500

void	put_pixel_square(t_cub3d *cub3d, int x, int y, int color)
{
	int		i;
	int		j;

	i = 0;
	while (i < SIZE_2D)
	{
		j = -1;
		while (++j < SIZE_2D)
		{	
			my_mlx_pixel_put(cub3d->img_2d, y + j, x + i, color);
		}
		i++;
	}
	j = -1;
}


void render_view(t_cub3d *cub3d, int is_mid, int size_2d)
{
	float	pixel_x;
	float	pixel_y;
	float	tmp[2];

	pixel_x = (float)cub3d->map->player.x / SIZE * size_2d;
	pixel_y = (float)cub3d->map->player.y / SIZE * size_2d;
	tmp[0] = pixel_x;
	tmp[1] = pixel_y;
	init_draw(cub3d);
	while (!check_hit_wall(cub3d, pixel_y, pixel_x, SIZE_2D))
	{
		if (!is_mid)
			my_mlx_pixel_put(cub3d->img_2d, pixel_x, pixel_y, 0xFF0000);
		else
			my_mlx_pixel_put(cub3d->img_2d, pixel_x, pixel_y, 0x00FF00);
		pixel_x += cub3d->draw->increment_x;
		pixel_y += cub3d->draw->increment_y;
	}
	put_player(cub3d, tmp);
	my_mlx_pixel_put(cub3d->img_2d, pixel_x, pixel_y, 0x00FF00);
	my_mlx_pixel_put(cub3d->img_2d, pixel_x - 1, pixel_y - 1, 0x00FF00);
}

void	render_background(t_cub3d *cub3d, int size)
{
	int	i;
	int	j;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	
	while (cub3d->map->square_map[i])
	{
		j = 0;
		y = 0;
		while (cub3d->map->square_map[i][j])
		{
			if (cub3d->map->square_map[i][j])
				put_pixel_square(cub3d, x, y, get_color(cub3d->map->square_map[i][j]));
			j++;
			y += size;
		}
		i++;
		x += size;
	}
}

void	mini_map(t_cub3d *cub3d, int size)
{
	int i;

	i = 0;

	render_background(cub3d, size);
	cub3d->draw->ray_angle = cub3d->map->player.angle - 30;
	while (++i <= WIDTH)
		render_view(cub3d, 0, size);
	cub3d->draw->ray_angle = cub3d->map->player.angle;
	render_view(cub3d, 1, size);
}

void	render_map_2d(t_cub3d *cub3d)
{
	mlx_clear_window(cub3d->mlx, cub3d->win);
	if (cub3d->minimap > 0)
		mini_map(cub3d, SIZE_2D);
	else
		mini_map(cub3d, SIZE_BIG_2D);
	render_player(cub3d);
}
