/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bresenham_line.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 11:46:42 by mhaan         #+#    #+#                 */
/*   Updated: 2023/05/12 16:09:17 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

static void		calc_step(int *err, t_point *p1, t_point *delta, t_point *s);
static int		get_sign(int i, int j);

void	bresenham_line(t_fdf *fdf, t_point p1, t_point p2)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		err[2];

	delta.x = ft_abs(p2.x - p1.x);
	delta.y = ft_abs(p2.y - p1.y);
	sign.x = get_sign(p1.x, p2.x);
	sign.y = get_sign(p1.y, p2.y);
	err[0] = delta.x - delta.y;
	cur = p1;
	while (cur.x != p2.x || cur.y != p2.y)
	{
		fdf_put_pixel(fdf, cur.x, cur.y, cur.c);
		calc_step(err, &cur, &delta, &sign);
	}
	fdf_put_pixel(fdf, cur.x, cur.y, cur.c);
}

static void	calc_step(int *err, t_point *p, t_point *delta, t_point *s)
{
	err[1] = 2 * err[0];
	if (err[1] > -delta->y)
	{
		err[0] -= delta->y;
		p->x += s->x;
	}
	if (err[1] < delta->x)
	{
		err[0] += delta->x;
		p->y += s->y;
	}
}

static int	get_sign(int i, int j)
{
	if (i < j)
		return (1);
	return (-1);
}
