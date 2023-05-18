/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   user_input2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 16:27:45 by mhaan         #+#    #+#                 */
/*   Updated: 2023/05/18 12:19:45 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void	cam_rotation_hooks(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_1))
		fdf->camera.alpha += 0.1;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_2))
		fdf->camera.alpha -= 0.1;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_7))
		fdf->camera.beta += 0.1;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_8))
		fdf->camera.beta -= 0.1;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		fdf->camera.gamma += 0.1;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		fdf->camera.gamma -= 0.1;
	check_cam_limits(fdf->camera, fdf->map, fdf->img);
	fdf_draw_image(fdf, 0x00000000);
}
