/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 10:43:10 by mhaan         #+#    #+#                 */
/*   Updated: 2023/05/03 11:48:06 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void	fdf_draw_image(t_fdf *fdf, int32_t background)
{
	int	x;
	int	y;

	ft_memset(fdf->img->pixels, background, WIDTH * HEIGHT * sizeof(int32_t));
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

	p1_proj = calculate_projection(p1, fdf);
	p2_proj = calculate_projection(p2, fdf);
	if (p1_proj.x >= 0 && p1_proj.x < WIDTH && p2_proj.x >= 0 && p2_proj.x < WIDTH)
	{
		if (p1_proj.y >= 0 && p1_proj.y < HEIGHT && p2_proj.y >= 0 && p2_proj.y < HEIGHT)
		{
			wu_line(fdf, p1_proj, p2_proj);
			// t_point	p3_proj = p1_proj;
			// t_point	p4_proj = p2_proj;
			// p3_proj.x += 900;
			// p4_proj.x += 900;
			// if (p3_proj.x >= 0 && p3_proj.x < WIDTH && p4_proj.x >= 0 && p4_proj.x < WIDTH)
			// 	if (p3_proj.y >= 0 && p3_proj.y < HEIGHT && p4_proj.y >= 0 && p4_proj.y < HEIGHT)
			// 		bresenham_line(fdf, p3_proj, p4_proj);
		}
	}
}


void	fdf_put_pixel(t_fdf *fdf, int x, int y, t_color c)
{
	if (x < 0 || x >= (int)(fdf->img->width))
		return ;
	if ( y < 0 || y >= (int)(fdf->img->height))
		return ;
	mlx_put_pixel(fdf->img, x, y, c.c);
}