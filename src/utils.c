/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 16:54:11 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/13 15:11:36 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void	ft_error(char *s)
{
	ft_putstr_fd(s, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

// void	print_map(char **map)
// {
// 	int i = 0;
// 	while (map[i])
// 	{
// 		ft_printf("%s\n", map[i]);
// 		i++;
// 	}
// }

void	print_grid(t_point	**grid, t_map *map)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < (map)->height)
	{
		x = 0;
		while (x < (map)->width)
		{
			ft_printf(" %d", grid[y][x].z);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}
