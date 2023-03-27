/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2d_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:42:34 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/03/27 17:12:43 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

int get_color(char c)
{
	if (c == 'K' || c == ' ')
		return (2508371);
	if (c == '1')
		return (15320170);
	return (0);
}

void	put_pixel_square(t_cub3d *cub3d, int x, int y, int color)
{
	int		i;
	int		j;

	i = 0;
	while (i < SIZE_2D)
	{
		j = -1;
		while (++j < SIZE_2D)
			my_mlx_pixel_put_2d(cub3d, y + j, x + i, color);
		i++;
	}
}


void render_view(t_cub3d *cub3d, int is_mid)
{
	float	pixel_x;
	float	pixel_y;
	float	tmp[2];

	pixel_x = (float)cub3d->map->player.x / SIZE * SIZE_2D;
	pixel_y = (float)cub3d->map->player.y / SIZE * SIZE_2D;
	tmp[0] = pixel_x;
	tmp[1] = pixel_y;
	init_draw(cub3d);
	while (!check_hit_wall_2d(cub3d, pixel_y, pixel_x))
	{
		if (!is_mid)
			my_mlx_pixel_put_2d(cub3d, pixel_x, pixel_y, 0xFF0000);
		else
			my_mlx_pixel_put_2d(cub3d, pixel_x, pixel_y, 0x00FF00);
		pixel_x += cub3d->draw->increment_x;
		pixel_y += cub3d->draw->increment_y;
	}
	put_player(cub3d, tmp);
	my_mlx_pixel_put_2d(cub3d, pixel_x, pixel_y, 0x00FF00);
	my_mlx_pixel_put_2d(cub3d, pixel_x - 1, pixel_y - 1, 0x00FF00);
}

void	render_background(t_cub3d *cub3d)
{
	int	i;
	int	j;
	int x;
	int y;

	i = 0;
	x = 0;
	while (cub3d->map->square_map[i])
	{
		j = 0;
		y = 0;
		while (cub3d->map->square_map[i][j])
		{
			if (cub3d->map->square_map[i][j] != '0')
				put_pixel_square(cub3d, x, y, get_color(cub3d->map->square_map[i][j]));
			j++;
			y += SIZE_2D;
		}
		i++;
		x += SIZE_2D;
	}
}

void	mini_map(t_cub3d *cub3d)
{
	int i;

	i = 0;

	render_background(cub3d);
	cub3d->draw->ray_angle = cub3d->map->player.angle - 30;
	while (++i <= WIDTH)
		render_view(cub3d, 0);
	cub3d->draw->ray_angle = cub3d->map->player.angle;
	render_view(cub3d, 1);
}

void	render_map_2d(t_cub3d *cub3d)
{
	mlx_clear_window(cub3d->mlx, cub3d->win);
	mlx_clear_window(cub3d->mlx, cub3d->win_3d);
	mini_map(cub3d);
	render_player(cub3d);
}
