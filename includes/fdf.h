/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 13:43:11 by mhaan         #+#    #+#                 */
/*   Updated: 2023/05/11 14:06:54 by mhaan         ########   odam.nl         */
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
# define RAD 0.01745

// Structs:

typedef union color
{
	uint32_t	c;
	struct s_rgba
	{
		uint8_t	a;
		uint8_t	b;
		uint8_t	g;
		uint8_t	r;
	}	t_rgba;
}	t_color;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	t_color	c;
}	t_point;

typedef struct s_map
{
	int		width;
	int		height;
	t_point	**grid;
}	t_map;

typedef struct s_camera
{
	double	alpha;
	double	beta;
	double	gamma;
	int		zoom;
	int		x_off;
	int		y_off;
	int		pretty;
	int		iso;
}	t_camera;

typedef struct s_fdf
{
	t_map		*map;
	t_camera	*camera;
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_fdf;

typedef struct s_line
{
	double	grad;
	double	intery;
	int		x;
}	t_line;

// Function headers:
// parser_funcs.c:
int			fdf_open_map_file(char *input_file);
t_list		*fdf_parse_map_data(int fd);
// char		**fdf_parse_map_data(int fd);
// init.c:
t_fdf		*fdf_init(t_fdf *fdf, t_list *map_data);
t_point		init_point(int x, int y, int z, uint32_t c);
t_camera	*init_camera(t_camera *camera, t_map *map, mlx_image_t *img);
// draw.c:
void		fdf_draw_image(t_fdf *fdf, int32_t background);
void		draw_line(t_fdf *fdf, t_point p1, t_point p2);
void		fdf_put_pixel(t_fdf *fdf, int x, int y, t_color c);
// map.c
void		create_grid(t_map *map, t_list *map_data);
void		fdf_create_map(t_map *map, t_list *map_data);
// camera.c
t_point		calculate_projection(t_point point, t_fdf *fdf);
void		reset_camera(t_camera *camera, t_map *map, mlx_image_t *img);
void		center_camera(t_camera *camera, t_map *map, mlx_image_t *img);
// bresenham_line.c
void		bresenham_line(t_fdf *fdf, t_point p1, t_point p2);
// wu_line.c:
void		wu_line(t_fdf *fdf, t_point p1, t_point p2);
// error_funcs.c
void		ft_error(char *s);
// user_input.c
void		user_controls(t_fdf *fdf);
void		my_keyhooks(mlx_key_data_t keydata, void* param);
// menu.c:
void		put_menu(t_fdf *fdf);
// color.c:
void		create_color(uint32_t num, t_color *color);
uint32_t	ft_hextodec(char *hex);
// utils.c:
void		print_map_data(t_list *map);
void		print_grid(t_map *map);
size_t		fdf_count_rows(t_list *map_data);
void		ft_swap(int *a, int *b);
long long	ft_atoi_long(const char *str);

#endif