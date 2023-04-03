/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 00:33:10 by ramhouch          #+#    #+#             */
/*   Updated: 2023/04/03 05:48:42 by ramhouch         ###   ########.fr       */
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
	if (keycode == MAP)
	{
		system("afplay sounds/popup.mp3&");
		if (!cub3d->mmap)
			cub3d->mmap = 1;
		else
			cub3d->mmap = 0;
		cub3d->events.map = 1;
	}
	return (0);
}

void *animate(void *ptr)
{
	t_cub3d *cub3d;

	cub3d = (t_cub3d *)ptr;

	cub3d->gun.img = cub3d->gun.g0;
	usleep(50000);
	cub3d->gun.img = cub3d->gun.g1;
	usleep(50000);
	cub3d->gun.img = cub3d->gun.g2;
	usleep(100000);
	system("afplay sounds/gun.mp3&");
	cub3d->gun.img = cub3d->gun.g3;
	usleep(50000);
	cub3d->gun.img = cub3d->gun.g4;
	usleep(100000);
	cub3d->gun.img = cub3d->gun.g5;
	usleep(100000);
	cub3d->gun.img = cub3d->gun.g0;
	return (0);
}

void	shoot(t_cub3d *cub3d)
{
	pthread_t th;

	pthread_create(&th, NULL, animate, cub3d);
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
	if (cub3d->events.right_move && !cub3d->events.left_move && i++)
		right3d(cub3d, 0, 0);
	if (cub3d->events.right_row && !cub3d->events.left_row && i++)
		cub3d->map->player.angle += RET_ANGLE;
	if (cub3d->events.left_row && !cub3d->events.right_row && i++)
		cub3d->map->player.angle -= RET_ANGLE;
	if (cub3d->events.map && i++)
		cub3d->events.map = 0;
	if (cub3d->events.esc)
		close_window3d(cub3d);
	if (cub3d->events.old_img != cub3d->gun.img && i++)
		cub3d->events.old_img = cub3d->gun.img;
	if (cub3d->events.shoot2 && i++)
		cub3d->events.shoot2 = 0;
	if (cub3d->events.closed && i++)
		cub3d->events.closed = 0;
	if (i > 1)
		raycasting(cub3d, 0);
	return (0);
}

int	mousemove(int x, int y, t_cub3d *cub3d)
{
	if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
	{
		if (cub3d->last_m_p == -1)
			cub3d->last_m_p = x;
		if (cub3d->last_m_p - x < 0)
		{
			cub3d->map->player.angle += RET_ANGLE + RET_ANGLE;
			raycasting(cub3d, 0);
			cub3d->last_m_p = x;
		}
		else if (cub3d->last_m_p - x > 0)
		{
			cub3d->map->player.angle -= RET_ANGLE + RET_ANGLE;
			raycasting(cub3d, 0);
			cub3d->last_m_p = x;
		}
	}
	return (0);
}
int	mouseclick(int	butt, int x, int y, t_cub3d *cub3d)
{
	if (butt == 3)
	{
		system("afplay sounds/popup.mp3&");
		if (!cub3d->mmap)
			cub3d->mmap = 1;
		else
			cub3d->mmap = 0;
		cub3d->events.map = 1;
	}
	if (butt == 1  && cub3d->events.shoot == 1)
		shoot(cub3d);
	if (butt == 2)
	{
		system("afplay sounds/gun2.mp3&");
		cub3d->events.shoot2 = 1;
		if (cub3d->events.shoot)
			cub3d->events.shoot = 0;
		else
			cub3d->events.shoot = 1;
	}
	return (0);
}
