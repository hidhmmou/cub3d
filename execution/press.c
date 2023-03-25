/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:26:22 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/03/25 14:17:19 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

int	close_window(t_cub3d *cub3d)
{
	printf("%sWindow Closed\n%s", RED, RESET);
	mlx_destroy_window(cub3d->mlx, cub3d->win);
	mlx_destroy_window(cub3d->mlx_3d, cub3d->win_3d);
	ft_free(cub3d);
	return (0);
}

int	press(int key, t_cub3d *cub3d)
{
	if (key == ESC)
		close_window(cub3d);
	else if (key == LEFT_ROW)
	{
		cub3d->map->player.angle += ROTATE_ANGLE;
		render_map_2d(cub3d);
	}
	else if (key == RIGHT_ROW)
	{
		cub3d->map->player.angle -= ROTATE_ANGLE;
		render_map_2d(cub3d);
	}
	else if (key == RIGHT_MOVE)
		move_right(cub3d);
	else if (key == LEFT_MOVE)
		move_left(cub3d);
	else if (key == DOWN_MOVE)
		move_down(cub3d);
	else if (key == UP_MOVE)
		move_up(cub3d);
	return (0);
}
