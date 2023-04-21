/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 10:43:10 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/21 16:57:43 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_color	color_interpolation(t_color c1, t_color c2, float t)
{
    t_color result;
    result.t_rgba.r = c1.t_rgba.r + (c2.t_rgba.r - c1.t_rgba.r) * t + 0.5;
    result.t_rgba.g = c1.t_rgba.g + (c2.t_rgba.g - c1.t_rgba.g) * t + 0.5;
    result.t_rgba.b = c1.t_rgba.b + (c2.t_rgba.b - c1.t_rgba.b) * t + 0.5;
    result.t_rgba.a = c1.t_rgba.a + (c2.t_rgba.a - c1.t_rgba.a) * t + 0.5;
    return result;
}

void wu_line(t_fdf *fdf, t_point p1, t_point p2)
{
	// p1.color.t_rgba.g = 0;
	// p1.color.t_rgba.r = 255;
	// p1.color.t_rgba.b = 255;
	// p1.color.t_rgba.a = 255;
    // p2.color.t_rgba.g = 0;
    // p2.color.t_rgba.r = 255;
    // p2.color.t_rgba.b = 255;
    // p2.color.t_rgba.a = 255;

    int steep = abs(p2.y - p1.y) > abs(p2.x - p1.x);
    if (steep)
    {
        ft_swap(&p1.x, &p1.y);
        ft_swap(&p2.x, &p2.y);
    }
    if (p1.x > p2.x)
    {
        ft_swap(&p1.x, &p2.x);
        ft_swap(&p1.y, &p2.y);
        t_color temp = p1.color;
        p1.color = p2.color;
        p2.color = temp;
    }

	int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    float gradient = (float)dy / (float)dx;
    float intery = p1.y + gradient;

    for (int x = p1.x + 1; x < p2.x; x++)
    {
        float t = (x - p1.x) / (float)dx;
        t_color c = color_interpolation(p1.color, p2.color, t);

        float i1 = 1.0 - (intery - (int)intery);
        float i2 = intery - (int)intery;

        c.t_rgba.a = (uint8_t)(i1 * 255);
        if (steep)
            fdf_put_pixel(fdf, (int)intery, x, c);
        else
            fdf_put_pixel(fdf, x, (int)intery, c);

        c.t_rgba.a = (uint8_t)(i2 * 255);
        if (steep)
            fdf_put_pixel(fdf, (int)intery + 1, x, c);
        else
            fdf_put_pixel(fdf, x, (int)intery + 1, c);

        intery += gradient;
    }
}

void bresenham_line(t_fdf *fdf, t_point p1, t_point p2)
{
	int w = p2.x - p1.x;
	int h = p2.y - p1.y;
	int longest;
	int shortest;
	int numerator;
	int dx1 = 0;
	int dy1 = 0;
	int dx2 = 0;
	int dy2 = 0;

	if (w < 0)
		dx1 = -1;
	else if (w > 0)
		dx1 = 1;
	if (h < 0)
		dy1 = -1;
	else if (h > 0)
		dy1 = 1;
	if (w < 0)
		dx2 = -1;
	else if (w > 0)
		dx2 = 1;
	longest = abs(w);
	shortest = abs(h);

	if (!(longest > shortest))
	{
		longest = abs(h) ;
		shortest = abs(w) ;
		if (h < 0)
			dy2 = -1;
		else if (h > 0)
			dy2 = 1;
		dx2 = 0;
	}
	numerator = longest >> 1;
	for (int i = 0; i <= longest; i++)
	{
		fdf_put_pixel(fdf, p1.x, p1.y, p1.color);
		numerator += shortest;
		if (!(numerator < longest))
		{
			numerator -= longest;
			p1.x += dx1;
			p1.y += dy1;
		}
		else
		{
			p1.x += dx2;
			p1.y += dy2;
		}
	}
}

void	fdf_put_pixel(t_fdf *fdf, int x, int y, t_color c)
{
	if (x < 0 || x > (int)(fdf->img->width))
		return ;
	if ( y < 0 || y > (int)(fdf->img->height))
		return ;
	mlx_put_pixel(fdf->img, x, y, c.c);
}