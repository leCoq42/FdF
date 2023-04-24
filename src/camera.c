/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/17 11:28:19 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/24 11:55:12 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

t_point	isometric_projection(t_point point, t_camera *camera)
{
	t_point	proj;

	point.x *= camera->zoom_factor;
	point.y *= camera->zoom_factor;
	point.z *= camera->zoom_factor;
	proj.x = (point.x - point.y) * cos(0.523599) + camera->x_offset;
	proj.y = (-point.z + (point.x + point.y)) * sin(0.523599) + camera->y_offset;
	// proj.x = (point.x - point.y) * cos(0.46373398) + camera->x_offset;
	// proj.y = (-point.z + (point.x + point.y)) * sin(0.46373398) + camera->y_offset;
	proj.z = 0;
	// proj.x = point.x + camera->x_offset;
	// proj.y = point.y + camera->y_offset;
	// proj.z = point.z;
	proj.color.c = 0xFFFFFFFF;
	return(proj);
}