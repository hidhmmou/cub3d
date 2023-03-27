/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2d_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:42:34 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/03/26 22:02:13 by hidhmmou         ###   ########.fr       */
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
	while (i < SIZE)
	{
		j = -1;
		while (++j < SIZE)
			my_mlx_pixel_put_2d(cub3d, y + j, x + i, color);
		i++;
	}
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

	put_pixel_square(cub3d, 0, 0, 0xFF0000);

	while (cub3d->map->square_map[i])
	{
		j = 0;
		y = 0;
		while (cub3d->map->square_map[i][j])
		{
			if (cub3d->map->square_map[i][j] != '0')
				put_pixel_square(cub3d, x, y, get_color(cub3d->map->square_map[i][j]));
			j++;
			y += SIZE;
		}
		i++;
		x += SIZE;
	}
	render_player(cub3d);
}
