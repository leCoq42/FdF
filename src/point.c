/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   point.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/13 13:27:31 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/28 18:18:10 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void	fill_grid(t_map *map, char **map_data)
{
	int			x;
	int			y;
	char		**points;
	char		**point;
	uint32_t	color;

	y = 0;
	map->grid = (t_point **)ft_calloc(map->height, sizeof(t_point *));
	while (map_data[y])
	{
		x = 0;
		map->grid[y] = (t_point *)ft_calloc(map->width, sizeof(t_point));
		points = ft_split(map_data[y], ' ');
		while (points[x])
		{
			point = ft_split(points[x], ',');
			if (!point[1])
				color = 0xFFFFFFFF;
			else
				color = ft_atoi_long(point[1]);
			map->grid[y][x] = init_point(x, y, ft_atoi_long(point[0]), color);
			x++;
		}
		free(points);
		y++;
	}
}

long long	ft_strtohex(char **str)
{
	int	i;

	i = 0;
	while(str[i])
	{


	}


}

long long	ft_atoi_long(const char *str)
{
	unsigned long long	val;
	int					sign;

	val = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str && *str > 47 && *str < 58)
		val = val * 10 + (*str++ - 48);
	if (val > (unsigned long long)LLONG_MAX + 1 || (val > LLONG_MAX && sign > 0))
		ft_error("Error, exceeding long long limit overflow!");
	return ((long long)(sign * val));
}