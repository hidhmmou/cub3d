/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:16:58 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/02/24 17:13:29 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	find(char **content, char *target, int flag)
{
	int	i;
	int	nb;
	
	i = 0;
	nb = 0;
	while (content[i])
	{
		if (!ft_strncmp(content[i++], target, ft_strlen(target)))
		{
			nb++;
			if (flag)
				break ;
		}
	}
	return (nb);
}

void	check_textures(char	**content)
{
	int	nb;
	
	nb = find(content, "NO ", 1);
	nb += find(content, "SO ", 1);
	nb += find(content, "WE ", 1);
	nb += find(content, "EA ", 1);
	if (nb == 4)
	{
		nb = 0;
		nb = find(content, "NO ", 0);
		nb += find(content, "WE ", 0);
		nb += find(content, "EA ", 0);
		nb += find(content, "SO ", 0);
		if (nb != 4)
			ft_error("duplicate textures in the file !", NULL);
	}
	else
		ft_error("incomplete texures !", NULL);
}

void	check_colors(char	**content)
{
	int	nb;

	nb = find(content, "F ", 1);
	nb += find(content, "C ", 1);
	if (nb == 2)
	{
		nb = 0;
		nb = find(content, "F ", 0);
		nb += find(content, "C ", 0);
		if (nb != 2)
			ft_error("duplicate colors in the file !", NULL);
	}
	else
		ft_error("incomplete colors !", NULL);
}

char	*get_from_file(char **content, char *target)
{
	int		i;
	char	*ret;

	i = 0;
	while (content[i])
	{
		if (!ft_strncmp(content[i++], target, ft_strlen(target)))
		{
			ret = ft_substr(content[i - 1] + ft_strlen(target), 0, \
				ft_strlen(content[i - 1] + ft_strlen(target)) - 1);
			return (ret);
		}
	}
	return (NULL);
}

int	get_rgb(int color)
{
	if (color >= 0 && color <= 255)
		return (color);
	else
		ft_error("colors must be included in [0,255]", NULL);
	return (0);
}
void	get_colors(t_cub3d *cub3d)
{
	char	**floor;
	char	**ciel;

	cub3d->map->c_color = get_from_file(cub3d->map->content, "C ");
	cub3d->map->f_color = get_from_file(cub3d->map->content, "F ");
	ciel = ft_split(cub3d->map->c_color, ',');
	floor = ft_split(cub3d->map->f_color, ',');
	cub3d->map->floor_color->r = get_rgb(ft_atoi(floor[0]));
	cub3d->map->floor_color->g = get_rgb(ft_atoi(floor[1]));
	cub3d->map->floor_color->b = get_rgb(ft_atoi(floor[2]));
	cub3d->map->ciel_color->r = get_rgb(ft_atoi(ciel[0]));
	cub3d->map->ciel_color->g = get_rgb(ft_atoi(ciel[1]));
	cub3d->map->ciel_color->b = get_rgb(ft_atoi(ciel[2]));
}

void	get_textures(t_cub3d *cub3d)
{
	cub3d->map->ea_texture = get_from_file(cub3d->map->content, "EA ");
	cub3d->map->no_texture = get_from_file(cub3d->map->content, "NO ");
	cub3d->map->so_texture = get_from_file(cub3d->map->content, "SO ");
	cub3d->map->we_texture = get_from_file(cub3d->map->content, "WE ");
	if (open(cub3d->map->ea_texture, O_RDONLY) < 0
		|| open(cub3d->map->so_texture, O_RDONLY) < 0
		|| open(cub3d->map->we_texture, O_RDONLY) < 0
		||open(cub3d->map->no_texture, O_RDONLY) < 0)
		ft_error("couldn't open texture !", NULL);
}

void	check_content(t_cub3d *cub3d)
{
	check_textures(cub3d->map->content);
	check_colors(cub3d->map->content);
	get_textures(cub3d);
	get_colors(cub3d);
	printf("%svalid map !\n%s", GREEN, RESET);
	//printf("ea_texture : %s", cub3d->map->ea_texture);
	//printf("no_texture : %s", cub3d->map->no_texture);
	//printf("we_texture : %s", cub3d->map->we_texture);
	//printf("so_texture : %s", cub3d->map->so_texture);
	//printf("f_color : %s", cub3d->map->f_color);
	//printf("c_color : %s", cub3d->map->c_color);
}