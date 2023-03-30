/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:05:32 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/03/29 06:53:38 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/raycasting.h"

void	parsing(t_cub3d **cub3d, char **av, int ac)
{
	if (ac != 2)
		ft_error("Usage : ./cub3d path/to/map", NULL);
	pre_check_map(av[1]);
	*cub3d = malloc(sizeof(t_cub3d));
	(*cub3d)->map = malloc(sizeof(t_map));
	(*cub3d)->map->ciel_color = malloc(sizeof(t_color));
	(*cub3d)->map->floor_color = malloc(sizeof(t_color));
	(*cub3d)->map->cc_color = rgb_to_int(*((*cub3d)->map->ciel_color));
	(*cub3d)->map->ff_color = rgb_to_int(*((*cub3d)->map->floor_color));
	fill_content(av[1], *cub3d);
	check_content(*cub3d);
	if (ON2D)
	{
		(*cub3d)->mlx = mlx_init();
		(*cub3d)->win = mlx_new_window((*cub3d)->mlx, \
		(ft_strlen((*cub3d)->map->square_map[0])) * SIZE, \
		len_double((*cub3d)->map->square_map) * SIZE, "Cub3d");
	}
	if (ON3D)
	{
		(*cub3d)->mlx3d = mlx_init();
		(*cub3d)->win3d = mlx_new_window((*cub3d)->mlx3d, WIDTH, HEIGHT, "Cub3d");
	}
}

static int	key_hook(int keycode, t_cub3d *cub3d)
{
	if (keycode == RIGHT_ROW)
	{
		cub3d->map->player.angle += RET_ANGLE;
		render_map(cub3d, 0, 0, 0);
	}
	else if (keycode == LEFT_ROW)
	{
		cub3d->map->player.angle -= RET_ANGLE;
		render_map(cub3d, 0, 0, 0);
	}
	else if (keycode == RIGHT_MOVE)
		right(cub3d, 0, 0, 0);
	else if (keycode == LEFT_MOVE)
		left(cub3d, 0, 0, 0);
	else if (keycode == DOWN_MOVE)
		down(cub3d, 0, 0, 0);
	else if (keycode == UP_MOVE)
		up(cub3d, 0, 0, 0);
	if (keycode == ESC)
		close_window(cub3d);
	return (0);
}

static int	key_hook3d(int keycode, t_cub3d *cub3d)
{
	if (keycode == RIGHT_ROW)
	{
		cub3d->map->player.angle += RET_ANGLE;
		raycasting(cub3d, 0, 0);
	}
	else if (keycode == LEFT_ROW)
	{
		cub3d->map->player.angle -= RET_ANGLE;
		raycasting(cub3d, 0, 0);
	}
	else if (keycode == RIGHT_MOVE)
		right3d(cub3d, 0, 0, 0);
	else if (keycode == LEFT_MOVE)
		left3d(cub3d, 0, 0, 0);
	else if (keycode == DOWN_MOVE)
		down3d(cub3d, 0, 0, 0);
	else if (keycode == UP_MOVE)
		up3d(cub3d, 0, 0, 0);
	if (keycode == ESC)
		close_window3d(cub3d);
	return (0);
}

int	main(int ac, char *av[])
{
	t_cub3d	*cub3d;

	parsing(&cub3d, av, ac);
	if (ON3D)
	{
		cub3d->img3d.img = mlx_new_image(cub3d->mlx3d, WIDTH, HEIGHT);
		cub3d->img3d.addr = mlx_get_data_addr(cub3d->img3d.img, &cub3d->img3d.bits_per_pixel, &cub3d->img3d.line_length, &cub3d->img3d.endian);
		raycasting(cub3d, 0 , 0);
		mlx_hook(cub3d->win3d, 2, 0, key_hook3d, cub3d);
		mlx_hook(cub3d->win3d, 17, 0, &close_window3d, cub3d);
		mlx_loop(cub3d->mlx3d);
	}
	if (ON2D)
	{
		cub3d->img.img = mlx_new_image(cub3d->mlx, (ft_strlen(cub3d->map->square_map[0])) * SIZE, len_double(cub3d->map->square_map) * SIZE);
		cub3d->img.addr = mlx_get_data_addr(cub3d->img.img, &cub3d->img.bits_per_pixel, &cub3d->img.line_length, &cub3d->img.endian);
		render_map(cub3d, 0, 0, 0);
		mlx_hook(cub3d->win, 2, 0, key_hook, cub3d);
		mlx_hook(cub3d->win, 17, 0, &close_window, cub3d);
		mlx_loop(cub3d->mlx);
	}
	return (0);
}
