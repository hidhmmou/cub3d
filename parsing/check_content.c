/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:16:58 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/02/24 22:23:13 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	in_set(char c, char *set)
{
	int	i;

	i = -1;
	while (set[++i])
		if (c == set[i])
			return (1);
	return (0);
}

int	map_len(char **content)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (content[i])
	{
		if (in_set(content[i][0], "0 1"))
			break ;
		i++;
	}
	while (content[i++])
		len++;
	return (len);
}

void	get_map(t_cub3d *cub3d)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = map_len(cub3d->map->content) + 1;
	cub3d->map->map = malloc(len * sizeof(char *));
	if (!cub3d->map->map)
		ft_error("malloc error !", NULL);
	while (cub3d->map->content[i] && !in_set(cub3d->map->content[i][0], "0 1"))
		i++;
	while (cub3d->map->content[i])
		cub3d->map->map[j++] = ft_strdup(cub3d->map->content[i++]);
	cub3d->map->map[j] = NULL;
}

void	check_content(t_cub3d *cub3d)
{
	check_textures(cub3d->map->content);
	check_colors(cub3d->map->content);
	get_textures(cub3d);
	get_colors(cub3d);
	get_map(cub3d);
	printf("%svalid map !\n%s", GREEN, RESET);
}
