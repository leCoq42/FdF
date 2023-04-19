/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/17 13:38:20 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/19 16:00:22 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

static t_camera	*init_camera(t_camera *camera, t_map *map);
static t_map	*init_map(char **map_data);

t_fdf	*fdf_init(t_fdf *fdf, char **map_data)
{
	fdf = (t_fdf *)ft_calloc(1, sizeof(t_fdf));
	fdf->map = init_map(map_data);
	if (!fdf->map)
		ft_error("Error with initializing map.\n");
	fdf->camera = init_camera(fdf->camera, fdf->map);
	if (!fdf->camera)
		ft_error("Error with initializing camera.\n");
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "FdF", false);
	if (!fdf->mlx)
		ft_error("Error with initializing mlx.\n");
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img)
		ft_error("Error with initializing image.\n");
	ft_memset(fdf->img->pixels, 0x00000000, fdf->img->width * fdf->img->height * sizeof(int32_t));
	return (fdf);
}

static t_map	*init_map(char **map_data)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->height = count_rows(map_data);
	map->width = count_columns(map_data);
	map->grid = NULL;
	return (map);
}

static t_camera *init_camera(t_camera *camera, t_map *map)
{
	camera = (t_camera *)ft_calloc(map->width * map->height, sizeof(t_camera));
	return (camera);
}
