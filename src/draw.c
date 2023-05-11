/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 10:43:10 by mhaan         #+#    #+#                 */
/*   Updated: 2023/05/11 13:59:09 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void	fdf_draw_image(t_fdf *fdf, int32_t background)
{
	int	x;
	int	y;

	ft_memset(fdf->img->pixels, background, HEIGHT * WIDTH * sizeof(int32_t));
	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (x < (fdf->map->width) - 1)
				draw_line(fdf, fdf->map->grid[y][x], fdf->map->grid[y][x + 1]);
			if (y < (fdf->map->height) - 1)
				draw_line(fdf, fdf->map->grid[y][x], fdf->map->grid[y + 1][x]);
			x++;
		}
		y++;
	}
}

void	draw_line(t_fdf *fdf, t_point p1, t_point p2)
{
	t_point	p1_p;
	t_point	p2_p;

	p1_p = calculate_projection(p1, fdf);
	p2_p = calculate_projection(p2, fdf);
	if (p1_p.x >= 0 && p1_p.x < (int)fdf->img->width && p2_p.x >= 0 && p2_p.x < (int)fdf->img->width)
	{
		if (p1_p.y >= 0 && p1_p.y < (int)fdf->img->height && p2_p.y >= 0 && p2_p.y < (int)fdf->img->height)
		{
			if (fdf->camera->pretty > 0)
				wu_line(fdf, p1_p, p2_p);
			else
				bresenham_line(fdf, p1_p, p2_p);
		}
	}
}

void	fdf_put_pixel(t_fdf *fdf, int x, int y, t_color c)
{
	if (x < 0 || x >= (int)(fdf->img->width))
		return ;
	if (y < 0 || y >= (int)(fdf->img->height))
		return ;
	mlx_put_pixel(fdf->img, x, y, c.c);
}
