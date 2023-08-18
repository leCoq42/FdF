/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wu_line.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/14 09:48:52 by mhaan         #+#    #+#                 */
/*   Updated: 2023/05/12 16:11:11 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		swap_points(t_point *p1, t_point *p2, int steep);
static t_color	color_interpol(t_point p1, t_point p2, int x, t_point delta);
static void		draw_pix(t_fdf *fdf, t_color c, t_line line, int steep);

void	wu_line(t_fdf *fdf, t_point p1, t_point p2)
{
	t_point		delta;
	t_line		line;
	const int	steep = ft_abs(p2.y - p1.y) >= ft_abs(p2.x - p1.x);

	if (steep)
		swap_points(&p1, &p2, 1);
	if (p1.x > p2.x)
		swap_points(&p1, &p2, 0);
	delta.x = p2.x - p1.x;
	delta.y = p2.y - p1.y;
	if (delta.x != 0)
		line.grad = (double)delta.y / delta.x;
	else
		line.grad = 0;
	line.intery = p1.y + line.grad;
	line.x = p1.x + 1;
	while (line.x <= p2.x)
	{
		draw_pix(fdf, color_interpol(p1, p2, line.x, delta), line, steep);
		line.intery += line.grad;
		line.x++;
	}
}

static void	swap_points(t_point *p1, t_point *p2, int steep)
{
	t_color	tmp;

	if (steep)
	{
		ft_swap(&p1->x, &p1->y);
		ft_swap(&p2->x, &p2->y);
	}
	else
	{
		ft_swap(&p1->x, &p2->x);
		ft_swap(&p1->y, &p2->y);
		tmp = p1->c;
		p1->c = p2->c;
		p2->c = tmp;
	}
}

static t_color	color_interpol(t_point p1, t_point p2, int x, t_point delta)
{
	t_color	res;
	double	t;

	ft_bzero(&res, sizeof(t_color));
	if (delta.x == 0)
		return (p1.c);
	t = (double)(x - p1.x) / (delta.x);
	res.t_rgba.r = round(p1.c.t_rgba.r + (p2.c.t_rgba.r - p1.c.t_rgba.r) * t);
	res.t_rgba.g = round(p1.c.t_rgba.g + (p2.c.t_rgba.g - p1.c.t_rgba.g) * t);
	res.t_rgba.b = round(p1.c.t_rgba.b + (p2.c.t_rgba.b - p1.c.t_rgba.b) * t);
	res.t_rgba.a = round(p1.c.t_rgba.a + (p2.c.t_rgba.a - p1.c.t_rgba.a) * t);
	return (res);
}

static void	draw_pix(t_fdf *fdf, t_color c, t_line line, int steep)
{
	if (steep)
	{
		c.t_rgba.a = (uint8_t)((1 - (line.intery - floor(line.intery))) * 255);
		fdf_put_pixel(fdf, (int)line.intery, line.x, c);
		c.t_rgba.a = (uint8_t)((line.intery - floor(line.intery)) * 255);
		fdf_put_pixel(fdf, (int)line.intery + 1, line.x, c);
	}
	else
	{
		c.t_rgba.a = (uint8_t)((1 - (line.intery - floor(line.intery))) * 255);
		fdf_put_pixel(fdf, line.x, (int)line.intery, c);
		c.t_rgba.a = (uint8_t)((line.intery - floor(line.intery)) * 255);
		fdf_put_pixel(fdf, line.x, (int)line.intery + 1, c);
	}
}
