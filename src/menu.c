/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   menu.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/05 12:59:43 by mhaan         #+#    #+#                 */
/*   Updated: 2023/05/05 14:51:50 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void	put_menu(t_fdf *fdf)
{
	int y;

	y = 0;
	mlx_put_string(fdf->mlx, "WSAD: Move up/down/left/right", 10, y+=20);
	mlx_put_string(fdf->mlx, "Up/Down: Zoom in/out", 10, y+=20);
	mlx_put_string(fdf->mlx, "P: Paralel view", 10, y+=20);
	mlx_put_string(fdf->mlx, "I: Isometric view", 10, y+=20);
	mlx_put_string(fdf->mlx, "Space: Make it prettier!", 10, y+=20);
	mlx_put_string(fdf->mlx, "R: Reset camera", 10, y+=20);
	mlx_put_string(fdf->mlx, "'1': Increase alpha-angle", 10, y+=20);
	mlx_put_string(fdf->mlx, "'2': Decrease alpha-angle", 10, y+=20);
	mlx_put_string(fdf->mlx, "'7': Increase beta-angle", 10, y+=20);
	mlx_put_string(fdf->mlx, "'8': Decrease beta-angle", 10, y+=20);
	mlx_put_string(fdf->mlx, "Left: Increase gamma-angle", 10, y+=20);
	mlx_put_string(fdf->mlx, "Right: Decrease gamma-angle", 10, y+=20);
}