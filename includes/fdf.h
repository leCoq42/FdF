/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 13:43:11 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/19 19:56:48 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// General Includes:
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line_bonus.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

// Project specific includes:
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "MLX42.h"

// DEFINES
# define WIDTH	1920
# define HEIGHT	1080
# define SCALE_FACTOR 10
# define TRANSLATION 500

// Structs:
// typedef struct s_color
// {
// 	int r;
// 	int b;
// 	int g;
// 	int a;
// }	t_color;

typedef union color
{
	uint32_t	c;
	struct s_rgba
	{
		uint8_t	r;
		uint8_t	g;
		uint8_t	b;
		uint8_t	a;
	}	t_rgba;
}	t_color;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	t_color	color;
}	t_point;

typedef struct s_map
{
	int		width;
	int		height;
	t_point	**grid;
}	t_map;

typedef struct s_camera
{
	int	x_proj;
	int	y_proj;
	int	x_ang;
	int	y_ang;
	int	z_ang;
}	t_camera;

typedef struct s_fdf
{
	t_map		*map;
	t_camera	*camera;
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_fdf;

// Functions:
int			fdf_open_map_file(char *input_file);
char		**fdf_parse_map_data(int fd);
t_fdf		*fdf_init(t_fdf *fdf, char **map_data);
void		fdf_draw_image(t_fdf *fdf, int32_t color);
size_t		count_rows(char **data);
size_t		count_columns(char **data);
void		fill_grid(t_map *map, char **map_data);
void		fdf_create_map(t_map *map, char **map_data);
t_point		isometric_projection(t_point point);
void		draw_iso_line(t_fdf *fdf, t_point p1, t_point p2);
void		bresenham_line(mlx_image_t *img, t_point p1, t_point p2);
void		wu_line(mlx_image_t *img, t_point p1, t_point p2);
void		ft_error(char *s);
t_color		color_interpolation(t_color c1, t_color c2, float t);
void		ft_swap(int *a, int *b);

// Testing funcs:
// void	print_map(char **map);
void		print_grid(t_map *map);
void		print_map_data(char **map);
void		free_map_data(char **map_data);

#endif