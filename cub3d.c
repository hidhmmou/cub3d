/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:05:32 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/03/30 04:14:34 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/raycasting.h"

void	parsing(t_cub3d **cub3d, char **av, int ac)
{
	if (ac != 2)
		ft_error("Usage : ./cub3d path/to/map", NULL);
	pre_check_map(av[1]);
	*cub3d = malloc(sizeof(t_cub3d));
	(*cub3d)->map = malloc(sizeof(t_map));
	(*cub3d)->map->ciel_color = malloc(sizeof(t_color));
	(*cub3d)->map->floor_color = malloc(sizeof(t_color));
	(*cub3d)->map->cc_color = rgb_to_int(*((*cub3d)->map->ciel_color));
	(*cub3d)->map->ff_color = rgb_to_int(*((*cub3d)->map->floor_color));
	fill_content(av[1], *cub3d);
	check_content(*cub3d);
}

int	main(int ac, char *av[])
{
	t_cub3d	*cub3d;

	parsing(&cub3d, av, ac);
	init(cub3d);
	if (ON2D)
	{
		render_map(cub3d, 0, 0, 0);
		mlx_hook(cub3d->win, 17, 0, &close_window2d, cub3d);
		mlx_loop(cub3d->mlx);
	}
	if (ON3D)
	{
		mlx_hook(cub3d->win3d, 17, 0, &close_window3d, cub3d);
		mlx_loop(cub3d->mlx3d);
	}
	return (0);
}
