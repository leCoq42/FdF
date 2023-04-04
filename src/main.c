/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 16:58:57 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/04 17:46:10 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

typedef void	(*mlx_closefunc)(void* param);

static void	draw_horz_line(mlx_image_t *image, uint32_t y, uint32_t color)
{
	u_int32_t	x;

	x = 0;
	while (x < image->width)
	{
		mlx_put_pixel(image, x, y, color);
		x++;
	}
}

static void	draw_vert_line(mlx_image_t *image, uint32_t x, uint32_t color)
{
	u_int32_t	y;

	y = 0;
	while (y < image->height)
	{
		mlx_put_pixel(image, x, y, color);
		y++;
	}
}

static void	close_func(void *param)
{
	const mlx_t	*mlx = param;

	ft_printf("Closing window: %d\n", mlx->window);
	exit(EXIT_SUCCESS);
}

int	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(800, 400, "Hello World!", false);
	mlx_image_t* img = mlx_new_image(mlx, 800, 400);
	draw_horz_line(img, 200, 0xFF0000FF);
	draw_vert_line(img, 400, 0xFF0000FF);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		exit(EXIT_FAILURE);
	mlx_close_hook(mlx, close_func, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	exit (EXIT_SUCCESS);
}
