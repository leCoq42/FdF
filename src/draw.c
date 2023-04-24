/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 10:43:10 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/24 11:57:16 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"



void	fdf_draw_image(t_fdf *fdf, int32_t color)
{
	int	x;
	int	y;

	ft_memset(fdf->img->pixels, color, WIDTH * HEIGHT * sizeof(int32_t));
	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (x < (fdf->map->width) - 1)
				draw_iso_line(fdf, fdf->map->grid[y][x], fdf->map->grid[y][x + 1]);
			if (y < (fdf->map->height) - 1)
				draw_iso_line(fdf, fdf->map->grid[y][x], fdf->map->grid[y + 1][x]);
			x++;
		}
		y++;
	}
}

void	draw_iso_line(t_fdf *fdf, t_point p1, t_point p2)
{
	t_point	p1_proj;
	t_point	p2_proj;

	p1_proj = isometric_projection(p1, fdf->camera);
	p2_proj = isometric_projection(p2, fdf->camera);
	wu_line(fdf, p1_proj, p2_proj);
	// t_point	p3_proj = p1_proj;
	// t_point	p4_proj = p2_proj;
	// p3_proj.x += 600;
	// p4_proj.x += 600;
	// // p4_proj.y -= 100;
	// // p3_proj.y -= 100;
	// bresenham_line(fdf, p1_proj, p2_proj);
}


void	fdf_put_pixel(t_fdf *fdf, int x, int y, t_color c)
{
	if (x < 0 || x > (int)(fdf->img->width))
		return ;
	if ( y < 0 || y > (int)(fdf->img->height))
		return ;
	mlx_put_pixel(fdf->img, x, y, c.c);
}