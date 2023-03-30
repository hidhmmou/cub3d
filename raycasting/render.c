/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:06:15 by ramhouch          #+#    #+#             */
/*   Updated: 2023/03/30 03:27:28 by ramhouch         ###   ########.fr       */
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
			my_mlx_pixel_put(cub3d->img, x + i,  y + j, c);
			j++;
		}
		i++;
	}
}

int	help_draw_line(t_cub3d *cub3d, float *increment2)
{
	if (cub3d->map->square_map[(int)increment2[1] / SIZE] \
			[(int)increment2[0] / SIZE] == '1')
		return (1);
	if (cub3d->map->square_map[((int)increment2[1] + 1) / SIZE] \
		[(int)increment2[0] / SIZE] == '1'
		&& cub3d->map->square_map[(int)increment2[1] / SIZE] \
		[((int)increment2[0] + 1) / SIZE] == '1')
		return (1);
	if (cub3d->map->square_map[((int)increment2[1] + 1) / SIZE] \
		[(int)increment2[0] / SIZE] == '1'
		&& cub3d->map->square_map[(int)increment2[1] / SIZE] \
		[((int)increment2[0] + 1) / SIZE] == '1')
		return (1);
	if (cub3d->map->square_map[((int)increment2[1] - 1) / SIZE] \
		[(int)increment2[0] / SIZE] == '1'
		&& cub3d->map->square_map[(int)increment2[1] / SIZE] \
		[((int)increment2[0] + 1) / SIZE] == '1')
		return (1);
	return (0);
}

static void	draw_line(t_cub3d *cub3d, int dx, int dy, float angle)
{
	float	radians;
	int		steps;
	float	increment[2];
	float	increment2[2];

	radians = angle * PI / 180;
	dx = 500 * cos(radians) * -1;
	dy = 500 * sin(radians);
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
		my_mlx_pixel_put(cub3d->img, increment2[0], increment2[1], 0xFF0000);
		increment2[0] -= increment[0];
		increment2[1] -= increment[1];
		if (help_draw_line(cub3d, increment2))
			break ;
	}
}

static void	render_player(t_cub3d *cub3d)
{
	float	angel_size;
	float	start;
	int		i;

	angel_size = 60.0 / WIDTH;
	start = cub3d->map->player.angle - 30;
	i = 0;
	while (i < WIDTH)
	{
		draw_line(cub3d, 0, 0, start);
		start += angel_size;
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
	render_player(cub3d);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->img.img, 0, 0);
}
