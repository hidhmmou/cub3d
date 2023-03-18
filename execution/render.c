/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:06:15 by ramhouch          #+#    #+#             */
/*   Updated: 2023/03/16 22:24:40 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

static void	put_pixel(t_cub3d *cub3d, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 32)
	{
		j = 0;
		while (j < 32)
		{
			mlx_pixel_put(cub3d->mlx, cub3d->win, x + i, y + j, color);
			j++;
		}
		i++;
	}
}
void	render_player(t_cub3d *cub3d)
{
	put_pixel(cub3d, cub3d->map->player.x * 32, cub3d->map->player.y * 32, get_color("255,0,0"));
}

void	render_map(t_cub3d *cub3d, int x, int y)
{
	int		i;
	int		j;
	int 	color;
	char	**str;

	i = 0;
	str = cub3d->map->square_map;
	mlx_clear_window(cub3d->mlx, cub3d->win);
	while (str[i])
	{
		j = 0;
		x = 0;
		while (str[i][j])
		{
			if (str[i][j] == '0')
				color = 16777215;
			else
				color = 0;
			put_pixel(cub3d, x, y, color);
			j++;
			x += 32;
		}
		i++;
		y += 32;
	}
}
