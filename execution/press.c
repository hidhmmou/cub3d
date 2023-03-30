/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:26:22 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/03/30 17:43:43 by hidhmmou         ###   ########.fr       */
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
	return (1);
}

int	loop(t_cub3d *cub3d)
{
	int change;

	change = 0;
	if (cub3d->keys[LEFT] && ++change)
		cub3d->map->player.angle += ROTATE_ANGLE;
	if (cub3d->keys[RIGHT] && ++change)
		cub3d->map->player.angle -= ROTATE_ANGLE;
	if (cub3d->keys[D])
		change = move_right(cub3d);
	if (cub3d->keys[A])
		change = move_left(cub3d);
	if (cub3d->keys[S])
		change = move_down(cub3d);
	if (cub3d->keys[W])
		change = move_up(cub3d);
	if (change)
		render_map_2d(cub3d);
	return (1);
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
	
	
	
	
	//put_xpm_file_to_window(cub3d, "textures/gun.xpm", WIDTH / 2 - 150, HEIGHT - 303);
	//put_xpm_file_to_window(cub3d, "textures/gun.xpm", WIDTH / 2 - 150, HEIGHT - 303);
	
