/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/17 11:28:19 by mhaan         #+#    #+#                 */
/*   Updated: 2023/05/04 11:39:46 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

static void	rotate_x(int *y, int *z, double alpha);
static void	rotate_y(int *x, int *z, double beta);
static void	rotate_z(int *x, int *y, double gamma);

t_point	calculate_projection(t_point point, t_fdf *fdf)
{
	t_point	proj;
	// double alpha = 0.785;
	// double beta = 0.615;
	// double gamma = 0.615;

	proj = init_point(point.x, point.y, point.z, point.c.c);
	proj.x *= fdf->camera->zoom;
	proj.y *= fdf->camera->zoom;
	proj.z *= fdf->camera->zoom;
	// proj.z *= (1 + fdf->camera->zoom_factor * 0.5);
	// if (2 < 1)
		rotate_x(&proj.y, &proj.z, fdf->camera->alpha);
	// if (2 < 1)
		rotate_y(&proj.x, &proj.z, fdf->camera->beta);
	// if (2 < 1)
		rotate_z(&proj.x, &proj.y, fdf->camera->gamma);
	// proj.x = (proj.x - proj.y) * cos(0.523599);
	proj.x += fdf->camera->x_off;
	// if (proj.x > WIDTH || proj.x < 0)
	// 	proj.y = 0;
	// else
	// 	proj.y = (-proj.z + (proj.x + proj.y)) * sin(0.523599);
	proj.y += fdf->camera->y_off;
	return (proj);
}

static void	rotate_x(int *y, int *z, double alpha)
{
	int	old_y;

	old_y = *y;
	*y = old_y * cos(alpha) - *z * sin(alpha);
	*z = old_y * sin(alpha) + *z * cos(alpha);
}

static void	rotate_y(int *x, int *z, double beta)
{
	int	old_x;

	old_x = *x;
	*x = old_x * cos(beta) - *z * sin(beta);
	*z = old_x * sin(beta) + *z * cos(beta);
}

static void	rotate_z(int *x, int *y, double gamma)
{
	int	old_x;

	old_x = *x;
	*x = old_x * cos(gamma) - *y * sin(gamma);
	*y = old_x * sin(gamma) + *y * cos(gamma);
}

void	reset_camera(t_camera *camera, t_map *map)
{
	if (WIDTH / map->width < 1 && HEIGHT / map->height < 1)
		camera->zoom = 1;
	else if (WIDTH / (map->width * 3) < HEIGHT / (map->height * 2))
		camera->zoom = WIDTH / (map->width * 3);
	else
		camera->zoom = HEIGHT / (map->height * 2);
	if (camera->zoom < 2)
		camera->zoom = 2;
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->pretty = -1;
	camera->x_off = (WIDTH / 2) - (map->width * camera->zoom)/2;
	camera->y_off = (HEIGHT / 2) - (map->height * camera->zoom)/2;
}