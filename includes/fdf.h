/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 13:43:11 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/14 10:52:33 by mhaan         ########   odam.nl         */
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
# define WIDTH	640
# define HEIGHT	480

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
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_map;

typedef struct	s_camera
{
	int	x_proj;
	int	y_proj;
	int	z_proj;
}	t_camera;


// Functions:
int		fdf_open_map_file(char *input_file);
char	**fdf_parse_map_data(int fd);
t_map	*init_map(char **map_data);
void	fill_grid(t_map **map, char **map_data);
void	fdf_create_map(t_map **map, char **map_data);
void	ft_error(char *s);
void	fdf_draw_image(t_map **map, int32_t color);
void	draw_line(mlx_image_t *img, int x,int y,int x2, int y2, int color);

// Testing funcs:
// void	print_map(char **map);
void	print_grid(t_point	**grid, t_map *map);

#endif