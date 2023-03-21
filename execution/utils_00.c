/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:42:58 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/03/21 17:43:05 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

void put_center_view(t_cub3d *cub3d, float *tmp, float pixel_x, float pixel_y)
{
	mlx_pixel_put(cub3d->mlx, cub3d->win, pixel_x, pixel_y, 0x00FF00);
	mlx_pixel_put(cub3d->mlx, cub3d->win, pixel_x - 1, pixel_y - 1, 0x00FF00);
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
