/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 03:37:48 by ramhouch          #+#    #+#             */
/*   Updated: 2023/04/02 01:45:51 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

void	init(t_cub3d *cub3d)
{
	int	a;
	int	b;

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
		cub3d->img3d.img = mlx_new_image(cub3d->mlx3d, WIDTH, HEIGHT + 1);
		cub3d->img3d.addr = mlx_get_data_addr(cub3d->img3d.img, &cub3d->img3d.bits_per_pixel, &cub3d->img3d.line_length, &cub3d->img3d.endian);
		cub3d->img.img = mlx_new_image(cub3d->mlx3d, MINI_MAP_WIDTH, MINI_MAP_HEIGHT);
		cub3d->img.addr = mlx_get_data_addr(cub3d->img.img, &cub3d->img.bits_per_pixel, &cub3d->img.line_length, &cub3d->img.endian);
		cub3d->win3d = mlx_new_window(cub3d->mlx3d, WIDTH, HEIGHT, "Cub3d");
		cub3d->colors.e = get_color("46, 204, 113");
		cub3d->colors.n = get_color("52, 152, 219");
		cub3d->colors.s = get_color("192, 57, 43");
		cub3d->colors.w = get_color("244, 208, 63");
		cub3d->events.down_move = 0;
		cub3d->events.esc = 0;
		cub3d->events.left_move = 0;
		cub3d->events.left_row = 0;
		cub3d->events.right_move = 0;
		cub3d->events.right_row = 0;
		cub3d->events.up_move = 0;
		cub3d->events.map = 0;
		cub3d->mmap = 0;
		cub3d->draw.old_color = 0;
		cub3d->last_m_p = -1;
		cub3d->imgs.minimap = mlx_xpm_file_to_image(cub3d->mlx3d, "textures/minimap.xpm", &a, &b);
		cub3d->imgs.EA.img = mlx_xpm_file_to_image(cub3d->mlx3d, "textures/EA.xpm", &a, &b);
		cub3d->imgs.EA.addr = mlx_get_data_addr(cub3d->imgs.EA.img, &cub3d->imgs.EA.bits_per_pixel, &cub3d->imgs.EA.line_length, &cub3d->imgs.EA.endian);
		cub3d->imgs.NO.img = mlx_xpm_file_to_image(cub3d->mlx3d, "textures/NO.xpm", &a, &b);
		cub3d->imgs.NO.addr = mlx_get_data_addr(cub3d->imgs.NO.img, &cub3d->imgs.NO.bits_per_pixel, &cub3d->imgs.NO.line_length, &cub3d->imgs.NO.endian);
		cub3d->imgs.SO.img = mlx_xpm_file_to_image(cub3d->mlx3d, "textures/SO.xpm", &a, &b);
		cub3d->imgs.SO.addr = mlx_get_data_addr(cub3d->imgs.SO.img, &cub3d->imgs.SO.bits_per_pixel, &cub3d->imgs.SO.line_length, &cub3d->imgs.SO.endian);
		cub3d->imgs.WE.img = mlx_xpm_file_to_image(cub3d->mlx3d, "textures/WE.xpm", &a, &b);
		cub3d->imgs.WE.addr = mlx_get_data_addr(cub3d->imgs.WE.img, &cub3d->imgs.WE.bits_per_pixel, &cub3d->imgs.WE.line_length, &cub3d->imgs.WE.endian);
		cub3d->bigmap.s = (float)WIDTH / (ft_strlen(cub3d->map->square_map[0]) * SIZE);
		if (cub3d->bigmap.s > (float)HEIGHT / (len_double(cub3d->map->square_map) * SIZE))
			cub3d->bigmap.s = (float)HEIGHT / (len_double(cub3d->map->square_map) * SIZE);
		cub3d->bigmap.size = (float)SIZE * cub3d->bigmap.s;
		cub3d->bigmap.with = (ft_strlen(cub3d->map->square_map[0]) - 1) * cub3d->bigmap.size - 10;
		cub3d->bigmap.hight = len_double(cub3d->map->square_map) * cub3d->bigmap.size;
		cub3d->bigmap.img.img = mlx_new_image(cub3d->mlx3d, cub3d->bigmap.with , cub3d->bigmap.hight);
		cub3d->bigmap.img.addr = mlx_get_data_addr(cub3d->bigmap.img.img, &cub3d->bigmap.img.bits_per_pixel, &cub3d->bigmap.img.line_length, &cub3d->bigmap.img.endian);
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

void	my_mlx_pixel_put2(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > MINI_MAP_WIDTH || x < 0 || y > MINI_MAP_HEIGHT || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
void	my_mlx_pixel_put3(t_data *data, int *xy, int color, int	*limits)
{
	char	*dst;
	if (xy[0] > limits[0] || xy[0] < 0 || xy[1] > limits[1] || xy[1] < 0)
		return ;
	dst = data->addr + (xy[1] * data->line_length + xy[0] * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int	plus_transp(t_cub3d *cub3d, int color, int y, int i)
{
	int	plus;
	int	percent;

	if (i)
	{
		plus = 255;
		percent = cub3d->draw.wall_height * 100 / HEIGHT;
		if (percent > 100)
			percent = 100;
		plus -= plus * percent / 100;
		plus = plus << 24;
		return (plus + cub3d->draw.color);
	}
	plus = (float)y / 2.5;
	plus = plus << 24;
	return (plus + color);
}

int	get_pexel_from_img(t_data *data, int x, int y)
{
	char	*dst;

	if (x > SIZE || x < 0 || y > SIZE || y < 0)
		return (-1);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}
