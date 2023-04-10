/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 13:43:11 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/10 18:31:04 by mhaan         ########   odam.nl         */
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
}	t_point;

typedef struct	s_map
{
	unsigned int	width;
	unsigned int	height;
	t_point			**grid;
	mlx_t			*mlx;
	mlx_image_t		img;
}	t_map;



// Functions:
int		fdf_open_map_file(char *input_file);
char	**fdf_parse_map_data(int fd);
t_map	*init_map(char **map_data);
void	fdf_create_map(t_map **map, char **map_data);
void	ft_error(char *s);


// Testing funcs:
void	print_map(char **map);

#endif