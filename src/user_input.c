/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   user_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 10:20:30 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/24 10:25:00 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void ft_on_key(void *param)
{
	mlx_t *mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{
		ft_printf("Closing.\n");
		mlx_close_window(mlx);
	}
}