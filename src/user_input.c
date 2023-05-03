/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   user_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 10:20:30 by mhaan         #+#    #+#                 */
/*   Updated: 2023/05/03 08:56:26 by mhaan         ########   odam.nl         */
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
		fdf->camera->x_offset += (10 + (fdf->camera->zoom_factor * 0.1));
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_D))
		fdf->camera->x_offset -= (10 + (fdf->camera->zoom_factor * 0.1));
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W))
		fdf->camera->y_offset += (10 + (fdf->camera->zoom_factor * 0.1));
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
		fdf->camera->y_offset -= (10 + (fdf->camera->zoom_factor * 0.1));
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		fdf->camera->zoom_factor++;
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		fdf->camera->zoom_factor--;
	if (fdf->camera->zoom_factor < 1)
		fdf->camera->zoom_factor = 1;
	if (fdf->camera->x_offset > WIDTH + fdf->map->width * fdf->camera->zoom_factor)
		fdf->camera->x_offset = 0 - fdf->map->width * fdf->camera->zoom_factor;
	if (fdf->camera->x_offset < 0 - fdf->map->width * fdf->camera->zoom_factor)
		fdf->camera->x_offset = WIDTH + fdf->map->width * fdf->camera->zoom_factor;
	if (fdf->camera->y_offset > HEIGHT + fdf->map->height * fdf->camera->zoom_factor)
		fdf->camera->y_offset = 0 - fdf->map->height * fdf->camera->zoom_factor;
	if (fdf->camera->y_offset < 0 - fdf->map->height * fdf->camera->zoom_factor)
		fdf->camera->y_offset = HEIGHT + fdf->map->height * fdf->camera->zoom_factor;
	fdf_draw_image(fdf, 0x00000000);
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
