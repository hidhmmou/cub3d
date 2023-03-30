/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:05:32 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/03/30 22:43:54 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parsing.h"
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
	fill_content(av[1], *cub3d);
	check_content(*cub3d);
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
		right(cub3d, 0, 0);
	else if (keycode == LEFT_MOVE)
		left(cub3d, 0, 0);
	else if (keycode == DOWN_MOVE)
		down(cub3d, 0, 0);
	else if (keycode == UP_MOVE)
		up(cub3d, 0, 0);
	if (keycode == ESC)
		close_window2d(cub3d);
	return (0);
}
static int	key_hook3d(int keycode, t_cub3d *cub3d)
{
	if (keycode == RIGHT_ROW)
	{
		cub3d->map->player.angle += RET_ANGLE;
		raycasting(cub3d, 0);
	}
	else if (keycode == LEFT_ROW)
	{
		cub3d->map->player.angle -= RET_ANGLE;
		raycasting(cub3d, 0);
	}
	else if (keycode == RIGHT_MOVE)
		right3d(cub3d, 0, 0);
	else if (keycode == LEFT_MOVE)
		left3d(cub3d, 0, 0);
	else if (keycode == DOWN_MOVE)
		down3d(cub3d, 0, 0);
	else if (keycode == UP_MOVE)
		up3d(cub3d, 0, 0);
	if (keycode == ESC)
		close_window3d(cub3d);
	return (0);
}

int	main(int ac, char *av[])
{
	t_cub3d	*cub3d;

	parsing(&cub3d, av, ac);
	init(cub3d);
	if (ON2D)
	{
		render_map(cub3d, 0, 0, 0);
		mlx_hook(cub3d->win, 2, 0, key_hook, cub3d);
		mlx_hook(cub3d->win, 17, 0, &close_window2d, cub3d);
		mlx_loop(cub3d->mlx);
	}
	if (ON3D)
	{
		raycasting(cub3d, 0);
		mlx_hook(cub3d->win3d, 2, 0, key_hook3d, cub3d);
		mlx_hook(cub3d->win3d, 17, 0, &close_window3d, cub3d);
		mlx_loop(cub3d->mlx3d);
	}
	return (0);
}
