/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   line.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/14 09:48:52 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/20 15:33:52 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

// static int	check_borders(t_fdf *fdf, t_point point);

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

	p1_proj = isometric_projection(p1);
	p2_proj = isometric_projection(p2);
	// if (!(check_borders(fdf, p1_proj)) || !(check_borders(fdf, p2_proj)))
	// 	return ;
	wu_line(fdf, p1_proj, p2_proj);
	// t_point	p3_proj = p1_proj;
	// t_point	p4_proj = p2_proj;
	// p3_proj.x += 800;
	// p4_proj.x += 800;
	// p4_proj.y -= 100;
	// p3_proj.y -= 100;
	// if (!(check_borders(fdf, p3_proj)) || !(check_borders(fdf, p4_proj)))
	// 	return ;
	// bresenham_line(fdf->img, p3_proj, p4_proj);
}

t_point	isometric_projection(t_point point)
{
	t_point	proj;

	proj.x = (point.x - point.y) * cos(0.523599) * SCALE_FACTOR + TRANSLATION;
	proj.y = (-point.z + (point.x + point.y)) * sin(0.523599) * SCALE_FACTOR + TRANSLATION * 0.5;
	proj.z = 0;
	// proj.x = point.x * SCALE_FACTOR + TRANSLATION;
	// proj.y = point.y  * SCALE_FACTOR + TRANSLATION;
	// proj.z = point.z;
	proj.color.c = 0x00FF00FF;
	return(proj);
}

// t_point isometric_projection(t_point point)
// {
//     const float sqrt3 = sqrtf(3);
//     t_point pt;

//     pt.x = (point.x - point.y) * sqrt3 / 2;
//     pt.y = (point.x + point.y) / 2 - point.z;
// 	pt.z = 0;
// 	pt.color.c = 0xF0F0F0FF;
//     return(pt);
// }

// static int	check_borders(t_fdf *fdf, t_point point)
// {
// 	if (point.x > (int)((fdf->img->width) - 2) || point.x < 0)
// 		return (0);
// 	if (point.y > (int)((fdf->img->height) - 2) || point.y < 0)
// 		return (0);
// 	return (1);
// }

int	check_borders(t_fdf *fdf, int x, int y)
{
	if (x > (int)((fdf->img->width) - 2) || x < 0)
		return (0);
	if (y > (int)((fdf->img->height) - 2) || y < 0)
		return (0);
	return (1);
}