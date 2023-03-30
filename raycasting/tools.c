/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 03:37:48 by ramhouch          #+#    #+#             */
/*   Updated: 2023/03/30 23:00:28 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

void	init(t_cub3d *cub3d)
{
	if (ON2D)
	{
		cub3d->mlx = mlx_init();
		cub3d->win = mlx_new_window(cub3d->mlx, \
		(ft_strlen(cub3d->map->square_map[0]) - 1) * SIZE, \
		len_double(cub3d->map->square_map) * SIZE, "Cub3d");
		cub3d->img.img = mlx_new_image(cub3d->mlx, (ft_strlen(cub3d->map->square_map[0])) * SIZE, len_double(cub3d->map->square_map) * SIZE);
		cub3d->img.addr = mlx_get_data_addr(cub3d->img.img, &cub3d->img.bits_per_pixel, &cub3d->img.line_length, &cub3d->img.endian);
	}
	if (ON3D)
	{
		cub3d->mlx3d = mlx_init();
		cub3d->win3d = mlx_new_window(cub3d->mlx3d, WIDTH, HEIGHT, "Cub3d");
		cub3d->img3d.img = mlx_new_image(cub3d->mlx3d, WIDTH, HEIGHT + 1);
		cub3d->img3d.addr = mlx_get_data_addr(cub3d->img3d.img, &cub3d->img3d.bits_per_pixel, &cub3d->img3d.line_length, &cub3d->img3d.endian);
		cub3d->colors.e = get_color("46, 204, 113");
		cub3d->colors.n = get_color("52, 152, 219");
		cub3d->colors.s = get_color("192, 57, 43");
		cub3d->colors.w = get_color("244, 208, 63");
	}
}

int	get_color(char *text)
{
	int		c;
	char	**rgb;
	int		color;
	int		i;

	color = 0;
	i = 0;
	rgb = ft_split(text, ',');
	c = ft_atoi(rgb[0]) << 16;
	color += c;
	c = ft_atoi(rgb[1]) << 8;
	color += c;
	c = ft_atoi(rgb[2]);
	color += c;
	while (rgb[i])
		free(rgb[i++]);
	free(rgb);
	return (color);
}
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > WIDTH || x < 0 || y > HEIGHT || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
