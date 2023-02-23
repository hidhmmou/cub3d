/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:03:01 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/02/23 17:49:53 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	ft_free(t_cub3d *cub3d)
{
	int	i;

	i = -1;
	while (cub3d->map->map[++i])
		free(cub3d->map->map[i]);
	free(cub3d->map->map);
}

void	ft_error(char *message, t_cub3d *cub3d)
{
	printf("%sError\n%s%s", RED, message, RESET);
	if (cub3d)
		ft_free(cub3d);
	exit(1);
}
