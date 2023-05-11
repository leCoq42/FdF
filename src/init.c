/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/17 13:38:20 by mhaan         #+#    #+#                 */
/*   Updated: 2023/05/11 14:38:41 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

static t_map	*init_map(t_list *map_data);

t_fdf	*fdf_init(t_fdf *fdf, t_list *map_data)
{
	fdf = (t_fdf *)ft_calloc(1, sizeof(t_fdf));
	if (!fdf)
		ft_error("Error with initializing fdf\n");
	fdf->map = init_map(map_data);
	fdf->camera = NULL;
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
	if (!fdf->mlx)
		ft_error("Error with initializing mlx.\n");
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img)
		ft_error("Error with initializing image.\n");
	return (fdf);
}

static t_map	*init_map(t_list *map_data)
{
	t_map	*map;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		ft_error("Error with initializing map.\n");
	map->height = fdf_count_rows(map_data);
	map->width = 0;
	map->grid = NULL;
	return (map);
}

t_camera	*init_camera(t_camera *camera, t_map *map, mlx_image_t *img)
{
	camera = (t_camera *)ft_calloc(1, sizeof(t_camera));
	if (!camera)
		ft_error("Error: unsuccesful camaera initialization.");
	if (img->width / (map->width * 3) < img->height / (map->height * 2))
		camera->zoom = img->width / (map->width * 3);
	else
		camera->zoom = img->height / (map->height * 2);
	if (camera->zoom < 2)
		camera->zoom = 2;
	camera->x_off = (img->width / 2) - (map->width * camera->zoom) / 2;
	camera->y_off = (img->height / 2) - (map->height * camera->zoom) / 2;
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->pretty = -1;
	camera->iso = 0;
	return (camera);
}

t_point	init_point(int x, int y, int z, uint32_t c)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.c.c = c;
	return (point);
}
