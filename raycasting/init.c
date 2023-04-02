/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 08:14:06 by ramhouch          #+#    #+#             */
/*   Updated: 2023/04/02 08:25:39 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

static void	help_int1(t_cub3d *cub3d)
{
	cub3d->mlx3d = mlx_init();
	cub3d->img3d.img = mlx_new_image(cub3d->mlx3d, WIDTH, HEIGHT + 1);
	cub3d->img3d.addr = mlx_get_data_addr(cub3d->img3d.img, \
		&cub3d->img3d.bits_per_pixel, &cub3d->img3d.line_length, \
		&cub3d->img3d.endian);
	cub3d->img.img = mlx_new_image(cub3d->mlx3d, \
		MINI_MAP_WIDTH, MINI_MAP_HEIGHT);
	cub3d->img.addr = mlx_get_data_addr(cub3d->img.img, \
		&cub3d->img.bits_per_pixel, \
		&cub3d->img.line_length, &cub3d->img.endian);
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
}

static void	help_int2(t_cub3d *cub3d)
{
	int	a;
	int	b;

	cub3d->last_m_p = -1;
	cub3d->imgs.minimap = mlx_xpm_file_to_image(cub3d->mlx3d, \
		"textures/minimap.xpm", &a, &b);
	cub3d->imgs.EA.img = mlx_xpm_file_to_image(cub3d->mlx3d, \
		"textures/EA.xpm", &a, &b);
	cub3d->imgs.EA.addr = mlx_get_data_addr(cub3d->imgs.EA.img, \
		&cub3d->imgs.EA.bits_per_pixel, &cub3d->imgs.EA.line_length, \
		&cub3d->imgs.EA.endian);
	cub3d->imgs.NO.img = mlx_xpm_file_to_image(cub3d->mlx3d, \
		"textures/NO.xpm", &a, &b);
	cub3d->imgs.NO.addr = mlx_get_data_addr(cub3d->imgs.NO.img, \
		&cub3d->imgs.NO.bits_per_pixel, &cub3d->imgs.NO.line_length, \
		&cub3d->imgs.NO.endian);
	cub3d->imgs.SO.img = mlx_xpm_file_to_image(cub3d->mlx3d, \
		"textures/SO.xpm", &a, &b);
	cub3d->imgs.SO.addr = mlx_get_data_addr(cub3d->imgs.SO.img, \
		&cub3d->imgs.SO.bits_per_pixel, &cub3d->imgs.SO.line_length, \
		&cub3d->imgs.SO.endian);
	cub3d->imgs.WE.img = mlx_xpm_file_to_image(cub3d->mlx3d, \
		"textures/WE.xpm", &a, &b);
}

static void	help_int3(t_cub3d *cub3d)
{
	help_int1(cub3d);
	help_int2(cub3d);
	cub3d->imgs.WE.addr = mlx_get_data_addr(cub3d->imgs.WE.img, \
		&cub3d->imgs.WE.bits_per_pixel, &cub3d->imgs.WE.line_length, \
		&cub3d->imgs.WE.endian);
	cub3d->bigmap.s = (float)WIDTH / \
		(ft_strlen(cub3d->map->square_map[0]) * SIZE);
	if (cub3d->bigmap.s > (float)HEIGHT / \
		(len_double(cub3d->map->square_map) * SIZE))
		cub3d->bigmap.s = (float)HEIGHT / \
			(len_double(cub3d->map->square_map) * SIZE);
	cub3d->bigmap.size = (float)SIZE * cub3d->bigmap.s;
	cub3d->bigmap.with = (ft_strlen(cub3d->map->square_map[0]) - 1) \
		* cub3d->bigmap.size - 10;
	cub3d->bigmap.hight = len_double(cub3d->map->square_map) \
		* cub3d->bigmap.size;
	cub3d->bigmap.img.img = mlx_new_image(cub3d->mlx3d, \
		cub3d->bigmap.with, cub3d->bigmap.hight);
	cub3d->bigmap.img.addr = mlx_get_data_addr(cub3d->bigmap.img.img, \
		&cub3d->bigmap.img.bits_per_pixel, \
		&cub3d->bigmap.img.line_length, &cub3d->bigmap.img.endian);
}

void	init(t_cub3d *cub3d)
{
	if (ON2D)
	{
		cub3d->mlx = mlx_init();
		cub3d->win = mlx_new_window(cub3d->mlx, \
		(ft_strlen(cub3d->map->square_map[0]) - 1) * SIZE, \
		len_double(cub3d->map->square_map) * SIZE, "Cub3d");
		cub3d->img.img = mlx_new_image(cub3d->mlx, \
			(ft_strlen(cub3d->map->square_map[0])) * SIZE, \
			len_double(cub3d->map->square_map) * SIZE);
		cub3d->img.addr = mlx_get_data_addr(cub3d->img.img, \
			&cub3d->img.bits_per_pixel, \
			&cub3d->img.line_length, &cub3d->img.endian);
	}
	if (ON3D)
		help_int3(cub3d);
}
