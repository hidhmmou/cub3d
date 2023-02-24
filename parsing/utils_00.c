/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:03:01 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/02/24 22:27:34 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	free_double(char	**arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	ft_free(t_cub3d *cub3d)
{
	int	i;

	i = -1;
	if (cub3d->map->content)
		free_double(cub3d->map->content);
	if (cub3d->map->map)
		free_double(cub3d->map->map);
}

void	ft_error(char *message, t_cub3d *cub3d)
{
	printf("%sError\n%s%s\n", RED, message, RESET);
	if (cub3d)
		ft_free(cub3d);
	exit(EXIT_FAILURE);
}
