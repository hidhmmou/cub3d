/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:26:22 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/03/21 19:41:43 by hidhmmou         ###   ########.fr       */
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

int	press(int key, t_cub3d *cub3d)
{
	if (key == ESC)
		close_window(cub3d);
	else if (key == LEFT_ROW)
	{
		cub3d->map->player.angle += ROTATE_ANGLE;
		printf("player angle : %f\n", cub3d->map->player.angle);
		render_map_2d(cub3d);
	}
	else if (key == RIGHT_ROW)
	{
		cub3d->map->player.angle -= ROTATE_ANGLE;
		printf("player angle : %f\n", cub3d->map->player.angle);
		render_map_2d(cub3d);
	}
	return (0);
}
