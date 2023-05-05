/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   user_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 10:20:30 by mhaan         #+#    #+#                 */
/*   Updated: 2023/05/05 15:25:34 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

static void	close_mlx(void *param);
static void	ft_on_key(void *param);

void	user_controls(t_fdf *fdf)
{
	mlx_loop_hook(fdf->mlx, &close_mlx, fdf);
	mlx_loop_hook(fdf->mlx, &ft_on_key, fdf);
}

static void	ft_on_key(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_A))
		fdf->camera->x_off += (10 + (fdf->camera->zoom * 0.1));
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_D))
		fdf->camera->x_off -= (10 + (fdf->camera->zoom * 0.1));
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W))
		fdf->camera->y_off += (10 + (fdf->camera->zoom * 0.1));
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
		fdf->camera->y_off -= (10 + (fdf->camera->zoom * 0.1));
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		fdf->camera->zoom += 1 + (fdf->camera->zoom * 0.1);
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		fdf->camera->zoom -= 1 + (fdf->camera->zoom * 0.1);
	if (fdf->camera->zoom < 2)
		fdf->camera->zoom = 2;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_1))
		fdf->camera->alpha += 0.1;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_2))
		fdf->camera->alpha -= 0.1;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_7))
		fdf->camera->beta += 0.1;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_8))
		fdf->camera->beta -= 0.1;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		fdf->camera->gamma += 0.1;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		fdf->camera->gamma -= 0.1;
	if (fdf->camera->x_off > WIDTH + fdf->map->width * fdf->camera->zoom)
		fdf->camera->x_off = 0 - fdf->map->width * fdf->camera->zoom;
	if (fdf->camera->x_off < 0 - fdf->map->width * fdf->camera->zoom)
		fdf->camera->x_off = WIDTH + fdf->map->width * fdf->camera->zoom;
	if (fdf->camera->y_off > HEIGHT + fdf->map->height * fdf->camera->zoom)
		fdf->camera->y_off = 0 - fdf->map->height * fdf->camera->zoom;
	if (fdf->camera->y_off < 0 - fdf->map->height * fdf->camera->zoom)
		fdf->camera->y_off = HEIGHT + fdf->map->height * fdf->camera->zoom;
	fdf_draw_image(fdf, 0x00000000);
}

void	my_keyhooks(mlx_key_data_t keydata, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
		fdf->camera->pretty *= -1;
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
		reset_camera(fdf->camera, fdf->map);
	if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
	{
		fdf->camera->iso = 0;
		fdf->camera->alpha = 1.570796;
		fdf->camera->beta = 0.0;
		fdf->camera->gamma = 0.0;
	}
	if (keydata.key == MLX_KEY_I && keydata.action == MLX_PRESS)
	{
		fdf->camera->iso = 1;
	}
}

static void	close_mlx(void *param)
{
	t_fdf	*fdf;

	fdf = param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
	{
		ft_printf("Closing.\n");
		mlx_close_window(fdf->mlx);
	}
}
