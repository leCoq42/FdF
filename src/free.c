/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/18 10:11:50 by mhaan         #+#    #+#                 */
/*   Updated: 2023/05/18 13:49:51 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

static void	free_grid(t_map *map);

void	free_before_exit(t_fdf **fdf)
{
	mlx_terminate((*fdf)->mlx);
	free_grid((*fdf)->map);
	free((*fdf)->map);
}

static void	free_grid(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->height)
	{
		free(map->grid[y]);
		y++;
	}
	free(map->grid);
	map->grid = NULL;
}

void	free_content(void *nodeptr)
{
	char	*content;

	content = (char *)nodeptr;
	free(content);
	content = NULL;
}
