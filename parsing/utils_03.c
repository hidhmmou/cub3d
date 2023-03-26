/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:31:47 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/03/26 14:30:06 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int check_commas(char *floor, char *ciel)
{
    int nbr;

    nbr = 0;
    while (*floor)
        if (*floor++ == ',')
            nbr++;
    while (*ciel)
        if (*ciel++ == ',')
            nbr++;
    return (nbr == 4);
}

void	cub3d_init(t_cub3d **cub3d)
{
	*cub3d = malloc(sizeof(t_cub3d));
    ft_bzero(*cub3d, sizeof(t_cub3d));
	(*cub3d)->map = malloc(sizeof(t_map));
    ft_bzero((*cub3d)->map, sizeof(t_map));
    (*cub3d)->draw = malloc(sizeof(t_draw));
    ft_bzero((*cub3d)->draw, sizeof(t_draw));
    (*cub3d)->img = malloc(sizeof(t_img));
    ft_bzero((*cub3d)->img, sizeof(t_img));
	(*cub3d)->map->ciel_color = malloc(sizeof(t_color));
    ft_bzero((*cub3d)->map->ciel_color, sizeof(t_color));
	(*cub3d)->map->floor_color = malloc(sizeof(t_color));
    ft_bzero((*cub3d)->map->floor_color, sizeof(t_color));
    (*cub3d)->img_2d = malloc(sizeof(t_img));
    ft_bzero((*cub3d)->img_2d, sizeof(t_img));
}
