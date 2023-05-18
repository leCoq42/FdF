/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   user_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 10:20:30 by mhaan         #+#    #+#                 */
/*   Updated: 2023/05/18 12:19:18 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

static void	close_mlx(void *param);
static void	cam_movement_hooks(void *param);
static void	my_keyhooks(mlx_key_data_t keydata, void *param);

void	user_controls(t_fdf *fdf)
{
	mlx_loop_hook(fdf->mlx, &cam_movement_hooks, fdf);
	mlx_loop_hook(fdf->mlx, &cam_rotation_hooks, fdf);
	mlx_key_hook(fdf->mlx, &my_keyhooks, fdf);
	mlx_loop_hook(fdf->mlx, &close_mlx, fdf);
}

static void	cam_movement_hooks(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_A))
		fdf->camera.x_off += (10 + (fdf->camera.zoom * 0.1));
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_D))
		fdf->camera.x_off -= (10 + (fdf->camera.zoom * 0.1));
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W))
		fdf->camera.y_off += (10 + (fdf->camera.zoom * 0.1));
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
		fdf->camera.y_off -= (10 + (fdf->camera.zoom * 0.1));
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		fdf->camera.zoom += 1 + (fdf->camera.zoom * 0.1);
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		fdf->camera.zoom -= 1 + (fdf->camera.zoom * 0.1);
	check_cam_limits(fdf->camera, fdf->map, fdf->img);
	fdf_draw_image(fdf, 0x00000000);
}

void	check_cam_limits(t_camera camera, t_map *map, mlx_image_t *img)
{
	if (camera.zoom < 2)
		camera.zoom = 2;
	if (camera.x_off > (int)(img->width + map->width * camera.zoom))
		camera.x_off = 0 - map->width * camera.zoom;
	if (camera.x_off < 0 - map->width * camera.zoom)
		camera.x_off = img->width + map->width * camera.zoom;
	if (camera.y_off > (int)(img->height + map->height * camera.zoom))
		camera.y_off = 0 - map->height * camera.zoom;
	if (camera.y_off < 0 - map->height * camera.zoom)
		camera.y_off = img->height + map->height * camera.zoom;
}

static void	my_keyhooks(mlx_key_data_t keydata, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
		fdf->camera.pretty *= -1;
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
		reset_camera(&fdf->camera, fdf->map, fdf->img);
	if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
	{
		fdf->camera.iso = -1;
		fdf->camera.alpha = 1.570796;
		fdf->camera.beta = 0;
		fdf->camera.gamma = 0;
	}
	if (keydata.key == MLX_KEY_I && keydata.action == MLX_PRESS)
	{
		fdf->camera.iso *= -1;
		fdf->camera.alpha = 0;
		fdf->camera.beta = 0;
		fdf->camera.gamma = 0;
	}
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
		center_camera(&fdf->camera, fdf->map, fdf->img);
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
