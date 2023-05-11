/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/10 15:48:39 by mhaan         #+#    #+#                 */
/*   Updated: 2023/05/11 17:05:23 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

static void			fill_grid(char *point, t_map *map);
static int			count_splits(char **array);

void	create_grid(t_map *map, t_list *map_data)
{
	int			x;
	int			y;
	int			width;
	t_list		*ptr;
	char		**points;

	y = 0;
	ptr = map_data;
	map->grid = (t_point **)ft_calloc(map->height, sizeof(t_point *));
	if (!map->grid)
			ft_error("Error: unsuccesful malloc.");
	while (ptr)
	{
		x = 0;
		points = ft_split(ptr->content, ' ');
		width = count_splits(points);
		if (map->width == 0 || width < map->width)
			map->width = width;
		map->grid[y] = (t_point *)ft_calloc(map->width, sizeof(t_point));
		if (!map->grid[y])
			ft_error("Error: unsuccesful malloc.");
		while (x < map->width)
		{
			fill_grid(points[x], map);
			free(points[x]);
			x++;
		}
		free(points);
		y++;
		ptr = ptr->next;
	}
}

static void	fill_grid(char *point, t_map *map)
{
	static int	x = 0;
	static int	y = 0;
	t_color		color;
	char		**data;

	data = ft_split(point, ',');
	ft_bzero(&color, sizeof(t_color));
	if (!data[1])
		color.c = 0xFFFFFFFF;
	else
	{
		color.c = ft_hextodec(data[1]);
		create_color(color.c, &color);
		printf("%u\n", color.c);
	}
	map->grid[y][x] = init_point(x, y, ft_atoi(data[0]), color.c);
	x++;
	free(data);
	if (x >= map->width)
	{
		x = 0;
		y++;
	}
}

static int	count_splits(char **array)
{
	int	count;

	count = 0;
	if (!array)
		return (count);
	while (array[count])
		count++;
	return (count);
}
