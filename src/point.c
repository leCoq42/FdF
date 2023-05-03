/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   point.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/13 13:27:31 by mhaan         #+#    #+#                 */
/*   Updated: 2023/05/03 10:24:38 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

static u_int32_t	ft_hextodec(char *hex);
static	void create_color(uint32_t num, t_color *color);
static long long	ft_atoi_long(const char *str);

void	fill_grid(t_map *map, char **map_data)
{
	int			x;
	int			y;
	char		**points;
	char		**point;
	t_color		color;

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
				color.c = 0xFFFFFFFF;
			else
			{
				color.c = ft_hextodec(point[1]);
				create_color(color.c, &color);
			}
			map->grid[y][x] = init_point(x, y, ft_atoi_long(point[0]), color.c);
			free(point);
			x++;
		}
		free(points);
		y++;
	}
}

static	void create_color(uint32_t num, t_color *color)
{
	color->t_rgba.r = (num >> 16) & 0xFF;
	color->t_rgba.g = (num >> 8) & 0xFF;
	color->t_rgba.b = num & 0xFF;
	color->t_rgba.a = 255;
}

static uint32_t	ft_hextodec(char *hex)
{
	int			i;
	uint32_t	res;
	uint8_t		byte;

	i = 0;
	if (hex[0] && hex[0] == '0' && hex[1] && (hex[1] == 'x' || hex[1] == 'X'))
		i += 2;
	while(hex[i])
	{
		byte = hex[i];
		if (byte >= '0' && byte <= '9')
			byte = byte - '0';
		else if (byte >= 'a' && byte <= 'f')
			byte = byte - 'a' + 10;
		else if (byte >= 'A' && byte <= 'F')
			byte = byte - 'A' + 10;
		else
			return (0);
		res = (res << 4) | (byte & 0xF);
		i++;
	}
	return (res);
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