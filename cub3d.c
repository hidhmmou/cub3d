/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:05:32 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/02/24 13:59:17 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parsing.h"

void	parsing(t_cub3d **cub3d, char **av, int ac)
{
	if (ac != 2)
		ft_error("Usage : ./cub3d path/to/map", NULL);
	pre_check_map(av[1]);
	*cub3d = malloc(sizeof(t_cub3d));
	(*cub3d)->map = malloc(sizeof(t_map));
	fill_content(av[1], *cub3d);
}

int	main(int ac, char *av[])
{
	t_cub3d	*cub3d;

	parsing(&cub3d, av, ac);
	return (0);
}
