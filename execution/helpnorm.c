/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpnorm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:53:07 by ramhouch          #+#    #+#             */
/*   Updated: 2023/03/25 20:55:53 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/execution.h"

int	check_movements(t_cub3d *cub3d, int x, int y)
{
	if (cub3d->map->square_map[(x - 1) / SIZE][y / SIZE] == '1' &&
		cub3d->map->square_map[x / SIZE][(y + 1) / SIZE] == '1')
		return (1);
	if (cub3d->map->square_map[(x - 1) / SIZE][y / SIZE] == '1' &&
		cub3d->map->square_map[x / SIZE][(y - 1) / SIZE] == '1')
		return (1);
	if (cub3d->map->square_map[(x + 1) / SIZE][y / SIZE] == '1' &&
		cub3d->map->square_map[x / SIZE][(y - 1) / SIZE] == '1')
		return (1);
	if (cub3d->map->square_map[(x + 1) / SIZE][y / SIZE] == '1' &&
		cub3d->map->square_map[x / SIZE][(y + 1) / SIZE] == '1')
		return (1);
	if (cub3d->map->square_map[x / SIZE][y / SIZE] == '1')
		return (2);
	return (0);
}

int	no(t_cub3d *cub3d, int *i)
{
	*i = *i - 1;
	cub3d->collisions = 0;
	return (1);
}
