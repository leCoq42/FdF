/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bresenham_line.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 11:46:42 by mhaan         #+#    #+#                 */
/*   Updated: 2023/05/11 17:46:09 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

static void	calculate_step(int *err, t_point *p1, t_point *delta, t_point *s);
static int	compare(int i, int j);
static t_color	color_interpol(t_point p1, t_point p2, int x, t_point delta);

void	bresenham_line(t_fdf *fdf, t_point p1, t_point p2)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		err[2];

	delta.x = ft_abs(p2.x - p1.x);
	delta.y = ft_abs(p2.y - p1.y);
	sign.x = compare(p1.x, p2.x);
	sign.y = compare(p1.y, p2.y);
	err[0] = delta.x - delta.y;
	cur = p1;
	while (cur.x != p2.x || cur.y != p2.y)
	{
		fdf_put_pixel(fdf, cur.x, cur.y, color_interpol(p1, p2, cur.x, delta));
		calculate_step(err, &cur, &delta, &sign);
	}
}

static void	calculate_step(int *err, t_point *p1, t_point *delta, t_point *s)
{
	err[1] = 2 * err[0];
	if (err[1] > -delta->y)
	{
		err[0] -= delta->y;
		p1->x += s->x;
	}
	if (err[1] < delta->x)
	{
		err[0] += delta->x;
		p1->y += s->y;
	}
}

static int	compare(int i, int j)
{
	if (i < j)
		return (1);
	return (-1);
}

static t_color	color_interpol(t_point p1, t_point p2, int x, t_point delta)
{
	t_color	res;
	float	t;

	if (delta.x == 0)
		return (p1.c);
	t = (x - p1.x) / (delta.x + 0.001f);
	res.t_rgba.r = p1.c.t_rgba.r + (p2.c.t_rgba.r - p1.c.t_rgba.r) * t + 0.5;
	res.t_rgba.g = p1.c.t_rgba.g + (p2.c.t_rgba.g - p1.c.t_rgba.g) * t + 0.5;
	res.t_rgba.b = p1.c.t_rgba.b + (p2.c.t_rgba.b - p1.c.t_rgba.b) * t + 0.5;
	res.t_rgba.a = p1.c.t_rgba.a + (p2.c.t_rgba.a - p1.c.t_rgba.a) * t + 0.5;
	return (res);
}
