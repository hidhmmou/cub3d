/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:31:47 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/03/20 14:39:27 by hidhmmou         ###   ########.fr       */
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