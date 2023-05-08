/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 16:54:11 by mhaan         #+#    #+#                 */
/*   Updated: 2023/05/08 17:12:32 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void	print_map_data(t_list *map_data)
{
	while (map_data)
	{
		ft_printf("%s", map_data->content);
		map_data = map_data->next;
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

size_t	fdf_count_rows(t_list *map_data)
{
	unsigned int	count;
	t_list			*ptr;

	count = 0;
	ptr = map_data;
	while (ptr)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}

// size_t	fdf_count_columns(t_list *map_data)
// {
// 	t_list	*ptr;
// 	size_t	count;
// 	size_t	min_width;

// 	ptr = map_data;
// 	min_width = 0;
// 	print_map_data(map_data);
// 	while (ptr)
// 	{
// 		count = 0;
// 		while (ptr->content && (char)ptr->content == ' ')
// 			(char *)ptr->content++;
// 		printf("%c\n", (char)ptr->content);
// 		// while (ptr->content)
// 		// {
// 		// 	printf("%c\n", (char)ptr->content);
// 		// 	if (ft_strchr(" \n", (char)ptr->content))
// 		// 		count++;
// 		// 	ptr->content++;
// 		// }
// 		if (min_width == 0)
// 			min_width = count;
// 		else if (count < min_width)
// 			min_width = count;
// 		ptr = ptr->next;
// 	}
// 	return (min_width);
// }

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
