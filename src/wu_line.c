/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   line.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/14 09:48:52 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/24 11:50:27 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

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