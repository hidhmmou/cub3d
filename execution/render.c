/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:42:34 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/03/20 17:03:17 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

int get_color(char c)
{
	if (c == 'K' || c == ' ')
		return (16777215);
	if (c == '0')
		return (0);
	if (c == '1')
		return (16170000);
	return (0);
}

void	put_pixel_square(t_cub3d *cub3d, int x, int y, int color)
{
	int		i;
	int		j;

	i = 0;
	while (i < 32)
	{
		j = -1;
		while (++j < 32)
			mlx_pixel_put(cub3d->mlx, cub3d->win, y + j, x + i, color);
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
	while (cub3d->map->square_map[i])
	{
		j = 0;
		y = 0;
		while (cub3d->map->square_map[i][j])
		{
			put_pixel_square(cub3d, x, y, get_color(cub3d->map->square_map[i][j]));
			j++;
			y += 32;
		}
		i++;
		x += 32;
	}
}
