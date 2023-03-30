/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:06:15 by ramhouch          #+#    #+#             */
/*   Updated: 2023/03/30 04:10:39 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

static void	put_pixel(t_cub3d *cub3d, int x, int y, int color)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	while (i < SIZE && color)
	{
		j = 0;
		if (i == SIZE - 1)
			color = get_color("0,130,0");
		while (j < SIZE)
		{
			c = color;
			if (j == 0)
				c = get_color("0,130,0");
			my_mlx_pixel_put(&cub3d->img, x + i,  y + j, c);
			j++;
		}
		i++;
	}
}

void	render_map(t_cub3d *cub3d, int x, int y, int i)
{
	int		j;
	int		color;
	char	**str;

	str = cub3d->map->square_map;
	mlx_clear_window(cub3d->mlx, cub3d->win);
	while (str[i])
	{
		j = 0;
		x = 0;
		while (str[i][j])
		{
			if (str[i][j] == '1' || str[i][j] == ' ')
				color = 0;
			else
				color = get_color("210, 180, 222");
			put_pixel(cub3d, x, y, color);
			j++;
			x += SIZE;
		}
		i++;
		y += SIZE;
	}
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->img.img, 0, 0);
}
