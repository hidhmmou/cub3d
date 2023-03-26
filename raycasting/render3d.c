/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 02:17:48 by ramhouch          #+#    #+#             */
/*   Updated: 2023/03/26 03:15:51 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

static int	help_help_draw_ray(t_cub3d *cub3d, float *increment2)
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
static int	help_draw_ray(t_cub3d *cub3d, float *increment2, int index)
{
	if (help_help_draw_ray(cub3d, increment2))
	{
		cub3d->rays[index].x = increment2[0];
		cub3d->rays[index].y = increment2[1];
		cub3d->rays[index].inter = inter(cub3d, increment2);
		return (1);
	}
	return (0);
}

static int	draw_ray(t_cub3d *cub3d, int *d, float angle, int index)
{
	int		i;
	int		steps;
	float	increment[2];
	float	increment2[2];

	i = 0;
	d[0] = 500 * cos(angle * PI / 180) * -1;
	d[1] = 500 * sin(angle * PI / 180);
	if (abs(d[0]) > abs(d[1]))
		steps = abs(d[0]);
	else
		steps = abs(d[1]);
	increment[0] = d[0] / (float)steps;
	increment[1] = d[1] / (float)steps;
	increment2[0] = cub3d->map->player.x;
	increment2[1] = cub3d->map->player.y;
	while (1)
	{
		i++;
		increment2[0] -= increment[0];
		increment2[1] -= increment[1];
		if (help_draw_ray(cub3d, increment2, index))
			break ;
	}
	return (i);
}

void	raycasting(t_cub3d *cub3d)
{
	float	angel_size;
	float	start;
	int		i;
	int		d[2];

	angel_size = 60.0 / WIDTH;
	start = cub3d->map->player.angle - 30;
	i = 0;
	while (i < WIDTH)
	{
		cub3d->rays[i].length = draw_ray(cub3d, d, start, i);
		start += angel_size;
		i++;
	}
}
void	render_fc(t_cub3d *cub3d)
{
	int		j;
	int		i;
	char	**str;

	str = cub3d->map->square_map;
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (i <= HEIGHT / 2)
				mlx_pixel_put(cub3d->mlx, cub3d->win, j, i, rgb_to_int(*(cub3d->map->ciel_color)));
			else
				mlx_pixel_put(cub3d->mlx, cub3d->win, j, i, rgb_to_int(*(cub3d->map->floor_color)));
			j++;
		}
		i++;
	}
}
