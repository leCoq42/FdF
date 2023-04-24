/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bresenham_line.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 11:46:42 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/24 11:50:53 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

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
