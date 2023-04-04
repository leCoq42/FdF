/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 16:58:57 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/04 15:42:54 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

int	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(800, 400, "Hello World!", false);
	mlx_image_t* img = mlx_new_image(mlx, 800, 400);
	mlx_put_pixel(img, 100, 100, 0xFF0000FF);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		exit(EXIT_FAILURE);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	exit (EXIT_SUCCESS);
}
