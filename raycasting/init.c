/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 08:14:06 by ramhouch          #+#    #+#             */
/*   Updated: 2023/04/04 01:20:48 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

static void	peint_error()
{
	printf("Bad textures\n");
	exit(0);
}

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

	cub3d->events.shoot = 0;
	cub3d->events.shoot2 = 0;
	cub3d->last_m_p = -1;
	cub3d->imgs.minimap = mlx_xpm_file_to_image(cub3d->mlx3d, \
		"textures/minimap.xpm", &a, &b);
	cub3d->imgs.ea.img = mlx_xpm_file_to_image(cub3d->mlx3d, \
		"textures/EA.xpm", &cub3d->imgs.ea.width, &cub3d->imgs.ea.hight);
	if (!cub3d->imgs.ea.img)
		peint_error();
	cub3d->imgs.ea.addr = mlx_get_data_addr(cub3d->imgs.ea.img, \
		&cub3d->imgs.ea.bits_per_pixel, &cub3d->imgs.ea.line_length, \
		&cub3d->imgs.ea.endian);
	cub3d->imgs.no.img = mlx_xpm_file_to_image(cub3d->mlx3d, \
		"textures/NO.xpm", &cub3d->imgs.no.width, &cub3d->imgs.no.hight);
	if (!cub3d->imgs.no.img)
		peint_error();
	cub3d->imgs.no.addr = mlx_get_data_addr(cub3d->imgs.no.img, \
		&cub3d->imgs.no.bits_per_pixel, &cub3d->imgs.no.line_length, \
		&cub3d->imgs.no.endian);
	cub3d->imgs.so.img = mlx_xpm_file_to_image(cub3d->mlx3d, \
		"textures/SO.xpm", &cub3d->imgs.so.width, &cub3d->imgs.so.hight);
	if (!cub3d->imgs.so.img)
		peint_error();
	cub3d->imgs.so.addr = mlx_get_data_addr(cub3d->imgs.so.img, \
		&cub3d->imgs.so.bits_per_pixel, &cub3d->imgs.so.line_length, \
		&cub3d->imgs.so.endian);
	cub3d->imgs.we.img = mlx_xpm_file_to_image(cub3d->mlx3d, \
		"textures/WE.xpm", &cub3d->imgs.we.width, &cub3d->imgs.we.hight);
	if (!cub3d->imgs.we.img)
		peint_error();
}

static void	help_int3(t_cub3d *cub3d)
{
	help_int1(cub3d);
	help_int2(cub3d);
	cub3d->imgs.we.addr = mlx_get_data_addr(cub3d->imgs.we.img, \
		&cub3d->imgs.we.bits_per_pixel, &cub3d->imgs.we.line_length, \
		&cub3d->imgs.we.endian);
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
	int	a;
	int	b;

	if (ON2D)
	{
		cub3d->mlx = mlx_init();
		cub3d->width = (ft_strlen(cub3d->map->square_map[0])) * SIZE;
		cub3d->hight = len_double(cub3d->map->square_map) * SIZE;
		cub3d->win = mlx_new_window(cub3d->mlx, cub3d->width - SIZE, cub3d->hight, "Cub3d");
		cub3d->img.img = mlx_new_image(cub3d->mlx, cub3d->width, cub3d->hight);
		cub3d->img.addr = mlx_get_data_addr(cub3d->img.img, \
			&cub3d->img.bits_per_pixel, \
			&cub3d->img.line_length, &cub3d->img.endian);
	}
	if (ON3D)
	{
		help_int3(cub3d);
		cub3d->gun.g0 = mlx_xpm_file_to_image(cub3d->mlx3d, \
		"textures/gun/0.xpm", &a, &b);
		cub3d->gun.g1 = mlx_xpm_file_to_image(cub3d->mlx3d, \
		"textures/gun/1.xpm", &a, &b);
		cub3d->gun.g2 = mlx_xpm_file_to_image(cub3d->mlx3d, \
		"textures/gun/2.xpm", &a, &b);
		cub3d->gun.g3 = mlx_xpm_file_to_image(cub3d->mlx3d, \
		"textures/gun/3.xpm", &a, &b);
		cub3d->gun.g4 = mlx_xpm_file_to_image(cub3d->mlx3d, \
		"textures/gun/4.xpm", &a, &b);
		cub3d->gun.g5 = mlx_xpm_file_to_image(cub3d->mlx3d, \
		"textures/gun/5.xpm", &a, &b);
		cub3d->gun.img = cub3d->gun.g0;
		cub3d->events.old_img = cub3d->gun.img;
		cub3d->imgs.door.img = mlx_xpm_file_to_image(cub3d->mlx3d, \
			"textures/door.xpm", &cub3d->imgs.door.width, &cub3d->imgs.door.hight);
		cub3d->imgs.start = mlx_xpm_file_to_image(cub3d->mlx3d, \
			"textures/cub3d.xpm", &a, &b);
		cub3d->imgs.door.addr = mlx_get_data_addr(cub3d->imgs.door.img, \
			&cub3d->imgs.door.bits_per_pixel, &cub3d->imgs.door.line_length, \
			&cub3d->imgs.door.endian);
		cub3d->events.closed = 0;
		cub3d->events.start = 0;
	}
}
