/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:06:15 by ramhouch          #+#    #+#             */
/*   Updated: 2023/03/18 23:00:21 by ramhouch         ###   ########.fr       */
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

void	draw_line(t_cub3d *cub3d, int dx, int dy, int angle)
{
	float	radians;
	int		steps;
	float	increment[2];
	float	increment2[2];

	radians = angle * PI / 180;
	dx = 200 * cos(radians) * -1;
	dy = 200 * sin(radians);
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	increment[0] = dx / (float)steps;
	increment[1] = dy / (float)steps;
	increment2[0] = cub3d->map->player.x;
	increment2[1] = cub3d->map->player.y;
	while (1)
	{
		mlx_pixel_put(cub3d->mlx, cub3d->win,
			increment2[0], increment2[1], 0xFF0000);
		if (cub3d->map->square_map[(int)increment2[1] / 32][(int)increment2[0] / 32] == '1')
			break ;
		increment2[0] += increment[0];
		increment2[1] += increment[1];
	}
}

static void	render_player(t_cub3d *cub3d)
{
	draw_line(cub3d, 0, 0, cub3d->map->player.angle);
	mlx_pixel_put(cub3d->mlx, cub3d->win, cub3d->map->player.x, cub3d->map->player.y, 0x00FF00);
	mlx_pixel_put(cub3d->mlx, cub3d->win, cub3d->map->player.x, cub3d->map->player.y + 1, 0x00FF00);
	mlx_pixel_put(cub3d->mlx, cub3d->win, cub3d->map->player.x, cub3d->map->player.y + 2, 0x00FF00);
	mlx_pixel_put(cub3d->mlx, cub3d->win, cub3d->map->player.x + 1, cub3d->map->player.y, 0x00FF00);
	mlx_pixel_put(cub3d->mlx, cub3d->win, cub3d->map->player.x + 1, cub3d->map->player.y + 1, 0x00FF00);
	mlx_pixel_put(cub3d->mlx, cub3d->win, cub3d->map->player.x + 1, cub3d->map->player.y + 2, 0x00FF00);
	mlx_pixel_put(cub3d->mlx, cub3d->win, cub3d->map->player.x + - 1, cub3d->map->player.y, 0x00FF00);
	mlx_pixel_put(cub3d->mlx, cub3d->win, cub3d->map->player.x + - 1, cub3d->map->player.y + 1, 0x00FF00);
	mlx_pixel_put(cub3d->mlx, cub3d->win, cub3d->map->player.x + - 1, cub3d->map->player.y + 2, 0x00FF00);
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
			if (str[i][j] == '1')
				color = 0;
			else
				color = 16777215;
			put_pixel(cub3d, x, y, color);
			j++;
			x += 32;
		}
		i++;
		y += 32;
	}
	render_player(cub3d);
}
