/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/17 11:28:19 by mhaan         #+#    #+#                 */
/*   Updated: 2023/05/12 14:07:47 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void	reset_camera(t_camera *camera, t_map *map, mlx_image_t *img)
{
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
	camera->iso = -1;
}

void	center_camera(t_camera *camera, t_map *map, mlx_image_t *img)
{
	camera->x_off = (img->width / 2) - (map->width * camera->zoom) / 2;
	camera->y_off = (img->height / 2) - (map->height * camera->zoom) / 2;
}
