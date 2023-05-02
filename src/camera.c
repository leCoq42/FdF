/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/17 11:28:19 by mhaan         #+#    #+#                 */
/*   Updated: 2023/05/02 17:12:40 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

t_point	isometric_projection(t_point point, t_fdf *fdf)
{
	t_point	proj;

	point.x *= fdf->camera->zoom_factor;
	point.y *= fdf->camera->zoom_factor;
	point.z *= fdf->camera->zoom_factor;
	proj.x = (point.x - point.y) * cos(0.523599) + fdf->camera->x_offset;
	if (proj.x > WIDTH || proj.x < 0)
		proj.y = 0;
	else
		proj.y = (-point.z + (point.x + point.y)) * sin(0.523599) + fdf->camera->y_offset;
	proj.color.c = point.color.c;
	return (proj);
}

// void	rotate_x(int *y, int *z, double alpha)
// {
// 	int tmp_y;

// 	tmp_y = *y;
// 	*y = tmp_y * cos(alpha) + *z * sin(alpha);
// 	*z = -tmp_y * sin(alpha) + *z * cos(alpha);
// }

// void	rotate_y(int *x, int *z, double beta)
// {
// 	int tmp_z
// }

// void	rotate_z(int *x, int *y, double gamma)
// {
// 	int tmp_x
// }