/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:26:22 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/03/13 11:26:23 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

void	close_window(t_cub3d *cub3d)
{
	printf("%sWindow Closed\n%s", RED, RESET);
	mlx_destroy_window(cub3d->mlx, cub3d->win);
	ft_free(cub3d);
}

int	press(int key, t_cub3d *cub3d)
{
	if (key == ESC || key == CLOSE)
		close_window(cub3d);
	return (0);
}
