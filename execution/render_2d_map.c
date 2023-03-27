/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2d_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:42:34 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/03/27 15:29:40 by hidhmmou         ###   ########.fr       */
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
	while (i < 1)
	{
		j = -1;
		while (++j < SIZE_2D)
			my_mlx_pixel_put_2d(cub3d, y + j, x + i, color);
		i++;
	}
	while (i < SIZE_2D)
	{
		j = -1;
		while (++j < SIZE_2D)
			my_mlx_pixel_put_2d(cub3d, y + j, x + i, color);
		i++;
	}
}

void render_player_2d(t_cub3d *cub3d)
{
	float	pixel_x;
	float	pixel_y;
	float	tmp[2];

	pixel_x = (float)cub3d->map->player.x / SIZE * SIZE_2D;
	pixel_y = (float)cub3d->map->player.y / SIZE * SIZE_2D;
	tmp[0] = pixel_x;
	tmp[1] = pixel_y;
	init_draw(cub3d);
	int i = 0;
	while (i++ < 30)
	{
		my_mlx_pixel_put_2d(cub3d, pixel_x, pixel_y, 0xFF0000);
		pixel_x += cub3d->draw->increment_x;
		pixel_y += cub3d->draw->increment_y;
		//if (check_hit_wall(cub3d, pixel_y, pixel_x))
		//{
		//	check_direction(cub3d, pixel_y, pixel_x);
		//	break ;
		//}
	}
	put_player(cub3d, tmp);
}

void	render_map_2d(t_cub3d *cub3d)
{
	int	i;
	int	j;
	int x;
	int y;

	i = 0;
	x = 0;
	mlx_clear_window(cub3d->mlx, cub3d->win);
	mlx_clear_window(cub3d->mlx, cub3d->win_3d);
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
	render_player_2d(cub3d);
	render_player(cub3d);
}
