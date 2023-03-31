/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:26:22 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/03/31 00:31:29 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

int	close_window(t_cub3d *cub3d)
{
	printf("%sWindow Closed\n%s", RED, RESET);
	mlx_destroy_window(cub3d->mlx, cub3d->win);
	ft_free(cub3d);
	return (0);
}


int release(int key, t_cub3d *cub3d)
{
	if (!cub3d->start)
		return (0);
	if (key == LEFT_ROW)
		cub3d->keys[LEFT] = 0;
	else if (key == RIGHT_ROW)
		cub3d->keys[RIGHT] = 0;
	else if (key == RIGHT_MOVE)
		cub3d->keys[D] = 0;
	else if (key == LEFT_MOVE)
		cub3d->keys[A] = 0;
	else if (key == DOWN_MOVE)
		cub3d->keys[S] = 0;
	else if (key == UP_MOVE)
		cub3d->keys[W] = 0;
	else if (key == SHIFT)
	{
		cub3d->map->player.angle -= 180;
		render_map_2d(cub3d);
	}
	return (1);
}

int	loop(t_cub3d *cub3d)
{
	if (cub3d->keys[LEFT] && ++cub3d->change)
		cub3d->map->player.angle += ROTATE_ANGLE;
	if (cub3d->keys[RIGHT] && ++cub3d->change)
		cub3d->map->player.angle -= ROTATE_ANGLE;
	if (cub3d->keys[D])
		cub3d->change = move_right(cub3d);
	if (cub3d->keys[A])
		cub3d->change = move_left(cub3d);
	if (cub3d->keys[S])
		cub3d->change = move_down(cub3d);
	if (cub3d->keys[W])
		cub3d->change = move_up(cub3d);
	if (cub3d->change)
	{
		cub3d->change = 0;
		render_map_2d(cub3d);
	}
	return (1);
}

void	show_hide_mouse(t_cub3d *cub3d)
{
	cub3d->mouse->shown *= -1;
	if (cub3d->mouse->shown == -1)
	{
		mlx_mouse_hide();
		mlx_mouse_move(cub3d->win, WIDTH / 2, HEIGHT / 2);
	}
	else
		mlx_mouse_show();
}

int	press(int key, t_cub3d *cub3d)
{
	//printf("button = %d\n", key);
	if (key == ESC)
		close_window(cub3d);
	if (key == SPACE)
	{
		cub3d->start++;
		render_map_2d(cub3d);
	}
	if (!cub3d->start)
		return (1);
	if (key == LEFT_ROW)
		cub3d->keys[LEFT] = 1;
	else if (key == RIGHT_ROW)
		cub3d->keys[RIGHT] = 1;
	else if (key == RIGHT_MOVE)
		cub3d->keys[D] = 1;
	else if (key == LEFT_MOVE)
		cub3d->keys[A] = 1;
	else if (key == DOWN_MOVE)
		cub3d->keys[S] = 1;
	else if (key == UP_MOVE)
		cub3d->keys[W] = 1;
	else if (key == TAB)
	{
		img_transparent(cub3d, cub3d->img_2d);
		cub3d->minimap *= -1;
		render_map_2d(cub3d);
	}
	else if (key == CTRL)
		show_hide_mouse(cub3d);
	else if (key == SHIFT)
	{
		cub3d->map->player.angle += 180;
		render_map_2d(cub3d);
	}
	return (0);
}


int mouse_press(int button, int x, int y, t_cub3d *cub3d)
{
	//printf("button = %d, x = %d, y = %d\n", button, x, y);
	press_start(button, x, y, cub3d);
	if (!cub3d->start)
		return (1);
	minimap(button, x, y, cub3d);
    return (0);
}
