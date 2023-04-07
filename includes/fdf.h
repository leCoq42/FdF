/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 13:43:11 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/07 17:42:36 by mhaan         ########   odam.nl         */
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
	int			width;
	int			height;
	t_point		*grid;
	mlx_t		*mlx;
	mlx_image_t	img;
}	t_map;



// Functions:
t_map	*fdf_parse_map(char *filename);
void	ft_error(char *s);


#endif