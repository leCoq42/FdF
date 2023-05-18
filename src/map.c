/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/10 15:48:39 by mhaan         #+#    #+#                 */
/*   Updated: 2023/05/18 14:25:32 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

static void	fill_grid(t_map *map, t_list *ptr, int y);
static int	create_point(char *point, t_map *map);
static int	count_splits(char **array);

void	create_grid(t_map *map, t_list **map_data)
{
	int		y;
	t_list	*ptr;

	y = 0;
	ptr = *map_data;
	map->grid = (t_point **)ft_calloc(map->height, sizeof(t_point *));
	if (!map->grid)
		ft_error("Error: unsuccesful malloc.\n");
	while (ptr)
	{
		fill_grid(map, ptr, y);
		y++;
		ptr = ptr->next;
	}
	ft_lstclear(map_data, free_content);
}

static void	fill_grid(t_map *map, t_list *ptr, int y)
{
	char	**points;
	int		x;
	int		width;

	x = 0;
	points = ft_split(ptr->content, ' ');
	width = count_splits(points);
	if (map->width == 0 || width < map->width)
		map->width = width;
	map->grid[y] = (t_point *)ft_calloc(map->width, sizeof(t_point));
	if (!map->grid[y])
		ft_error("Error: unsuccesful malloc.\n");
	while (x < width)
	{
		if (x < map->width)
			create_point(points[x], map);
		free(points[x]);
		x++;
	}
	free(points);
	points = NULL;
}

static int	create_point(char *point, t_map *map)
{
	static int	x = 0;
	static int	y = 0;
	t_color		color;
	char		**data;

	data = ft_split(point, ',');
	if (!data)
		ft_error("Error with splitting data.\n");
	ft_bzero(&color, sizeof(t_color));
	if (!data[1])
		color.c = 0xFFFFFFFF;
	else
	{
		color.c = ft_hextodec(data[1]);
		create_color(color.c, &color);
		free(data[1]);
	}
	map->grid[y][x] = init_point(x, y, ft_atoi(data[0]), color.c);
	x++;
	if (x >= map->width)
	{
		x = 0;
		y++;
	}
	return (free(data[0]), free(data), 0);
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
