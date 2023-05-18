/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 12:07:27 by mhaan         #+#    #+#                 */
/*   Updated: 2023/05/18 14:39:49 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int			fd;
	t_list		*map_data;
	t_fdf		*fdf;

	fdf = NULL;
	if (argc != 2)
		ft_error("Usage: ./fdf <path_to_map>\n");
	fd = fdf_open_map_file(argv[1]);
	map_data = fdf_parse_map_data(fd);
	fdf = fdf_init(fdf, map_data);
	create_grid(fdf->map, &map_data);
	fdf->camera = init_camera(fdf->map, fdf->img);
	fdf_draw_image(fdf, 0x00000000);
	if (mlx_image_to_window(fdf->mlx, fdf->img, 0, 0) < 0)
		free_after_error(&fdf, "Error: unsuccesful drawing of image.\n");
	put_menu(fdf);
	user_controls(fdf);
	mlx_loop(fdf->mlx);
	free_before_exit(&fdf);
	exit(EXIT_SUCCESS);
}
