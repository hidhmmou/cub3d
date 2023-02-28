/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:16:58 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/02/28 22:18:11 by hidhmmou         ###   ########.fr       */
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

void	get_square_map(t_cub3d *cub3d)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while (cub3d->map->map[i])
	{
		cub3d->map->square_map[i] = malloc(sizeof(char) * cub3d->map->max_len);
		cub3d->map->square_map[i][cub3d->map->max_len] = 0;
		cub3d->map->square_map[i][cub3d->map->max_len - 1] = '\n';
		ft_memset(cub3d->map->square_map[i], 'K', cub3d->map->max_len - 1);
		tmp = 0;
		while (cub3d->map->map[i][j] && cub3d->map->map[i][j] != '\n')
		{
			cub3d->map->square_map[i][j] = cub3d->map->map[i][j];
			j++;
		}
		i++;
		j = 0;
	}
	cub3d->map->square_map[i] = NULL;
}

int	fast_check(char	*line, int i, int len)
{
	if (line[0] == '\n')
		ft_error("invalid map (extra new line)!", NULL);
	if (i == len - 2 && line[ft_strlen(line) - 1] == '\n')
		ft_error("invalid map (extra new line at the end of the map)!", NULL);
	return (1);
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
	cub3d->map->square_map = malloc(len * sizeof(char *));
	if (!cub3d->map->map || !cub3d->map->check_map || !cub3d->map->square_map)
		ft_error("malloc error !", NULL);
	while (cub3d->map->content[i] && !in_set(cub3d->map->content[i][0], "0 1"))
		i++;
	while (cub3d->map->content[i] && fast_check(cub3d->map->content[i], j, len))
	{
		cub3d->map->map[j] = ft_strdup(cub3d->map->content[i]);
		if (ft_strlen(cub3d->map->map[j]) > cub3d->map->max_len)
			cub3d->map->max_len = ft_strlen(cub3d->map->map[j]);
		i++;
		j++;
	}
	cub3d->map->map[j] = NULL;
}

void	check_map(t_cub3d *cub3d)
{
	if (!check_surrounded(cub3d))
		ft_error("map not surrounded by walls !", NULL);
	if (!check_outsider_floor(cub3d))
		ft_error("floor outside !", NULL);
}

void	check_imposter_elements(char **content)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (content[++i])
	{
		if (in_set(content[i][0], " 10FC\n"))
			continue ;
		else if (ft_strncmp(content[i], "WE", 2)
			&& ft_strncmp(content[i], "NO", 2)
			&& ft_strncmp(content[i], "EA", 2)
			&& ft_strncmp(content[i], "SO", 2))
			ft_error("bad elements in the map !", NULL);
	}
}

void	check_content(t_cub3d *cub3d)
{
	check_imposter_elements(cub3d->map->content);
	check_textures(cub3d->map->content);
	check_colors(cub3d->map->content);
	get_textures(cub3d);
	get_colors(cub3d);
	get_map(cub3d);
	check_player(cub3d);
	get_check_map(cub3d);
	get_square_map(cub3d);
	check_map(cub3d);
	printf("%svalid map !\n%s", GREEN, RESET);
}
