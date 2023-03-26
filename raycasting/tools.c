/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:13:04 by ramhouch          #+#    #+#             */
/*   Updated: 2023/03/26 01:05:10 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

int	get_color(char *text)
{
	int		c;
	char	**rgb;
	int		color;

	color = 0;
	rgb = ft_split(text, ',');
	c = ft_atoi(rgb[0]) << 16;
	color += c;
	c = ft_atoi(rgb[1]) << 8;
	color += c;
	c = ft_atoi(rgb[2]);
	color += c;
	return (color);
}
