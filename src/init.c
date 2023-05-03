/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/17 13:38:20 by mhaan         #+#    #+#                 */
/*   Updated: 2023/05/03 17:05:45 by mhaan         ########   odam.nl         */
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
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
	if (!fdf->mlx)
		ft_error("Error with initializing mlx.\n");
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img)
		ft_error("Error with initializing image.\n");
	ft_bzero(fdf->img->pixels, fdf->img->width * fdf->img->height * sizeof(int32_t));
	return (fdf);
}

static t_map	*init_map(char **map_data)
{
	t_map	*map;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	map->height = count_rows(map_data);
	map->width = count_columns(map_data);
	map->grid = NULL;
	return (map);
}

static t_camera *init_camera(t_camera *camera, t_map *map)
{
	camera = (t_camera *)ft_calloc(1, sizeof(t_camera));

	if (WIDTH / map->width < 1 && HEIGHT / map->height < 1)
		camera->zoom_factor = 1;
	else if (WIDTH / (map->width * 3) < HEIGHT / (map->height * 2))
		camera->zoom_factor = WIDTH / (map->width * 3);
	else
		camera->zoom_factor = HEIGHT / (map->height * 2);
	if (camera->zoom_factor < 2)
		camera->zoom_factor = 2;
	camera->x_offset = map->width * camera->zoom_factor * 1.2;
	camera->y_offset = map->height * camera->zoom_factor * 0.6;
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	return (camera);
}

t_point	init_point(int x, int y, int z, uint32_t c)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.color.c = c;
	return (point);
}
