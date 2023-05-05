/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 16:54:11 by mhaan         #+#    #+#                 */
/*   Updated: 2023/05/05 15:51:57 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void	print_map_data(char **map)
{
	int	i;

	i = 0;
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

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
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
	if (val > (uint64_t)LLONG_MAX + 1 || (val > LLONG_MAX && sign > 0))
		ft_error("Error, exceeding long long limit overflow!");
	return ((long long)(sign * val));
}