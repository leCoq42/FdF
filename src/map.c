/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/10 15:48:39 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/13 15:13:15 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

static unsigned int	count_rows(char **data);
static unsigned int	count_columns(char **data);

t_map	*init_map(char **map_data)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->height = count_rows(map_data);
	map->width = count_columns(map_data);
	map->grid = NULL;
	map->mlx = NULL;
	return (map);
}

void	fdf_create_map(t_map **map, char **map_data)
{
	fill_grid(map, map_data);
	ft_printf("Height = %u\n", (*map)->height);
	ft_printf("Width = %u\n", (*map)->width);
	print_grid((*map)->grid, *map);
}

static unsigned int	count_rows(char **data)
{
	unsigned int	count;

	count = 0;
	while (data[count])
		count++;
	return (count);
}

static unsigned int	count_columns(char **data)
{
	unsigned int	y;
	char			**points;
	unsigned int	count;
	unsigned int	min_width;

	y = 0;
	while (data[y])
	{
		count = 0;
		points = ft_split(data[y], ' ');
		while (points[count])
			count++;
		if (y == 0)
			min_width = count;
		else if (count < min_width)
			min_width = count;
		free(points);
		y++;
	}
	return (min_width);
}
