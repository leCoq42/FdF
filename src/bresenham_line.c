/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bresenham_line.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 11:46:42 by mhaan         #+#    #+#                 */
/*   Updated: 2023/05/04 11:32:54 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

static void	calculate_step(int *err, t_point *p1, t_point *d, t_point *s);
static int	compare(int i, int j);

void	bresenham_line(t_fdf *fdf, t_point p1, t_point p2)
{
	t_point	delta;
	t_point	sign;
	int		err[2];

	delta.x = ft_abs(p2.x - p1.x);
	delta.y = ft_abs(p2.y - p1.y);
	sign.x = compare(p1.x, p2.x);
	sign.y = compare(p1.y, p2.y);
	err[0] = delta.x - delta.y;
	while (p1.x != p2.x || p1.y != p2.y)
	{
		fdf_put_pixel(fdf, p1.x, p1.y, p1.c);
		calculate_step(err, &p1, &delta, &sign);
	}
}

static void	calculate_step(int *err, t_point *p1, t_point *d, t_point *s)
{
	err[1] = 2 * err[0];
	if (err[1] > -d->y)
	{
		err[0] -= d->y;
		p1->x += s->x;
	}
	if (err[1] < d->x)
	{
		err[0] += d->x;
		p1->y += s->y;
	}
}

static int	compare(int i, int j)
{
	if (i < j)
		return (1);
	return (-1);
}
