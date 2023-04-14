/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 12:07:27 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/14 13:27:17 by mhaan         ########   odam.nl         */
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
	t_map		*map;

	// atexit(f);
	// 1. Basic error check, open map file and check the .fdf extension.
	if (argc != 2)
		ft_error("Usage: ./fdf <path_to_map>\n");
	fd = fdf_open_map_file(argv[1]);
	// 2. Parse map data from fd.
	map_data = fdf_parse_map_data(fd);
	// 3. Create map
	map = init_map(map_data);
	fdf_create_map(&map, map_data);
	// // 4. Create a MLX instance.
	map->mlx = mlx_init(WIDTH, HEIGHT, "FdF: ’Fil de Fer’", false);
	if (!map->mlx)
		exit(EXIT_FAILURE);
	// // 5. Create the image and a window to display the iamge.
	fdf_draw_image(&map, 0x00000000);
	if (mlx_image_to_window(map->mlx, map->img, 0, 0) < 0)
		exit(EXIT_FAILURE);
	mlx_loop(map->mlx);
	// // 6. Handle user input.
	// // 7. Exit program.
	mlx_terminate(map->mlx);
	// free_map()
	// free_map_data()
	// Test funcs:
	// print_map(map_data);
	exit(EXIT_SUCCESS);
	// return (0);
}
