/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:05:32 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/03/28 17:16:51 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parsing.h"
#include "includes/execution.h"

void	parsing(t_cub3d **cub3d, char **av, int ac)
{
	if (ac != 2)
		ft_error("Usage : ./cub3d path/to/map", NULL);
	pre_check_map(av[1]);
	cub3d_init(cub3d);
	fill_content(av[1], *cub3d);
	check_content(*cub3d);
}

void img_transparent(t_cub3d *cub3d, t_img *img)
{
	int		i;
	int		j;
	int		color;

	i = 0;
	while (i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			my_mlx_pixel_put(img, j, i, 0xFFFFFFFF);
		i++;
	}
}

void	executing(t_cub3d *cub3d)
{
	cub3d->draw->x = WIDTH;
	cub3d->draw->ray_angle = cub3d->map->player.angle - 30;
	cub3d->win_height = --cub3d->map->len * SIZE;
	cub3d->win_width = --cub3d->map->max_len * SIZE;
	cub3d->minimap = 1;
	cub3d->map->minimap_size = SIZE_2D;
	cub3d->mlx = mlx_init();
	cub3d->win = mlx_new_window(cub3d->mlx, WIDTH, HEIGHT, "lo3ba w safi ;-;");
	cub3d->img->img = mlx_new_image(cub3d->mlx, WIDTH, HEIGHT);
	cub3d->img->addr = mlx_get_data_addr(cub3d->img->img, &cub3d->img->bits_per_pixel, &cub3d->img->line_length, &cub3d->img->endian);
	cub3d->img_2d->img = mlx_new_image(cub3d->mlx, WIDTH, HEIGHT);
	cub3d->img_2d->addr = mlx_get_data_addr(cub3d->img_2d->img, &cub3d->img_2d->bits_per_pixel, &cub3d->img_2d->line_length, &cub3d->img_2d->endian);
}

int	main(int ac, char *av[])
{
	t_cub3d	*cub3d;

	parsing(&cub3d, av, ac);
	executing(cub3d);
	render_map_2d(cub3d);
	mlx_hook(cub3d->win, 2, 0, &press, cub3d);
	mlx_hook(cub3d->win, 17, 0, &close_window, cub3d);
	mlx_loop(cub3d->mlx);
	return (0);
}
