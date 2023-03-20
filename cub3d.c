/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:05:32 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/03/20 16:57:50 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parsing.h"
#include "includes/execution.h"

void	parsing(t_cub3d **cub3d, char **av, int ac)
{
	if (ac != 2)
		ft_error("Usage : ./cub3d path/to/map", NULL);
	pre_check_map(av[1]);
	cub3d_init(cub3d);
	fill_content(av[1], *cub3d);
	check_content(*cub3d);
}

void	executing(t_cub3d *cub3d)
{
	cub3d->mlx = mlx_init();
	cub3d->win = mlx_new_window(cub3d->mlx, --cub3d->map->max_len * 32, --cub3d->map->len * 32, "Cub3d");
	render_map_2d(cub3d);
}

int	main(int ac, char *av[])
{
	t_cub3d	*cub3d;

	parsing(&cub3d, av, ac);
	executing(cub3d);
	mlx_hook(cub3d->win, 2, 0, &press, cub3d);
	mlx_hook(cub3d->win, 17, 0, &close_window, cub3d);
	mlx_loop(cub3d->mlx);
	return (0);
}
