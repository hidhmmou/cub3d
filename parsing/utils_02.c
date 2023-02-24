/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 22:47:53 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/02/24 22:48:56 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	is_num(const char t)
{
	if (t >= '0' && t <= '9')
		return (1);
	return (0);
}

int	check_colors_format(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	while(tab[i])
	{
		while (tab[i][j])
		{
			if (!is_num(tab[i][j]))
				ft_error("colors must be numbers !", NULL);
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	while (tab[i])
		i++;
	return (i);
}
