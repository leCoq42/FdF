/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   projection.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 13:43:09 by mhaan         #+#    #+#                 */
/*   Updated: 2023/05/18 12:21:31 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

static void	rotate_x(int *y, int *z, double alpha);
static void	rotate_y(int *x, int *z, double beta);
static void	rotate_z(int *x, int *y, double gamma);
static void	iso_projection(t_point *proj);

t_point	calculate_projection(t_point point, t_fdf *fdf)
{
	t_point	proj;

	proj = init_point(point.x, point.y, point.z, point.c.c);
	proj.x *= fdf->camera.zoom;
	proj.y *= fdf->camera.zoom;
	proj.z *= (fdf->camera.zoom * 0.5);
	rotate_x(&proj.y, &proj.z, fdf->camera.alpha);
	rotate_y(&proj.x, &proj.z, fdf->camera.beta);
	rotate_z(&proj.x, &proj.y, fdf->camera.gamma);
	if (fdf->camera.iso > 0)
		iso_projection(&proj);
	proj.x += fdf->camera.x_off;
	proj.y += fdf->camera.y_off;
	return (proj);
}

static void	iso_projection(t_point *proj)
{
	int	old_x;

	old_x = proj->x;
	proj->x = (proj->x - proj->y) * cos(0.523599);
	proj->y = (-proj->z + (old_x + proj->y) * sin(0.523599));
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
