/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:05:32 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/03/13 10:32:42 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parsing.h"
#include "includes/execution.h"

void	parsing(t_cub3d **cub3d, char **av, int ac)
{
	if (ac != 2)
		ft_error("Usage : ./cub3d path/to/map", NULL);
	pre_check_map(av[1]);
	*cub3d = malloc(sizeof(t_cub3d));
	(*cub3d)->map = malloc(sizeof(t_map));
	(*cub3d)->map->ciel_color = malloc(sizeof(t_color));
	(*cub3d)->map->floor_color = malloc(sizeof(t_color));
	(*cub3d)->mlx = mlx_init();
	(*cub3d)->win = mlx_new_window((*cub3d)->mlx, 1024, 1024, "Cub3d");
	fill_content(av[1], *cub3d);
	check_content(*cub3d);
}

int	main(int ac, char *av[])
{
	t_cub3d	*cub3d;

	parsing(&cub3d, av, ac);
	mlx_loop(cub3d->mlx);
	return (0);
}
