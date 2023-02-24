/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:11:07 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/02/24 17:11:31 by hidhmmou         ###   ########.fr       */
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


typedef struct t_color
{
	int	r;
	int	g;
	int	b;
}	t_color;
typedef struct s_map
{
	char		**content;
	char		**map;
	char		*so_texture;
	char		*no_texture;
	char		*ea_texture;
	char		*we_texture;
	char		*f_color;
	char		*c_color;
	t_color		*floor_color;
	t_color		*ciel_color;
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
void	check_content(t_cub3d *cub3d);

#endif