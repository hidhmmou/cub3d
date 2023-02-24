/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:11:07 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/02/24 13:59:30 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define RESET "\033[0m"

typedef struct s_map
{
	char		**content;
	char		**map;
	char		*file_name;
}		t_map;
typedef struct s_cub3d
{
	t_map	*map;
}	t_cub3d;

void	ft_error(char *message, t_cub3d *cub3d);
void	ft_free(t_cub3d *cub3d);
char	*get_next_line(int fd);
void	pre_check_map(char *file);
void	fill_content(char *map_file, t_cub3d *cub3d);

#endif