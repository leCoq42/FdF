/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/10 15:48:39 by mhaan         #+#    #+#                 */
/*   Updated: 2023/05/05 09:56:29 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

static void	free_map_data(char ***map_data);

void	fdf_create_map(t_map *map, char **map_data)
{
	// print_map_data(map_data);
	create_grid(map, map_data);
	ft_printf("Height = %u\n", map->height);
	ft_printf("Width = %u\n", map->width);
	free_map_data(&map_data);
	if (map_data)
		ft_error("Error with freeing!\n");
}

static void	free_map_data(char ***map_data)
{
	int	i;

	i = 0;
	while ((*map_data)[i])
	{
		free((*map_data)[i]);
		i++;
	}
	free(*map_data);
	*map_data = NULL;
}
