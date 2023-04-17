/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   line.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/14 09:48:52 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/17 18:28:44 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void	fdf_draw_image(t_fdf *fdf, int32_t color)
{
	unsigned int	x;
	unsigned int	y;

	ft_memset(fdf->img->pixels, color, WIDTH * HEIGHT * sizeof(int32_t));
	y = 0;
	while (y < (fdf->map->height))
	{
		x = 0;
		while (x < (fdf->map->width))
		{
			if (x < (fdf->map->width) - 1)
				draw_line(fdf->img, fdf->map->grid[y][x].x, fdf->map->grid[y][x].y,
					fdf->map->grid[y][x + 1].x, fdf->map->grid[y][x + 1].y, 0xFF0000FF);
			if (y < (fdf->map->height) - 1)
				draw_line(fdf->img, fdf->map->grid[y][x].x, fdf->map->grid[y][x].y,
					fdf->map->grid[y + 1][x].x, fdf->map->grid[y + 1][x].y, 0xFF0000FF);
			x++;
		}
		y++;
	}
}

void draw_line(mlx_image_t *img, int x1, int y1, int x2, int y2, int color)
{
	x1 *= 100;
	x2 *= 100;
	y1 *= 100;
	y2 *= 100;
	int w = x2 - x1;
	int h = y2 - y1;
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
		mlx_put_pixel(img, x1, y1, color);
		numerator += shortest;
		if (!(numerator < longest))
		{
			numerator -= longest;
			x1 += dx1;
			y1 += dy1;
		}
		else
		{
			x1 += dx2;
			y1 += dy2;
		}
	}
}