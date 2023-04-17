/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/10 15:48:39 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/17 15:59:28 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

// static void	free_map_data(char **map_data);

void	fdf_create_map(t_map *map, char **map_data)
{
	fill_grid(map, map_data);
	ft_printf("Height = %u\n", map->height);
	ft_printf("Width = %u\n", map->width);
	// free_map_data(map_data);
	print_grid(map);
}

// void	free_map_data(char **map_data)
// {
// 	int	i;

// 	i = 0;
// 	while (map_data[i])
// 	{
// 		free(map_data[i]);
// 		i++;
// 	}
// 	free(map_data);
// }
