/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 10:43:10 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/19 19:57:15 by mhaan         ########   odam.nl         */
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
    result.t_rgba.r = c1.t_rgba.r + (c2.t_rgba.r - c1.t_rgba.r) * t;
	// printf("c1.r: %u\n", c1.t_rgba.r);
	// printf("c2.r: %u\n", c2.t_rgba.r);
	// printf("t: %f\n", t);
	// printf("result.r: %u\n", result.t_rgba.r);
    result.t_rgba.g = c1.t_rgba.g + (c2.t_rgba.g - c1.t_rgba.g) * t;
	// printf("G: %u\n", result.t_rgba.g);
    result.t_rgba.b = c1.t_rgba.b + (c2.t_rgba.b - c1.t_rgba.b) * t;
	// printf("B: %u\n", result.t_rgba.b);
    result.t_rgba.a = c1.t_rgba.a + (c2.t_rgba.a - c1.t_rgba.a) * t;
	// printf("A: %u\n", result.t_rgba.a);
    return result;
}

void wu_line(mlx_image_t *img, t_point p1, t_point p2)
{
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
    float gradient = dy / (float)dx;
    float intery = p1.y + gradient;

    for (int x = p1.x + 1; x < p2.x; x++)
    {
        float t = (x - p1.x) / (float)dx;
        t_color c = color_interpolation(p1.color, p2.color, t);

        if (steep)
        {
            mlx_put_pixel(img, (int)intery, x, c.c);
            mlx_put_pixel(img, (int)intery + 1, x, c.c);
        }
        else
        {
            mlx_put_pixel(img, x, (int)intery, c.c);
            mlx_put_pixel(img, x, (int)intery + 1, c.c);
        }
        intery += gradient;
    }
}

void bresenham_line(mlx_image_t *img, t_point p1, t_point p2)
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
		mlx_put_pixel(img, p1.x, p1.y, p1.color.c);
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
