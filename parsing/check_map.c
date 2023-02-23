/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:47:20 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/02/23 17:48:44 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	check_empty(char *file)
{
	int		fd;
	char	test;
	int		ret;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("%sso_long: no such file or directory: %s%s",
			RED, file, RESET);
		exit(1);
	}
	ret = read(fd, &test, 1);
	close(fd);
	return (ret);
}

void	check_if_dir(char *f_name)
{
	if (open(f_name, O_DIRECTORY) != -1)
		ft_error("this is a directory !", NULL);
	close(open(f_name, O_DIRECTORY));
}

int	check_extention(char *f_name)
{
	size_t	len;
	char	*ext;
	int		i;

	i = 0;
	len = ft_strlen(f_name);
	ext = ".cub";
	while (len-- > 4)
		i++;
	while (f_name[i])
	{
		if (f_name[i] != *ext)
			return (0);
		i++;
		ext++;
	}
	return (1);
}

void	ft_check_map(char *file, t_cub3d *cub3d)
{
	check_if_dir(file);
	if (!check_extention(file))
		ft_error("bad extention !", NULL);
	if (!check_empty(file))
		ft_error("empty file !", NULL);
	fill_content(file, cub3d);
}