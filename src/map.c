/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/10 15:48:39 by mhaan         #+#    #+#                 */
/*   Updated: 2023/05/08 16:20:23 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

static void			fill_grid(char *points, t_map *map);
static int			count_splits(char **array);

void	fdf_create_map(t_map *map, t_list *map_data)
{
	// print_map_data(map_data);
	create_grid(map, map_data);
	ft_printf("Height = %i\n", map->height);
	ft_printf("Width = %i\n", map->width);
}

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
	while (ptr)
	{
		x = 0;
		points = ft_split(ptr->content, ' ');
		width = count_splits(points);
		if (map->width == 0 || width < map->width)
			map->width = width;
		map->grid[y] = (t_point *)ft_calloc(map->width, sizeof(t_point));
		while (points[x])
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

static void	fill_grid(char *points, t_map *map)
{
	static int	x = 0;
	static int	y = 0;
	t_color		color;
	char		**point;

	point = ft_split(points, ',');
	if (!point[1])
		color.c = 0xFFFFFFFF;
	else
	{
		color.c = ft_hextodec(point[1]);
		create_color(color.c, &color);
	}
	map->grid[y][x] = init_point(x, y, ft_atoi_long(point[0]), color.c);
	x++;
	free(point);
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
