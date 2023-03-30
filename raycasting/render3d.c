/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 02:41:37 by ramhouch          #+#    #+#             */
/*   Updated: 2023/03/30 03:27:36 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

static int	draw_ray(t_cub3d *cub3d, int dx, int dy, float angle)
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
		increment2[0] -= increment[0];
		increment2[1] -= increment[1];
		if (help_draw_line(cub3d, increment2))
			break ;
	}
	cub3d->inter = inter(cub3d, increment2);
	return (sqrt(pow(increment2[0] - cub3d->map->player.x, 2) + pow(increment2[1] - cub3d->map->player.y, 2)) * cos((angle - cub3d->map->player.angle) * PI / 180));
}

static int	right_color(int i)
{
	if (i == 1)
		return (get_color("46, 204, 113"));
	if (i == 2)
		return (get_color("52, 152, 219"));
	if (i == 3)
		return (get_color("192, 57, 43"));
	return (get_color("241, 196, 15"));
}

static void	draw_wall(t_cub3d *cub3d, int length, int i)
{
	int	y;

	y = 0;
	while (y < (HEIGHT - length) / 2)
	{
		my_mlx_pixel_put(cub3d->img3d, i, y, rgb_to_int(*(cub3d->map->ciel_color)));
		y++;
	}
	while (y < HEIGHT - ((HEIGHT - length) / 2))
	{
		my_mlx_pixel_put(cub3d->img3d, i, y, right_color(cub3d->inter));
		y++;
	}
	while (y < HEIGHT)
	{
		my_mlx_pixel_put(cub3d->img3d, i, y, rgb_to_int(*(cub3d->map->floor_color)));
		y++;
	}
}

void	raycasting(t_cub3d *cub3d, float a, float b)
{
	float	angel_size;
	float	start;
	int		i;

	angel_size = 60.0 / WIDTH;
	start = cub3d->map->player.angle - 30;
	i = 0;
	mlx_clear_window(cub3d->mlx3d, cub3d->win3d);
	while (i < WIDTH)
	{
		a = ((float)SIZE / draw_ray(cub3d, 0, 0, start));
		b = ((WIDTH / 2) / tan((VEW_ANGLE / 2) * PI / 180));
		draw_wall(cub3d, a * b, i);
		start += angel_size;
		i++;
	}
	mlx_put_image_to_window(cub3d->mlx3d, cub3d->win3d, cub3d->img3d.img, 0, 0);
}
