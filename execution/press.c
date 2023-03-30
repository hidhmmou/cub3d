/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:26:22 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/03/30 04:07:06 by hidhmmou         ###   ########.fr       */
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
	//printf("button = %d\n", key);
	//mlx_destroy_image(cub3d->mlx, cub3d->img->img);
	//mlx_destroy_image(cub3d->mlx, cub3d->img_2d->img);
	//cub3d->img->img = mlx_new_image(cub3d->mlx, WIDTH, HEIGHT);
	//cub3d->img_2d->img = mlx_new_image(cub3d->mlx, WIDTH, HEIGHT);
	if (key == ESC)
		close_window(cub3d);
	if (key == SPACE)
	{
		cub3d->start++;
		render_map_2d(cub3d);
	}
	if (!cub3d->start)
		return (1);
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
	
