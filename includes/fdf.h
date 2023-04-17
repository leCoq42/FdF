/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 13:43:11 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/17 14:57:28 by mhaan         ########   odam.nl         */
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
# define TILE_WIDTH 128;
# define TILE_WIDTH_HALF 64;
# define TILE_HEIGHT = 64;
# define TILE_HEIGHT_HALF 32;


// Structs:
typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct	s_map
{
	size_t		width;
	size_t		height;
	t_point		**grid;
}	t_map;

typedef struct	s_camera
{
	int	x_proj;
	int	y_proj;
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
t_camera	*isometric_projection(t_map *map);
void		draw_line(mlx_image_t *img, int x,int y,int x2, int y2, int color);
void		ft_error(char *s);

// Testing funcs:
// void	print_map(char **map);
void		print_grid(t_map *map);
void		print_map_data(char **map);
void		free_map_data(char **map_data);

#endif