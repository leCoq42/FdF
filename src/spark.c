/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spark.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 16:58:57 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/07 13:50:20 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

// typedef void	(*mlx_closefunc)(void* param);

// static void	draw_horz_line(mlx_image_t *image, uint32_t y, uint32_t color)
// {
// 	u_int32_t	x;

// 	x = 0;
// 	while (x < image->width)
// 	{
// 		mlx_put_pixel(image, x, y, color);
// 		x++;
// 	}
// }

// static void	draw_vert_line(mlx_image_t *image, uint32_t x, uint32_t color)
// {
// 	u_int32_t	y;

// 	y = 0;
// 	while (y < image->height)
// 	{
// 		mlx_put_pixel(image, x, y, color);
// 		y++;
// 	}
// }

static mlx_image_t* block;

static void	close_func(void *param)
{
	const mlx_t	*mlx = param;

	ft_printf("Closing window: %d\n", mlx->height);
	exit(EXIT_SUCCESS);
}

#define BPP sizeof(int32_t)

static mlx_image_t	*ft_draw_rect(mlx_t *mlx, int32_t width, int32_t height, int32_t color)
{
	mlx_image_t	*img;
	int32_t		x = 0;
	int32_t		y = 0;

	img = mlx_new_image(mlx, width, height);
	ft_memset(img->pixels, color, img->width * img->height * BPP);
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			mlx_put_pixel(img, x, y, color);
			y++;
		}
		x++;
	}
	return (img);
}

// static void ft_on_key(void *param)
// {
// 	mlx_t* mlx = param;

// 	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
// 	{
// 			mlx_terminate(mlx);
// 			ft_printf("Success!\n");
// 			exit (EXIT_SUCCESS);
// 	}
// }

static void ft_on_key(void *param)
{
	mlx_t *mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{
		ft_printf("Success!\n");
		mlx_close_window(mlx);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		block->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		block->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		block->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		block->instances[0].x += 5;
}

// void f(void)
// {
// 	system("leaks fdf");
// }

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*background;
	// mlx_image_t	*block;
	// int32_t		WIDTH = 800;
	// int32_t		HEIGHT = 400;

	// atexit(f);
	mlx = mlx_init(WIDTH, HEIGHT, "Hello World!", false);
	if (!mlx)
		exit(EXIT_FAILURE);
	background = ft_draw_rect(mlx, WIDTH, HEIGHT, 0xFFFFFFFF);
	if (mlx_image_to_window(mlx, background, 0, 0) < 0)
		exit(EXIT_FAILURE);
	block = ft_draw_rect(mlx, 30, 30, 0x0000FFFF);
	if (mlx_image_to_window(mlx, block, 0, 0) < 0)
		exit(EXIT_FAILURE);
	// draw_horz_line(img, (HEIGHT/2), 0xFF0000FF);
	// draw_vert_line(img, (WIDTH/2), 0xFF0000FF);
	mlx_loop_hook(mlx, ft_on_key, mlx);
	mlx_close_hook(mlx, close_func, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	exit (EXIT_SUCCESS);
}
