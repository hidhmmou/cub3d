/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:31:47 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/03/26 21:26:35 by hidhmmou         ###   ########.fr       */
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
	//*cub3d = malloc(sizeof(t_cub3d));
	//(*cub3d)->map = malloc(sizeof(t_map));
    //(*cub3d)->draw = malloc(sizeof(t_draw));
    //(*cub3d)->img = malloc(sizeof(t_img));
	//(*cub3d)->map->ciel_color = malloc(sizeof(t_color));
	//(*cub3d)->map->floor_color = malloc(sizeof(t_color));
    //(*cub3d)->img_2d = malloc(sizeof(t_img));
    *cub3d = ft_calloc(1, sizeof(t_cub3d));
	(*cub3d)->map = ft_calloc(1, sizeof(t_map));
    (*cub3d)->draw = ft_calloc(1, sizeof(t_draw));
    (*cub3d)->img = ft_calloc(1, sizeof(t_img));
	(*cub3d)->map->ciel_color = ft_calloc(1, sizeof(t_color));
	(*cub3d)->map->floor_color = ft_calloc(1, sizeof(t_color));
    (*cub3d)->img_2d = ft_calloc(1, sizeof(t_img));
}
