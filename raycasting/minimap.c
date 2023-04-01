/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:28:03 by ramhouch          #+#    #+#             */
/*   Updated: 2023/04/01 02:28:13 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"


static	int	check(t_cub3d *cub3d, int x, int y)
{
	int xp;
	int	yp;

	xp = cub3d->map->player.x * (((float)MINI_MAP_SIZE / (float)SIZE));
	yp = cub3d->map->player.y * (((float)MINI_MAP_SIZE / (float)SIZE));
	if (abs(x - xp) < (MINI_MAP_WIDTH / 2) && abs(y - yp) < (MINI_MAP_HEIGHT / 2))
		return (1);
	return (0);
}

static void	put_pixel(t_cub3d *cub3d, int x, int y, int color, int	*first, int *fx, int *fy)
{
	int	i;
	int	j;

	i = 0;
	while (i < MINI_MAP_SIZE && color)
	{
		j = 0;
		while (j < MINI_MAP_SIZE)
		{
			if (check(cub3d, x + i, y + j))
			{
				if (*first)
				{
					*first = 0;
					*fx = x + i;
					*fy = y + j;
					my_mlx_pixel_put2(&cub3d->img, 0,  0, color);
				}
				else
					my_mlx_pixel_put2(&cub3d->img, x + i - *fx,  y + j - *fy, color);
			}
			j++;
		}
		i++;
	}
}

void	clear_img(t_cub3d *cub3d)
{
	int	i;
	int	y;

	i = 0;
	while (i < MINI_MAP_WIDTH)
	{
		y = 0;
		while (y < MINI_MAP_HEIGHT)
		{
			my_mlx_pixel_put2(&cub3d->img, i,  y, 0x0AFFFFFF);
			y++;
		}
		i++;
	}
}
void	make_it_circular(t_cub3d *cub3d)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = MINI_MAP_HEIGHT / 2;
	y = MINI_MAP_HEIGHT / 2;
	i = 0;
	while (i < MINI_MAP_WIDTH)
	{
		j = 0;
		while (j < MINI_MAP_HEIGHT)
		{
			if (sqrt(pow(x - i, 2) + pow(y - j, 2)) > (MINI_MAP_HEIGHT / 2))
				my_mlx_pixel_put2(&cub3d->img, i,  j, 0xFFFFFFFF);
			j++;
		}
		i++;
	}
	
}

void	render_mini_map(t_cub3d *cub3d, int x, int y, int i)
{
	int		j;
	int		color;
	char	**str;
	int		fx;
	int		fy;
	int		first;

	str = cub3d->map->square_map;
	first = 1;
	clear_img(cub3d);
	while (str[i])
	{
		j = 0;
		x = 0;
		while (str[i][j])
		{
			if (str[i][j] == '1' || str[i][j] == ' ' || str[i][j] == 'K')
				color = get_color("100,100,100");
			else
				color = 0;
			put_pixel(cub3d, x, y, color, &first, &fx, &fy);
			j++;
			x += MINI_MAP_SIZE;
		}
		i++;
		y += MINI_MAP_SIZE;
	}
	j = cub3d->map->player.x * (((float)MINI_MAP_SIZE / (float)SIZE));
	color = cub3d->map->player.y * (((float)MINI_MAP_SIZE / (float)SIZE));
	my_mlx_pixel_put2(&cub3d->img, j - fx,  color - fy, 0xFF0000);
	my_mlx_pixel_put2(&cub3d->img, j - fx,  color - fy + 1, 0xFF0000);
	my_mlx_pixel_put2(&cub3d->img, j - fx + 1,  color - fy, 0xFF0000);
	my_mlx_pixel_put2(&cub3d->img, j - fx + 1,  color - fy + 1, 0xFF0000);
	make_it_circular(cub3d);
	mlx_put_image_to_window(cub3d->mlx3d, cub3d->win3d, cub3d->img.img, WIDTH - MINI_MAP_WIDTH - 20, HEIGHT - MINI_MAP_HEIGHT - 20);
}