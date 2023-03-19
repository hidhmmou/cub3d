/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:05:32 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/03/19 18:29:06 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/execution.h"

void	parsing(t_cub3d **cub3d, char **av, int ac)
{
	if (ac != 2)
		ft_error("Usage : ./cub3d path/to/map", NULL);
	pre_check_map(av[1]);
	*cub3d = malloc(sizeof(t_cub3d));
	(*cub3d)->map = malloc(sizeof(t_map));
	(*cub3d)->map->ciel_color = malloc(sizeof(t_color));
	(*cub3d)->map->floor_color = malloc(sizeof(t_color));
	(*cub3d)->map->cc_color = rgb_to_int(*((*cub3d)->map->ciel_color));
	(*cub3d)->map->ff_color = rgb_to_int(*((*cub3d)->map->floor_color));
	fill_content(av[1], *cub3d);
	check_content(*cub3d);
	(*cub3d)->mlx = mlx_init();
	(*cub3d)->win = mlx_new_window((*cub3d)->mlx,
			ft_strlen((*cub3d)->map->square_map[0]) * 32,
			len_double((*cub3d)->map->square_map) * 32, "Cub3d");
}

static int	key_hook(int keycode, t_cub3d *cub3d)
{
	(void)cub3d;
	if (keycode == RIGHT_ROW)
	{
		cub3d->map->player.angle -= RET_ANGLE;
		render_map(cub3d, 0, 0, 0);
	}
	else if (keycode == LEFT_ROW)
	{
		cub3d->map->player.angle += RET_ANGLE;
		render_map(cub3d, 0, 0, 0);
	}
	else if (keycode == RIGHT_MOVE)
		right(cub3d);
	else if (keycode == LEFT_MOVE)
		left(cub3d);
	else if (keycode == DOWN_MOVE)
		down(cub3d);
	else if (keycode == UP_MOVE)
		up(cub3d);
	return (0);
}

int	main(int ac, char *av[])
{
	t_cub3d	*cub3d;
	int		i;

	i = 0;
	parsing(&cub3d, av, ac);
	k21(cub3d->map->square_map);
	mlx_hook(cub3d->win, 2, 0, &press, cub3d);
	mlx_hook(cub3d->win, 17, 0, &close_window, cub3d);
	render_map(cub3d, 0, 0, 0);
	mlx_hook(cub3d->win, 2, 0, key_hook, cub3d);
	mlx_loop(cub3d->mlx);
	return (0);
}
