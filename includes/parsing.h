/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:11:07 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/03/26 14:11:51 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define RESET "\033[0m"
/*--keys--*/
# define RIGHT_MOVE 2
# define LEFT_MOVE 0
# define DOWN_MOVE 1
# define UP_MOVE 13
# define RIGHT_ROW 124
# define LEFT_ROW 123
# define ESC 53
# define CLOSE 17
# define PI 3.14159265358979323846264338327950288
# define WIDTH 2048
# define HEIGHT 1024
# define FOV 60
# define SIZE 16
# define ANGLE_SIZE FOV / WIDTH

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;


typedef struct s_draw
{
	double	radiant;
	int		dx;
	int		dy;
	int 	x;
	double	ray_angle;
	int		pixel_nbr;
	double	increment_x;
	double	increment_y;
	double	distance;
	double	wall_height;
	double	draw_start;
	double	draw_end;
	int		color;
}	t_draw;

typedef struct s_player
{
	double		x;
	double		y;
	double 		angle;
	double		direction;
}	t_player;
typedef struct s_map
{
	int			rows;
	int			cols;
	t_player	player;
	char		**content;
	char		**check_map;
	char		**square_map;
	char		**map;
	char		*so_texture;
	char		*no_texture;
	char		*ea_texture;
	char		*we_texture;
	char		*f_color;
	char		*c_color;
	t_color		*floor_color;
	t_color		*ciel_color;
	int			empty_nbr;
	size_t		max_len;
	int			len;
}		t_map;

typedef struct s_img
{
	void		*img;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		*addr;
}	t_img;

typedef struct s_cub3d
{
	t_img		*img_2d;
	t_map		*map;
	t_draw		*draw;
	t_img		*img;
	void		*mlx;
	void		*win;
	void		*mlx_3d;
	void		*win_3d;
	int			win_width;
	int			win_height;
}	t_cub3d;


void	ft_error(char *message, t_cub3d *cub3d);
void	free_double(char **content);
void	ft_free(t_cub3d *cub3d);
char	*get_next_line(int fd);
void	pre_check_map(char *file);
void	fill_content(char *map_file, t_cub3d *cub3d);
void	check_content(t_cub3d *cub3d);
char	*get_from_file(char **content, char *target);
int		find(char **content, char *target, int flag);
void	get_colors(t_cub3d *cub3d);
void	get_textures(t_cub3d *cub3d);
void	check_textures(char	**content);
void	check_colors(char	**content);
int		get_rgb(int color);
void	get_colors(t_cub3d *cub3d);
int		check_colors_format(char **tab);
void	check_player(t_cub3d *cub3d);
int		in_set(char c, char *set);
int		check_surrounded(t_cub3d *cub3d);
int		check_outsider_floor(t_cub3d *cub3d);
int		rgb_to_int(t_color color);
int		check_floor_outside_1(char **map);
int		check_floor_outside_2(char **map);
int		fast_check(char	*line, int i, int len);
int		in_set(char c, char *set);
int		map_len(char **content);
int		len_double(char **map);
void	ft_func_helper(t_cub3d *cub3d, int x, int y);
void	virus_floor(t_cub3d *cub3d, int x, int y);
void	get_check_map(t_cub3d *cub3d);
void	get_square_map(t_cub3d *cub3d);
void	get_map(t_cub3d *cub3d);
char	**splite_colors(char const *s);
int		check_commas(char *floor, char *ciel);
void	cub3d_init(t_cub3d **cub3d);
int		is_wall(char c);
void	my_mlx_pixel_put(t_cub3d *cub3d, int x, int y, int color);
void	my_mlx_pixel_put_2d(t_cub3d *cub3d, int x, int y, int color);
#endif