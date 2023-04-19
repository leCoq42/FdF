/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 16:54:11 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/19 15:33:40 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void	print_map_data(char **map)
{
	int i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

void	print_grid(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			ft_printf(" %d", map->grid[y][x].z);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}

size_t	count_rows(char **data)
{
	unsigned int	count;

	count = 0;
	while (data[count])
		count++;
	return (count);
}

size_t	count_columns(char **data)
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
