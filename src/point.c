/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   point.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/13 13:27:31 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/13 15:12:19 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

static t_point	init_point(int x, int y, int z)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.color = 0;
	return (point);
}

void	fill_grid(t_map **map, char **map_data)
{
	int				x;
	int				y;
	char			**points;

	y = 0;
	(*map)->grid = (t_point **)malloc((*map)->height * sizeof(t_point));
	while (map_data[y])
	{
		x = 0;
		(*map)->grid[y] = (t_point *)malloc((*map)->width * sizeof(t_point));
		points = ft_split(map_data[y], ' ');
		while (points[x])
		{
			(*map)->grid[y][x] = init_point(x, y, ft_atoi(points[x]));
			x++;
		}
		free(points);
		y++;
	}
}
