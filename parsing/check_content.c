/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:16:58 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/02/27 23:35:21 by hidhmmou         ###   ########.fr       */
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

void	get_check_map(t_cub3d *cub3d)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while (cub3d->map->map[i])
	{
		cub3d->map->check_map[i] = malloc(sizeof(char) * cub3d->map->max_len);
		cub3d->map->check_map[i][cub3d->map->max_len] = 0;
		cub3d->map->check_map[i][cub3d->map->max_len - 1] = '\n';
		ft_memset(cub3d->map->check_map[i], '0', cub3d->map->max_len - 1);
		tmp = 0;
		while (cub3d->map->map[i][j] && cub3d->map->map[i][j] != '\n')
		{
			cub3d->map->check_map[i][j] = cub3d->map->map[i][j];
			j++;
		}
		i++;
		j = 0;
	}
	cub3d->map->check_map[i] = NULL;
}

void	get_map(t_cub3d *cub3d)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	cub3d->map->max_len = 0;
	len = map_len(cub3d->map->content) + 1;
	cub3d->map->map = malloc(len * sizeof(char *));
	cub3d->map->check_map = malloc(len * sizeof(char *));
	if (!cub3d->map->map || !cub3d->map->check_map)
		ft_error("malloc error !", NULL);
	while (cub3d->map->content[i] && !in_set(cub3d->map->content[i][0], "0 1"))
		i++;
	while (cub3d->map->content[i])
	{
		cub3d->map->map[j] = ft_strdup(cub3d->map->content[i]);
		if (ft_strlen(cub3d->map->map[j]) > cub3d->map->max_len)
			cub3d->map->max_len = ft_strlen(cub3d->map->map[j]);
		i++;
		j++;
	}
	cub3d->map->map[j] = NULL;
	get_check_map(cub3d);
	check_player(cub3d);
}

void	check_map(t_cub3d *cub3d)
{
	if (!check_surrounded(cub3d))
		ft_error("map not surrounded by walls !", NULL);
	// printf("spaces nbr = %d\n", cub3d->map->empty_nbr);
	// printf("player in x = %d, y = %d\n", cub3d->map->player.x, cub3d->map->player.y);
}

void	check_content(t_cub3d *cub3d)
{
	check_textures(cub3d->map->content);
	check_colors(cub3d->map->content);
	get_textures(cub3d);
	get_colors(cub3d);
	get_map(cub3d);
	check_map(cub3d);
	printf("%svalid map !\n%s", GREEN, RESET);
}
