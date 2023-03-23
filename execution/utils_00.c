/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:42:58 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/03/23 18:35:16 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

void check_direction(t_cub3d *cub3d, float y, float x)
{
	if (!is_wall(cub3d->map->square_map[(int)(y + 2) / SIZE][(int)x / SIZE]))
		cub3d->map->player.direction = 1;
	else if (!is_wall(cub3d->map->square_map[(int)y / SIZE][(int)(x - 2) / SIZE]))
		cub3d->map->player.direction = 2;
	else if (!is_wall(cub3d->map->square_map[(int)(y - 2) / SIZE][(int)x / SIZE]))
		cub3d->map->player.direction = 3;
	else
		cub3d->map->player.direction = 4;
	printf("the direction is : %d\n", cub3d->map->player.direction);
}

void put_player(t_cub3d *cub3d, float *tmp)
{
	mlx_pixel_put(cub3d->mlx, cub3d->win, tmp[0] , tmp[1], 0x00FF00);
	mlx_pixel_put(cub3d->mlx, cub3d->win, tmp[0], tmp[1] - 1, 0x00FF00);
	mlx_pixel_put(cub3d->mlx, cub3d->win, tmp[0], tmp[1] + 1, 0x00FF00);
	mlx_pixel_put(cub3d->mlx, cub3d->win, tmp[0], tmp[1] - 2, 0x00FF00);
	mlx_pixel_put(cub3d->mlx, cub3d->win, tmp[0], tmp[1] + 2, 0x00FF00);
	mlx_pixel_put(cub3d->mlx, cub3d->win, tmp[0] - 1, tmp[1], 0x00FF00);
	mlx_pixel_put(cub3d->mlx, cub3d->win, tmp[0] + 1, tmp[1], 0x00FF00);
	mlx_pixel_put(cub3d->mlx, cub3d->win, tmp[0] - 2, tmp[1], 0x00FF00);
	mlx_pixel_put(cub3d->mlx, cub3d->win, tmp[0] + 2, tmp[1], 0x00FF00);
}

void	cast_mid_ray(t_cub3d *cub3d)
{
	float	pixel_x;
	float	pixel_y;
	float	tmp[2];

	pixel_x = cub3d->map->player.x;
	pixel_y = cub3d->map->player.y;
	tmp[0] = pixel_x;
	tmp[1] = pixel_y;
	cub3d->draw->ray_angle = cub3d->map->player.angle;
	init_draw(cub3d);
	while (1)
	{
		mlx_pixel_put(cub3d->mlx, cub3d->win, pixel_x, pixel_y, 0x00FF00);
		pixel_x -= cub3d->draw->increment_x;
		pixel_y -= cub3d->draw->increment_y;
		if (check_hit_wall(cub3d, pixel_y, pixel_x))
		{
			check_direction(cub3d, pixel_y, pixel_x);
			break ;
		}
	}
	mlx_pixel_put(cub3d->mlx, cub3d->win, pixel_x, pixel_y, 0x00FF00);
	mlx_pixel_put(cub3d->mlx, cub3d->win, pixel_x - 1, pixel_y - 1, 0x00FF00);
	put_player(cub3d, tmp);
}
