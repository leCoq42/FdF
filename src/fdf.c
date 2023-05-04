/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 12:07:27 by mhaan         #+#    #+#                 */
/*   Updated: 2023/05/04 10:58:27 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static void	f(void)
// {
// 	system("leaks fdf");
// }

int	main(int argc, char **argv)
{
	int			fd;
	char		**map_data;
	t_fdf		*fdf;

	// Test leaks:
	// atexit(f);
	fdf = NULL;
	// 1. Basic error check, open map file and check the .fdf extension.
	if (argc != 2)
		ft_error("Usage: ./fdf <path_to_map>\n");
	fd = fdf_open_map_file(argv[1]);
	// 2. Parse map data from fd.
	map_data = fdf_parse_map_data(fd);
	// 3. Create map
	fdf = fdf_init(fdf, map_data);
	fdf_create_map(fdf->map, map_data);
	// 4. Create the image and a window to display the iamge.
	fdf_draw_image(fdf, 0x00000000);
	if (mlx_image_to_window(fdf->mlx, fdf->img, 0, 0) < 0)
		exit(EXIT_FAILURE);
	// 5. Handle user input.
	user_controls(fdf);
	mlx_key_hook(fdf->mlx, &my_keyhooks, fdf);
	// mlx_close_hook(mlx, close_func, mlx);
	mlx_loop(fdf->mlx);
	// 6. Exit program.
	mlx_terminate(fdf->mlx);
	// free_map()
	exit(EXIT_SUCCESS);
}
