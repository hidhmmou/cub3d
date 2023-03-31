/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 00:33:10 by ramhouch          #+#    #+#             */
/*   Updated: 2023/03/31 01:08:37 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

int	key_hook(int keycode, t_cub3d *cub3d)
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
int	press(int keycode, t_cub3d *cub3d)
{
	if (keycode == RIGHT_ROW)
		cub3d->events.right_row = 1;
	else if (keycode == LEFT_ROW)
		cub3d->events.left_row = 1;
	else if (keycode == RIGHT_MOVE)
		cub3d->events.right_move = 1;
	else if (keycode == LEFT_MOVE)
		cub3d->events.left_move = 1;
	else if (keycode == DOWN_MOVE)
		cub3d->events.down_move = 1;
	else if (keycode == UP_MOVE)
		cub3d->events.up_move = 1;
	if (keycode == ESC)
		cub3d->events.esc = 1;
	return (0);
}

int	depress(int keycode, t_cub3d *cub3d)
{
	if (keycode == RIGHT_ROW)
		cub3d->events.right_row = 0;
	else if (keycode == LEFT_ROW)
		cub3d->events.left_row = 0;
	else if (keycode == RIGHT_MOVE)
		cub3d->events.right_move = 0;
	else if (keycode == LEFT_MOVE)
		cub3d->events.left_move = 0;
	else if (keycode == DOWN_MOVE)
		cub3d->events.down_move = 0;
	else if (keycode == UP_MOVE)
		cub3d->events.up_move = 0;
	if (keycode == ESC)
		cub3d->events.esc = 0;
	return (0);
}
int	action(t_cub3d *cub3d)
{
	int	i;

	i = 1;
	if (cub3d->events.down_move && !cub3d->events.up_move && i++)
		down3d(cub3d, 0, 0);
	if (cub3d->events.up_move && !cub3d->events.down_move && i++)
		up3d(cub3d, 0, 0);
	if (cub3d->events.left_move && !cub3d->events.right_move && i++)
		left3d(cub3d, 0, 0);
	if (cub3d->events.right_move && !cub3d->events.left_move  && i++)
		right3d(cub3d, 0, 0);
	if (cub3d->events.right_row && !cub3d->events.left_row && i++)
		cub3d->map->player.angle += RET_ANGLE;
	if (cub3d->events.left_row && !cub3d->events.right_row && i++)
		cub3d->map->player.angle -= RET_ANGLE;
	if (cub3d->events.esc)
		close_window3d(cub3d);
	if (i > 1)
		raycasting(cub3d, 0);
	return (0);
}
