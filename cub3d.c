/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:05:32 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/02/23 21:29:56 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parsing.h"

int	get_rows_nbr(int fd)
{
	int		len;
	char	*line;

	len = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		len++;
	}
	free(line);
	return (len);
}

void	fill_content(char *map_file, t_cub3d *cub3d)
{
	int	fd;
	int	i;
	int	rows;

	i = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
	{
		printf("%sso_long: no such file or directory: %s%s",
			RED, map_file, RESET);
		exit(1);
	}
	rows = get_rows_nbr(fd);
	close(fd);
	fd = open(map_file, O_RDONLY);
	cub3d->map->content = malloc(sizeof(char *) * (rows + 1));
	cub3d->map->content[i] = get_next_line(fd);
	while (i < rows && cub3d->map->content[i++])
		cub3d->map->content[i] = get_next_line(fd);
	close(fd);
}

void	init(t_cub3d **cub3d, char **av)
{
	*cub3d = malloc(sizeof(t_cub3d));
	(*cub3d)->map = malloc(sizeof(t_map));
	fill_content(av[1], *cub3d);
}

int	main(int ac, char *av[])
{
	t_cub3d	*cub3d;

	if (ac != 2)
		ft_error("only one argument is allowed !", NULL);
	init(&cub3d, av);
	int i = 0;
	while(cub3d->map->content[i])
		printf("%s", cub3d->map->content[i++]);
	//check_map(cub3d);
	return (0);
}
